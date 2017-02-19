#pragma once

//Make sure _WIN32 is a reliable define
#if !defined(_WIN32) && (defined(WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
	#define _WIN32
#endif

#include <stdexcept>

#ifdef _WIN32
#include "window_os_win32_internal.h"
#else
//....
#endif