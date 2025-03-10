#include "theme.c"

static const unsigned int borderpx  = 1;            /* border pixel of windows */
static const unsigned int gappx     = 10;           /* gaps between windows */
static const unsigned int snap      = 32;           /* snap pixel */
static const int showbar            = 1;            /* 0 means no bar */
static const int topbar             = 0;            /* 0 means bottom bar */
static const int vertpad            = 10;           /* vertical bar padding */
static const int sidepad            = 10;           /* horizontal bar padding */
static const char *fonts[]          = { "SpaceMono Nerd Font:size=11:style=Regular" };
static const char dmenufont[]       = "SpaceMono Nerd Font:size=11:style=Regular";

static const Theme theme            = th_pink_lain; /* theme.c */

/* TODO ORDER */
static const char col_black[]       = "#000000";
static const char col_red[]         = "#ff0000";
static const char col_yellow[]      = "#ffff00";
static const char col_white[]       = "#ffffff";

static const char *colors[][3] = {
  /*               fg            bg           border   */
  [SchemeNorm] =  { theme.white, theme.black, theme.black },
  [SchemeSel]  =  { theme.black, theme.red,   theme.grey },
  /* dwmblocks: \0x3 \0x4 \0x5 \0x6 respectively (statuscolors patch) */
  [SchemeBarNormal]  = { theme.bar.normal,  theme.bar.background, theme.bar.background },
  [SchemeBarSuccess] = { theme.bar.success, theme.bar.background, theme.bar.background },
  [SchemeBarWarning] = { theme.bar.warning, theme.bar.background, theme.bar.background },
  [SchemeBarError]   = { theme.bar.error,   theme.bar.background, theme.bar.background },
};

/* tagging */
/* numerals:
 *  - javanese: "꧑", "꧒", "꧓", "꧔", "꧕", "꧖", "꧗", "꧘", "꧙"
 * */
static const char *tags[] = { "I", "II", "III", "IV", "V" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating    monitor */
	/* { "Gimp",     NULL,       NULL,       0,            1,           -1 }, */
  { "ColorPicker", NULL,   NULL,        0,            1,            -1 },
  { "Io.elementary.files", NULL, NULL,  0,            1,            -1 },
  { "SimpleScreenRecorder", NULL, NULL, 0,            1,            -1 },
  { "TodoC",    NULL,       NULL,       0,            1,            0 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "󱔼",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char hpitems[] = "shot,spotify,firefox,chromium,color-picker,codium,vim,neovim,librewolf,telegram,simplescreenrecorder";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-hp", hpitems, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *sscmd[] = { "flameshot", "gui", NULL };
static const char *ckbcmd[] = { "chkeys.sh", NULL };
static const char *get_win_t[] = { "cp_wm_class.sh", NULL };

static const Key keys[] = {
	/* modifier                     key              function        argument */
	{ MODKEY,                       XK_d,            spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_s,            spawn,          {.v = sscmd } },
  { MODKEY|ShiftMask,             XK_k,            spawn,          {.v = ckbcmd } },
  { MODKEY|ShiftMask,             XK_w,            spawn,          {.v = get_win_t } },
  { MODKEY,                       XK_bracketleft,  shiftview,      {.i = -1} },
  { MODKEY,                       XK_bracketright, shiftview,      {.i = +1} },
	{ MODKEY,                       XK_Return,       spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,            togglebar,      {0} },
	{ MODKEY,                       XK_j,            focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,            focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,            incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,            incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,            setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,            setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,       zoom,           {0} },
	{ MODKEY,                       XK_Tab,          view,           {0} },
	{ MODKEY,                       XK_c,            killclient,     {0} },
	{ MODKEY,                       XK_t,            setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,            setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,            setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,        setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,        togglefloating, {0} },
	{ MODKEY,                       XK_0,            view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,            tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,        focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,       focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,         {.i = +1 } },
  { MODKEY,                       XK_minus,        setgaps,        {.i = -1 } },
  { MODKEY,                       XK_equal,        setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,        setgaps,        {.i =  0 } },
	TAGKEYS(                        XK_1,                            0)
	TAGKEYS(                        XK_2,                            1)
	TAGKEYS(                        XK_3,                            2)
	TAGKEYS(                        XK_4,                            3)
	TAGKEYS(                        XK_5,                            4)
  /*
	TAGKEYS(                        XK_6,                            5)
	TAGKEYS(                        XK_7,                            6)
	TAGKEYS(                        XK_8,                            7)
	TAGKEYS(                        XK_9,                            8)
  */
	{ MODKEY|ShiftMask,             XK_q,            quit,           {0} },
  { MODKEY|ShiftMask,             XK_r,            quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

