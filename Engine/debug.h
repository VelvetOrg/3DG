#ifndef _DEBUG_H
#define _DEBUG_H

#include "types.h"
//#include "logging.h"

#define GE_DEBUG_FATAL_ERROR_STRING "Fatal error"
#define GE_DEBUG_WARNING_STRING "Warning"
#define GE_DEBUG_ERROR_STRING "Error"

//Declare debugging function - simple
//TODO: Templates/PRINTF w/ and in program console & file logging
namespace Debug
{
	//Logs the error, then exits the program with the error code.
	void FatalError(GE_STR data, GE_UINT errorCode = 1, 
		GE_STR errorString = GE_DEBUG_FATAL_ERROR_STRING);

	//Logs the error, but continues running
	void Error(GE_STR data, GE_STR errorString = GE_DEBUG_ERROR_STRING);

	//Logs warning
	void Warning(GE_STR data, GE_STR warningString = GE_DEBUG_WARNING_STRING);

	//Push data to the console
	void Print(GE_STR data, GE_STR end = "\n");
};

#endif // !_DEBUG_H