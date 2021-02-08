#ifndef EQUAL_H
#define EQUAL_H

#include <stdbool.h>

#if NOCOLOR == false
#define CLRRED  "\e[91m"
#define CLRGRN  "\e[92m"
#define CLROFF  "\e[0m"
#else
#define CLRRED  ""
#define CLRGRN  ""
#define CLROFF  ""
#endif
#define ABS(x) (((x) > 0) ? (x) : -(x))
#define PASSED printf("%s:%zu: %spassed%s\n", file, line, CLRGRN, CLROFF)
#define FAILED fprintf(stderr,"%s:%zu: %sfailed%s\n", file, line, CLRRED, CLROFF)

#define isEqualSInt(a,b)  int_isEqualSInt((signed long long int)(a), (signed long long int)(b))
#define isEqualUInt(a,b)  int_isEqualUInt((unsigned long long int)(a), (unsigned long long int)(b))
#define isEqualFloat(a,b) int_isEqualFloat((long double)(a), (long double)(b))

bool isEqualStr(char *a, char *b);

bool int_isEqualSInt(signed long long int a, signed long long int b);
bool int_isEqualUInt(unsigned long long int a, unsigned long long int b);

#endif // EQUAL_H
