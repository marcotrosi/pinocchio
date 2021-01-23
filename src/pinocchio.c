// string manipulation
// regex
// shell colors
// file io

/* C <<<

https://en.cppreference.com/w/c/string/byte
https://pubs.opengroup.org/onlinepubs/7908799/xsh/strings.h.html

strcpy copies one string to another
strncpy copies a certain amount of characters from one string to another
strcat concatenates two strings
strncat concatenates a certain amount of characters of two strings
strxfrm transform a string so that strcmp would produce the same result as strcoll
strlen returns the length of a given string
strcmp compares two strings
strncmp compares a certain number of characters from two strings
strcoll compares two strings in accordance to the current locale
strchr finds the first occurrence of a character
strrchr finds the last occurrence of a character
strspn returns the length of the maximum initial segment that consists of only the characters found in another byte string
strcspn returns the length of the maximum initial segment that consists of only the characters not found in another byte string
strpbrk finds the first location of any character from a set of separators
strstr finds the first occurrence of a substring of characters
strtok finds the next token in a byte string
memchr searches an array for the first occurrence of a character
memcmp compares two buffers
memset fills a buffer with a character
memcpy copies one buffer to another
memmove moves one buffer to another
strerror returns a text version of a given error code 

isalnum checks if a character is alphanumeric
isalpha checks if a character is alphabetic
islower checks if a character is lowercase
isupper checks if a character is an uppercase character
isdigit checks if a character is a digit
isxdigit checks if a character is a hexadecimal character
iscntrl checks if a character is a control character
isgraph checks if a character is a graphical character
isspace checks if a character is a space character
isblank checks if a character is a blank character
isprint checks if a character is a printing character
ispunct checks if a character is a punctuation character
tolower converts a character to lowercase
toupper converts a character to uppercase 

int    bcmp(const void *, const void *, size_t);
void   bcopy(const void *, void *, size_t);
void   bzero(void *, size_t);
int    ffs(int);
char   *index(const char *, int);
char   *rindex(const char *, int);
int    strcasecmp(const char *, const char *);
int    strncasecmp(const char *, const char *, size_t);

atof converts a byte string to a floating point value
atoi atol atoll (C++11) converts a byte string to an integer value
strtol strtoll (C++11) converts a byte string to an integer value
strtoul strtoull (C++11) converts a byte string to an unsigned integer value
strtof strtod strtold converts a byte string to a floating point value

>>> */
/* Lua <<<

https://www.lua.org/manual/5.4/manual.html#6.4

string.byte (s [, i [, j]])
string.char (···)
string.dump (function [, strip])
string.pack (fmt, v1, v2, ···)
string.packsize (fmt)
string.unpack (fmt, s [, pos])
tostring()
tonumber()

string.sub (s, i [, j])
string.find (s, pattern [, init [, plain]])
string.gmatch (s, pattern [, init])
string.gsub (s, pattern, repl [, n])
string.match (s, pattern [, init])

string.format (formatstring, ···)
string.len (s)
string.lower (s)
string.upper (s)
string.rep (s, n [, sep])
string.reverse (s)

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
      va_end(args);
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
         WriteIndex = WriteIndex + strlen(Arg); 
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

string lower(string s) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   for(int i=0; s[i] != '\0'; i++)
   {
      s[i] = tolower(s[i]);
   }

   return s;
} // >>>

string upper(string s) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   for(int i=0; s[i] != '\0'; i++)
   {
      s[i] = toupper(s[i]);
   }

   return s;
} // >>>

string repv(string s, unsigned int n, string g) // <<<
{
   size_t StrLen = 0u;
   size_t GlueLen = 0;
   string Glue = NULL;

   if(s == NULL)
   {
      return NULL;
   }

   StrLen = strlen(s);

   if(g != NULL)
   {
      GlueLen = strlen(g);
      Glue = g;
   }
   else
   {
      Glue = "";
   }

   if(n == 0u)
   {
      StrLen = 0u;
   }
   else
   {
      StrLen = (n*StrLen)+((n-1)*GlueLen)+1;
   }

   string Address = (string)malloc(StrLen*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   if(n == 0u)
   {
      return Address;
   }

   unsigned int WriteIndex = 0u;
   StrLen = strlen(s);
   
	for(int i=0; i < (n-1); i++)
	{
      strcpy(&(Address[WriteIndex]), s);
      WriteIndex = WriteIndex + StrLen;
      strcpy(&(Address[WriteIndex]), Glue);
      WriteIndex = WriteIndex + GlueLen; 
	}
   strcpy(&(Address[WriteIndex]), s);
   WriteIndex = WriteIndex + StrLen;

   return Address;
} // >>>

string rev(string s) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s);

   for(int i=0; i < (StrLen/2) ; i++)
   {
      char Tmp = s[i];
      s[i] = s[StrLen-i-1];
      s[StrLen-i-1] = Tmp;
   }

   return s;
} // >>>

size_t len(string s) // <<<
{
   if(s == NULL)
   {
      return 0;
   }
   return strlen(s);
} // >>>

string appendv(string *s, int n, ...) // <<<
{
   va_list args;

   if(s == NULL)
   {
      return NULL;
   }

   if(n == 0u)
   {
      return *s;
   }

   va_start(args, n);

   size_t StrLen = strlen(*s);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         StrLen = StrLen + strlen(Arg);
		}
	}

   StrLen++; // for null terminator

   string Address = (string)realloc(*s, StrLen*sizeof(char));

   if(Address == NULL)
   {
      va_end(args);
      return *s; // because realloc keeps ptr as it was on fail
   }
   *s = Address; // write potential new address back

   va_start(args, n);

   unsigned int WriteIndex = strlen(*s);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         strcpy(&(Address[WriteIndex]), Arg);
         WriteIndex = WriteIndex + strlen(Arg); 
		}
	}

   va_end(args);

   return Address;
} // >>>

string prependv(string *s, int n, ...) // <<<
{
   va_list args;

   if(s == NULL)
   {
      return NULL;
   }

   if(n == 0u)
   {
      return *s;
   }

   va_start(args, n);

   size_t StrLen = strlen(*s);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         StrLen = StrLen + strlen(Arg);
		}
	}

   StrLen++; // for null terminator

   string Address = (string)realloc(*s, StrLen*sizeof(char));

   if(Address == NULL)
   {
      va_end(args);
      return *s; // because realloc keeps ptr as it was on fail
   }
   *s = Address; // write potential new address back

   string Tmp = str(*s);
   va_start(args, n);

   unsigned int WriteIndex = 0;

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
         strcpy(&(Address[WriteIndex]), Arg);
         WriteIndex = WriteIndex + strlen(Arg); 
		}
	}

   strcpy(&(Address[WriteIndex]), Tmp);

   va_end(args);
   free(Tmp);

   return Address;
} // >>>

// vim: fmr=<<<,>>> fdm=marker
