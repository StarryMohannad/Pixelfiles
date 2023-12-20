static const char *fonts[] = { "FiraCode Nerd Font:size=10" };

static const char *colors[SchemeLast][2] = {
[SchemeNorm] = { "#cad3f5", "#24273a" },
[SchemeSel] = { "#cad3f5", "#5b6078" },
[SchemeOut] = { "#000000", "#00ffff" }, };

static int topbar = 1;
static const char *prompt = NULL;
static unsigned int lines = 53;
static const char worddelimiters[] = " ";
