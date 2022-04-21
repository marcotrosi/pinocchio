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

string i2s(signed long long int x) // <<<
{
   string Buffer = (string)malloc(BUFFERSIZE*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, BUFFERSIZE, "%lld", x);

   return Buffer;
} // >>>

string u2s(unsigned long long int x) // <<<
{
   string Buffer = (string)malloc(BUFFERSIZE*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, BUFFERSIZE, "%llu", x);

   return Buffer;
} // >>>

string f2s(long double x) // <<<
{
   string Buffer = (string)malloc(BUFFERSIZE*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, BUFFERSIZE, "%LF", x);

   return Buffer;
} // >>>

string c2s(char x) // <<<
{
   string Buffer = (string)malloc(2*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, 2, "%c", x);

   return Buffer;
} // >>>

string b2s(bool x) // <<<
{
   string Buffer = (string)malloc(6*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, 6, "%s", (x)?"true":"false");

   return Buffer;
} // >>>

string x2s(long long int x) // <<<
{
   string Buffer = (string)malloc(20*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, 20, "0x%llX", x);

   return Buffer;
} // >>>


// internal functions used by macros
void int_freestr(int n, ...) // <<<
{
   va_list args;

   va_start(args, n);

	for(int i=0; i < n; i++)
	{
      char *Arg = va_arg(args, char *);

		if(Arg != NULL)
		{
			free(Arg);
		}
	}

   va_end(args);
} // >>>

void int_print(int n, ...) // <<<
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

void int_iprint(int n, ...) // <<<
{
   va_list args;

   va_start(args, n);

	for(int i=0; i < n; i++)
	{
      signed int Arg = va_arg(args, signed int);

      printf("%d", Arg);

      if(i != (n-1))
      {
         printf("\t");
      }
	}

   va_end(args);

   printf("\n");
} // >>>

string int_join(int n, ...) // <<<
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

string int_glue(char *g, int n, ...) // <<<
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

string int_rep(string s, unsigned int n, string g) // <<<
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

string int_append(string *s, int n, ...) // <<<
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

string int_prepend(string *s, int n, ...) // <<<
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

string int_sub(string s, int i, int j) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s);

   int L = 0;
   int R = 0;

   /*
  -9-8-7-6-5-4-3-2-1   neg i and j
   1 2 3 4 5 6 7 8 9   pos i and j

   a b c d e f g h i   StrLen = 9

   0 1 2 3 4 5 6 7 8   array index
   */

   if( i < 0 )
   {
      L = StrLen + i + 1;
   }
   else
   {
      L = i;
   }

   if( j < 0 )
   {
      R = StrLen + j + 1;
   }
   else
   {
      R = j;
   }

   if( L < 1 )
   {
      L = 1;
   }

   if( R > StrLen )
   {
      R = StrLen;
   }

   string Address = NULL;

   if( L > R )
   {
      Address = (string)malloc(sizeof(char));
      if(Address == NULL)
      {
         return NULL;
      }
      Address[0] = '\0';
      return Address;
   }

   Address = (string)malloc(((R-L)+2)*sizeof(char));
   if(Address == NULL)
   {
      return NULL;
   }

   int WriteIndex = 0;
   L--;
   R--;

   for(int ReadIndex=L; ReadIndex <= R; ReadIndex++)
   {
      Address[WriteIndex] = s[ReadIndex];
      WriteIndex++;
   }

   Address[WriteIndex] = '\0';

   return Address;
} // >>>

string int_center(string s, unsigned int width, char c) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   string Address = (string)malloc((width+1)*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s);

   if( width <= StrLen )
   {
       strncpy(Address, s, width);
       return Address;
   }

   unsigned int LPad = (width - StrLen)/2u;
   unsigned int RPad = width - StrLen - LPad;

   for(int i=0; i < LPad ; i++)
   {
      Address[i] = c;
   }

   strcpy(&(Address[LPad]), s);

   for(int i=0; i < RPad ; i++)
   {
      Address[LPad+StrLen+i] = c;
   }

   Address[width] = '\0';

   return Address;
} // >>>

string int_left(string s, unsigned int width, char c) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   string Address = (string)malloc((width+1)*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s);

   if( width <= StrLen )
   {
       strncpy(Address, s, width);
       return Address;
   }

   strcpy(Address, s);

   for(int i=StrLen; i < width ; i++)
   {
      Address[i] = c;
   }

   Address[width] = '\0';

   return Address;
} // >>>

