static int topbar                = 1;    /* -b  option; if 0, dmenu appears at bottom */
static int centered              = 1;    /* -c option; centers dmenu on screen */
static int min_width             = 400;  /* minimum width when centered */
static const int user_bt         = 9;    /* add an defined amount of pixels to the bar height */
static unsigned int lines        = 6;    /* -l option; vertical list with given number of lines */
static unsigned int border_width = 2;    /* size of the window border */
static const unsigned int alpha  = 0xb9; /* alpha transparency; 0xff is OPAQUE */

static const char *prompt = NULL; /* -p option; prompt to the left of input field */
static const char *fonts[] = {
	"SpaceMono Nerd Font:size=11:style=Regular"
};
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel]  = { "#eeeeee", "#005577" },
	[SchemeOut]  = { "#000000", "#00ffff" },
	[SchemeHp]   = { "#bbbbbb", "#333333" }
};
static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel]  = { OPAQUE, alpha },
	[SchemeOut]  = { OPAQUE, alpha },
};

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
