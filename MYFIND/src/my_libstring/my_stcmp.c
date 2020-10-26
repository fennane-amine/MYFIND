#include "../include/my_libstring.h"

int mymy_strcmp(const char *str1, const char *str2)
{
  size_t c = 0;
  for (; str1[c] != '\0' && str2[c] != '\0'; c++)
    if (str1[c] != str2[c])
      return 1;
  if (str1[c] == str2[c])
    return 0;
  return 1;
}
