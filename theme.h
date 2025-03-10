#ifndef THEME_H
#define THEME_H

#include "bar_theme.h"

typedef struct {
  const char* white;
  const char* black;
  const char* grey;
  const char* red;
  const char* green;
  const char* blue;
  const BarTheme bar;
} Theme;

#endif /* THEME_H */
