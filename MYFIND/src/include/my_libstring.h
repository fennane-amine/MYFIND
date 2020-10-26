#ifndef LIBSTRING_H
# define LIBSTRING_H
# include <stdlib.h>

size_t mymy_strlen(const char *string);
char *mymy_strcat(char *dest, const char *src);
int mymy_strcmp(const char *str1, const char *str2);
char *my_strcpy(const char *str, size_t n);
#endif /* !LIBSTRING_H */
