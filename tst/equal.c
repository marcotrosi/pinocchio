#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "equal.h"


bool int_isEqualSInt(signed long long int a, signed long long int b)
{
   return (a==b);
}

bool int_isEqualUInt(unsigned long long int a, unsigned long long int b)
{
   return (a==b);
}

bool isEqualStr(char *a, char *b)
{
   if(a == b)
   {
      return true;
   }

   if(!strcmp(a, b))
   {
      return true;
   }
   return false;
}

bool int_isEqualFloat(long double a, long double b, long double e)
{
   if (ABS(a-b) < e)
   {
   		return true;
   }	
   return false;
}

