/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#ifndef MYSTRING_H
#define MYSTRING_H

char* mystrdup(const char* src);
int mystrlen(const char* ptr);
char *mystrcpy(char *target, const char *origin);
char *mystrcat(char *target, const char *origin);
char *mystrncat(char *target, const char *origin, int num);
char *mystrncpy(char *target, const char *origin, int num);
char *mystrndup(const char *origin, size_t num);

#endif
