/**
 *  _____   _____ 
 * |  _  | |  ___|  DMENU Config (Pixelfiles)
 * | |_| | | |__    Author: StarryMohannad :DD
 * |  ___| |  __|   
 * | |     | |      GitLab: https://gitlab.com/starrymohannad/Pixelfiles
 * |_|     |_|      GitHub: https://github.com/starrymohannad/Pixelfiles
 *
**/

// FiraCode Font
static const char *fonts[] = {
	"FiraCode Nerd Font:size=10"
};

// Catppuccin Colorscheme
static const char *colors[SchemeLast][2] = {
	               /* fg         bg      */
	[SchemeNorm] = { "#cad3f5", "#24273a" },
	[SchemeSel]  = { "#cad3f5", "#5b6078" },
	[SchemeOut]  = { "#000000", "#00ffff" },
};

static int topbar                  = 1;    // Dmenu Appear from the top
static const char *prompt          = NULL; // Default Prompt
static unsigned int lines          = 53;   // Deafult Number of Lines
static const char worddelimiters[] = " ";  // Characters not considered part of a word while deleting words

