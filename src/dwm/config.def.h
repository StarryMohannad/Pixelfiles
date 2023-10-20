/**
 *  _____   _____ 
 * |  _  | |  ___|  DWM Config (Pixelfiles)
 * | |_| | | |__    Author: StarryMohannad :DD
 * |  ___| |  __|   
 * | |     | |      GitLab: https://gitlab.com/starrymohannad/Pixelfiles
 * |_|     |_|      GitHub: https://github.com/starrymohannad/Pixelfiles
 *
**/

#include <X11/XF86keysym.h>

// APPEARANCE 

// > window layout
static const unsigned int borderpx       = 2;  // Window Borders
static const unsigned int gappx          = 7;  // Gaps Between Windows
static const unsigned int snap           = 16; // Snap Corners

// > systray
static const int showsystray             = 1;  // Toggle SysTray
static const unsigned int systrayspacing = 2;  // SysTray Spacing
static const unsigned int systrayonleft  = 0;  // SysTray on left of status text
static const unsigned int systraypinning = 0;  // Which Monitor is the SysTray on (0 for the Focused Monitor)
static const int systraypinningfailfirst = 1;  // 1: if pinning fails, display systray on the first monitor, 0: display systray on the last monitor

// > topbar
static const int showbar                 = 1;  // Toggle Bar
static const int topbar                  = 1;  // Wheather the Bar is on the Top

// > firacode font
static const char *fonts[]               = { "FiraCode Nerd Font:size=10" };

