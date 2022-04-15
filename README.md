# Content
* [About](#about)
* [Overview](#overview)
* [Reference](#reference)
	* [Typedefs](#typedefs)
	* [String Functions](#string-functions)
	* [File Functions](#file-functions)
	* [Terminal Escape Sequences](#terminal-escape-sequences)
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

| Name                | Type                      | Memory    | Description                                                       |
|---------------------|---------------------------|-----------|-------------------------------------------------------------------|
| [str](#str)         | function                  | malloc    | create string from string literal or string "objects"             |
| [strfmt](#strfmt)   | function                  | malloc    | create string from format string                                  |
| [freestr](#freestr) | function wrapping macro   | -         | free allocated memory                                             |
| [len](#len)         | function                  | -         | get string length                                                 |
| [append](#append)   | function wrapping macro   | realloc   | append to string                                                  |
| [prepend](#prepend) | function wrapping macro   | realloc   | prepend to string                                                 |
| [join](#join)       | function wrapping macro   | malloc    | join strings                                                      |
| [glue](#glue)       | function wrapping macro   | malloc    | join strings with a separator string                              |
| [rep](#rep)         | function wrapping macro   | malloc    | repeat string with an optional separator string                   |
| [left](#left)       | function wrapping macro   | malloc    | align string left to width with optional fill character           |
| [center](#center)   | function wrapping macro   | malloc    | center string to width with optional fill character               |
| [right](#right)     | function wrapping macro   | malloc    | align string right to width with optional fill character          |
| [sub](#sub)         | function wrapping macro   | malloc    | get substring                                                     |
| [lower](#lower)     | function                  | -         | convert all characters to lower case                              |
| [upper](#upper)     | function                  | -         | convert all characters to upper case                              |
| [rev](#rev)         | function                  | -         | reverse string                                                    |
| i2s                 | function                  | malloc    | convert signed integer to string                                  |
| u2s                 | function                  | malloc    | convert unsigned integer to string                                |
| f2s                 | function                  | malloc    | convert float to string                                           |
| c2s                 | function                  | malloc    | convert character to string                                       |
| b2s                 | function                  | malloc    | convert boolean to string                                         |
| x2s                 | function                  | malloc    | convert hex value to string                                       |
| p2s                 | function wrapping macro   | malloc    |                                                                   |
| a2s                 | function wrapping macro   | malloc    |                                                                   |
| s2i                 | function wrapping macro   | -         | convert string to integer                                         |
| s2u                 | function wrapping macro   | -         | convert string to unsigned integer                                |
| s2lli               | function wrapping macro   | -         | convert string to long long integer                               |
| s2llu               | function wrapping macro   | -         | convert string to long long unsigned integer                      |
| s2f                 | function wrapping macro   | -         | convert string to float                                           |
| s2d                 | function wrapping macro   | -         | convert string to double                                          |
| s2ld                | function wrapping macro   | -         | convert string to long double                                     |
| print               | function wrapping macro   | -         | print strings                                                     |
| iprint              | function wrapping macro   | -         | print integers                                                    |
| strip               | function wrapping macro   | -         | strip string left and right                                       |
| lstrip              | function wrapping macro   | -         | strip string left                                                 |
| rstrip              | function wrapping macro   | -         | strip string right                                                |
| cindex              | function wrapping macro   | -         | get index of character position in string                         |
| ccount              | function wrapping macro   | -         | count number of given character in string                         |
| creplace            | function wrapping macro   | -         | replace character in string with a given character                |
| hasChar             | comparison wrapping macro | -         | checks if string contains a given character                       |
| hasString           | comparison wrapping macro | -         | checks if string contains a given string                          |
| scount              |                           |           |                                                                   |
| index               |                           |           |                                                                   |
| replace             |                           |           |                                                                   |
| compare             |                           |           |                                                                   |
| find                |                           |           |                                                                   |
| match               |                           |           |                                                                   |
| substitute          |                           |           |                                                                   |
| show                |                           |           | show \n \t ...                                                    |
| protect             |                           |           | make regex safe                                                   |
| split               |                           |           |                                                                   |
|                     |                           |           |                                                                   |


# Reference

## Defines

## Typedefs
### string
`typedef char* string;`

##### Description
Short typedef to hide `char *`.

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
* s - the string from which to create a string "object"
* ... - format string values, sames as for `printf`

##### Return
* string - address of allocated memory

##### Example

      int a = 42;
      string A = strfmt("foo %d bar", a);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### freestr
`#define freestr(...)`

##### Description
free all strings passed as args.

##### Parameters
* ... - 1 or more strings to free

##### Example

      string A = str("foo");
      string B = str("bar");
      free(A,B);
----------------------------------------------------------------------------------------------------
### lower
`string lower(string s)`

##### Description
convert all characters to lower case.

##### Parameters
* s - the string to convert to lower case characters

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
* s - the string to convert to upper case characters

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
* s - the string to reverse

##### Return
* string - address of s

##### Example

      string A = rev("foobar");
      rev(A);
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### len
`size_t len(string s)`

##### Description
get string length.

##### Parameters
* s - the string of which to get the length

##### Return
* size_t - length of s

##### Example

      string A = str("foobar");
      iprint( len(A) );
      free(A);
----------------------------------------------------------------------------------------------------
### append
`#define append(s, ...)`

##### Description
append strings to string.

##### Parameters
* s - the string to which to append
* ... - 1 or more strings to append

##### Return
* string - potential new address of s

##### Example

      string A = str("foobar");
      append(A, "2000", " is da thing");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### prepend
`#define prepend(s, ...)`

##### Description
prepend strings to string.

##### Parameters
* s - the string to which to prepend
* ... - 1 or more strings to prepend

##### Return
* string - potential new address of s

##### Example

      string A = str("foobar");
      prepend(A, "this", " is ");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### join
`#define join(...)`

##### Description
join strings.

##### Parameters
* ... - 1 or more strings to join

##### Return
* string - address of created string

##### Example

      string A = join("this ", "is ", "foobar");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### glue
`#define glue(g, ...)`

##### Description
join strings with a glue string.

##### Parameters
* g - the glue string
* ... - 1 or more strings to glue

##### Return
* string - address of created string

##### Example

      string A = glue(" ", "this", "is", "foobar");
      print(A);
      free(A);
----------------------------------------------------------------------------------------------------
### rep
`#define rep(s, n [,g])`

##### Description
repeat string N times with optional glue string.

##### Parameters
* s - the string to repeat
* n - number of repititions
* g - (optional) glue string

##### Return
* string - address of created string

##### Example

      string A = rep("foo", 3, "_");
      string B = rep("foo", 3);
      print(A, B);
      freestr(A,B);
----------------------------------------------------------------------------------------------------
### left
`#define left(s, w [,f])`

##### Description
create left aligned string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* s - the string to align
* w - width
* f - (optional) fill character, default is space

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
`#define center(s, w [,f])`

##### Description
create centered string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* s - the string to align
* w - width
* f - (optional) fill character, default is space

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
`#define right(s, w [,f])`

##### Description
create right aligned string according to width, with an optional fill character.
if the width is smaller than the string length, then the string gets shortened.

##### Parameters
* s - the string to align
* w - width
* f - (optional) fill character, default is space

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
`#define sub(s, i [,j])`

##### Description
get substring from string starting from index `i` til end of string, or til index `j`.
first index from the left is 1, and -1 from the right.

##### Parameters
* s - the string to align
* i - start index
* j - (optional) end index, default -1

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
### cindex
`size_t int_cindex(string s, char c, signed long long int n, size_t start)`

##### Description
returns the index of a character in a given string.

##### Parameters
* s - the string to search in
* c - the character to search for
* n - (optional) the nth character to search for, default is 1
* start - (optional) the index from where to start the search, default is 0

##### Return
* size_t integer representing the string index (0 based) of the given character.
* returns NO_RESULT when the character was not found.

##### Example 1 - find index of the 3rd 'k'

    string S = str("knockknock");
    printf("index is %lld\n", cindex(S, 'k', 3)); // index is 5
    freestr(S);

----------------------------------------------------------------------------------------------------

## File Functions

## Terminal Escape Sequences

# ToDo
* 216 color names on/off??
* new names for cursor and erase escape sequences
* configurable 1 based indexing for the functions?
* malloc_size in append/prepend printf("%zu\n", malloc_size(A));
* should append use strcat instead of strcpy?
* iterator macro - is it possible?
* should I get rid of join as it is the same as glue("", ...) or keep it for convenience?
* would it be better if append/prepend would use malloc instead of realloc? this would allow literal strings as input, but would force users to store the new string
* should the third sub(s,i,j) parameter be the length instead of the end index?
