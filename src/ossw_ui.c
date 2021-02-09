/* ********************************************************************** */
/*                                                                        */
/* Copyright (c) 2019-2021 Binary Solo                                    */
/*                                                                        */
/* This file is part of the Open SCART Switch project (OSSW).             */
/*                                                                        */
/* This program is free software: you can redistribute it and/or modify   */
/* it under the terms of the GNU General Public License as published by   */
/* the Free Software Foundation, either version 3 of the License, or      */
/* (at your option) any later version.                                    */
/*                                                                        */
/* This program is distributed in the hope that it will be useful,        */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/* GNU General Public License for more details.                           */
/*                                                                        */
/* You should have received a copy of the GNU General Public License      */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>  */
/*                                                                        */
/* ********************************************************************** */
/* Derived from OSSC menu code at https://github.com/marqs85/ossc         */
/* Original copyright notice:                                             */
/* ********************************************************************** */
//
// Copyright (C) 2015-2019  Markus Hiienkari <mhiienka@niksula.hut.fi>
//

/*
 * includes
 *
 */

#include <samd21.h>
#include <stdio.h>
#include <string.h>

#include <ossw_ir.h>
#include <ossw_lcd.h>
#include <ossw_bus.h>
#include <ossw_rgb.h>
#include <ossw_delay.h>
#include <ossw_timer.h>
#include <ossw_button.h>
#include <ossw_settings.h>
#include <ossw_version.h>

/* implements */
#include <ossw_ui.h>

/* 
 * defines
 *
 */

/* UI defines --------------------------------------------------------------- */

/* Time */
#define UI_STATE_SPLASH_DURATION    5000ul
#define UI_MS_PER_SEC               1000ul

/* Menu timeout (seconds) */
#define UI_MENU_TIMEOUT_MIN         5u
#define UI_MENU_TIMEOUT_MAX         30u

/* LED backlight */
#define UI_LCD_BACKLIGHT_MIN        0u
#define UI_LCD_BACKLIGHT_MAX        60u

/*
 * macros
 *
 */

/* UI macros ---------------------------------------------------------------- */

#define UI_BTN_ACTION(btn)  ((btn & OSSW_BUTTON_ACTION) == OSSW_BUTTON_ACTION)
#define UI_BTN_UP(btn)      ((btn & OSSW_BUTTON_UP) == OSSW_BUTTON_UP)
#define UI_BTN_DOWN(btn)    ((btn & OSSW_BUTTON_DOWN) == OSSW_BUTTON_DOWN)
#define UI_BTN_LEFT(btn)    ((btn & OSSW_BUTTON_LEFT) == OSSW_BUTTON_LEFT)
#define UI_BTN_RIGHT(btn)   ((btn & OSSW_BUTTON_RIGHT) == OSSW_BUTTON_RIGHT)

#define UI_IR_ACTION(res)   ossw_ir_match(UI_ACTION_EXEC, res)
#define UI_IR_UP(res)       ossw_ir_match(UI_ACTION_UP, res)
#define UI_IR_DOWN(res)     ossw_ir_match(UI_ACTION_DOWN, res)
#define UI_IR_LEFT(res)     ossw_ir_match(UI_ACTION_LEFT, res)
#define UI_IR_RIGHT(res)    ossw_ir_match(UI_ACTION_RIGHT, res)

/* MENU macros -------------------------------------------------------------- */

#define SETTING_ITEM(x) 0, sizeof(x)/sizeof(char*)-1, x
#define MENU(X, Y) menu_item_t X##_items[] = Y; const menu_t X = { sizeof(X##_items)/sizeof(menu_item_t), X##_items };

#define P99_PROTECT(...) __VA_ARGS__

#define MENU_BACK  { "  <Previous Menu>",    UI_MENU_OPT_BACK, { .back = { } } },
#define MENU_EXIT  { "  <Exit Menu>",        UI_MENU_OPT_EXIT, { .exit = { } } },

/*
 * enums
 *
 */

/* UI enums ----------------------------------------------------------------- */

/**
 * UI state identifiers
 */
