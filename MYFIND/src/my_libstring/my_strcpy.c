#include "../include/my_libstring.h"

char *my_strcpy(const char *str, size_t n)
{
  char *res = malloc(n * sizeof (char));
  size_t t = 0;
  for (; str[t] != '\0'; t++)
    res[t] = str[t];
  res[t] = '\0';
  return res;
}
