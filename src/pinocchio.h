#ifndef PINOCCHIO_H
#define PINOCCHIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef char* string;

string str(const string s);
string strfmt(const string s, ...);

void printv(int n, ...);
string joinv(int n, ...);
string gluev(char *g, int n, ...);

#define BUFFERSIZE 1024

#define COUNT_ARGS_(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,cnt,...) cnt
#define COUNT_ARGS(...) COUNT_ARGS_(,##__VA_ARGS__,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define print(...) printv(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define join(...) joinv(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define glue(g,...) gluev(g, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)

#endif // PINOCCHIO_H

// vim: fmr=<<<,>>> fdm=marker
