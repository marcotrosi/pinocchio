#ifndef PINOCCHIO_H
#define PINOCCHIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <malloc/malloc.h>

typedef char* string;

string str(const string s);
string strfmt(const string s, ...);
string lower(string s);
string upper(string s);
string rev(string s);
size_t len(string s);

string x2s(long long int x);
string i2s(signed long long int x);
string u2s(unsigned long long int x);
string f2s(long double x);
string c2s(char x);
string b2s(bool x);

// internal functions used by macros
void   int_freestr(int n, ...);
void   int_print(int n, ...);
void   int_iprint(int n, ...);
// uprint
// xprint
// fprint
// cprint
// pprint
// bprint

string int_join(int n, ...);
string int_glue(char *g, int n, ...);
string int_rep(string s, unsigned int n, string g);
string int_append(string *s, int n, ...);
string int_prepend(string *s, int n, ...);
string int_sub(string s, int i, int j);
string int_center(string s, unsigned int w, char c);
string int_left(string s, unsigned int w, char c);
string int_right(string s, unsigned int w, char c);
string int_a2s(void *x);
string int_strip(string s, char side, string w);
size_t int_cindex(string s, char c, signed long long int n, size_t start);
size_t int_ccount(string s, char c, size_t start, size_t end);
string int_creplace(string s, char c, char r, size_t n, size_t start, size_t end);
size_t int_scount(string s, string ss/*, size_t start, size_t end*/);

// TODO make BUFFERSIZE setable from commandline
#define BUFFERSIZE 1024
#define NO_RESULT SIZE_MAX
#define MAX_LEN (SIZE_MAX - 1U)

#define COUNT_ARGS_HLP(aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,ba,bb,bc,bd,be,bf,bg,bh,bi,bj,bk,ca,cb,cc,cd,ce,cf,cg,ch,ci,cj,ck,da,db,dc,dd,de,df,dg,dh,di,dj,dk,ea,eb,ec,ed,ee,ef,eg,eh,ei,ej,ek,fa,fb,fc,fd,fe,ff,fg,fh,fi,fj,fk,ga,gb,gc,gd,ge,gf,gg,gh,gi,gj,gk,ha,hb,hc,hd,he,hf,hg,hh,hi,hj,hk,ia,ib,ic,id,ie,if,ig,ih,ii,ij,ik,ja,jb,jc,jd,je,jf,jg,jh,ji,jj,jk,ka,kb,kc,kd,ke,kf,kg,kh,ki,kj,kk,cnt,...) cnt
#define COUNT_ARGS(...) COUNT_ARGS_HLP(,##__VA_ARGS__,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define OPT_ARG_0(dflt) (dflt)
#define OPT_ARG_1(dflt,arg) (arg)
#define OPT_ARG_HLP(cnt,dflt,...) OPT_ARG_##cnt(dflt,##__VA_ARGS__)
#define OPT_ARG(cnt,dflt,...) OPT_ARG_HLP(cnt,dflt,##__VA_ARGS__)

#define OPT_2ARG_0(dflt1,dflt2) (dflt1),(dflt2)
#define OPT_2ARG_1(dflt1,dflt2,arg1) (arg1),(dflt2)
#define OPT_2ARG_2(dflt1,dflt2,arg1,arg2) (arg1),(arg2)
#define OPT_2ARG_HLP(cnt,dflt1,dflt2,...) OPT_2ARG_##cnt(dflt1,dflt2,##__VA_ARGS__)
#define OPT_2ARG(cnt,dflt1,dflt2,...) OPT_2ARG_HLP(cnt,dflt1,dflt2,##__VA_ARGS__)

#define CINDEX_OPT_2ARG_0(dflt1,dflt2) (dflt1),(dflt2)
#define CINDEX_OPT_2ARG_1(dflt1,dflt2,arg1) (arg1),(((arg1)<0)?MAX_LEN:0)
#define CINDEX_OPT_2ARG_2(dflt1,dflt2,arg1,arg2) (arg1),(arg2)
#define CINDEX_OPT_2ARG_HLP(cnt,dflt1,dflt2,...) CINDEX_OPT_2ARG_##cnt(dflt1,dflt2,##__VA_ARGS__)
#define CINDEX_OPT_2ARG(cnt,dflt1,dflt2,...) CINDEX_OPT_2ARG_HLP(cnt,dflt1,dflt2,##__VA_ARGS__)

#define OPT_3ARG_0(dflt1,dflt2,dflt3) (dflt1),(dflt2),(dflt3)
#define OPT_3ARG_1(dflt1,dflt2,dflt3,arg1) (arg1),(dflt2),(dflt3)
#define OPT_3ARG_2(dflt1,dflt2,dflt3,arg1,arg2) (arg1),(arg2),(dflt3)
#define OPT_3ARG_3(dflt1,dflt2,dflt3,arg1,arg2,arg3) (arg1),(arg2),(arg3)
#define OPT_3ARG_HLP(cnt,dflt1,dflt2,dflt3,...) OPT_3ARG_##cnt(dflt1,dflt2,dflt3,##__VA_ARGS__)
#define OPT_3ARG(cnt,dflt1,dflt2,dflt3,...) OPT_3ARG_HLP(cnt,dflt1,dflt2,dflt3,##__VA_ARGS__)

