#include "equal.h"
#include "pinocchio.h"
#include "test_pinocchio.h"

void test_cindex(char *s, char c, signed long long int n, size_t start, signed long long int must, char *file, size_t line)
{
   signed long long int just = cindex(s,c,n,start);
   if(isEqualSInt(just, must))
   {
      PASSED;
   }
   else
   {
      FAILED;
      fprintf(stderr, "\tmust: %lld\n", must);
      fprintf(stderr, "\tjust: %lld\n", just);
   }
}

