#pragma once
#include <iostream>

#define GE_FATAL_ERROR_STRING "Fatal error "
#define GE_WARNING_STRING "Warning "
#define GE_ERROR_STRING "Error "

//Later this will use std::ostream - temporary
namespace Debug
{
	template<typename T> inline void FatalError(T text, int code=1, const char* errString=GE_FATAL_ERROR_STRING) 
	{ 
		std::cerr << errString << text << std::endl;
		
		getchar();
		exit(code);
	}

	template<typename T> inline void Error(T text, const char* errString=GE_ERROR_STRING)
	{
		std::cerr << errString << text << std::endl;
	}

	template<typename T> inline void Warning(T text, const char* warnString=GE_WARNING_STRING) { std::cout << warnString << text << std::endl; }
	template<typename T> inline void Log(T text, const char* end = "\n") { std::cout << text << end; }
}