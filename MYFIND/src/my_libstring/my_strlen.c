#include "../include/my_libstring.h"

size_t mymy_strlen(const char *var)
{
  size_t q = 0;
  for (; var[q] != '\0'; q++)
    continue;
  return q;
}