enum ui_state {

    /**
     * Initial state
     */
    UI_STATE_INIT     = 0,

    /**
     * Splash state
     */
    UI_STATE_SPLASH,

    /**
     * Home state
     */
    UI_STATE_HOME,

    /**
     * Menu state
     */
    UI_STATE_MENU,

};

/**
 * UI action identifiers
 */
enum ui_actions {

    /**
     * No action
     */
    UI_ACTION_NONE  = 0,

    /**
     * Execute action
     */
    UI_ACTION_EXEC,

    /**
     * Next action
     */
    UI_ACTION_UP,

    /**
     * Previous action
     */
    UI_ACTION_DOWN,

    /**
     * Jump left action
     */
    UI_ACTION_LEFT,

    /**
     * Jump right action
     */
    UI_ACTION_RIGHT

};

/* MENU enums --------------------------------------------------------------- */

typedef enum {

    UI_MENU_OPT_NONE = 0,
    UI_MENU_OPT_SELECT,
    UI_MENU_OPT_SELECT_STR,
    UI_MENU_OPT_NUMVAL,
    UI_MENU_OPT_SUBMENU,
    UI_MENU_OPT_STRING,
    UI_MENU_OPT_BACK,
    UI_MENU_OPT_EXIT,
    UI_MENU_OPT_FUNC

} menu_option_type_t;

enum menu_wrap {
    
    UI_MENU_OPT_NOWRAP = 0,
    UI_MENU_OPT_WRAP

};

/* LCD enums ---------------------------------------------------------------- */

/**
 * LCD custom character identifiers
 */
enum custom_char {

    UI_LCD_LPF_DISABLED     = 0,
    UI_LCD_LPF_ENABLED      = 1,
    UI_LCD_SYNC_DISABLED    = 2,
    UI_LCD_SYNC_ENABLED     = 3,
    UI_LCD_BUS_SIGNAL       = 4,
    UI_LCD_BUS_ENABLED      = 5,
    UI_LCD_MENU_POINTER     = 6

};

/*
 * types
 *
 */

/* UI control types --------------------------------------------------------- */

/**
 * UI input state structure
 */
struct ui_input {

    /* buttons */
    uint8_t button;

    /* infra-red */
    struct ossw_ir_result ir_curr;
    struct ossw_ir_result ir_prev;

};

/**
 * UI action structure
 */
struct ui_action {

    /* action identifier */
    uint8_t action;

    /* last action time */
    unsigned long last_action;

};

/* MENU types --------------------------------------------------------------- */

/**
 * Menu function prototypes
 */

/**
 * UI_MENU_OPT_FUNC prototypes
 */
typedef int (*func_call)(void);

/**
 * UI_MENU_OPT_STRING prototypes
 */
typedef void  (*disp_func_str)(char*, char*);
typedef void  (*disp_func_numval)(char*, uint8_t val);
typedef char* (*get_func_str)(void);
typedef void  (*set_func_str)(unsigned int, const char*);

/**
 * UI_MENU_OPT_SELECT menu structure
 */
typedef struct {

    uint8_t *data;
    uint8_t wrap;
    uint8_t min;
    uint8_t max;
    const char** settings;

} menu_option_select_t;

/**
 * UI_MENU_OPT_SELECT_STR menu structure
 */
typedef struct {

    char* data;
    uint8_t idx;
    uint8_t wrap;
    set_func_str sf;
    uint8_t min;
    uint8_t max;
    const char** settings;

} menu_option_select_str_t;

/**
 * UI_MENU_OPT_NUMVAL menu structure
 */
typedef struct {

    uint8_t *data;
    uint8_t wrap;
    uint8_t min;
    uint8_t max;
    disp_func_numval df;

} menu_option_numval_t;

/**
 * UI_MENU_OPT_FUNC menu structure
 */
typedef struct {

    func_call f;
    int ret;
    int call;

} menu_option_func_t;

/**
 * UI_MENU_OPT_STRING menu structure
 */
typedef struct {

    get_func_str  gf;
    disp_func_str df;

} menu_option_string_t;

