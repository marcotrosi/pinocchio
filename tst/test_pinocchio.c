#include "equal.h"
#include "pinocchio.h"
#include "test_pinocchio.h"

// test_cindex <<<
void test_cindex(char *s, char c, signed long long int n, size_t start, size_t must, char *file, size_t line)
{
   /* size_t just = int_cindex(s,c,n,start); */
   size_t just = cindex(s,c,n,start);
   if(isEqualUInt(just, must))
   {
      PASSED;
   }
   else
   {
      FAILED;
      fprintf(stderr, "\tmust: %zu\n", must);
      fprintf(stderr, "\tjust: %zu\n", just);
   }
} // >>>

// test_ccount <<<
void test_ccount(char *s, char c, size_t start, size_t end, size_t must, char *file, size_t line)
{
   /* size_t just = int_ccount(s,c,start,end); */
   size_t just = ccount(s,c,start,end);
   if(isEqualUInt(just, must))
   {
      PASSED;
   }
   else
   {
      FAILED;
      fprintf(stderr, "\tmust: %zu\n", must);
      fprintf(stderr, "\tjust: %zu\n", just);
   }
} // >>>

// test_creplace <<<
void test_creplace(char *s, char c, char r, size_t n, size_t start, size_t end, size_t must, char *file, size_t line)
{
   /* size_t just = int_creplace(s,c,r,n,start,end); */
   size_t just = creplace(s,c,r,n,start,end);
   if(isEqualUInt(just, must))
   {
      PASSED;
   }
   else
   {
      FAILED;
      fprintf(stderr, "\tmust: %zu\n", must);
      fprintf(stderr, "\tjust: %zu\n", just);
   }
} // >>>
