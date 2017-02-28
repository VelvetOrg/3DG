#include "debug.h"

#include <stdio.h>
#include <stdlib.h>

namespace Debug
{
	void FatalError(GE_STR data, GE_UINT errorCode, GE_STR errorString)
	{
		printf("%s\n", data);
		getchar();
		
		exit(errorCode);
	};

	void Warning(GE_STR data, GE_STR warningString) { printf("%s %s\n", warningString, data); };
	void Error(GE_STR data, GE_STR errorString) { printf("%s %s\n", errorString, data); };
	void Print(GE_STR data, GE_STR end) { printf("%s%s", data, end); };
};