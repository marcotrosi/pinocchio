#include "pinocchio.h"

// Name2Enum <<<
enum DEMO
{
   _ALL_,
   _STR_,
   _STRFMT_,
   _LOWER_,
   _UPPER_,
   _REV_,
   _LEN_,
   _LAST_
};

char* FUNC[] =
{
   "all",
   "str",
   "strfmt",
   "lower",
   "upper",
   "rev",
   "len",
   NULL
};

int Name2Enum(char *name)
{
   for(int i=0; i < _LAST_ ; i++)
   {
      if(!strcmp(name, FUNC[i]))
      {
         return i;
      }
   }
   return _ALL_;
}
// >>>

int main(int argc, char **argv)
{
   int demo = _ALL_; // 0 means demo all

   if(argc == 2)
   {
      demo = Name2Enum(argv[1]);
   }

   // str <<<
   if((demo == _ALL_) || (demo == _STR_))
   {
      print("\n::. demo str() .::");
      print("string A = str(\"foobar\");");
      print("string B = str(A);");
      print("print(A,B);");
      print("freestr(A,B);");
      print("------- prints -------");
      string A = str("foobar");
      string B = str(A);
      print(A, B);
      freestr(A, B);
   }
   // >>>

   // strfmt <<<
   if((demo == _ALL_) || (demo == _STRFMT_))
   {
      print("\n::. demo strfmt() .::");
      print("int a = 42;");
      print("string C = strfmt(\"foo %d bar\", a);");
      print("print(C);");
      print("free(C);");
      print("------- prints -------");
      int a = 42;
      string C = strfmt("foo %d bar", a);
      print(C);
      free(C);
   }
   // >>>

   // lower <<<
   if((demo == _ALL_) || (demo == _LOWER_))
   {
      print("\n::. demo lower() .::");
      print("string D = str(\"FOOBAR\");");
      print("lower(D);");
      print("print(D);");
      print("free(D);");
      print("------- prints -------");
      string D = str("FOOBAR");
      lower(D);
      print(D);
      free(D);
   }
   // >>>

   // upper <<<
   if((demo == _ALL_) || (demo == _UPPER_))
   {
      print("\n::. demo upper() .::");
      print("string E = str(\"foobar\");");
      print("upper(E);");
      print("print(E);");
      print("free(E);");
      print("------- prints -------");
      string E = str("foobar");
      upper(E);
      print(E);
      free(E);
   }
   // >>>

   // rev <<<
   if((demo == _ALL_) || (demo == _REV_))
   {
      print("\n::. demo rev() .::");
      print("string F = str(\"foobar\");");
      print("upper(F);");
      print("print(F);");
      print("free(F);");
      print("------- prints -------");
      string F = str("foobar");
      rev(F);
      print(F);
      free(F);
   }
   // >>>

   // len <<<
   if((demo == _ALL_) || (demo == _LEN_))
   {
      print("\n::. demo len() .::");
      print("string G = str(\"foobar\");");
      print("iprint( len(G) );");
      print("free(G);");
      print("------- prints -------");
      string G = str("foobar");
      iprint( len(G) );
      free(G);
   }
   // >>>

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
   /* printf("%s has fourth k at index %zu\n", C, cindex(C, 'k', -2)); */
   /* printf("%s has second o at index %zu\n", C, cindex(C, 'o', 1, 4)); */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k'));       // 4 */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k', 2));    // 3 */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k', 2, 7)); // 2 */
   /* printf("knockknock is now %s\n", creplace(C, 'k', 'g')); // gnocggnocg */
   /* printf("gnocggnocg is now %s\n", creplace(C, 'g', 'k', 2)); // knockgnocg */
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
   /* iprint(int_scount(C, "oc")); */
   /* iprint(scount(C, "k")); */
   /* iprint(ccount(C, 'k')); */
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

   return 0;
}

// vim: fmr=<<<,>>> fdm=marker
