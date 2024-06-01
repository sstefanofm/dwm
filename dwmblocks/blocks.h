static const Block blocks[] = {
  /* Icon */ /* Command */ /* Update Interval */ /* Update Signal */
  { "  ",   "memo.sh",	   5,                    0 },
  { "  ",   "date.sh",    900,                  0 },
  { "󰅒  ",   "hour.sh",    60,                   0 },
  { "󱐋 ",    "batt.sh",    120,                  0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 10;