string int_right(string s, unsigned int width, char c) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   string Address = (string)malloc((width+1)*sizeof(char));

   if(Address == NULL)
   {
      return NULL;
   }

   size_t StrLen = strlen(s);

   if( width <= StrLen )
   {
       strncpy(Address, &(s[StrLen-width]), width);
       return Address;
   }

   unsigned int LPad = width - StrLen;

   for(int i=0; i < LPad ; i++)
   {
      Address[i] = c;
   }

   strcpy(&(Address[LPad]), s);

   Address[width] = '\0';

   return Address;
} // >>>

string int_a2s(void *x) // <<<
{
   string Buffer = (string)malloc(20*sizeof(char));

   if(Buffer == NULL)
   {
      return NULL;
   }

   snprintf(Buffer, 20, "%p", x);

   return Buffer;
} // >>>

string int_strip(string s, char side, string charlist) // <<<
{
   if(s == NULL)
   {
      return NULL;
   }

   if(charlist == NULL)
   {
      return s;
   }

   size_t StrLen  = strlen(s);
   size_t StrLenCL = strlen(charlist);

   if((StrLen == 0) || (StrLenCL == 0))
   {
      return s;
   }

   // strip right
   if((side == 'b') || (side == 'r'))
   {
      for(int i=StrLen-1; i >=0 ; i--)
      {
         if( hasChar(charlist, s[i]) )
         {
            s[i] = '\0';
         }
         else
         {
            break;
         }
      }
   }

   // strip left
   if((side == 'b') || (side == 'l'))
   {
      int WrIdx = 0;
      bool StopStripping = false;
      for(int RdIdx=0; s[RdIdx] != '\0'; RdIdx++)
      {
         s[WrIdx] = s[RdIdx];

         if(StopStripping)
         {
            WrIdx++;
         }
         else if( ! hasChar(charlist, s[RdIdx]))
         {
            WrIdx++;
            StopStripping = true;
         }
      }
      s[WrIdx] = '\0';
   }

   return s;

} // >>>

size_t int_cindex(string s, char c, int n, size_t start) // <<<
{
   size_t Cnt = 0; // match counter

   if(s==NULL)
   {
      return NO_RESULT;
   }

   if(n==0)
   {
      return NO_RESULT;
   }

   size_t StrLen = strlen(s);

   if(start >= StrLen)
   {
      start = StrLen;
   }

   if(n>0) // TODO maybe reduce to 1 for-loop
   {
      for(size_t i=start; i <= StrLen; i++)
      {
         if(s[i] == c)
         {
            Cnt++;
            if(Cnt == n)
            {
               return i;
            }
         }
      }
   }
   else
   {
      for(size_t i=start; i >= 0; i--)
      {
         if(s[i] == c)
         {
            Cnt++;
            if(Cnt == -(n))
            {
               return i;
            }
         }
      }
   }

   return NO_RESULT;
} // >>>

size_t int_ccount(string s, char c, size_t start, size_t end) // <<<
{
   size_t Cnt=0u;

   if(s==NULL)
   {
      return Cnt;
   }

   size_t StrLen = strlen(s);

   if(end >= StrLen)
   {
      end = StrLen;
   }

   for(size_t i=start; i <= end; i++)
   {
      if(s[i] == c)
      {
         Cnt++;
      }
   }

   return Cnt;
} // >>>

string int_creplace(string s, char c, char r, size_t n, size_t start, size_t end) // <<<
{
   size_t Cnt=0u;

   if(s==NULL)
   {
      return s;
   }

   size_t StrLen = strlen(s);

   if(end >= StrLen)
   {
      end = StrLen;
   }

   for(size_t i=start; i <= end; i++)
   {
      if(s[i] == c)
      {
         s[i] = r;
         Cnt++;
      }

      if((n != 0) && (Cnt == n))
      {
         break;
      }
   }

   return s;
} // >>>

size_t int_scount(string s, string ss/*, size_t start, size_t end*/) // <<<
{
   size_t Cnt=0u;
   string Next  = NULL;
   string Start = NULL;

   size_t StrLen  = strlen(s);
   size_t SStrLen = strlen(ss);

   if((s==NULL) | (ss==NULL) | (StrLen==0) | (SStrLen==0))
   {
      return Cnt;
   }

   /*
   if(end >= StrLen)
   {
      end = StrLen;
   }
   */

   /* Next = s+start; */
   Next = s;
   while(1)
   {
      Start = strstr(Next, ss);
      if( Start != NULL )
      {
         Cnt++;
         Next = Start + SStrLen;
      }
      else
      {
         break;
      }
   }

   return Cnt;
} // >>>

// vim: fmr=<<<,>>> fdm=marker