/**
 * UI_MENU_OPT_BACK menu structure
 */
typedef struct { } menu_option_back_t;

/**
 * UI_MENU_OPT_EXIT menu structure
 */
typedef struct { } menu_option_exit_t;

/**
 * Menu structure declaration
 */
typedef struct menu menu_t;

/**
 * Menu option submenu
 */
typedef struct {

    const menu_t *menu;

} menu_option_submenu_t;

/**
 * Menu item structure
 */
typedef struct {
    
    const char* name;
    menu_option_type_t type;

    union {
        
        menu_option_submenu_t       sub;
        menu_option_select_t        sel;
        menu_option_select_str_t    sel_str;
        menu_option_numval_t        num;
        menu_option_string_t        str;
        menu_option_back_t          back;
        menu_option_exit_t          exit;
        menu_option_func_t          fun;
    };

} menu_item_t;

/**
 * Menu structure definition
 */
struct menu {

    uint8_t num_items;
    menu_item_t *items;

};

/**
 * Menu navigation structure
 */
typedef struct {

    const menu_t *m;
    uint8_t mp;

} menu_nav_t;


/*
 * globals
 *
 */

/* global settings structure */
extern struct ossw_settings g_ossw_settings;

/* UI control globals ------------------------------------------------------- */

/**
 * UI current state
 */
static uint8_t g_ui_state   = UI_STATE_INIT;

/**
 * UI refresh flag
 */
static uint8_t g_ui_refresh = 0;

/**
 * UI input state
 */
static struct ui_input g_ui_inputs = {

    .button = 0
};

/**
 * UI current action
 */
static struct ui_action g_ui_action = {

    .action = UI_ACTION_NONE,
    .last_action = 0
};

/* LCD control globals ------------------------------------------------------ */

/**
 * LCD row 1
 */
static char g_lcd_row1[OSSW_LCD_MAX_CHARS] = { 0 };

/**
 * LCD row 2
 */
static char g_lcd_row2[OSSW_LCD_MAX_CHARS] = { 0 };

/**
 * LCD custom characters
 */
static uint8_t g_custom_chars[OSSW_LCD_MAX_CUSTOM_CHARS][OSSW_LCD_CHAR_HEIGHT] = {

    {0x00, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x00, 0x00},       /* LPF: DISABLED icon */
    {0x1F, 0x17, 0x17, 0x17, 0x17, 0x11, 0x1F, 0x1F},       /* LPF: ENABLED icon */
    {0x00, 0x0E, 0x08, 0x0E, 0x02, 0x0E, 0x00, 0x00},       /* SYNC: DISABLED icon */
    {0x1F, 0x11, 0x17, 0x11, 0x1D, 0x11, 0x1F, 0x1F},       /* SYNC: ENABLED icon */
    {0x02, 0x06, 0x0A, 0x12, 0x0A, 0x06, 0x02, 0x00},       /* BUS: SIGNAL icon */
    {0x02, 0x06, 0x0E, 0x1E, 0x0E, 0x06, 0x02, 0x00},       /* BUS: ENABLED icon */
    {0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08, 0x00},       /* Menu: Pointer icon */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}        /* free */
};

/* MENU globals ------------------------------------------------------------- */


/* system names */
static const char* g_ui_systems[] = {

    "<default>",
    "Amiga CD32",
    "Atari 5200",
    "Atari 7800",
    "Atari Jaguar",
    "Coleco Vision",
    "CAPCOM CPS",
    "CAPCOM CPS II",
    "CAPCOM CPS III",
    "FM Towns Marty",
    "Microsoft XBox",
    "Microsoft XBox 360",
    "Neo Geo AES",
    "Neo Geo MVS",
    "Neo Geo CD",
    "Nintendo NES",
    "Nintendo Famicom",
    "Nintendo SNES",
    "Nintendo Super Famicom",
    "Nintendo N64",
    "Nintendo Gamecube",
    "Nintendo Wii",
    "Nintendo Wii-U",
    "Panasonic 3DO",
    "PC Engine",
    "PC-FX",
    "Philips CD-i",
    "Sega SG-1000",
    "Sega Mark III",
    "Sega Master System",
    "Sega Genesis",
    "Sega Megadrive",
    "Sega Saturn",
    "Sega Dreamcast",
    "Sony Playstation 1",
    "Sony Playstation 2",
    "Sony PSOne",
    "TurboDuo",
    "TurboGrafx-16",
};

