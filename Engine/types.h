#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h> //Would prefer if this wasn't included but, eh

//Standard type wrappers
typedef void			GE_VOID;
typedef void*			GE_VOIDP;
typedef float			GE_FLOAT;
typedef double			GE_DOUBLE;
typedef signed int		GE_INT;
typedef long int		GE_LONG;
typedef short int		GE_SHORT;
typedef unsigned int	GE_UINT;
typedef unsigned long int GE_ULONG;
typedef unsigned short int GE_USHORT;

//Fixed width integers
//TODO: Create wide int without cstdint.h
typedef uint8_t		GE_BYTE;
typedef uint32_t	GE_DWORD;
typedef uint16_t	GE_WORD;
typedef intmax_t	GE_INTMAX;
typedef uintmax_t	GE_UINTMAX;

typedef uint8_t		GE_UINT8;
typedef uint16_t	GE_UINT16;
typedef uint32_t	GE_UINT32;
typedef uint64_t	GE_UINT64;

typedef int8_t		GE_INT8;
typedef int16_t		GE_INT16;
typedef int32_t		GE_INT32;
typedef int64_t		GE_INT64;

//Char stuff
typedef char				GE_CHAR;
typedef wchar_t				GE_WCHAR;
typedef const char			GE_CCHAR;
typedef const wchar_t		GE_CWCHAR;
typedef unsigned char		GE_UCHAR;
typedef const unsigned char	GE_CUCHAR;

typedef const char* GE_STR;
typedef const wchar_t* GE_WSTR;

//Add booleans to C99
typedef unsigned char GE_BOOL; //Later bit packing will be used

#define GE_TRUE	 1
#define GE_FALSE 0

//Added this macro to help me out
#define DELETE(n) \
	delete n;	  \
	n = nullptr;  \

#define DELETE_ARR(n) \
	delete[] n;	  \
	n = nullptr;  \

#endif // !_TYPES_H