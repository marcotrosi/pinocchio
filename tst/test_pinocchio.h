#include "equal.h"
#include "pinocchio.h"

void test_cindex(char *s, char c, signed long long int n, size_t start, size_t must, char *file, size_t line);
void test_ccount(char *s, char c, size_t start, size_t end, size_t must, char *file, size_t line);
void test_creplace(char *s, char c, char r, size_t n, size_t start, size_t end, string must, char *file, size_t line);
