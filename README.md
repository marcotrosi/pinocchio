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
want to write C code. This lib is only supposed to take away my pain, not more.

# Overview
Most functions are actually macros that wrap a function, which allowed me to get optional
parameters. The following table provides this information. You can also see in this table which
functions allocate new memory, means that you have to store the returned address to be able to
`free()` them later. Some functions work directly on the string and don't allocate or re-allocate
memory.

| Name           | Type                      | Memory    | Description                                                       |
|----------------|---------------------------|-----------|-------------------------------------------------------------------|
| str            | function                  | malloc    | create string from string literal                                 |
| strfmt         | function                  | malloc    | create string from format string                                  |
| i2s            | function                  | malloc    | convert signed integer to string                                  |
| u2s            | function                  | malloc    | convert unsigned integer to string                                |
| f2s            | function                  | malloc    | convert float to string                                           |
| c2s            | function                  | malloc    | convert character to string                                       |
| b2s            | function                  | malloc    | convert boolean to string                                         |
| x2s            | function                  | malloc    | convert hex value to string                                       |
| lower          | function                  | -         | convert all characters to lower case                              |
| upper          | function                  | -         | convert all characters to upper case                              |
| rev            | function                  | -         | reverse string                                                    |
| len            | function                  | -         | get string length                                                 |
| freestr        | function wrapping macro   | -         | free memory                                                       |
| print          | function wrapping macro   | -         | print strings                                                     |
| iprint         | function wrapping macro   | -         | print integers                                                    |
| join           | function wrapping macro   | malloc    | join strings                                                      |
| glue           | function wrapping macro   | malloc    | join strings with a separator string                              |
| rep            | function wrapping macro   | malloc    | repeat string with an optional separator string                   |
| append         | function wrapping macro   | realloc   | append to string                                                  |
| prepend        | function wrapping macro   | realloc   | prepend to string                                                 |
| sub            | function wrapping macro   | malloc    | get substring                                                     |
| center         | function wrapping macro   | malloc    | center string to width with optional fill character               |
| left           | function wrapping macro   | malloc    | align string left to width with optional fill character           |
| right          | function wrapping macro   | malloc    | align string right to width with optional fill character          |
| strip          | function wrapping macro   | -         | strip string left and right                                       |
| lstrip         | function wrapping macro   | -         | strip string left                                                 |
| rstrip         | function wrapping macro   | -         | strip string right                                                |
| cindex         | function wrapping macro   | -         | get index of character position in string                         |
| ccount         | function wrapping macro   | -         | count number of given character in string                         |
| creplace       | function wrapping macro   | -         | replace character in string with a given character                |
| p2s            | function wrapping macro   | malloc    |                                                                   |
| a2s            | function wrapping macro   | malloc    |                                                                   |
| s2i            | function wrapping macro   | -         | convert string to integer                                         |
| s2u            | function wrapping macro   | -         | convert string to unsigned integer                                |
| s2lli          | function wrapping macro   | -         | convert string to long long integer                               |
| s2llu          | function wrapping macro   | -         | convert string to long long unsigned integer                      |
| s2f            | function wrapping macro   | -         | convert string to float                                           |
| s2d            | function wrapping macro   | -         | convert string to double                                          |
| s2ld           | function wrapping macro   | -         | convert string to long double                                     |
| hasChar        | comparison wrapping macro | -         | checks if string contains a given character                       |
| hasString      | comparison wrapping macro | -         | checks if string contains a given string                          |
| scount         |                           |           |                                                                   |
| index          |                           |           |                                                                   |
| replace        |                           |           |                                                                   |
| compare        |                           |           |                                                                   |
| find           |                           |           |                                                                   |
| match          |                           |           |                                                                   |
| substitute     |                           |           |                                                                   |
| show           |                           |           | show \n \t ...                                                    |
| protect        |                           |           | make regex safe                                                   |
| split          |                           |           |                                                                   |
|                |                           |           |                                                                   |


# Reference

## Defines

## Typedefs

## String Functions

----------------------------------------------------------------------------------------------------
### cindex
##### Description
`cindex` returns the index of a character in a given string.

`size_t int_cindex(string s, char c, signed long long int n, size_t start)`

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
### cindex
##### Description
`ccount` returns the index of a character in a given string.

`size_t int_ccount(string s, char c, size_t start, size_t end)`

##### Parameters
* s - the string to search in
* c - the character to search for
* start - (optional) the index from where to start the search, default is 0
* end - (optional) the nth character to search for, default is 1

##### Return

##### Example

    string S = str("knockknock");
    printf("%s has k at index %lld\n", S, cindex(S, 'k', 1));
    freestr(S);

## File Functions

## Terminal Escape Sequences

# ToDo
* 216 color names on/off??
* new names for cursor and erase escape sequences
* configurable 1 based indexing for the functions?
* malloc_size in append/prepend printf("%zu\n", malloc_size(A));
* should append use strcat instead of strcpy?
* iterator macro - is it possible?
