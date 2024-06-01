#include "../theme.c"

static int topbar                = 1;    /* -b  option; if 0, dmenu appears at bottom */
static int centered              = 1;    /* -c option; centers dmenu on screen */
static int min_width             = 400;  /* minimum width when centered */
static const int user_bt         = 19;   /* add an defined amount of pixels to the bar height */
static unsigned int lines        = 4;    /* -l option; vertical list with given number of lines */
static unsigned int border_width = 2;    /* size of the window border */
static const unsigned int alpha  = 0xb9; /* alpha transparency; 0xff is OPAQUE */

static const Theme theme = th_pink_lain;
static const char *prompt = " "; /* -p option; prompt to the left of input field */
static const char *fonts[] = {
	"SpaceMono Nerd Font:size=11:style=Regular"
};
static const char *colors[SchemeLast][2] = {
	/*               fg           bg       */
	[SchemeNorm] = { theme.white, theme.black },
	[SchemeSel]  = { theme.black, theme.red },
	[SchemeOut]  = { "#000000",   "#00ffff" },
	[SchemeHp]   = { "#ffffff",   theme.black }
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
