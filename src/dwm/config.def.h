#include <X11/XF86keysym.h>

static const unsigned int borderpx = 2;
static const unsigned int gappx = 7;
static const unsigned int snap = 16;

static const int showsystray = 1;
static const unsigned int systrayspacing = 2;
static const unsigned int systrayonleft = 0;
static const unsigned int systraypinning = 0;
static const int systraypinningfailfirst = 1;

static const int showbar = 1;
static const int topbar = 1;

static const int swallowfloating = 0;

static const char *fonts[] = { "FiraCode Nerd Font:size=10" };

static const char col_gray1[] = "#24273a";
static const char col_gray2[] = "#24273a";
static const char col_gray3[] = "#cad3f5";
static const char col_gray4[] = "#cad3f5";
static const char col_cyan[]  = "#5b6078";
static const char *colors[][3] = { [SchemeNorm] = { col_gray3, col_gray1, col_gray2 }, [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  } };

static const char *tags[] = { "󰖟", "", "", "", "", "", "", "󰍡", "*" };

static const Rule rules[] = {

{ "st-256color", NULL, NULL, 0, 0, 1, 0, -1 },

{ "firefox", NULL, NULL, -1, 0, 0, 0, -1 },
{ "Librewolf", NULL, NULL, -1, 0, 0, 0, -1 },
{ "qutebrowser", NULL, NULL, -1, 0, 0, 0, -1 },
{ "waterfox", NULL, NULL, -1, 0, 0, 0, -1 },
{ "thorium-browser", NULL, NULL, -1, 0, 0, 0, -1 },
{ "chromium", NULL, NULL, -1, 0, 0, 0, -1 },
{ "brave-browser", NULL, NULL, -1, 0, 0, 0, -1 },

{ "discord", NULL, NULL, 1 << 7, 0, 0, 0, -1 },

{ "steam", NULL, NULL, 0, 1, 0, 0, -1 },
{ "steam", NULL, "Steam", 1 << 3, 0, 0, 0, -1 },

{ "DoomRunner", NULL, NULL, 1 << 3, 1, 0, 0, -1 } };

static const float mfact = 0.55; // Factor of Master Stack
static const int nmaster = 1;    // Number of Windows in Master Stack
static const int resizehints = 1;    //
static const int lockfullscreen = 1; // force focus on the fullscreen window

static const Layout layouts[] = {
{ "[]=", tile },
{ "><>", NULL },
{ "[M]", monocle },
};

#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG)												\
	&((Keychord){1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#include "shiftview.c"

static Keychord *keychords[] = {

&((Keychord){1, {{MODKEY, XK_e }}, spawn, SHCMD("$DWM/defapps/emacs" ) }),
&((Keychord){1, {{MODKEY, XK_m }}, spawn, SHCMD("$DWM/defapps/mpd" ) }),
&((Keychord){1, {{MODKEY, XK_r }}, spawn, SHCMD("$DWM/defapps/file") }),
&((Keychord){1, {{MODKEY, XK_t }}, spawn, SHCMD("$DWM/defapps/term") }),
&((Keychord){1, {{MODKEY, XK_w }}, spawn, SHCMD("$DWM/defapps/www" ) }),

&((Keychord){1, {{MODKEY, XK_o }}, spawn, SHCMD("$DWM/dmenu/pass") }),
&((Keychord){1, {{MODKEY, XK_p }}, spawn, SHCMD("$DWM/dmenu/run") }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_t }}, spawn, SHCMD("$DWM/dmenu/code" ) }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_h }}, spawn, SHCMD("$DWM/dmenu/art" ) }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_g }}, spawn, SHCMD("$DWM/dmenu/steam" ) }),

&((Keychord){1, {{0, XK_Print  }}, spawn, SHCMD("$DWM/scripts/regshot" ) }),
&((Keychord){1, {{MODKEY, XK_Print  }}, spawn, SHCMD("$DWM/scripts/scrshot" ) }),

&((Keychord){1, {{ 0, XF86XK_MonBrightnessDown }}, spawn, SHCMD("$DWM/hotkeys/bright_down") }),
&((Keychord){1, {{ 0, XF86XK_MonBrightnessUp }}, spawn, SHCMD("$DWM/hotkeys/bright_up") }),

&((Keychord){1, {{ 0, XF86XK_AudioMute }}, spawn, SHCMD("$DWM/hotkeys/vol_mute") }),
&((Keychord){1, {{ 0, XF86XK_AudioLowerVolume }}, spawn, SHCMD("$DWM/hotkeys/vol_down") }),
&((Keychord){1, {{ 0, XF86XK_AudioRaiseVolume }}, spawn, SHCMD("$DWM/hotkeys/vol_up") }),