#define freestr(...)        int_freestr(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define print(...)          int_print(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define iprint(...)         int_iprint(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define join(...)           int_join(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define glue(g,...)         int_glue(g, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define rep(s,n,...)        int_rep(s, n, OPT_ARG(COUNT_ARGS(__VA_ARGS__), NULL, ##__VA_ARGS__))
#define append(s,...)       int_append(&(s), COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define prepend(s,...)      int_prepend(&(s), COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define sub(s,i,...)        int_sub(s,i,OPT_ARG(COUNT_ARGS(__VA_ARGS__), -1, ##__VA_ARGS__))
#define center(s,w,...)     int_center(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))
#define left(s,w,...)       int_left(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))
#define right(s,w,...)      int_right(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))
#define p2s(x)              int_a2s((void *)(&(x)))
#define a2s(x)              int_a2s((void *)(x))
#define strip(s,...)        int_strip(s, 'b', OPT_ARG(COUNT_ARGS(__VA_ARGS__), " \t\n\r", ##__VA_ARGS__))
#define lstrip(s,...)       int_strip(s, 'l', OPT_ARG(COUNT_ARGS(__VA_ARGS__), " \t\n\r", ##__VA_ARGS__))
#define rstrip(s,...)       int_strip(s, 'r', OPT_ARG(COUNT_ARGS(__VA_ARGS__), " \t\n\r", ##__VA_ARGS__))
#define cindex(s,c,...)     int_cindex(s, c, CINDEX_OPT_2ARG(COUNT_ARGS(__VA_ARGS__), 1, 0, ##__VA_ARGS__))
#define ccount(s,c,...)     int_ccount(s, c, OPT_2ARG(COUNT_ARGS(__VA_ARGS__), 0, MAX_LEN, ##__VA_ARGS__))
#define creplace(s,c,r,...) int_creplace(s, c, r, OPT_3ARG(COUNT_ARGS(__VA_ARGS__), 0, 0, MAX_LEN, ##__VA_ARGS__))
#define scount(s,ss)        int_scount(s, ss)

#define s2i(x)   strtol(x,NULL,10)
#define s2u(x)   strtoul(x,NULL,10)

#define s2lli(x) strtoll(x,NULL,10)
#define s2llu(x) strtoull(x,NULL,10)

#define s2f(x)   strtof(x,NULL)
#define s2d(x)   strtod(x,NULL)
#define s2ld(x)  strtold(x,NULL)

#define hasChar(s,c)    (strchr((s),(c))!=NULL)
#define hasString(s,ss) (strstr((s),(ss))!=NULL)

// terminal escape sequences <<<
/*
https://en.wikipedia.org/wiki/ANSI_escape_code
http://ascii-table.com/ansi-escape-sequences-vt-100.php

\e[<CODES;SEP>m
\e[<num>;<num>;<num>m
\e[38;5;⟨n⟩m Select foreground color
\e[48;5;⟨n⟩m Select background color
       0-7: standard colors (as in ESC [ 30–37 m)
      8-15: high intensity colors (as in ESC [ 90–97 m)
    16-231: 6 × 6 × 6 cube (216 colors): 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
   232-255: grayscale from black to white in 24 steps
\e[38;2;⟨r⟩;⟨g⟩;⟨b⟩m Select RGB foreground color
\e[48;2;⟨r⟩;⟨g⟩;⟨b⟩m Select RGB background color
*/

// text attributes <<<
#define OFF         "\e[0m"

#define BOLD        "\e[1m"
#define NOBOLD      "\e[21m"

#define DIM         "\e[2m"
#define NODIM       "\e[22m"

#define ITALIC      "\e[3m"
#define NOITALIC    "\e[23m"

#define UNDERLINE   "\e[4m"
#define NOUNDERLINE "\e[24m"

#define BLINK       "\e[5m"
#define NOBLINK     "\e[25m"

#define REVERSE     "\e[7m"
#define NOREVERSE   "\e[27m"

#define INVISIBLE   "\e[8m"
#define NOINVISIBLE "\e[28m"
// >>>
// text colors <<<
#define BLACK      "\e[30m"
#define RED        "\e[31m"
#define GREEN      "\e[32m"
#define YELLOW     "\e[33m"
#define BLUE       "\e[34m"
#define MAGENTA    "\e[35m"
#define CYAN       "\e[36m"
#define WHITE      "\e[37m"

#define BRTBLACK   "\e[90m"
#define BRTRED     "\e[91m"
#define BRTGREEN   "\e[92m"
#define BRTYELLOW  "\e[93m"
#define BRTBLUE    "\e[94m"
#define BRTMAGENTA "\e[95m"
#define BRTCYAN    "\e[96m"
#define BRTWHITE   "\e[97m"

