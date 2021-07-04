#include "equal.h"
#include "pinocchio.h"
#include "test_pinocchio.h"

void test_cindex(char *s, char c, signed long long int n, size_t start, size_t must, char *file, size_t line)
{
   /* size_t just = int_cindex(s,c,n,start); */
   size_t just = cindex(s,c,n,start);
   if(isEqualSInt(just, must))
   {
      PASSED;
   }
   else
   {
      FAILED;
      fprintf(stderr, "\tmust: %zu\n", must);
      fprintf(stderr, "\tjust: %zu\n", just);
   }
}

