#include "str.h"

#include <stdio.h>

//String to int conversion
namespace Str
{
	void IntToStr(GE_INT i, GE_CHAR* buffer, GE_USHORT bufferLength)
	{
		sprintf_s(buffer, bufferLength, "%d", i);
	}

	void FloatToStr(GE_FLOAT f, GE_CHAR* buffer, GE_USHORT bufferLength)
	{
		sprintf_s(buffer, bufferLength, "%f", f);
	}
}