#define GREY1      "\e[38;5;232m"
#define GREY2      "\e[38;5;233m"
#define GREY3      "\e[38;5;234m"
#define GREY4      "\e[38;5;235m"
#define GREY5      "\e[38;5;236m"
#define GREY6      "\e[38;5;237m"
#define GREY7      "\e[38;5;238m"
#define GREY8      "\e[38;5;239m"
#define GREY9      "\e[38;5;240m"
#define GREY10     "\e[38;5;241m"
#define GREY11     "\e[38;5;242m"
#define GREY12     "\e[38;5;243m"
#define GREY13     "\e[38;5;244m"
#define GREY14     "\e[38;5;245m"
#define GREY15     "\e[38;5;246m"
#define GREY16     "\e[38;5;247m"
#define GREY17     "\e[38;5;248m"
#define GREY18     "\e[38;5;249m"
#define GREY19     "\e[38;5;250m"
#define GREY20     "\e[38;5;251m"
#define GREY21     "\e[38;5;252m"
#define GREY22     "\e[38;5;253m"
#define GREY23     "\e[38;5;254m"
#define GREY24     "\e[38;5;255m"

#define CLR(v)     "\e[38;5;"#v"m"
#define RGB(r,g,b) "\e[38;2;"#r";"#g";"#b"m"
// >>>
// background colors <<<
#define BG_BLACK      "\e[40m"
#define BG_RED        "\e[41m"
#define BG_GREEN      "\e[42m"
#define BG_YELLOW     "\e[43m"
#define BG_BLUE       "\e[44m"
#define BG_MAGENTA    "\e[45m"
#define BG_CYAN       "\e[46m"
#define BG_WHITE      "\e[47m"

#define BG_BRTBLACK   "\e[100m"
#define BG_BRTRED     "\e[101m"
#define BG_BRTGREEN   "\e[102m"
#define BG_BRTYELLOW  "\e[103m"
#define BG_BRTBLUE    "\e[104m"
#define BG_BRTMAGENTA "\e[105m"
#define BG_BRTCYAN    "\e[106m"
#define BG_BRTWHITE   "\e[107m"

#define BG_GREY1      "\e[48;5;232m"
#define BG_GREY2      "\e[48;5;233m"
#define BG_GREY3      "\e[48;5;234m"
#define BG_GREY4      "\e[48;5;235m"
#define BG_GREY5      "\e[48;5;236m"
#define BG_GREY6      "\e[48;5;237m"
#define BG_GREY7      "\e[48;5;238m"
#define BG_GREY8      "\e[48;5;239m"
#define BG_GREY9      "\e[48;5;240m"
#define BG_GREY10     "\e[48;5;241m"
#define BG_GREY11     "\e[48;5;242m"
#define BG_GREY12     "\e[48;5;243m"
#define BG_GREY13     "\e[48;5;244m"
#define BG_GREY14     "\e[48;5;245m"
#define BG_GREY15     "\e[48;5;246m"
#define BG_GREY16     "\e[48;5;247m"
#define BG_GREY17     "\e[48;5;248m"
#define BG_GREY18     "\e[48;5;249m"
#define BG_GREY19     "\e[48;5;250m"
#define BG_GREY20     "\e[48;5;251m"
#define BG_GREY21     "\e[48;5;252m"
#define BG_GREY22     "\e[48;5;253m"
#define BG_GREY23     "\e[48;5;254m"
#define BG_GREY24     "\e[48;5;255m"

#define BG_CLR(v)     "\e[48;5;"#v"m"
#define BG_RGB(r,g,b) "\e[48;2;"#r";"#g";"#b"m"
// >>>
/*
// cursor movements <<<
#define CUS "\e[s"
#define CUL "\e[u"

#define CUU(n)   "\e["#n"A"
#define CUD(n)   "\e["#n"B"
#define CUF(n)   "\e["#n"C"
#define CUB(n)   "\e["#n"D"
#define CNL(n)   "\e["#n"E"
#define CPL(n)   "\e["#n"F"
#define CHA(n)   "\e["#n"G"
#define CUP(l,c) "\e["#l";"#c"H"
#define HVP(l,c) "\e["#l";"#c"f"
// >>>
// clearing deleting <<<
#define RESET        "\ec"
#define CLEAR        "\e[H"
#define CLEAR_DOWN   "\e[0J"
#define CLEAR_UP     "\e[1J"
#define CLEAR_RIGHT  "\e[0K"
#define CLEAR_LEFT   "\e[1K"
#define CLEAR_SCREEN "\e[2J"
#define CLEAR_LINE   "\e[2K"
// >>>
// scrolling <<<
#define SU(n) "\e["#n"S"
#define SD(n) "\e["#n"T"
// >>>
*/
// >>>

#endif // PINOCCHIO_H

// vim: fmr=<<<,>>> fdm=marker
