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
parameters. The following table also provides this information. You can also see in this table which
functions allocate new memory, means that you have to store the returned address to be able to
free() them later. Some functions work directly on the string and don't allocate or re-allocate
memory.

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

