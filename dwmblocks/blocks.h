static const Block blocks[] = {
  /* Icon */ /* Command */                  /* Update Interval */ /* Update Signal */
  { "  ",   "/home/stf/.local/bin/memo.sh",	  5,                    0 },
  { "  ",   "/home/stf/.local/bin/date.sh",    900,                  0 },
  { "󰅒  ",   "/home/stf/.local/bin/hour.sh",    60,                   0 },
  { "󱐋 ",    "/home/stf/.local/bin/batt.sh",    120,                  0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 10;
