#include <X11/XF86keysym.h>

static const unsigned int borderpx = 1;
static const unsigned int gappx = 5;
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

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

static const char *tags[] = { "󰖟", "", "", "", "", "", "", "󰍡", "*" };

static const Rule rules[] = {

{ "firefox", NULL, NULL, 1 << 0, 0, 0, 0, -1 },
{ "Librewolf", NULL, NULL, 1 << 0, 0, 0, 0, -1 },
{ "qutebrowser", NULL, NULL, 1 << 0, 0, 0, 0, -1 },
{ "waterfox", NULL, NULL, 1 << 0, 0, 0, 0, -1 },
{ "chromium", NULL, NULL, 1 << 0, 0, 0, 0, -1 },
{ "brave-browser", NULL, NULL, 1 << 0, 0, 0, 0, -1 },

{ "emacs", NULL, NULL, 1 << 1, 0, 0, 0, -1 },

{ "St", NULL, NULL, 0, 0, 1, 0, -1 },

{ "discord", NULL, NULL, 1 << 7, 0, 0, 0, -1 },
{ "zoom", NULL, NULL, 1 << 7, 0, 0, 0, -1 },

{ NULL, NULL, "Steam", 1 << 3, 1, 0, 0, -1 },
{ "steam", NULL, NULL, 1 << 3, 1, 0, 0, -1 },
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

&((Keychord){1, {{MODKEY, XK_e }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/emacs" ) }),
&((Keychord){1, {{MODKEY, XK_g }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/game" ) }),
&((Keychord){1, {{MODKEY, XK_m }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/mpd" ) }),
&((Keychord){1, {{MODKEY, XK_r }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/file") }),
&((Keychord){1, {{MODKEY, XK_t }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/term") }),
&((Keychord){1, {{MODKEY, XK_w }}, spawn, SHCMD("$DWM/scripts/dwm/defapps/www" ) }),

&((Keychord){1, {{MODKEY, XK_o }}, spawn, SHCMD("$DWM/scripts/dmenu/pass") }),
&((Keychord){1, {{MODKEY, XK_p }}, spawn, SHCMD("$DWM/scripts/dmenu/run") }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_t }}, spawn, SHCMD("$DWM/scripts/dmenu/code" ) }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_h }}, spawn, SHCMD("$DWM/scripts/dmenu/art" ) }),
&((Keychord){2, {{MODKEY, XK_d }, {0, XK_g }}, spawn, SHCMD("$DWM/scripts/dmenu/steam" ) }),

&((Keychord){1, {{0, XK_Print  }}, spawn, SHCMD("$DWM/scripts/dwm/prtsc/rectangle-shot.sh" ) }),
&((Keychord){1, {{Mod1Mask, XK_Print  }}, spawn, SHCMD("$DWM/scripts/dwm/prtsc/rectangle-text.sh" ) }),
&((Keychord){1, {{MODKEY, XK_Print  }}, spawn, SHCMD("$DWM/scripts/dwm/prtsc/screenshot.sh" ) }),

&((Keychord){1, {{ 0, XF86XK_MonBrightnessDown }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/bright/down.sh") }),
&((Keychord){1, {{ 0, XF86XK_MonBrightnessUp }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/bright/up.sh") }),

&((Keychord){1, {{ 0, XF86XK_AudioMute }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/vol/mute.sh") }),
&((Keychord){1, {{ 0, XF86XK_AudioLowerVolume }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/vol/down.sh") }),
&((Keychord){1, {{ 0, XF86XK_AudioRaiseVolume }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/vol/up.sh") }),

&((Keychord){1, {{ 0, XF86XK_AudioPlay }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/mpd/play.sh") }),
&((Keychord){1, {{ 0, XF86XK_AudioPrev }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/mpd/previous.sh") }),
&((Keychord){1, {{ 0, XF86XK_AudioNext }}, spawn, SHCMD("$DWM/scripts/dwm/hotkeys/mpd/next.sh") }),

&((Keychord){1, {{MODKEY, XK_c }}, killclient, { 0 } }),
&((Keychord){1, {{MODKEY, XK_j }}, focusstack, { .i =  +1 } }),
&((Keychord){1, {{MODKEY, XK_k }}, focusstack, { .i =  -1 } }),
&((Keychord){1, {{MODKEY, XK_Return }}, zoom, { 0 } }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_g }}, togglefloating, { 0 } }),

&((Keychord){1, {{MODKEY|ShiftMask, XK_l }}, setmfact,   { .f =  +0.05 } }), // Scale The Master Stack       | UP   //
&((Keychord){1, {{MODKEY|ShiftMask, XK_h }}, setmfact,   { .f =  -0.05 } }), //                              | DOWN //
&((Keychord){1, {{MODKEY, XK_i }}, incnmaster, { .i =  +1 } }), // Increse | The No. of Master Windows //
&((Keychord){1, {{MODKEY, XK_u }}, incnmaster, { .i =  -1 } }), // Decrese |                           //
&((Keychord){1, {{MODKEY, XK_b }}, togglebar,  { 0 } }), // Toggle the Top Bar                  //
&((Keychord){1, {{MODKEY|ShiftMask, XK_t }}, setlayout,  { .v =  &layouts[0] } }), // Layout  | Tiled                     //
&((Keychord){1, {{MODKEY|ShiftMask, XK_f }}, setlayout,  { .v =  &layouts[1] } }), //         | Floating                  //
&((Keychord){1, {{MODKEY|ShiftMask, XK_m }}, setlayout,  { .v =  &layouts[2] } }), //         | Monocle                   //
&((Keychord){1, {{MODKEY, XK_minus }}, setgaps, {.i = -1 } }),
&((Keychord){1, {{MODKEY, XK_equal }}, setgaps, {.i = +1 } }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_equal }}, setgaps, {.i = gappx  } }),

&((Keychord){1, {{MODKEY, XK_h }}, shiftview, { .i  = -1 } }),
&((Keychord){1, {{MODKEY, XK_l }}, shiftview, { .i  = +1 } }),
&((Keychord){1, {{MODKEY, XK_Tab }}, view, { 0 } }),
&((Keychord){1, {{MODKEY, XK_0 }}, view, { .ui = ~0 } }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_0 }}, tag, { .ui = ~0 } }),

&((Keychord){2, {{MODKEY|ShiftMask, XK_q },{0, XK_q }}, spawn, SHCMD("$DWM/scripts/dwm/quit.sh") }),
&((Keychord){2, {{MODKEY|ShiftMask, XK_q },{0, XK_w }}, spawn, SHCMD("xkill") }),
&((Keychord){1, {{MODKEY|ShiftMask, XK_p }}, spawn, SHCMD("$DWM/scripts/dwm/lock.sh") }),
&((Keychord){1, {{MODKEY, XK_F5 }}, xrdb, { .v = NULL } }),

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
