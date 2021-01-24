#ifndef PINOCCHIO_H
#define PINOCCHIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef char* string;

string str(const string s);
string strfmt(const string s, ...);
string lower(string s);
string upper(string s);
string rev(string s);
size_t len(string s);

// internal functions used by macros
void   int_print(int n, ...);
string int_join(int n, ...);
string int_glue(char *g, int n, ...);
string int_rep(string s, unsigned int n, string g);
string int_append(string *s, int n, ...);
string int_prepend(string *s, int n, ...);
string int_sub(string s, int i, int j);
string int_center(string s, unsigned int w, char c);
string int_left(string s, unsigned int w, char c);
string int_right(string s, unsigned int w, char c);

#define BUFFERSIZE 1024

#define COUNT_ARGS_HLP(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,cnt,...) cnt
#define COUNT_ARGS(...) COUNT_ARGS_HLP(,##__VA_ARGS__,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define OPT_ARG_HLP(cnt,opt,...) OPT_ARG_##cnt(opt,##__VA_ARGS__)
#define OPT_ARG(cnt,opt,...) OPT_ARG_HLP(cnt,opt,##__VA_ARGS__)
#define OPT_ARG_0(opt) (opt)
#define OPT_ARG_1(opt,arg) (arg)

#define print(...)      int_print(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define join(...)       int_join(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define glue(g,...)     int_glue(g, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define rep(s,n,...)    int_rep(s, n, OPT_ARG(COUNT_ARGS(__VA_ARGS__), NULL, ##__VA_ARGS__))
#define append(s,...)   int_append(&(s), COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define prepend(s,...)  int_prepend(&(s), COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define sub(s,i,...)    int_sub(s,i,OPT_ARG(COUNT_ARGS(__VA_ARGS__), -1, ##__VA_ARGS__))
#define center(s,w,...) int_center(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))
#define left(s,w,...)   int_left(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))
#define right(s,w,...)  int_right(s,w,OPT_ARG(COUNT_ARGS(__VA_ARGS__), ' ', ##__VA_ARGS__))

// s2i
// s2u
// s2f
// s2c

// i2s
// u2s
// x2s
// f2s
// c2s
// p2s
// b2s

// iprint
// uprint
// xprint
// fprint
// cprint
// pprint
// bprint

#endif // PINOCCHIO_H

// vim: fmr=<<<,>>> fdm=marker
