//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Mem:", "free -h | awk '/^lol/ { print $3\" / \"$2\"  \" }' | sed s/i//g",	30,		0},
	{"", "date.sh",					900,		0},
  {"", "batt.sh",         120,    0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " r ";
static unsigned int delimLen = 10;
