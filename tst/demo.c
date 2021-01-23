#include "pinocchio.h"

int main(void)
{
   string A = str("foo");
   string B = strfmt("bar %d", 3);
   string C = strfmt("knockknock");
   string F = rep("foo", 4, "_");
   string G = str("abcde");
   /* string H = str("abcde"); */

   print(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(); // print empty line
   string D = join(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(D);
   string E = glue("|", A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(E);
   print(upper(E));
   print(F);
   print(rev(G));
   /* print(rev(H)); */
   printf("%zu\n", len("pinocchio"));
   printf("%zu\n", len(NULL));
   print(append(C,", who is", " ", "there?"));
   print(prepend(C,"Hey, ", "listen!", "   "));

   free(A);
   free(B);
   free(C);
   free(D);
   free(E);
   free(F);
   free(G);
   /* free(H); */

   return 0;
}

// vim: fmr=<<<,>>> fdm=marker
