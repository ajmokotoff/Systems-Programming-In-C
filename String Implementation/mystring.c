/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// stdlib.h is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src or null if no memory is available
*/

char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** more efficent function to find the length of a string
 *@param ptr: pointer to the beginning of a string
 *@return length: length of the string
 */

int mystrlen(const char *ptr) {
  const char *begin;
  begin = ptr;
  while(*ptr != '\0'){
    ++ptr;
  }
  return ptr-begin;
}

/** Given two pointers to blocks of allocated memory, the function will copy strings and assign them to those blocks of memory.
 * @param target: Location of memory where the origin will be copied to
 * @param origin: String to be copied
 * @return char: The new copied string
 */

char *mystrcpy(char *target, const char *origin) {
  char* copy = target;
  while(*target++ = *origin++);

  return copy;
}

/** Appends a version of the string pointed to by origin to the end of the string pointed to by target.
 * @param target: Pointer to a string that will be modified, origin will be copied here.
 * @param origin: Pointer to a string that will be copied to the end of target.
 * @return char: The concatenated string
 */

char *mystrcat(char *target, const char *origin) {
  mystrcpy(target + mystrlen(target), origin);
  return target;
}

/** Concatenates or appends the first num characters from origin to target.
 * @param target: Pointer to a string that will be modified, origin will be copied here.
 * @param origin: Pointer to a string that will be copied to the end of target. The first (num) characters will be copied over.
 * @param num:  Number of characters in origin to be copied over to the end of target.
 * @return final: The new concatenated string
 */

char *mystrncat(char *target, const char *origin, int num) {
  char *final = target;
  while(*target) {
    target++;
  }
  while(num--) {
    if(!(*target++ = *origin++)) {
      return final;
    }
  }
  *target = 0;
  return final;
}

/** Copies the first num characters from the string pointed to by origin, to the string pointed to by target.
 * @param target: Pointer to the character array to copy to.
 * @param origin: Pointer of the character array to copy from.
 * @param num:  Maximum number of characters to copy.
 * @return char: The new String with the characters copied to it.
 */

char *mystrncpy(char *target, const char *origin, int num) {
  char *final = target;
  do{
    if(!num--) {
      return final;
    }
  } while(*target++=*origin++);
    while(num--){
      *target++=0;
      return final;
    }
}

/** Duplicates the first num characters of the string that origin points to.
 * @param origin: Points to a string which will be copied from.
 * @param num: Maximum number of characters to be duplicated
 * @return char: The new String with the characters copied to it.
 */

char *mystrndup(const char *origin, size_t num) {
  char *target;
  size_t length = mystrlen(origin);
  if(num<length) {
    length=num;
  }
  target=malloc(length + 1);
  *target='\0';
  return memcpy(target,origin,length);
}
