#include "pinocchio.h"

int main(void)
{
   /* string A = str("foo"); */
   /* string B = strfmt("bar %d", 3); */
   string C = strfmt("knockknock");
   /* string F = rep("foo", 4, "_"); */
   /* string G = str("abcde"); */
   /* string H = str("abcdefgh"); */
   /* string I = center("center", 20); */
   /* string J = center("center", 8, '_'); */
   /* string K = left("left", 6, '_'); */
   /* string L = right("right", 8, '_'); */
   /* string U = str("   foo bar   "); */

   /* print(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc"); */
   /* print(); // print empty line */
   /* string D = join(A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc"); */
   /* print(D); */
   /* string E = glue("|", A, B, "super", NULL, C, "aaaa", "bbbbb", "ccccc"); */
   /* print(E); */
   /* print(upper(E)); */
   /* print(F); */
   /* print(rev(G)); */
   /* print(sub(H,2,5)); */
   /* print(sub(H,2,-1)); */
   /* print(sub(H,2)); */
   /* print(sub(H,-2)); */
   /* print(sub(H,-2,-4)); */
   /* print(sub(NULL,3,5)); */
   /* print(sub(H,2,2)); */
   /* printf("%zu\n", len("pinocchio")); */
   /* printf("%zu\n", len(NULL)); */
   /* printf("%s has k at index %zu\n", C, cindex(C, 'k')); */
   /* printf("%s has fourth k at index %zu\n", C, cindex(C, 'k', 4)); */
   /* printf("%s has second o at index %zu\n", C, cindex(C, 'o', 1, 4)); */
   printf("%s has %zu k's\n", C, ccount(C, 'k'));
   printf("%s has %zu k's\n", C, ccount(C, 'k', 2));
   printf("%s has %zu k's\n", C, ccount(C, 'k', 2, 7));
   /* print(append(C,", who is", " ", "there?")); */
   /* print(prepend(C,"Hey, ", "listen!", "   ")); */
   /* print(I); */
   /* print(J); */
   /* print(K); */
   /* print(L); */
   /* iprint(5,0,-2,1323,282474); */
   /* string M = i2s(-456747844848); */
   /* print(M); */
   /* string N = u2s(94567478448480); */
   /* print(N); */
   /* string O = f2s(9456747.8448480); */
   /* print(O); */
   /* string P = c2s('x'); */
   /* print(P); */
   /* string Q = b2s(false); */
   /* print(Q); */
   /* string R = p2s(A); */
   /* print(R); */
   /* string S = a2s(A); */
   /* print(S); */
   /* string T = x2s(-1); */
   /* print(T); */
   /* print(strip(U)); */
   /*  */
   /* printf("%lli\n", s2lli(M)); */
   /* printf("%llu\n", s2llu(N)); */
   /* printf("%LF\n" , s2ld(O) ); */
   /* printf("%c\n"  , P[0]    ); */
   /*  */
   /* if(hasString(C, "kk")) */
   /* { */
   /*    printf("yes\n"); */
   /* } */
   /* else */
   /* { */
   /*    printf("no\n"); */
   /* } */
   /*  */
   /* printf(BOLD"Foo"NOBOLD"Bar"OFF"\n"); */
   /* printf(DIM"Foo"NODIM"Bar"OFF"\n"); */
   /* printf(ITALIC"Foo"NOITALIC"Bar"OFF"\n"); */
   /* printf(UNDERLINE"Foo"NOUNDERLINE"Bar"OFF"\n"); */
   /* printf(BLINK"Foo"NOBLINK"Bar"OFF"\n"); */
   /* printf(REVERSE"Foo"NOREVERSE"Bar"OFF"\n"); */
   /* printf(INVISIBLE"Foo"NOINVISIBLE"Bar"OFF"\n"); */
   /*  */
   /* printf(BLACK"FooBar"OFF"\n"); */
   /* printf(BRTBLACK"FooBar"OFF"\n"); */
   /* printf(RED"FooBar"OFF"\n"); */
   /* printf(BRTRED"FooBar"OFF"\n"); */
   /* printf(GREEN"FooBar"OFF"\n"); */
   /* printf(BRTGREEN"FooBar"OFF"\n"); */
   /* printf(YELLOW"FooBar"OFF"\n"); */
   /* printf(BRTYELLOW"FooBar"OFF"\n"); */
   /* printf(BLUE"FooBar"OFF"\n"); */
   /* printf(BRTBLUE"FooBar"OFF"\n"); */
   /* printf(MAGENTA"FooBar"OFF"\n"); */
   /* printf(BRTMAGENTA"FooBar"OFF"\n"); */
   /* printf(CYAN"FooBar"OFF"\n"); */
   /* printf(BRTCYAN"FooBar"OFF"\n"); */
   /* printf(WHITE"FooBar"OFF"\n"); */
   /* printf(BRTWHITE"FooBar"OFF"\n"); */
   /*  */
   /* printf(GREY10"FooBar"OFF"\n"); */
   /* printf(GREY11"FooBar"OFF"\n"); */
   /* printf(GREY12"FooBar"OFF"\n"); */
   /* printf(GREY13"FooBar"OFF"\n"); */
   /* printf(GREY14"FooBar"OFF"\n"); */
   /* printf(GREY15"FooBar"OFF"\n"); */
   /* printf(GREY16"FooBar"OFF"\n"); */
   /* printf(GREY17"FooBar"OFF"\n"); */
   /* printf(GREY18"FooBar"OFF"\n"); */
   /*  */
   /* printf(BG_BLACK"FooBar"OFF"\n"); */
   /* printf(BG_BRTBLACK"FooBar"OFF"\n"); */
   /* printf(BG_RED"FooBar"OFF"\n"); */
   /* printf(BG_BRTRED"FooBar"OFF"\n"); */
   /* printf(BG_GREEN"FooBar"OFF"\n"); */
   /* printf(BG_BRTGREEN"FooBar"OFF"\n"); */
   /* printf(BG_YELLOW"FooBar"OFF"\n"); */
   /* printf(BG_BRTYELLOW"FooBar"OFF"\n"); */
   /* printf(BG_BLUE"FooBar"OFF"\n"); */
   /* printf(BG_BRTBLUE"FooBar"OFF"\n"); */
   /* printf(BG_MAGENTA"FooBar"OFF"\n"); */
   /* printf(BG_BRTMAGENTA"FooBar"OFF"\n"); */
   /* printf(BG_CYAN"FooBar"OFF"\n"); */
   /* printf(BG_BRTCYAN"FooBar"OFF"\n"); */
   /* printf(BG_WHITE"FooBar"OFF"\n"); */
   /* printf(BG_BRTWHITE"FooBar"OFF"\n"); */
   /*  */
   /* printf(BG_GREY10"FooBar"OFF"\n"); */
   /* printf(BG_GREY11"FooBar"OFF"\n"); */
   /* printf(BG_GREY12"FooBar"OFF"\n"); */
   /* printf(BG_GREY13"FooBar"OFF"\n"); */
   /* printf(BG_GREY14"FooBar"OFF"\n"); */
   /* printf(BG_GREY15"FooBar"OFF"\n"); */
   /* printf(BG_GREY16"FooBar"OFF"\n"); */
   /* printf(BG_GREY17"FooBar"OFF"\n"); */
   /* printf(BG_GREY18"FooBar"OFF"\n"); */
   /*  */
   /* printf(CLR(58)"Text with Color number"OFF"\n"); */
   /* printf(RGB(55,134,129)"Text with RGB Color"OFF"\n"); */
   /*  */
   /* printf(BG_CLR(58)"Background with Color number"OFF"\n"); */
   /* printf(BG_RGB(55,134,129)"Background with RGB Color"OFF"\n"); */

   /* printf("Foo"CRS_SAVE CRS_PUT(4,40)"Bar"CRS_LOAD"BAR\n"); */
   /* printf("FooBar\n"); */
   /* printf("FooBar"CRS_UP(1) CRS_BW(5)"X"CRS_DN(1) CRS_FW(1)"Y\n"); */

   /* printf("foobar"CLEAR_LEFT"FOOBAR\n"); */
   /* printf("foobarfoobarfoobarfoobarfoobarfoobar"CRS_BW(28)CLEAR_RIGHT"FOOBAR\n"); */
   /* printf(CLEAR"FOOBAR\n"); */
   /* printf(CLEAR_UP"FOOBAR\n"); */
   /* printf(CLEAR_SCREEN"FOOBAR\n"); */
   /* printf(RESET"FOOBAR\n"); */


   /* freestr(A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U); */
   freestr(C);

   return 0;
}

// vim: fmr=<<<,>>> fdm=marker
