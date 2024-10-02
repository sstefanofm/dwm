static const Block blocks[] = {
  /* Icon */ /* Command */ /* Update Interval */ /* Update Signal */
  { "  ",   "memo.sh",	   5,                    0 },
  { "  ",   "date.sh",    900,                  0 },
  { "󰅒  ",   "hour.sh",    60,                   0 },
  { "",      "vol.sh",     240,                  2 },
  { "",      "batt.sh",    120,                  1 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 10;