&((Keychord){1, {{ 0, XF86XK_AudioPlay }}, spawn, SHCMD("$DWM/hotkeys/mpd_play") }),
&((Keychord){1, {{ 0, XF86XK_AudioPrev }}, spawn, SHCMD("$DWM/hotkeys/mpd_prev") }),
&((Keychord){1, {{ 0, XF86XK_AudioNext }}, spawn, SHCMD("$DWM/hotkeys/mpd_next") }),

&((Keychord){1, {{MODKEY, XK_c }}, killclient, { 0 } }),
&((Keychord){1, {{MODKEY, XK_j }}, focusstack, { .i =  +1 } }),
&((Keychord){1, {{MODKEY, XK_k }}, focusstack, { .i =  -1 } }),
&((Keychord){1, {{MODKEY, XK_Return }}, zoom, { 0 } }),
&((Keychord){1, {{MODKEY, XK_space }}, togglefloating, { 0 } }),

&((Keychord){1, {{MODKEY|ShiftMask, XK_l }}, setmfact,   { .f =  +0.05 } }), // Scale The Master Stack       | UP   //
&((Keychord){1, {{MODKEY|ShiftMask, XK_h }}, setmfact,   { .f =  -0.05 } }), //                              | DOWN //
&((Keychord){1, {{MODKEY, XK_i }}, incnmaster, { .i =  +1 } }), // Increse | The No. of Master Windows //
&((Keychord){1, {{MODKEY, XK_u }}, incnmaster, { .i =  -1 } }), // Decrese |                           //
&((Keychord){1, {{MODKEY, XK_b }}, togglebar,  { 0 } }), // Toggle the Top Bar                  //
&((Keychord){1, {{MODKEY|ShiftMask, XK_t }}, setlayout,  { .v =  &layouts[0] } }), // Layout  | Tiled                     //
&((Keychord){1, {{MODKEY|ShiftMask, XK_f }}, setlayout,  { .v =  &layouts[1] } }), //         | Floating                  //
&((Keychord){1, {{MODKEY|ShiftMask, XK_m }}, setlayout,  { .v =  &layouts[2] } }), //         | Monocle                   //

&((Keychord){1, {{MODKEY, XK_h }}, shiftview, { .i  = -1 } }),
&((Keychord){1, {{MODKEY, XK_l }}, shiftview, { .i  = +1 } }),
&((Keychord){1, {{MODKEY, XK_Tab }}, view, { 0 } }),
&((Keychord){1, {{MODKEY, XK_0 }}, view, { .ui = ~0 } }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_0 }}, tag, { .ui = ~0 } }),

&((Keychord){2, {{MODKEY|ShiftMask, XK_q },{0, XK_q }}, spawn, SHCMD("$DWM/dmenu/bye") }),
&((Keychord){2, {{MODKEY|ShiftMask, XK_q },{0, XK_w }}, spawn, SHCMD("xkill") }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_p }}, spawn, SHCMD("$DWM/defapps/lock") }),

TAGKEYS(XK_1, 0 )
TAGKEYS(XK_2, 1 )
TAGKEYS(XK_3, 2 )
TAGKEYS(XK_4, 3 )
TAGKEYS(XK_5, 4 )
TAGKEYS(XK_6, 5 )
TAGKEYS(XK_7, 6 )
TAGKEYS(XK_8, 7 )
TAGKEYS(XK_9, 8 )

/**
&((Keychord){1, {{MODKEY|ShiftMask, XK_comma  }}, tagmon,    { .i  = -1 } }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_period }}, tagmon,    { .i  = +1 } }),
&((Keychord){1, {{MODKEY,           XK_comma  }}, focusmon,  { .i  = -1 } }),
&((Keychord){1, {{MODKEY,           XK_period }}, focusmon,  { .i  = +1 } }),
**/ };

static const Button buttons[] = {
{ ClkTagBar, MODKEY, Button1, tag, { 0 } },
{ ClkTagBar, MODKEY, Button3, toggletag, { 0 } },
{ ClkWinTitle, 0, Button2, zoom, { 0 } },
{ ClkStatusText, 0, Button2, spawn, SHCMD("$DWM/defapps/term") },
{ ClkClientWin, MODKEY, Button1, movemouse, { 0 } },
{ ClkClientWin, MODKEY, Button2, togglefloating, { 0 } },
{ ClkClientWin, MODKEY, Button3, resizemouse, { 0 } },
{ ClkTagBar, 0, Button1, view, { 0 } },
{ ClkTagBar, 0, Button3, toggleview, { 0 } }, };
