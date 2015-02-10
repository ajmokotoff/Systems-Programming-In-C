#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char mya1[MAX_CHARS + 1];
  char a2[] = "Hello"; // Character array--unsized but initialized
  char mya2[] = "Hello";
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char mya3[MAX_CHARS + 1];
  char* p1 = "Hello"; // Pointer to constant string
  char* myp1 = "Hello";
  char* p2;           // Will be a pointer to dynamically-allocated string
  char* myp2;
  int copy_limit;     // Maximum characters to copy.
  int mycopy_limit;
  char origin[40];
  char target[12];
  char myorigin[40];
  char mytarget[12];
  const char* target2 = "Testing my strndup function";
  const char* mytarget2 = "Testing my strndup function";
  size_t size = 17;


  strcpy(a3, "Hello, also"); // Initialize underfilled character array
  mystrcpy(mya3, "Hello, also");

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Original functions: \n");
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);
  printf("New Functions: \n");
  printf("Pointers: mya1 = %p, mya2 = %p, mya3 = %p\n",mya1,mya2,mya3);
  printf("          myp1 = %p myp2 = %p\n",myp1,myp2);

  strcpy(a1, "Hi"); // Initialize character array
  mystrcpy(mya1,"Hi");

  printf("Original functions: \n");
  printf("Contents of a1 = %s\n", a1);
  printf("Contents of a2 = %s\n", a2);
  printf("Contents of a3 = %s\n", a3);

  printf("New Functions: \n");
  printf("Contents of mya1 = %s\n",mya1);
  printf("Contents of mya2 = %s\n",mya2);
  printf("Contents of mya3 = %s\n",mya3);

  // Concatenate two character arrays, then print.
  printf("Original Concatenate: \n");
  strcat(a1, a2);
  printf("After concatenating, contents of a1 = %s\n", a1);

  printf("New Concatenate: \n");
  mystrcat(mya1,mya2);
  printf("After concatenating, contents of mya1 = %s\n",mya1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("Original Concatenate: \n");
  printf("After concatenating, contents of a1 = %s\n", a1);

  mycopy_limit = MAX_CHARS - mystrlen(mya1); // How much space is left?
  if (mycopy_limit > 0) mystrncat(mya1, mya3, mycopy_limit);
  printf("New Concatenate: \n");
  printf("After concatenating, contents of mya1 = %s\n", mya1);

  // Duplicate a string, using my function, then print
  printf("Original duplicate function: \n");
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = strdup(a2);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);

  printf("New Duplicate function: \n");
  printf("Before mydup, pointer mya2 = %p, contents = %s\n", mya2, mya2);
  myp2 = mystrdup(mya2);
  printf("After dup, pointer myp2 = %p, contents = %s\n", myp2, myp2);



  //strdup()
  printf("\nStrdup() testing...\n\n");
  printf("Original Strdup()\n");
  char *strp1 = "Andrew";
  char *strp2;
  strp2=strdup(strp1);
  printf("Duplicated String is: %s\n",strp2);

  printf("New Strdup()\n");
  char *mystrp1 = "Andrew";
  char *mystrp2;
  mystrp2=mystrdup(mystrp1);
  printf("Duplicated String is: %s\n",mystrp2);

  //strlen()
  printf("\nStrlen() testing...\n\n");
  printf("Original Strlen()\n");
  char string4[20];
  char string5[20];
  strcpy(string4,"Hello");
  strcpy(string5,"gooooooodbye");
  printf("Length of string4: %d\n",strlen(string4));
  printf("Length of string5: %d\n",strlen(string5));

  printf("New Strlen()\n");
  char mystring4[20];
  char mystring5[20];
  strcpy(mystring4,"Hello");
  strcpy(mystring5,"gooooooodbye");
  printf("Length of mystring4: %d\n",mystrlen(mystring4));
  printf("Length of mystring5: %d\n",mystrlen(mystring5));

  //strcpy()
  printf("\nStrcpy() testing...\n\n");
  printf("Original Strcpy()\n");
  char input_str2[20];
  char *output_str2;
  strcpy(input_str2,"Hello");
  printf("input_str2: %s\n",input_str2);
  output_str2 = strcpy(input_str2,"World");
  printf("input_str2: %s\n",input_str2);
  printf("output_str2: %s\n",output_str2);

  printf("New Strcpy()\n");
  char myinput_str2[20];
  char *myoutput_str2;
  mystrcpy(myinput_str2,"Hello");
  printf("myinput_str2: %s\n",myinput_str2);
  myoutput_str2 = mystrcpy(myinput_str2,"World");
  printf("myinput_str2: %s\n",myinput_str2);
  printf("myoutput_str2: %s\n",myoutput_str2);



  //strcat()
  printf("\nStrcat() testing...\n\n");
  printf("Original Strncat()\n");
  char s1[20];
  char s2[20];
  strcpy(s1,"Hello");
  strcpy(s2,"goodbye");
  printf("Returned String: %s\n",strcat(s1,s2));
  printf("Concatenated String: %s\n",s1);

  printf("New Strcat()\n");
  char mys1[20];
  char mys2[20];
  mystrcpy(mys1,"Hello");
  mystrcpy(mys2,"goodbye");
  printf("Returned String: %s\n",mystrcat(mys1,mys2));
  printf("Concatenated String: %s\n",mys1);


  //strncat()
  printf("\nStrncat() testing...\n\n");
  printf("Original Strncat()\n");
  char string1[20];
  char string2[20];
  strcpy(string1,"Hello");
  strcpy(string2,"Hellooo");
  printf("Returned String: %s\n",strncat(string1,string2,4));

  printf("\nNew Strncat()\n");
  char mystring1[20];
  char mystring2[20];
  mystrcpy(mystring1,"Hello");
  mystrcpy(mystring2,"Hellooo");
  printf("Returned String: %s\n",mystrncat(mystring1,mystring2,4));

  printf("\nOriginal Strncat()\n");
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("Original Concatenate: \n");
  printf("After concatenating, contents of a1 = %s\n", a1);

  printf("\nNew Strncat()\n");
  mycopy_limit = MAX_CHARS - mystrlen(mya1); // How much space is left?
  if (mycopy_limit > 0) mystrncat(mya1, mya3, mycopy_limit);
  printf("New Concatenate: \n");
  printf("After concatenating, contents of mya1 = %s\n", mya1);


  //strncpy()
  printf("\nStrncpy() testing...\n\n");
  printf("Original Strncpy()\n");
  char input_str[20];
  char *output_str;
  strncpy(input_str, "Hello",20);
  printf("input_str: %s\n", input_str);
  memset(input_str,'\0',sizeof(input_str));
  strncpy(input_str,"Hello",2);
  printf("input_str: %s\n",input_str);
  memset(input_str,'\0',sizeof(input_str));
  output_str=strncpy(input_str,"World",3);
  printf("input_str: %s\n",input_str);
  printf("output_str: %s\n",output_str);

  printf("\nNew Strncpy()\n");
  char myinput_str[20];
  char *myoutput_str;
  mystrncpy(myinput_str, "Hello",20);
  printf("myinput_str: %s\n", myinput_str);
  memset(myinput_str,'\0',sizeof(myinput_str));
  mystrncpy(myinput_str,"Hello",2);
  printf("myinput_str: %s\n",myinput_str);
  memset(myinput_str,'\0',sizeof(myinput_str));
  myoutput_str=mystrncpy(myinput_str,"World",3);
  printf("myinput_str: %s\n",myinput_str);
  printf("myoutput_str: %s\n",myoutput_str);



  //strndup() test
  printf("\nStrndup() testing...\n\n");
  printf("Original strndup()\n");
  char* ret;
  ret = strndup(target2,size);
  printf("Duplicated String Contents: %s\n",ret);
  ret=strndup("short",17);
  printf("Duplicated String Contents: %s\n",ret);
  ret=strndup("test",0);
  printf("Duplicated String Contents: %s\n",ret);
  ret=strndup("more testing",30);
  printf("Duplicated String Contents: %s\n",ret);
  ret=strndup("short",1);
  printf("Duplicated String Contents: %s\n",ret);

  char* ret2;
  printf("\nNew strndup()\n");
  ret2 = mystrndup(mytarget2,size);
  printf("Duplicated String Contents: %s\n",ret2);
  ret2=mystrndup("short",17);
  printf("Duplicated String Contents: %s\n",ret2);
  ret2=mystrndup("test",0);
  printf("Duplicated String Contents: %s\n",ret2);
  ret2=mystrndup("more testing",30);
  printf("Duplicated String Contents: %s\n",ret2);
  ret2=mystrndup("short",1);
  printf("Duplicated String Contents: %s\n",ret2);


  return 0;
}
