#include "pinocchio.h"

// Name2Enum <<<
enum DEMO
{
   _ALL_,
   _STR_,
   _STRFMT_,
   _FREESTR_,
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
   _SUB_,
   _STRIP_,
   _LSTRIP_,
   _RSTRIP_,
   _CINDEX_,
   _CCOUNT_,
   _CREPLACE_,
   _ESCCOLOR_,
   _LAST_
};

char* FUNC[] =
{
   "all",
   "str",
   "strfmt",
   "freestr",
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
   "sub",
   "strip",
   "lstrip",
   "rstrip",
   "cindex",
   "ccount",
   "creplace",
   "esccolor",
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

   // freestr <<<
   if((demo == _ALL_) || (demo == _FREESTR_))
   {
      print("\n::. demo freestr() .::");
      print("string A = str(\"foo\");");
      print("string B = str(\"bar\");");
      print("freestr(A,B);");
      string A = str("foo");
      string B = str("bar");
      freestr(A,B);
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

   // sub <<<
   if((demo == _ALL_) || (demo == _SUB_))
   {
      print("\n::. demo sub() .::");
      print("string V = sub(\"foobar2000\",1);");
      print("print(V);");
      print("string W = sub(\"foobar2000\",4,6);");
      print("print(W);");
      print("string X = sub(\"foobar2000\",-4);");
      print("print(X);");
      print("string Y = sub(\"foobar2000\",2,-6);");
      print("print(Y);");
      print("string Z = sub(\"foobar2000\",-4,-3);");
      print("print(Z);");
      print("freestr(V,W,X,Y,Z);");
      print(":::::::. prints .::::::");
      string V = sub("foobar2000",1);
      print(V);
      string W = sub("foobar2000",4,6);
      print(W);
      string X = sub("foobar2000",-4);
      print(X);
      string Y = sub("foobar2000",2,-6);
      print(Y);
      string Z = sub("foobar2000",-4,-3);
      print(Z);
      freestr(V,W,X,Y,Z);
   }
   // >>>

   // strip <<<
   if((demo == _ALL_) || (demo == _STRIP_))
   {
      print("\n::. demo strip() .::");
      print("string AA = str(\"   foobar   \n\");");
      print("strip(AA);");
      print("print(AA);");
      print("string AB = str(\"___foobar___\");");
      print("print(strip(AB, \"_\"));");
      print("freestr(AA,AB);");
      print(":::::::. prints .::::::");
      string AA = str("   foobar   \n");
      strip(AA);
      print(AA);
      string AB = str("___foobar___");
      print(strip(AB, "_"));
      freestr(AA,AB);
   }
   // >>>

   // lstrip <<<
   if((demo == _ALL_) || (demo == _LSTRIP_))
   {
      print("\n::. demo lstrip() .::");
      print("string AC = str(\"   foobar   \n\");");
      print("lstrip(AC);");
      print("print(AC);");
      print("string AD = str(\"___foobar___\");");
      print("print(lstrip(AD, \"_\"));");
      print("freestr(AC,AD);");
      print(":::::::. prints .::::::");
      string AC = str("   foobar   \n");
      lstrip(AC);
      print(AC);
      string AD = str("___foobar___");
      print(lstrip(AD, "_"));
      freestr(AC,AD);
   }
   // >>>

   // rstrip <<<
   if((demo == _ALL_) || (demo == _RSTRIP_))
   {
      print("\n::. demo rstrip() .::");
      print("string AE = str(\"   foobar   \n\");");
      print("rstrip(AE);");
      print("print(AE);");
      print("string AF = str(\"___foobar___\");");
      print("print(rstrip(AF, \"_\"));");
      print("freestr(AE,AF);");
      print(":::::::. prints .::::::");
      string AE = str("   foobar   \n");
      rstrip(AE);
      print(AE);
      string AF = str("___foobar___");
      print(rstrip(AF, "_"));
      freestr(AE,AF);
   }
   // >>>

   // cindex <<<
   if((demo == _ALL_) || (demo == _CINDEX_))
   {
      print("\n::. demo cindex() .::");
      print("string AG = str(\"knock knock\");");
      print("iprint(cindex(AG,'o'));");
      print("iprint(cindex(AG,'o',2));");
      print("iprint(cindex(AG,'k',2,3));");
      print("iprint(cindex(AG,'o',-1));");
      print("free(AG);");
      print(":::::::. prints .::::::");
      string AG = str("knock knock");
      iprint(cindex(AG,'o'));
      iprint(cindex(AG,'o',2));
      iprint(cindex(AG,'k',2,3));
      iprint(cindex(AG,'o',-1));
      free(AG);
   }
   // >>>

   // ccount <<<
   if((demo == _ALL_) || (demo == _CCOUNT_))
   {
      print("\n::. demo ccount() .::");
      print("string AH = str(\"knock knock\");");
      print("iprint(ccount(AH,'o'));");
      print("iprint(ccount(AH,'o',3));");
      print("iprint(ccount(AH,'k',2,8));");
      print("free(AH);");
      print(":::::::. prints .::::::");
      string AH = str("knock knock");
      iprint(ccount(AH,'o'));
      iprint(ccount(AH,'o',3));
      iprint(ccount(AH,'k',2,8));
      free(AH);
   }
   // >>>

   // creplace <<<
   if((demo == _ALL_) || (demo == _CREPLACE_))
   {
      print("\n::. demo creplace() .::");
      print("string AI = str(\"knock knock\");");
      print("print(creplace(AI,'k','g'));");
      print("print(creplace(AI,'g','k',2));");
      print("print(creplace(AI,'k','g',2));");
      print("print(creplace(AI,'g','k',2,3,9));");
      print("print(creplace(AI,'k','g',1,6));");
      print("free(AI);");
      print(":::::::. prints .::::::");
      string AI = str("knock knock");
      print(creplace(AI,'k','g'));
      print(creplace(AI,'g','k',2));
      print(creplace(AI,'k','g',2));
      print(creplace(AI,'g','k',2,3,9));
      print(creplace(AI,'k','g',1,6));
      free(AI);
   }
   // >>>

   /* iprint(5,0,-2,1323,282474); */
   /* string M = i2s(-456747844848); */
   /* string N = u2s(94567478448480); */
   /* string O = f2s(9456747.8448480); */
   /* string P = c2s('x'); */
   /* string Q = b2s(false); */
   /* string R = p2s(A); */
   /* string S = a2s(A); */
   /* iprint(int_scount(C, "oc")); */
   /* iprint(scount(C, "k")); */
   /* iprint(ccount(C, 'k')); */
   /* string T = x2s(-1); */
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

   // escape colors <<<
   if((demo == _ALL_) || (demo == _ESCCOLOR_))
   {
      printf(BOLD"Foo"NOBOLD"Bar"OFF"\n");
      printf(DIM"Foo"NODIM"Bar"OFF"\n");
      printf(ITALIC"Foo"NOITALIC"Bar"OFF"\n");
      printf(UNDERLINE"Foo"NOUNDERLINE"Bar"OFF"\n");
      printf(BLINK"Foo"NOBLINK"Bar"OFF"\n");
      printf(REVERSE"Foo"NOREVERSE"Bar"OFF"\n");
      printf(INVISIBLE"Foo"NOINVISIBLE"Bar"OFF"\n");

      printf(BLACK"FooBar"OFF"\n");
      printf(BRTBLACK"FooBar"OFF"\n");
      printf(RED"FooBar"OFF"\n");
      printf(BRTRED"FooBar"OFF"\n");
      printf(GREEN"FooBar"OFF"\n");
      printf(BRTGREEN"FooBar"OFF"\n");
      printf(YELLOW"FooBar"OFF"\n");
      printf(BRTYELLOW"FooBar"OFF"\n");
      printf(BLUE"FooBar"OFF"\n");
      printf(BRTBLUE"FooBar"OFF"\n");
      printf(MAGENTA"FooBar"OFF"\n");
      printf(BRTMAGENTA"FooBar"OFF"\n");
      printf(CYAN"FooBar"OFF"\n");
      printf(BRTCYAN"FooBar"OFF"\n");
      printf(WHITE"FooBar"OFF"\n");
      printf(BRTWHITE"FooBar"OFF"\n");

      printf(GREY10"FooBar"OFF"\n");
      printf(GREY11"FooBar"OFF"\n");
      printf(GREY12"FooBar"OFF"\n");
      printf(GREY13"FooBar"OFF"\n");
      printf(GREY14"FooBar"OFF"\n");
      printf(GREY15"FooBar"OFF"\n");
      printf(GREY16"FooBar"OFF"\n");
      printf(GREY17"FooBar"OFF"\n");
      printf(GREY18"FooBar"OFF"\n");

      printf(BG_BLACK"FooBar"OFF"\n");
      printf(BG_BRTBLACK"FooBar"OFF"\n");
      printf(BG_RED"FooBar"OFF"\n");
      printf(BG_BRTRED"FooBar"OFF"\n");
      printf(BG_GREEN"FooBar"OFF"\n");
      printf(BG_BRTGREEN"FooBar"OFF"\n");
      printf(BG_YELLOW"FooBar"OFF"\n");
      printf(BG_BRTYELLOW"FooBar"OFF"\n");
      printf(BG_BLUE"FooBar"OFF"\n");
      printf(BG_BRTBLUE"FooBar"OFF"\n");
      printf(BG_MAGENTA"FooBar"OFF"\n");
      printf(BG_BRTMAGENTA"FooBar"OFF"\n");
      printf(BG_CYAN"FooBar"OFF"\n");
      printf(BG_BRTCYAN"FooBar"OFF"\n");
      printf(BG_WHITE"FooBar"OFF"\n");
      printf(BG_BRTWHITE"FooBar"OFF"\n");

      printf(BG_GREY10"FooBar"OFF"\n");
      printf(BG_GREY11"FooBar"OFF"\n");
      printf(BG_GREY12"FooBar"OFF"\n");
      printf(BG_GREY13"FooBar"OFF"\n");
      printf(BG_GREY14"FooBar"OFF"\n");
      printf(BG_GREY15"FooBar"OFF"\n");
      printf(BG_GREY16"FooBar"OFF"\n");
      printf(BG_GREY17"FooBar"OFF"\n");
      printf(BG_GREY18"FooBar"OFF"\n");

      printf(CLR(58)"FooBar"OFF"\n");
      printf(RGB(55,134,129)"FooBar"OFF"\n");

      printf(BG_CLR(58)"FooBar"OFF"\n");
      printf(BG_RGB(55,134,129)"FooBar"OFF"\n");
   }
   // >>>

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