// > catppuccin colorscheme
static const char col_gray1[]            = "#24273a";
static const char col_gray2[]            = "#24273a";
static const char col_gray3[]            = "#cad3f5";
static const char col_gray4[]            = "#cad3f5";
static const char col_cyan[]             = "#5b6078";
static const char *colors[][3]           = {
                                             /*               fg         bg         border   */
                                             [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
                                             [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
                                           };

// TAG NAMES
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

// WINDOW RULES
static const Rule rules[] = {
	/* class   instance title    tagsmask floating monitor */
    { "steam", NULL,    NULL,    0,       1,       -1 },
    { "steam", NULL,    "Steam", 0,       0,       -1 }
};

// LAYOUTS
static const float mfact     = 0.55; // Factor of Master Stack 
static const int nmaster     = 1;    // Number of Windows in Master Stack
static const int resizehints = 1;    // respect size hints in tiled resizals
static const int lockfullscreen = 1; // force focus on the fullscreen window

// > layout array
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

// KEYS

// > key definitions
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG)												\
	&((Keychord){1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),
 

// > shcmd Config
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// > keychords
#include "shiftview.c" // Import Shiftview
static Keychord *keychords[] = {
        
        // Default Applications and Scripts
        //*****************************************************************************************//***********************//
        &((Keychord){1, {{MODKEY          , XK_q     }}, spawn, SHCMD("$DWM/defapps/term"    ) }), // Open       | TERMINAL //
        &((Keychord){1, {{MODKEY          , XK_o     }}, spawn, SHCMD("$DWM/defapps/pass"    ) }), //            | KPMENU   //
        &((Keychord){1, {{MODKEY          , XK_m     }}, spawn, SHCMD("$DWM/defapps/mpd"     ) }), //            | MUSIC    //
        &((Keychord){2, {{MODKEY, XK_e},{0, XK_w     }}, spawn, SHCMD("$DWM/defapps/www"     ) }), //            | BROWSER  //
        &((Keychord){2, {{MODKEY, XK_e},{0, XK_r     }}, spawn, SHCMD("$DWM/defapps/file"    ) }), //            | FILEMANG //
        &((Keychord){2, {{MODKEY, XK_e},{0, XK_e     }}, spawn, SHCMD("$DWM/defapps/emacs"   ) }), //            | EMACS    //
        //*****************************************************************************************//***********************//
        &((Keychord){1, {{MODKEY          , XK_r     }}, spawn, SHCMD("$DWM/dmenu/run"       ) }), // Prompt     | Run      //
        &((Keychord){1, {{MODKEY          , XK_g     }}, spawn, SHCMD("$DWM/dmenu/steam"     ) }), //            | Steam    //
        &((Keychord){1, {{MODKEY|ShiftMask, XK_w     }}, spawn, SHCMD("$DWM/dmenu/bye"       ) }), //            | Poweroff //
        //*****************************************************************************************//***********************//  
        &((Keychord){1, {{MODKEY          , XK_p     }}, spawn, SHCMD("$DWM/defapps/lock"    ) }), // Lock Screen           //
        //*****************************************************************************************//***********************//
        &((Keychord){1, {{0               , XK_Print }}, spawn, SHCMD("$DWM/scripts/regshot" ) }), // Screenshot | Region   //
        &((Keychord){1, {{MODKEY          , XK_Print }}, spawn, SHCMD("$DWM/scripts/scrshot" ) }), //            | Screen   //
        //*****************************************************************************************//***********************//

        // Hotkeys
        //**********************************************************************************************//********//******//
        &((Keychord){1, {{ 0, XF86XK_MonBrightnessDown }}, spawn, SHCMD("$DWM/hotkeys/bright_down") }), // Bright // DOWN //
        &((Keychord){1, {{ 0, XF86XK_MonBrightnessUp   }}, spawn, SHCMD("$DWM/hotkeys/bright_up"  ) }), //        // UP   //
        //**********************************************************************************************//********//******//
        &((Keychord){1, {{ 0, XF86XK_AudioMute         }}, spawn, SHCMD("$DWM/hotkeys/vol_mute"   ) }), // Volume // MUTE // 
        &((Keychord){1, {{ 0, XF86XK_AudioLowerVolume  }}, spawn, SHCMD("$DWM/hotkeys/vol_down"   ) }), //        // DOWN //
        &((Keychord){1, {{ 0, XF86XK_AudioRaiseVolume  }}, spawn, SHCMD("$DWM/hotkeys/vol_up"     ) }), //        // UP   //
        //**********************************************************************************************//********//******//
        &((Keychord){1, {{ 0, XF86XK_AudioPlay         }}, spawn, SHCMD("$DWM/hotkeys/mpd_play"   ) }), // MPD    // PLAY //
        &((Keychord){1, {{ 0, XF86XK_AudioPrev         }}, spawn, SHCMD("$DWM/hotkeys/mpd_prev"   ) }), //        // PREV //
        &((Keychord){1, {{ 0, XF86XK_AudioNext         }}, spawn, SHCMD("$DWM/hotkeys/mpd_next"   ) }), //        // NEXT //
        //**********************************************************************************************//****************//

        // Focused Window
        //*********************************************************************************//*********************************//
        &((Keychord){1, {{MODKEY,           XK_j      }}, focusstack,     { .i =  +1 } }), // Move Focus To | NEXT Window     // 
        &((Keychord){1, {{MODKEY,           XK_k      }}, focusstack,     { .i =  -1 } }), //               | Prev Window     //
        //*********************************************************************************//*********************************//
        &((Keychord){1, {{MODKEY,           XK_Return }}, zoom,           {        0 } }), // Focused Window | Move to Master //
        &((Keychord){1, {{MODKEY|ShiftMask, XK_space  }}, togglefloating, {        0 } }), //                | Floating       //
        &((Keychord){1, {{MODKEY,           XK_w      }}, killclient,     {        0 } }), //                | Close          //
        //*********************************************************************************//*********************************//

        // Layout
        //*********************************************************************************//*************************************//
        &((Keychord){1, {{MODKEY,           XK_l }}, setmfact,   { .f =  +0.05       } }), // Scale The Master Stack       | UP   //
        &((Keychord){1, {{MODKEY,           XK_h }}, setmfact,   { .f =  -0.05       } }), //                              | DOWN //
        //*********************************************************************************//*************************************//
        &((Keychord){1, {{MODKEY,           XK_i }}, incnmaster, { .i =  +1          } }), // Increse | The No. of Master Windows //
        &((Keychord){1, {{MODKEY,           XK_u }}, incnmaster, { .i =  -1          } }), // Decrese |                           //
        //*********************************************************************************//*************************************//
        &((Keychord){1, {{MODKEY,           XK_b }}, togglebar,  {        0          } }), // Toggle the Top Bar                  // 
        //*********************************************************************************//*************************************//
        &((Keychord){1, {{MODKEY|ShiftMask, XK_t }}, setlayout,  { .v =  &layouts[0] } }), // Layout  | Tiled                     //
        &((Keychord){1, {{MODKEY|ShiftMask, XK_f }}, setlayout,  { .v =  &layouts[1] } }), //         | Floating                  //
        &((Keychord){1, {{MODKEY|ShiftMask, XK_m }}, setlayout,  { .v =  &layouts[2] } }), //         | Monocle                   //
        //*********************************************************************************//*************************************//

        // Tags
        //****************************************************************************//***********************************//
        &((Keychord){1, {{MODKEY,           XK_a      }}, shiftview, { .i  = -1 } }), // Shiftview | NEXT                  //
        &((Keychord){1, {{MODKEY,           XK_s      }}, shiftview, { .i  = +1 } }), //           | PREV                  //
        &((Keychord){1, {{MODKEY,           XK_Tab    }}, view,      {        0 } }), //           | Current & Next Tag    //
        //****************************************************************************//***********************************//
        &((Keychord){1, {{MODKEY,           XK_0      }}, view,      { .ui = ~0 } }), // Enable All Tags                   //
        &((Keychord){1, {{MODKEY|ShiftMask, XK_0      }}, tag,       { .ui = ~0 } }), // Move the Focus Window to All Tags //
        //****************************************************************************//***********************************//

        TAGKEYS(XK_1, 0 )
        TAGKEYS(XK_2, 1 )
        TAGKEYS(XK_3, 2 )
        TAGKEYS(XK_4, 3 )
        TAGKEYS(XK_5, 4 )
        TAGKEYS(XK_6, 5 )
        TAGKEYS(XK_7, 6 )
        TAGKEYS(XK_8, 7 )
        TAGKEYS(XK_9, 8 )

        /** Multi-Monitor Stuff
        &((Keychord){1, {{MODKEY|ShiftMask, XK_comma  }}, tagmon,    { .i  = -1 } }),
        &((Keychord){1, {{MODKEY|ShiftMask, XK_period }}, tagmon,    { .i  = +1 } }), 
        &((Keychord){1, {{MODKEY,           XK_comma  }}, focusmon,  { .i  = -1 } }), 
        &((Keychord){1, {{MODKEY,           XK_period }}, focusmon,  { .i  = +1 } }),
        **/
};

// > mousebinds
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	/** { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } }, **/
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

