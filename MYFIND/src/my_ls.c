#define _DEFAULT_SOURCE
#define _POSIX_C_SOURCE = 200112L

#include "./include/my_find.h"
#include "./include/my_tree.h"
#include "./include/my_libstring.h"

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

static
int myFind_r(char *way, enum FLAG flag, struct tree *svp)
{
  DIR* dir = NULL;
  struct dirent* file_read = NULL;
  dir = opendir(way);
  if (!dir)
  {
    fprintf(stderr, "myfind: cannot do ‘%s’: Permission denied\n", way);
    return 0;
  }
  int iss = 1;
  while ((file_read = readdir(dir)) != NULL)
  {
    if (mymy_strcmp(file_read->d_name, ".") != 0
        && mymy_strcmp(file_read->d_name, "..") !=0)
      iss &= mymyFind(way, file_read->d_name, flag, svp);
  }
  closedir(dir);
  return iss;
}

static
struct stat *verify_lstat(const char *way)
{
  struct stat *out = malloc(sizeof (struct stat));
  if (lstat(way, out) != 0)
  {
    fprintf(stderr, "myfind: cannot do '%s': No such file or directory\n"
        , way);
    free(out);
    return NULL;
  }
  return out;
}

static
int check_FLAG_L_H(enum FLAG flag, struct stat *out, char *ccp)
{
  if ((flag == FLAG_L || flag == FLAG_H) && S_ISLNK(out->st_mode))
  {
    free(out);
    ccp = mymy_strcat(ccp, "/");
    if (!(out = verify_lstat(ccp)))
      return 1;
  }
  return 0;
}

int mymyFind(char *way, const char *file, enum FLAG flag, struct tree *svp)
{
  int iss = 0;
  struct stat *out;
  char *ccp = my_strcpy(way, 512);
  mymy_strcat(ccp, file);
  if (!(out = verify_lstat(ccp)))
    return 1;
  if (flag != FLAG_D)
    show_tree(ccp, file, svp, out);
  if (check_FLAG_L_H(flag, out, ccp) == 1)
    return 1;
  if (flag == FLAG_H)
    flag = FLAG_P;
  size_t len = mymy_strlen(ccp) - 1;
  ccp[len] = ccp[len] == '/' ? '\0' : ccp[len];
  if (!S_ISDIR(out->st_mode))
    iss = 0;
  else if (!S_ISLNK(out->st_mode) || (flag == FLAG_L && S_ISLNK(out->st_mode)))
    iss = myFind_r(mymy_strcat(ccp,"/"), flag, svp);
  if (flag == FLAG_D)
    show_tree(ccp, file, svp, out);
  free(out);
  free(ccp);
  return iss;
}
