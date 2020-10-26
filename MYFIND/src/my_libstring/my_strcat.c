#include "../include/my_libstring.h"

char *mymy_strcat(char *dest, const char *src)
{
  size_t size_src = mymy_strlen(src);
  size_t size_dest = mymy_strlen(dest);
  for (size_t f = 0; f < size_src; f++)
    dest[size_dest + f] = src[f];
  dest[size_src + size_dest] = '\0';
  return dest;
}