/* on/off selection values */
static const char* off_on_desc[] = { "Off", "On" };

/* display function forward declarations */
static void ui_menu_opt_string(char*, char*);
static void ui_menu_opt_numval(char*, uint8_t val);
static void ui_menu_opt_numval_secs(char*, uint8_t val);
static void ui_menu_opt_numval_bus(char*, uint8_t val);

/**
 * General settings menu
 */
MENU(menu_general, P99_PROTECT({ \
            { "  <Save settings>",    UI_MENU_OPT_FUNC, { .fun = { ossw_settings_save, -1, 0 } } },
            { "  <Load settings>",    UI_MENU_OPT_FUNC, { .fun = { ossw_settings_load, -1, 0 } } },
            { "  <Default settings>", UI_MENU_OPT_FUNC, { .fun = { ossw_settings_default, -1, 0 } } },
            MENU_BACK
            MENU_EXIT
}))


/**
 * Input labels menu
 */
MENU(menu_input_labels, P99_PROTECT({ \
            { "  Input 1",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[0], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 2",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[1], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 3",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[2], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 4",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[3], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 5",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[4], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 6",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[5], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 7",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[6], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            { "  Input 8",  UI_MENU_OPT_SELECT_STR, { .sel_str = { g_ossw_settings.bus_names[7], 0, UI_MENU_OPT_WRAP, ossw_settings_set_bus_name, SETTING_ITEM(g_ui_systems) } } },
            MENU_BACK
            MENU_EXIT
}))

/**
 * Input settings menu
 */
MENU(menu_input, P99_PROTECT({ \
            { "  Default input", UI_MENU_OPT_NUMVAL, { .num = { &g_ossw_settings.default_bus, UI_MENU_OPT_WRAP, OSSW_BUS_ID1, OSSW_BUS_NUM - 1,  ui_menu_opt_numval_bus } } },
            { "  Input labels    >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_input_labels } } },
            { "  Sync strip",  UI_MENU_OPT_SELECT, { .sel = { &g_ossw_settings.sync_strip_enabled, UI_MENU_OPT_WRAP, SETTING_ITEM(off_on_desc) } } },
            MENU_BACK
            MENU_EXIT
}))

/**
 * Output settings menu
 */
MENU(menu_output, P99_PROTECT({ \
            { "  Low pass filter",  UI_MENU_OPT_SELECT, { .sel = { &g_ossw_settings.lpf_enabled, UI_MENU_OPT_WRAP, SETTING_ITEM(off_on_desc) } } },
            MENU_BACK
            MENU_EXIT
}))

/**
 * Display settings menu
 */
MENU(menu_display, P99_PROTECT({ \
            { "  Menu timeout", UI_MENU_OPT_NUMVAL, { .num = { &g_ossw_settings.menu_timeout, UI_MENU_OPT_WRAP, UI_MENU_TIMEOUT_MIN, UI_MENU_TIMEOUT_MAX,  ui_menu_opt_numval_secs } } },
            { "  LCD contrast", UI_MENU_OPT_NUMVAL, { .num = { &g_ossw_settings.lcd_contrast, UI_MENU_OPT_WRAP, OSSW_LCD_CONTRAST_MIN, OSSW_LCD_CONTRAST_MAX,  ui_menu_opt_numval } } },
            { "  LCD backlight", UI_MENU_OPT_NUMVAL, { .num = { &g_ossw_settings.lcd_backlight, UI_MENU_OPT_WRAP, UI_LCD_BACKLIGHT_MIN, UI_LCD_BACKLIGHT_MAX,  ui_menu_opt_numval_secs } } },
            MENU_BACK
            MENU_EXIT
}))

/**
 * About menu
 */
MENU(menu_about, P99_PROTECT({ \
            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_product_name, ui_menu_opt_string } } },

            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_firmware, ui_menu_opt_string } } },

            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_company_name, ui_menu_opt_string } } },

            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_website, ui_menu_opt_string } } },
