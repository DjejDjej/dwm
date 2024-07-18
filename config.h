/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char *barlayout        = "tn|s	";
static const char dmenufont[]       = "monospace:size=13";
static const char col_black[]       = "#000000";
static const char col_white[]       = "#ffffff";
static const char col_grey[]       = "#606060";
static const char normfgcolor[]     = "#0dcdcd";  // Normal foreground color
static const char col_term[]     = "#1a1d23";  // Normal foreground color

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_term, col_term },
	[SchemeSel]  = { col_white, col_term,  col_term  },
};




/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {

	/* class      		instance    title       tags mask     isfloating   monitor */
	{ "firefox",        NULL,       NULL,         1,       		0,           -1 },
	{ "Alacritty",	    NULL,       NULL,         2,       		0,           -1 },
	{ "discord", 		NULL,       NULL,         8,      		0,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */


/* key definitions */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	

};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }



/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] =    {"dmenu_ruddn", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_white, "-sb", col_black, "-sf", col_white, NULL };

static const char *rofi[] =    {"rofi", "-show","drun"};
static const char *termcmd[]  =    {"alacritty", NULL };
static const char *browser[]  =    {"firefox", NULL };
static const char *discord[]  =    {"discord",NULL};
static const char *screenshotcmd[] = { "flameshot", "gui", NULL };
static const char *togglelayoutcmd[] = { "changeLayout", NULL };
static const char *shutdown[] = { "shutdown", "now", NULL };
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                      	XK_r,	   spawn,            {.v = browser } },
	{0 ,                       			XK_Super_L,      spawn,          {.v = rofi } },
	{ MODKEY,          							XK_t, 	   spawn,          {.v = termcmd } },
	{ MODKEY,             					XK_y,      spawn,          {.v = togglelayoutcmd} },
  { MODKEY,												XK_q,      killclient,     {0} },
	{ MODKEY,             					XK_End,    quit,           {0} },
  { 0,     	               				XK_Print,   spawn,            {.v = screenshotcmd } },
	{ MODKEY|ShiftMask,            	XK_End,    spawn, { .v = shutdown} },
	{ MODKEY,                      	XK_d,	   spawn,            {.v = discord } },
	///
	{ MODKEY,                       XK_Up,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Down,    focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,      {.i = +1 } },
	{ MODKEY,                       XK_u,      deccnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_j,      setmfact,        {.f = -0.05} },
	{ MODKEY,                       XK_k,      setmfact,        {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,            {0} },
	{ MODKEY,        	    					XK_Tab,    shiftviewclients, { .i = +1 } },
	{ MODKEY|ShiftMask,            	XK_Tab,    shiftviewclients, { .i = +-1 } },

    TAGKEYS(                        XK_1,                           0)
    TAGKEYS(                        XK_2,                           1)
    TAGKEYS(                        XK_3,                           2)
    TAGKEYS(                        XK_4,                           3)
    TAGKEYS(                        XK_5,                           4)
    TAGKEYS(                        XK_6,                           5)
    TAGKEYS(                        XK_7,                           6)
    TAGKEYS(                        XK_8,                           7)
    TAGKEYS(                        XK_9,                           8)	
    TAGKEYS(                        XK_plus,                        0)
    TAGKEYS(                        XK_ecaron,                      1)  // ě
    TAGKEYS(                        XK_scaron,                      2)  // š
    TAGKEYS(                        XK_ccaron,                      3)  // č
    TAGKEYS(                        XK_rcaron,                      4)  // ř
    TAGKEYS(                        XK_zcaron,                      5)  // ž
    TAGKEYS(                        XK_yacute,                      6)  // ý
    TAGKEYS(                        XK_aacute,                      7)  // á
    TAGKEYS(                        XK_iacute,                      8)  // í

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

