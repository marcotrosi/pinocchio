#include "pinocchio.h"

int main(void)
{
   string A = str("foo");
   string B = strfmt("bar %d", 3);
   string C = strfmt("knockknock");

   print(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(); // print empty line
   string D = join(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(D);
   string E = glue("|", A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(E);

   free(A);
   free(B);
   free(C);
   free(D);
   free(E);

   return 0;
}

// vim: fmr=<<<,>>> fdm=marker