#ifdef _DEBUG
            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_build_date, ui_menu_opt_string } } },

            { "", UI_MENU_OPT_STRING, 
            { .str = { ossw_version_get_build_host, ui_menu_opt_string } } },
#endif
}))

/**
 * Main menu
 */
MENU(menu_main, P99_PROTECT({ \
            { "  General options >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_general } } },
            { "  Input options   >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_input   } } },
            { "  Output options  >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_output  } } },
            { "  Display options >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_display } } },
            { "  About           >",  UI_MENU_OPT_SUBMENU, { .sub = { &menu_about   } } },
            MENU_EXIT
}))

static menu_nav_t g_menu_nav[] = {{&menu_main, 0}, {NULL, 0}, {NULL, 0}};
static uint8_t g_menu_nav_lvl  = 0;

/*
 * static functions
 *
 */

/* UI control functions ----------------------------------------------------- */

/**
 * Set UI state
 */
static void 
ui_set_state(int state)
{
    g_ui_state = (uint8_t) state;
    g_ui_refresh = 1;
}

/**
 * Clear UI row data
 */
static void 
ui_clear_row_data(void)
{
    (void) memset(g_lcd_row1, 0x0, OSSW_LCD_MAX_CHARS);
    (void) memset(g_lcd_row2, 0x0, OSSW_LCD_MAX_CHARS);
}

/* UI display functions ----------------------------------------------------- */

/**
 * UI_MENU_OPT_STRING display function
 */
static void
ui_menu_opt_string(char* dst, char* src)
{
    strncpy(dst, src, OSSW_LCD_MAX_CHARS);
}

/**
 * UI_MENU_OPT_NUMVAL display function - no units
 */
static void 
ui_menu_opt_numval(char* dst, uint8_t val)
{
    snprintf(dst, OSSW_LCD_MAX_CHARS, "%u", val);
}

/**
 * UI_MENU_OPT_NUMVAL display function - unit in SECONDS
 */
static void 
ui_menu_opt_numval_secs(char* dst, uint8_t val)
{
    snprintf(dst, OSSW_LCD_MAX_CHARS, "%us", val);
}

/**
 * UI_MENU_OPT_NUMVAL display function - Input Bus
 */
static void 
ui_menu_opt_numval_bus(char* dst, uint8_t val)
{
    snprintf(dst, OSSW_LCD_MAX_CHARS, "Input %u", val + 1);
}

static void 
ui_show_splash(void)
{
    ui_clear_row_data();

    /* show firmware version */
    snprintf(g_lcd_row1, OSSW_LCD_MAX_CHARS, "%s: %s",
            ossw_version_get_product_name(), ossw_version_get_firmware());

    /* show copyright */
    snprintf(g_lcd_row2, OSSW_LCD_MAX_CHARS, "%s (c) %s",
            ossw_version_get_company_name(), ossw_version_get_build_year());

    ossw_lcd_display(g_lcd_row1, g_lcd_row2, 0, 0);
    delay_ms(UI_STATE_SPLASH_DURATION);

    ui_set_state(UI_STATE_HOME);
}

static void 
ui_show_home(void)
{
    int bus = 0;
    char* p = NULL;

    if(g_ui_refresh) {

        ui_clear_row_data();
        bus = ossw_bus_get_current_bus();

        /* show current bus name */
        strncpy(g_lcd_row1, ossw_settings_get_bus_name(bus), OSSW_LCD_MAX_CHARS);

        /* display bus numbers */
        p = g_lcd_row2;
        for(int i = 1; i <= OSSW_BUS_NUM; i++) {
            *(p++) = (char) (i + '0');              /* int to ascii char value */
            *(p++) = ' ';
        }
        ossw_lcd_display(g_lcd_row1, g_lcd_row2, 0, 0);

        /* indicate bus signals */

        /* indicate enabled bus */
        ossw_lcd_set_cursor(2, (bus == 0) ? 2 : (2 * bus) + 2);
        ossw_lcd_print_custom_char(UI_LCD_BUS_ENABLED);

        /* display RGB LPF setting */
        ossw_lcd_set_cursor(2,19);
        ossw_lcd_print_custom_char(
                (ossw_settings_get_lpf_enable()) ? UI_LCD_LPF_ENABLED : UI_LCD_LPF_DISABLED);

        /* display sync strip setting */
        ossw_lcd_set_cursor(2,20);
        ossw_lcd_print_custom_char(
                (ossw_settings_get_sync_strip_enable()) ? UI_LCD_SYNC_ENABLED : UI_LCD_SYNC_DISABLED);

        g_ui_refresh = 0;
    }
}

static void 
ui_show_menu(void)
{
    const menu_t* m = g_menu_nav[g_menu_nav_lvl].m;         /* current menu */
    uint8_t mp  = g_menu_nav[g_menu_nav_lvl].mp;            /* menu item index */
    uint8_t nmp = (mp + 1 + m->num_items) % m->num_items;   /* next menu item index */

    menu_option_type_t t1 = m->items[mp].type;
    menu_option_type_t t2 = m->items[nmp].type;

    if(g_ui_refresh) {
        ui_clear_row_data();

        /* row 1 */
        switch(t1) {

            case UI_MENU_OPT_STRING:
                m->items[mp].str.df(g_lcd_row1, m->items[mp].str.gf());
                break;;
            default:
                strncpy(g_lcd_row1, 
                        m->items[mp].name, 
                        OSSW_LCD_MAX_CHARS); 

                break;;
        }

        /* row 2 */
        switch(t1) {
            case UI_MENU_OPT_NUMVAL:
                m->items[mp].num.df(g_lcd_row2, *(m->items[mp].num.data));
                break;;

            case UI_MENU_OPT_SELECT:
                strncpy(
                        g_lcd_row2, 
                        m->items[mp].sel.settings[*(m->items[mp].sel.data)], 
                        OSSW_LCD_MAX_CHARS
                );
                break;;
            case UI_MENU_OPT_SELECT_STR:
                strncpy(
                        g_lcd_row2, 
                        m->items[mp].sel_str.data,
                        OSSW_LCD_MAX_CHARS
                );
                break;;
            case UI_MENU_OPT_FUNC:
                if(m->items[mp].fun.call){
                    strncpy(
                            g_lcd_row2, 
                            (m->items[mp].fun.ret == 0) ? "Success" : "Failed",
                            OSSW_LCD_MAX_CHARS
                    );
                    m->items[mp].fun.ret = -1;
                    m->items[mp].fun.call = 0;
                    break;;
                }
                /* intentional fall through */
            default:
                switch(t2) {
                    case UI_MENU_OPT_STRING:
                        m->items[nmp].str.df(g_lcd_row2, m->items[nmp].str.gf());
                        break;;
                    default:
                        strncpy(g_lcd_row2, 
                                m->items[nmp].name, 
                                OSSW_LCD_MAX_CHARS); 
                        break;;
                }
        }

        ossw_lcd_display(g_lcd_row1, g_lcd_row2, 0, 0);

        /* menu pointer */
        switch(t1) {

            case UI_MENU_OPT_STRING:

                break;;
            default:
                ossw_lcd_set_cursor(1,1);
                ossw_lcd_print_custom_char(UI_LCD_MENU_POINTER);
                break;;
        }

        g_ui_refresh = 0;
    }
}

static void
ui_show_error(void)
{
    ui_clear_row_data();
}

/* UI input handler functions ----------------------------------------------- */

static void
ui_menu_exit(void)
{
    /* calculate deepest level */
    int lvl = (sizeof(g_menu_nav) / sizeof(menu_nav_t)) - 1;

    /* reset sub level nav data */
    while(lvl > 0){
        g_menu_nav[lvl].m = NULL;
        g_menu_nav[lvl--].mp = 0;
    }

    /* reset root level nav data */
    g_menu_nav[lvl].mp = 0;
    g_menu_nav_lvl = 0;

    ui_set_state(UI_STATE_HOME);
}

static void
ui_menu_back(void)
{
    /* reset sub level nav data */
    if(g_menu_nav_lvl > 0) {
        g_menu_nav[g_menu_nav_lvl].m = NULL;
        g_menu_nav[g_menu_nav_lvl--].mp = 0;

        ui_set_state(UI_STATE_MENU);
    }
}

static void
ui_read_input(void)
{
    struct ossw_ir_result *ir = NULL;

    /* clear previous action */
    g_ui_action.action = UI_ACTION_NONE;

    /* ---------------------------------------------------------------------- */

    /* 
     * read button input
     *
     */

    g_ui_inputs.button = 0;
    (void) ossw_button_read(&g_ui_inputs.button);

    /* ---------------------------------------------------------------------- */

    /* 
     * read infra-red input
     *
     */

    /* store previous code but only if it was a complete code */
    if((g_ui_inputs.ir_curr.data != OSSW_IR_REPEAT) && (g_ui_inputs.ir_curr.data != 0)) {
        memcpy(&g_ui_inputs.ir_prev, &g_ui_inputs.ir_curr, sizeof(struct ossw_ir_result));
    }
    memset(&g_ui_inputs.ir_curr, 0, sizeof(struct ossw_ir_result));

    /* receive new data, if we get a repeat sequence then
     * use previously stored code to lookup action mapping
     */
    if(ossw_ir_recv(&g_ui_inputs.ir_curr) > 0){
        if(g_ui_inputs.ir_curr.data == OSSW_IR_REPEAT) {
            ir = &g_ui_inputs.ir_prev;
        } else {
            ir = &g_ui_inputs.ir_curr;
        }
    }

    /*
     * process inputs
     *
     */

    if(UI_BTN_ACTION(g_ui_inputs.button) || UI_IR_ACTION(ir)) { 
        g_ui_action.action = UI_ACTION_EXEC;
    }

    if(UI_BTN_UP(g_ui_inputs.button) || UI_IR_UP(ir)) {
        g_ui_action.action = UI_ACTION_UP;
    }

    if(UI_BTN_DOWN(g_ui_inputs.button) || UI_IR_DOWN(ir)) {
        g_ui_action.action = UI_ACTION_DOWN;
    }

    if(UI_BTN_LEFT(g_ui_inputs.button) || UI_IR_LEFT(ir)) {
        g_ui_action.action = UI_ACTION_LEFT;
    }

    if(UI_BTN_RIGHT(g_ui_inputs.button) || UI_IR_RIGHT(ir)) {
        g_ui_action.action = UI_ACTION_RIGHT;
    }

    /* update menu timeout */
    if(g_ui_action.action != UI_ACTION_NONE) {
        g_ui_action.last_action = millis();
        ossw_lcd_backlight_enable();
    }
}

static void
ui_input_home(void)
{
    switch(g_ui_action.action) {

        /* display menu */
        case UI_ACTION_EXEC:
            ui_set_state(UI_STATE_MENU);
            break;;

        /* previous bus */
        case UI_ACTION_RIGHT:
            ossw_bus_enable_next();
            g_ui_refresh = 1;
            break;;

        /* next bus */
        case UI_ACTION_LEFT:
            ossw_bus_enable_prev();
            g_ui_refresh = 1;
            break;;

        default:
            break;;
    }
}

static void
ui_input_menu(void)
{
    uint8_t* val = NULL;
    uint8_t wrap = 0, min = 0, max = 0;

    const menu_t* m = g_menu_nav[g_menu_nav_lvl].m;
    uint8_t mp = g_menu_nav[g_menu_nav_lvl].mp;

    menu_option_type_t type = m->items[mp].type;

    switch(g_ui_action.action) {

        /* display menu */
        case UI_ACTION_EXEC:

            switch(type) {

                case UI_MENU_OPT_STRING:
                case UI_MENU_OPT_BACK:
                    ui_menu_back();
                    break;;

                case UI_MENU_OPT_EXIT:
                    ui_menu_exit();
                    break;;

                case UI_MENU_OPT_FUNC:
                    m->items[mp].fun.ret = m->items[mp].fun.f();
                    m->items[mp].fun.call = 1;

                    g_ui_refresh = 1;
                    break;;

                case UI_MENU_OPT_SUBMENU:
                    if(g_menu_nav[g_menu_nav_lvl + 1].m != m->items[mp].sub.menu) {
                        g_menu_nav[g_menu_nav_lvl + 1].mp = 0;
                    }
                    g_menu_nav[g_menu_nav_lvl + 1].m = m->items[mp].sub.menu;
                    g_menu_nav_lvl++;

                    g_ui_refresh = 1;
                    break;;

                default:
                    break;;

            }

            break;;

        /* previous item */
        case UI_ACTION_UP:
            g_menu_nav[g_menu_nav_lvl].mp = (mp == 0) ? (m->num_items - 1) : (mp - 1);
            g_ui_refresh = 1;
            break;;

        /* next item */
        case UI_ACTION_DOWN:
            g_menu_nav[g_menu_nav_lvl].mp = (mp + 1) % m->num_items;
            g_ui_refresh = 1;
            break;;

        /* next/previous value */
        case UI_ACTION_LEFT:
        case UI_ACTION_RIGHT:
            switch(type) {
                case UI_MENU_OPT_NUMVAL:
                case UI_MENU_OPT_SELECT:

                    val  = m->items[mp].sel.data;
                    wrap = m->items[mp].sel.wrap;
                    min  = m->items[mp].sel.min;
                    max  = m->items[mp].sel.max;

                    if (g_ui_action.action == UI_ACTION_LEFT) {
                        *val = (*val > min) ? (*val-1) : (wrap ? max : min);             
                    } else {
                        *val = (*val < max) ? (*val+1) : (wrap ? min : max);
                    }
                    g_ui_refresh = 1;
                    break;;

                case UI_MENU_OPT_SELECT_STR:

                    val  = &m->items[mp].sel_str.idx;
                    wrap = m->items[mp].sel_str.wrap;
                    min  = m->items[mp].sel_str.min;
                    max  = m->items[mp].sel_str.max;

                    if (g_ui_action.action == UI_ACTION_LEFT) {
                        *val = (*val > min) ? (*val-1) : (wrap ? max : min);             
                    } else {
                        *val = (*val < max) ? (*val+1) : (wrap ? min : max);
                    }
                    m->items[mp].sel_str.sf(
                            mp, (*val == 0) ? NULL : m->items[mp].sel_str.settings[*val]);
                    g_ui_refresh = 1;
                    break;;

                default:
                    break;;
            }

        case UI_ACTION_NONE:
        default:

            /* exit menu */
            if((millis() - g_ui_action.last_action) 
                    >= (ossw_settings_get_menu_timeout() * UI_MS_PER_SEC)){
                ui_menu_exit();
            }
            break;;
    }
}


/*
 * exported functions
 *
 */

void
ossw_ui_init(void)
{
    /* write custom characters to display CGRAM */
    for(int i = 0; i < OSSW_LCD_MAX_CUSTOM_CHARS; i++) {
        ossw_lcd_create_custom_char(i, g_custom_chars[i]);
    }
    ui_set_state(UI_STATE_SPLASH);
}

void
ossw_ui_update(void)
{
    ui_read_input();

    switch(g_ui_state) {
        case UI_STATE_SPLASH:
            ui_show_splash();
            break;;

        case UI_STATE_HOME:
            ui_show_home();
            ui_input_home();
            break;;

        case UI_STATE_MENU:
            ui_show_menu();
            ui_input_menu();
            break;;

        default:
            ui_show_error();
            break;;
    }

    /* disable backlight */
    uint8_t bl = ossw_settings_get_lcd_backlight();
    if((bl != 0) && (millis() - g_ui_action.last_action) >= (bl * UI_MS_PER_SEC)){
        ossw_lcd_backlight_disable();
    }
}
