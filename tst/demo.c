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
   _APPEND_,
   _PREPEND_,
   _JOIN_,
   _GLUE_,
   _REP_,
   _LEFT_,
   _CENTER_,
   _RIGHT_,
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
   "append",
   "prepend",
   "join",
   "glue",
   "rep",
   "left",
   "center",
   "right",
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
   return _LAST_;
}
// >>>

int main(int argc, char **argv)
{
   int demo = _ALL_; // 0 means demo all

   if(argc == 2)
   {
      demo = Name2Enum(argv[1]);
      if(demo == _LAST_)
      {
         printf("no demo for '%s'\n", argv[1]);
         exit(0);
      }
   }

   // str <<<
   if((demo == _ALL_) || (demo == _STR_))
   {
      print("\n::. demo str() .::");
      print("string A = str(\"foobar\");");
      print("string B = str(A);");
      print("print(A,B);");
      print("freestr(A,B);");
      print(":::::::. prints .::::::");
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
      print(":::::::. prints .::::::");
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
      print(":::::::. prints .::::::");
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
      print(":::::::. prints .::::::");
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
      print(":::::::. prints .::::::");
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
      print(":::::::. prints .::::::");
      string G = str("foobar");
      iprint( len(G) );
      free(G);
   }
   // >>>

   // append <<<
   if((demo == _ALL_) || (demo == _APPEND_))
   {
      print("\n::. demo append() .::");
      print("string H = str(\"foobar\");");
      print("append(H, \"2000\", \" is da thing\");");
      print("print(H);");
      print("free(H);");
      print(":::::::. prints .::::::");
      string H = str("foobar");
      append(H, "2000", " is da thing");
      print(H);
      free(H);
   }
   // >>>

   // prepend <<<
   if((demo == _ALL_) || (demo == _PREPEND_))
   {
      print("\n::. demo prepend() .::");
      print("string I = str(\"foobar\");");
      print("prepend(I, \"this\", \" is \");");
      print("print(I);");
      print("free(I);");
      print(":::::::. prints .::::::");
      string I = str("foobar");
      prepend(I, "this", " is ");
      print(I);
      free(I);
   }
   // >>>

   // join <<<
   if((demo == _ALL_) || (demo == _JOIN_))
   {
      print("\n::. demo join() .::");
      print("string J = str(\"foobar\");");
      print("string K = join(\"this\", \" \", \"is \", J);");
      print("print(K);");
      print("freestr(J,K);");
      print(":::::::. prints .::::::");
      string J = str("foobar");
      string K = join("this", " ", "is ", J);
      print(K);
      freestr(J,K);
   }
   // >>>

   // glue <<<
   if((demo == _ALL_) || (demo == _GLUE_))
   {
      print("\n::. demo glue() .::");
      print("string L = str(\"foobar\");");
      print("string M = glue(\" \", \"this\", \"is\", L);");
      print("print(M);");
      print("freestr(L,M);");
      print(":::::::. prints .::::::");
      string L = str("foobar");
      string M = join("this", " ", "is ", L);
      print(M);
      freestr(L,M);
   }
   // >>>

   // rep <<<
   if((demo == _ALL_) || (demo == _REP_))
   {
      print("\n::. demo rep() .::");
      print("string N = rep(\"foo\", 3, \"_\");");
      print("string O = rep(\"foo\", 3);");
      print("print(N, O);");
      print("freestr(N,O);");
      print(":::::::. prints .::::::");
      string N = rep("foo", 3, "_");
      string O = rep("foo", 3);
      print(N,O);
      freestr(N,O);
   }
   // >>>

   // left <<<
   if((demo == _ALL_) || (demo == _LEFT_))
   {
      print("\n::. demo left() .::");
      print("string P = left(\"left aligned\", 10);");
      print("string Q = left(\"left aligned\", 20, '_');");
      print("print(P);");
      print("print(Q);");
      print("freestr(P,Q);");
      print(":::::::. prints .::::::");
      string P = left("left aligned", 10);
      string Q = left("left aligned", 20, '_');
      print(P);
      print(Q);
      freestr(P,Q);
   }
   // >>>

   // center <<<
   if((demo == _ALL_) || (demo == _CENTER_))
   {
      print("\n::. demo center() .::");
      print("string R = center(\"centered text\", 10);");
      print("string S = center(\"centered text\", 20, '-');");
      print("print(R);");
      print("print(S);");
      print("freestr(R,S);");
      print(":::::::. prints .::::::");
      string R = center("centered text", 10);
      string S = center("centered text", 20, '-');
      print(R);
      print(S);
      freestr(R,S);
   }
   // >>>

   // right <<<
   if((demo == _ALL_) || (demo == _RIGHT_))
   {
      print("\n::. demo right() .::");
      print("string T = right(\"right aligned\", 10);");
      print("string U = right(\"right aligned\", 20, '-');");
      print("print(T);");
      print("print(U);");
      print("freestr(T,U);");
      print(":::::::. prints .::::::");
      string T = right("right aligned", 10);
      string U = right("right aligned", 20, '-');
      print(T);
      print(U);
      freestr(T,U);
   }
   // >>>

   /* print(sub(H,2,5)); */
   /* print(sub(H,2,-1)); */
   /* print(sub(H,2)); */
   /* print(sub(H,-2)); */
   /* print(sub(H,-2,-4)); */
   /* print(sub(NULL,3,5)); */
   /* print(sub(H,2,2)); */

   /* printf("%s has k at index %zu\n", C, cindex(C, 'k')); */
   /* printf("%s has fourth k at index %zu\n", C, cindex(C, 'k', 4)); */
   /* printf("%s has fourth k at index %zu\n", C, cindex(C, 'k', -2)); */
   /* printf("%s has second o at index %zu\n", C, cindex(C, 'o', 1, 4)); */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k'));       // 4 */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k', 2));    // 3 */
   /* printf("%s has %zu k's\n", C, ccount(C, 'k', 2, 7)); // 2 */
   /* printf("knockknock is now %s\n", creplace(C, 'k', 'g')); // gnocggnocg */
   /* printf("gnocggnocg is now %s\n", creplace(C, 'g', 'k', 2)); // knockgnocg */
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
