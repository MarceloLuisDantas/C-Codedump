#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>

void trim(char **s);
void removeExtraSpaces(char **s);
char **split(const char *s, const char splitter);
void reallocAndCopy(char **dest, char *src);
char *arrayToString(char **array);
char *getSlice(const char *s, size_t from, size_t to);
char *concat(char *str1, char *str2);
void *intToStr(char **s, int num);
int isEmptyStr(char *s);

#endif
