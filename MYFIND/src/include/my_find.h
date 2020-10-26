#ifndef MYFIND_H
# define MYFIND_H
# include "my_tree.h"

enum FLAG {
  FLAG_D,
  FLAG_H,
  FLAG_L,
  FLAG_P,
  FLAG_ERROR
};
int mymyFind(char *path, const char *file, enum FLAG flag, struct tree *expr);
#endif /* !MYFIND_H */
