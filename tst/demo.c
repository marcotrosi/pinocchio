#include "pinocchio.h"

int main(void)
{
   string A = str("foo");
   string B = strfmt("bar %d", 3);
   string C = strfmt("knockknock");
   string F = rep("foo", 4, "_");
   string G = str("abcde");
   string H = str("abcdefgh");
   string I = center("center", 20);
   string J = center("center", 8, '_');
   string K = left("left", 6, '_');
   string L = right("right", 8, '_');

   print(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(); // print empty line
   string D = join(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(D);
   string E = glue("|", A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc");
   print(E);
   print(upper(E));
   print(F);
   print(rev(G));
   print(sub(H,2,5));
   print(sub(H,2,-1));
   print(sub(H,2));
   print(sub(H,-2));
   print(sub(H,-2,-4));
   print(sub(NULL,3,5));
   print(sub(H,2,2));
   printf("%zu\n", len("pinocchio"));
   printf("%zu\n", len(NULL));
   print(append(C,", who is", " ", "there?"));
   print(prepend(C,"Hey, ", "listen!", "   "));
   print(I);
   print(J);
   print(K);
   print(L);
   iprint(5,0,-2,1323,282474);
   string M = i2s(-456747844848);
   print(M);
   string N = u2s(94567478448480);
   print(N);
   string O = f2s(9456747.8448480);
   print(O);
   string P = c2s('x');
   print(P);
   string Q = b2s(false);
   print(Q);
   string R = p2s(A);
   print(R);
   string S = a2s(A);
   print(S);
   string T = x2s(-1);
   print(T);

   printf("%lli\n", s2lli(M));
   printf("%llu\n", s2llu(N));
   printf("%LF\n" , s2ld(O) );
   printf("%c\n"  , P[0]    );

   free(A);
   free(B);
   free(C);
   free(D);
   free(E);
   free(F);
   free(G);
   free(H);
   free(I);
   free(J);
   free(K);
   free(L);
   free(M);
   free(N);
   free(O);
   free(P);
   free(Q);
   free(R);
   free(S);
   free(T);

   return 0;
}

// vim: fmr=<<<,>>> fdm=marker
