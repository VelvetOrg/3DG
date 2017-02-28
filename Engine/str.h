#ifndef _STR_H
#define _STR_H

#include "types.h"

//Apparently more convenient
#define GE_STR_LITERAL_CARRIAGE_RETURN '\r'
#define GE_STR_LITERAL_HORIZONTALTAB '\t'
#define GE_STR_LITERAL_SINGLE_QUOTE '\''
#define GE_STR_LITERAL_DOUBLE_QUOTE '\"'
#define GE_STR_LITERAL_VERTICALTAB '\v'
#define GE_STR_LITERAL_BACKSPACE '\b'
#define GE_STR_LITERAL_FORM_FEED '\f'
#define GE_STR_LITERAL_BACKSLASH '\\'
#define GE_STR_LITERAL_NEWLINE '\n'
#define GE_STR_LITERAL_ALERT '\a'
#define GE_STR_LITERAL_NULL '\0'

//TODO: implemented a string class using a Trie structure

namespace Str
{
	//String to int conversion
	//TODO: implement custom solution
	extern void IntToStr(GE_INT i, GE_CHAR* buffer, GE_USHORT bufferLength);
	extern void FloatToStr(GE_FLOAT f, GE_CHAR* buffer, GE_USHORT bufferLength);
}

#endif