#ifndef TREE_H
# define TREE_H
# include <stdlib.h>
# include "my_find.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

enum EXPR
{
  NAME,
  TYPE,
  OR,
  AND,
  PRINT,
  EXEC,
  EXEC_DIR,
  PO,
  PC,
  NOT,
  NONE,
  ERROR
};
enum TYPE
{
  B,
  C,
  D,
  L,
  F,
  P,
  S,
  ERROR_TYPE
};
struct expr
{
  enum EXPR expr;
  enum TYPE type;
  char **arg;
  char *func;
};
struct tree
{
  struct tree *left;
  struct tree *right;
  struct expr *data;
};
struct tree *make_tree(char **argv, int argc, int *i);
void show_tree(char *path, const char *file, struct tree *expr,
    struct stat *buf);
void delete_tree(struct tree *tree);
#endif /* !LIBSTRING_H */
