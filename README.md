# Content
* [About](#about)
* [Overview](#overview)
* [Reference](#reference)
	* [Defines](#defines)
	* [Typedefs](#typedefs)
	* [String Functions](#string-functions)
	* [File Functions](#file-functions)
* [ToDo](#todo)

# About
Yes, yet another string library. Why? Because the libs I found use structs. I'm a Lua lover and I
tried to create something that reminds me of Lua, but without exaggerating too much, cause I still
want to write C code. This lib is only supposed to take away my pain, and not more.

# Overview
Most functions are actually macros that wrap a function, which allowed me to get optional
parameters. The following table provides this information. You can also see in this table which
functions allocate new memory, which means that you have to store the returned address to be able to
`free()` them later. Some functions work directly on the string and don't allocate or re-allocate memory.
It is also listed if the object of interest is already implemented, tested and documented.

| Name                    | Impl | Test | Doc | Demo | Type                      | Memory    | Description                                                       |
|-------------------------|------|------|-----|------|---------------------------|-----------|-------------------------------------------------------------------|
| [str](#str)             | yes  | no   | yes |      | function                  | malloc    | create string from string literal or string "objects"             |
| [strfmt](#strfmt)       | yes  | no   | yes |      | function                  | malloc    | create string from format string                                  |
| [freestr](#freestr)     | yes  | no   | yes |      | function wrapping macro   | -         | free allocated memory                                             |
| [len](#len)             | yes  | no   | yes |      | function                  | -         | get string length                                                 |
| [append](#append)       | yes  | no   | yes |      | function wrapping macro   | realloc   | append to string                                                  |
| [prepend](#prepend)     | yes  | no   | yes |      | function wrapping macro   | realloc   | prepend to string                                                 |
| [join](#join)           | yes  | no   | yes |      | function wrapping macro   | malloc    | join strings                                                      |
| [glue](#glue)           | yes  | no   | yes |      | function wrapping macro   | malloc    | join strings with a glue string                                   |
| [rep](#rep)             | yes  | no   | yes |      | function wrapping macro   | malloc    | repeat string with an optional separator string                   |
| [left](#left)           | yes  | no   | yes |      | function wrapping macro   | malloc    | align string left to width with optional fill character           |
| [center](#center)       | yes  | no   | yes |      | function wrapping macro   | malloc    | center string to width with optional fill character               |
| [right](#right)         | yes  | no   | yes |      | function wrapping macro   | malloc    | align string right to width with optional fill character          |
| [sub](#sub)             | yes  | no   | yes |      | function wrapping macro   | malloc    | get substring                                                     |
| [lower](#lower)         | yes  | no   | yes |      | function                  | -         | convert all characters to lower case                              |
| [upper](#upper)         | yes  | no   | yes |      | function                  | -         | convert all characters to upper case                              |
| [rev](#rev)             | yes  | no   | yes |      | function                  | -         | reverse string                                                    |
| [strip](#strip)         | yes  | no   | yes |      | function wrapping macro   | -         | strip string left and right                                       |
| [lstrip](#lstrip)       | yes  | no   | yes |      | function wrapping macro   | -         | strip string left                                                 |
| [rstrip](#rstrip)       | yes  | no   | yes |      | function wrapping macro   | -         | strip string right                                                |
| [cindex](#cindex)       | yes  | yes  | no  |      | function wrapping macro   | -         | get index of character position in string                         |
| [ccount](#ccount)       | yes  | yes  | no  |      | function wrapping macro   | -         | count number of given character in string                         |
| [creplace](#creplace)   | yes  | yes  | no  |      | function wrapping macro   | -         | replace character in string with a given character                |
| i2s                     | yes  | no   | no  |      | function                  | malloc    | convert signed integer to string                                  |
| u2s                     | yes  | no   | no  |      | function                  | malloc    | convert unsigned integer to string                                |
| f2s                     | yes  | no   | no  |      | function                  | malloc    | convert float to string                                           |
| c2s                     | yes  | no   | no  |      | function                  | malloc    | convert character to string                                       |
| b2s                     | yes  | no   | no  |      | function                  | malloc    | convert boolean to string                                         |
| x2s                     | yes  | no   | no  |      | function                  | malloc    | convert hex value to string                                       |
| p2s                     | yes  | no   | no  |      | function wrapping macro   | malloc    |                                                                   |
| a2s                     | yes  | no   | no  |      | function wrapping macro   | malloc    | convert address to string                                         |
| s2i                     | yes  | no   | no  |      | function wrapping macro   | -         | convert string to integer                                         |
| s2u                     | yes  | no   | no  |      | function wrapping macro   | -         | convert string to unsigned integer                                |
| s2lli                   | yes  | no   | no  |      | function wrapping macro   | -         | convert string to long long integer                               |
| s2llu                   | yes  | no   | no  |      | function wrapping macro   | -         | convert string to long long unsigned integer                      |
| s2f                     | yes  | no   | no  |      | function wrapping macro   | -         | convert string to float                                           |
| s2d                     | yes  | no   | no  |      | function wrapping macro   | -         | convert string to double                                          |
| s2ld                    | yes  | no   | no  |      | function wrapping macro   | -         | convert string to long double                                     |
| print                   | yes  | no   | no  |      | function wrapping macro   | -         | print strings                                                     |
| iprint                  | yes  | no   | no  |      | function wrapping macro   | -         | print integers                                                    |
| scount                  | no   | no   | no  |      |                           |           |                                                                   |
| index                   | no   | no   | no  |      |                           |           |                                                                   |
| replace                 | no   | no   | no  |      |                           |           |                                                                   |
| compare                 | no   | no   | no  |      |                           |           |                                                                   |
| find                    | no   | no   | no  |      |                           |           |                                                                   |
| match                   | no   | no   | no  |      |                           |           |                                                                   |
| substitute              | no   | no   | no  |      |                           |           |                                                                   |
| show                    | no   | no   | no  |      |                           |           | show \n \t ...                                                    |
| protect                 | no   | no   | no  |      |                           |           | make regex safe                                                   |
| split                   | no   | no   | no  |      |                           |           |                                                                   |
| [hasChar](#haschar)     | yes  | no   | no  |      | comparison wrapping macro | -         | checks if string contains a given character                       |
| [hasString](#hasstring) | yes  | no   | no  |      | comparison wrapping macro | -         | checks if string contains a given string                          |
| cinsert                 | no   | no   | no  |      |                           |           |                                                                   |
| sinsert/insert?         | no   | no   | no  |      |                           |           |                                                                   |
| equal/isequal           | no   | no   | no  |      |                           |           |                                                                   |
| contains/containss      | no   | no   | no  |      |                           |           |                                                                   |
| contains/containsc      | no   | no   | no  |      |                           |           |                                                                   |
| CLR                     | no   | no   | yes |      |                           |           |                                                                   |
| BG_CLR                  | no   | no   | yes |      |                           |           |                                                                   |
| RGB                     | no   | no   | yes |      |                           |           |                                                                   |
| BG_RGB                  | no   | no   | yes |      |                           |           |                                                                   |


# Reference

## Defines

### Escape Sequences

#### Text Attributes

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

#### Predefined Font Colors

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

#### Predefined Background Colors

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

#### Function-like Macros For Font and Background Colors

    #define CLR(v)        "\e[38;5;"#v"m"
    #define BG_CLR(v)     "\e[48;5;"#v"m"
    #define RGB(r,g,b)    "\e[38;2;"#r";"#g";"#b"m"
    #define BG_RGB(r,g,b) "\e[48;2;"#r";"#g";"#b"m"

##### Description

`CLR()` and `BG_CLR()` have to be called with a value between 0 and 255.
The meanings for these values are defined as follows, ...

- 0-7: standard colors (as in 30–37m)
- 8-15: high intensity colors (as in 90–97m)
- 16-231: 6 × 6 × 6 cube (216 colors): 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
- 232-255: grayscale from black to white in 24 steps

`RGB()` and `BG_RGB()` have to be called with 3 values, all between 0 and 255, representing the Red, Green and Blue values of each color.
To learn more about escape sequences ...

- [ANSI_escape_code](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [ansi-escape-sequences-vt-100](http://ascii-table.com/ansi-escape-sequences-vt-100.php)

##### Examples

    printf(CLR(13)"foobar"OFF"\n");
    printf("%sfoobar%s\n", BG_RGB(80,120,200), OFF);
    printf("%sfoobar%s\n", RED UNDERLINE BG_BRTWHITE, OFF);
    string A = str("foobar");
    printf("%s%s%s\n", BG_CLR(58) BOLD, A, OFF);
    free(A);


## Typedefs

### string
`typedef char* string;`

##### Description
Short typedef to hide `char *` and represent a string "object".

## String Functions

----------------------------------------------------------------------------------------------------
### str
`string str(const string s)`

##### Description
create string from string literal or string "objects".

##### Parameters
* s - the string from which to create a string "object"

##### Return
* string - address of allocated memory

##### Example 1 - create string from string literal

    string A = str("foobar");
    print(A)
    free(A);

##### Example 2 - create string from string

    string A = str("foobar");
    string B = str(A);
    print(A, B)
    freestr(A, B);
----------------------------------------------------------------------------------------------------
### strfmt
`string strfmt(const string s, ...)`

##### Description
create string from format string.

##### Parameters
* s - the format string from which to create a string "object"
* ... - format string values, sames as for `printf` & Co.

##### Return
* string - address of allocated memory

##### Example

      int a = 42;
      string A = strfmt("foo %d bar", a);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### freestr
`void freestr(string s1[,s2,..,sN])`

##### Description
free all strings passed as args.

##### Parameters
* string s1..sN - 1 or more strings to free

##### Example

      string A = str("foo");
      string B = str("bar");
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### len
`size_t len(string s)`

##### Description
get string length.

##### Parameters
* string s - the string of which to get the length

##### Return
* size_t - length of s

##### Example

      string A = str("foobar");
      iprint( len(A) );
      free(A);
----------------------------------------------------------------------------------------------------
### append
`string append(string s, string a1[,a2,...,aN])`

##### Description
append strings to string. This wrapper macro uses *call by reference* and `realloc`.

##### Parameters
* string s - the string to which to append
* string a1..aN - 1 or more strings to append

##### Return
* string - potential new address of s

##### Example

      string A = str("foobar");
      append(A, "2000", " is da thing");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### prepend
`string prepend(string s, string p1[,p2,...,pN])`

##### Description
prepend strings to string.

##### Parameters
* string s - the string to which to prepend
* string p1..pN - 1 or more strings to prepend

##### Return
* string - potential new address of s

##### Example

      string A = str("foobar");
      prepend(A, "this", " is ");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### join
`string join(string s1[,s2,..,sN])`

##### Description
join strings.

##### Parameters
* string s1..sN - 1 or more strings to join

##### Return
* string - address of created string

##### Example

      string A = join("this ", "is ", "foobar");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### glue
`string glue(string g, string s1[,s2,..sN])`

##### Description
join strings with a glue string.

##### Parameters
* string g - the glue string
* string s1..sN - 1 or more strings to glue

##### Return
* string - address of created string

##### Example

      string A = glue(" ", "this", "is", "foobar");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### rep
`string rep(string s, unsigned int n [,string g])`

##### Description
repeat string N times with optional glue string.

##### Parameters
* string s - the string to repeat
* unsigned int n - number of repititions
* string g - optional glue string

##### Return
* string - address of created string

##### Example

      string A = rep("foo", 3, "_");
      string B = rep("foo", 3);
      print(A, B);
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### lower
`string lower(string s)`

##### Description
convert all characters to lower case.

##### Parameters
* string s - the string to convert to lower case characters

##### Return
* string - address of s

##### Example

      string A = str("FOOBAR");
      lower(A);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### upper
`string upper(string s)`

##### Description
convert all characters to upper case.

##### Parameters
* string s - the string to convert to upper case characters

##### Return
* string - address of s

##### Example

      string A = str("foobar");
      upper(A);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### rev
`string rev(string s)`

##### Description
reverse string.

##### Parameters
* string s - the string to reverse

##### Return
* string - address of s

##### Example

      string A = rev("foobar");
      rev(A);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### left
`string left(string s, unsigned int w [, char f])`

##### Description
create left aligned string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* string s - the string to align
* unsigned int w - width
* char f - optional fill character, default is space

##### Return
* string - address of created string

##### Example 1 - using a fill character

      string A = left("left aligned", 20, '_');
      print(A);
      free(A);

##### Example 2 - width smaller than string length

      string A = left("left aligned", 10);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### center
`string center(string s, unsigned int w [, char f])`

##### Description
create centered string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* string s - the string to align
* unsigned int w - width
* char f - optional fill character, default is space

##### Return
* string - address of created string

##### Example 1 - using a fill character

      string A = center("centered text", 20, '_');
      print(A);
      free(A);

##### Example 2 - width smaller than string length

      string A = center("centered text", 10);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### right
`string right(string s, unsigned int w [, char f])`

##### Description
create right aligned string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* string s - the string to align
* unsigned int w - width
* char f - optional fill character, default is space

##### Return
* string - address of created string

##### Example 1 - simple right aligned

      string A = right("right aligned", 20);
      print(A);
      free(A);

##### Example 2 - using a fill character

      string A = right("right aligned", 20, '_');
      print(A);
      free(A);

##### Example 3 - width smaller than string length

      string A = right("right aligned", 10);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### sub
`string sub(string s, int i [, int j])`

##### Description
get substring from string starting from index `i` til end of string, or til index `j`.
negative values start counting from end of string. first index from the left is 1, and -1 from the right.

##### Parameters
* string s - the string to align
* int i - start index
* int j - optional end index, default -1

##### Return
* string - address of created string

##### Examples

      string A = sub("foobar2000",1);
      print(A);
      string B = sub("foobar2000",4,6);
      print(B);
      string C = sub("foobar2000",-4);
      print(C);
      string D = sub("foobar2000",2,-6);
      print(D);
      string E = sub("foobar2000",-4,-3);
      print(E);
      freestr(A,B,C,D,E);
----------------------------------------------------------------------------------------------------
### strip
`string strip(string s [, string charlist])`

##### Description
remove set of characters from start and end of the given string.

##### Parameters
* string s - the string to strip from start and end
* string charlist - optional string containing the characters to remove, default is " \t\n\r".

##### Return
* string - address of string

##### Examples

      string A = str("   foobar   \n");
      strip(A);
      print(A);
      string B = str("___foobar___");
      print(strip(B, "_"));
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### lstrip
`string lstrip(string s [, string charlist])`

##### Description
remove set of characters from start of the given string.

##### Parameters
* string s - the string to strip from start
* string charlist - optional string containing the characters to remove, default is " \t\n\r".

##### Return
* string - address of string

##### Examples

      string A = str("   foobar   \n");
      lstrip(A);
      print(A);
      string B = str("___foobar___");
      print(lstrip(B, "_"));
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### rstrip
`string rstrip(string s [, string charlist])`

##### Description
remove set of characters from end of the given string.

##### Parameters
* string s - the string to strip from end
* string charlist - optional string containing the characters to remove, default is " \t\n\r".

##### Return
* string - address of string

##### Examples

      string A = str("   foobar   \n");
      rstrip(A);
      print(A);
      string B = str("___foobar___");
      print(rstrip(B, "_"));
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### cindex
`size_t cindex(string s, char c [, int n, size_t start])`

##### Description
returns the index of a character in a given string.

##### Parameters
* string s - the string to search in
* char c - the character to search for
* int n - optional nth character to search for. Default is 1. Negative values search backwards.
* size_t start - optional index from where to start the search, default is 0 for positive `n` values and end of string for negative `n` values.

##### Return
* size_t integer representing the string index (0 based) of the given character. returns NO_RESULT when the character was not found.

##### Example


----------------------------------------------------------------------------------------------------
### ccount
`size_t ccount(string s, char c [,int start, int end])`

##### Description
counts the number of occurences of a given character in the string.

##### Parameters
* string s - the string to search in
* char c - the character to search for
* int start - optional index from where to start the search
* int end - optional index of search range end

##### Return
* size_t number of occurences.

##### Example

----------------------------------------------------------------------------------------------------
### creplace
`string creplace(string s, char c, char r, [size_t n, int start, int end])`

##### Description

##### Parameters
* string s - the string to search in
* char c - the characters to replace
* char r - the replacement character
* size_t n - optional number of replacements
* int start - optional index from where to start the replacing
* int end - optional index where to end the replacing

##### Return
* size_t number of occurences.

##### Example


----------------------------------------------------------------------------------------------------

## File Functions

# ToDo
* 216 color names on/off??
* should the font colors be called foreground colors and maybe get FG as prefix?
* new names for cursor and erase escape sequences
* configurable 1 based indexing for the functions? or general 0 or 1 based?
* malloc_size in append/prepend printf("%zu\n", malloc_size(A));
* should append use strcat instead of strcpy?
* iterator macro - is it possible?
* should I get rid of join as it is the same as glue("", ...) or keep it for convenience?
* would it be better if append/prepend would use malloc instead of realloc? this would allow literal strings as input, but would force users to store the new string
* should the third sub(s,i,j) parameter be the length instead of the end index?
* rename hasChar/hasString?
* negative values for start/end in creplace,...
* creplace, should n==0 mean replace none, or all? and maybe -1 all?
