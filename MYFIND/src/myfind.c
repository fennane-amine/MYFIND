#include "./include/my_find.h"
#include "./include/my_tree.h"
#include "./include/my_libstring.h"

#include <stdio.h>
#include <stdlib.h>

static
enum FLAG verify_flag(char **flag, int *j, int argc)
{
  enum FLAG res = FLAG_P;
  for (; *j < argc; (*j)++)
  {
    if (flag[*j][0] == '-')
      switch (flag[*j][1])
      {
      case 'd':
        res = FLAG_D;
        break;
      case 'H':
        res = FLAG_H;
        break;
      case 'L':
        res = FLAG_L;
        break;
      case 'P':
        res = FLAG_P;
        break;
      default:
        return FLAG_ERROR;
        break;
      }
    else
      break;
  }
    return res;
}

static
char **verify_files(char *path, char **flag, int *j, int argc, size_t *mes)
{
  *mes = 0;
  char **files = malloc((argc - *j) * sizeof (char *));
  for (; *j < argc; (*j)++, (*mes)++)
  {
    if (flag[*j][0] != '-' && flag[*j][0] != '!' && flag[*j][0] != '(')
      files[*mes] = flag[*j];
    else
      break;
  }
  if (*mes != 0)
    return files;
  files[(*mes)++] = path;
  return files;
}
