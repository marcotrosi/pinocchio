// string manipulation
// regex
// shell colors
// file io

/* C <<<

https://en.cppreference.com/w/c/string/byte
https://pubs.opengroup.org/onlinepubs/7908799/xsh/strings.h.html

>>> */
/* Lua <<<

https://www.lua.org/manual/5.4/manual.html#6.4

string.byte (s [, i [, j]])
string.char (···)
string.dump (function [, strip])
string.find (s, pattern [, init [, plain]])
string.format (formatstring, ···)
string.gmatch (s, pattern [, init])
string.gsub (s, pattern, repl [, n])
string.len (s)
string.lower (s)
string.match (s, pattern [, init])
string.pack (fmt, v1, v2, ···)
string.packsize (fmt)
string.rep (s, n [, sep])
string.reverse (s)
string.sub (s, i [, j])
string.unpack (fmt, s [, pos])
string.upper (s)
tostring()
tonumber()

>>> */
/* Python <<<

https://docs.python.org/3/library/stdtypes.html#string-methods

str.capitalize()
str.casefold()
str.center(width[, fillchar])
str.count(sub[, start[, end]])
str.encode(encoding="utf-8", errors="strict")
str.endswith(suffix[, start[, end]])
str.expandtabs(tabsize=8)
str.find(sub[, start[, end]])
str.format(*args, **kwargs)
str.format_map(mapping)
str.index(sub[, start[, end]])
str.isalnum()
str.isalpha()
str.isascii()
str.isdecimal()
str.isdigit()
str.isidentifier()
str.islower()
str.isnumeric()
str.isprintable()
str.isspace()
str.istitle()
str.isupper()
str.join(iterable)
str.ljust(width[, fillchar])
str.lower()
str.lstrip([chars])
str.partition(sep)
str.removeprefix(prefix, /)
str.removesuffix(suffix, /)
str.replace(old, new[, count])
str.rfind(sub[, start[, end]])
str.rindex(sub[, start[, end]])
str.rjust(width[, fillchar])
str.rpartition(sep)
str.rsplit(sep=None, maxsplit=-1)
str.rstrip([chars])
str.split(sep=None, maxsplit=-1)
str.splitlines([keepends])
str.startswith(prefix[, start[, end]])
str.strip([chars])
str.swapcase()
str.title()
str.translate(table)
str.upper()
str.zfill(width)¶

>>> */
/* aRT <<<

aRT.alignString_s(String_s, Width_n, Alignment_s)
aRT.makeStringVisible_s(String_s)
aRT.deleteEscapeSequences_s(String_s, Key_t)
aRT.deleteWhiteSpaces_s(KeyWord_s, String_s)
aRT.splitString_t(s, sep)

>>> */

#include "pinocchio.h"

string str(const string s) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s)+1u; // +1 for null terminator

   string Address = (string)malloc(StrLen*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   memcpy(Address, s, StrLen);

   return Address;
} // >>>

string strfmt(const string s, ...) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   string Buffer = (string)malloc(BUFFERSIZE*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   va_list args;
   va_start(args, s);
   vsnprintf(Buffer, BUFFERSIZE, s, args);
   va_end(args);

   size_t StrLen = strlen(Buffer)+1u; // +1 for null terminator

   string Address = (string)malloc(StrLen*sizeof(char));

   if(Address == NULL)
   {
      free(Buffer);
      return NULL;
   }

   memcpy(Address, Buffer, StrLen);

   free(Buffer);

   return Address;
} // >>>

void printv(int n, ...) // <<<
{
   va_list args;

   va_start(args, n);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg == NULL)
		{
			printf("NULL");
		}
		else
		{
			printf("%s", Arg);
		}

      if(i != (n-1))
      {
         printf("\t");
      }
	}

   va_end(args);

   printf("\n");
} // >>>

string joinv(int n, ...) // <<<
{
   va_list args;

   va_start(args, n);

   size_t StrLen = 0u;

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         StrLen = StrLen + strlen(Arg);
		}
	}

   StrLen++; // for null terminator

   string Address = (string)malloc(StrLen*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   va_start(args, n);

   unsigned int WriteIndex = 0u;

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         strcpy(&(Address[WriteIndex]), Arg);
         StrLen = strlen(Arg);
         WriteIndex = WriteIndex + StrLen; 
		}
	}

   va_end(args);

   return Address;
} // >>>

string gluev(char *g, int n, ...) // <<<
{
   va_list args;

   va_start(args, n);

   size_t StrLen = 0u;
   size_t GlueLen = strlen(g);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         StrLen = StrLen + strlen(Arg);
		}
	}

   StrLen++; // for null terminator
   StrLen = StrLen + ((n-1)*GlueLen);

   string Address = (string)malloc(StrLen*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   va_start(args, n);

   unsigned int WriteIndex = 0u;

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         strcpy(&(Address[WriteIndex]), Arg);
         StrLen = strlen(Arg);
         WriteIndex = WriteIndex + StrLen; 
         strcpy(&(Address[WriteIndex]), g);
         WriteIndex = WriteIndex + GlueLen; 
		}
	}

   va_end(args);

   return Address;
} // >>>

// vim: fmr=<<<,>>> fdm=marker
