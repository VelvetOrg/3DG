#ifndef _WINDOW_MANAGER_H
#define _WINDOW_MANAGER_H

//Core logic found here: http://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor
/*
GE_OS_WINDOWS		> Windows
GE_OS_WINDOWS64		> Windows 64 bit
GE_OS_WINDOWS32		> Window 32 bit (possibly 16 bit)

GE_OS_APPLE			> Some kind of apple platform
GE_OS_IOS_SIMULATOR	> Running an IOS simulator
GE_OS_IOS			> IOS install or IOS simulator
GE_OS_MACOS			> An mac platform, most likely OSX
GE_OS_OSX			> An mac platform, most likely OSX
GE_OS_APPLE_UNKNOWN	> Some unknown apple platform

GE_OS_ANDROID		> Android phone OS
GE_OS_LINUX			> Running the Linux kernel
GE_OS_UNIX			> Unix based OS
GE_OS_UNIX_STYLE	> 99% sure it's a Unix based OS
GE_OS_POSIX			> POSIX based Linux
GE_OS_UNKNOWN		> Some autistic OS
GE_OS_BSD			> Berkeley Software Distribution
*/

#if !defined(_WIN32) && (defined(WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
	#define _WIN32
#endif

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#define GE_OS_UNIX_STYLE
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
	#include <sys/param.h>
	#if defined(BSD)
		#define GE_OS_BSD
	#endif
#endif

#ifdef _WIN32
	#define GE_OS_WINDOWS
	#ifdef _WIN64
		#define GE_OS_WINDOWS64
	#else
		#define GE_OS_WINDOWS32
	#endif // _WIN64

#elif __APPLE__
	#define GE_OS_APPLE

	//https://opensource.apple.com/source/CarbonHeaders/CarbonHeaders-18.1/TargetConditionals.h
	#include "TargetConditionals.h"

	#if TARGET_IPHONE_SIMULATOR
		#define GE_OS_IOS_SIMULATOR
		#define GE_OS_IOS
	#elif TARGET_OS_IPHONE
		#define GE_OS_IOS
	#elif TARGET_OS_MAC
		#define GE_OS_MACOS
		#define GE_OS_OSX
	#else
		#define GE_OS_APPLE_UNKNOWN
	#endif
#elif defined(__ANDROID__)
	#define GE_OS_ANDROID
#elif __linux__
	#define GE_OS_LINUX
#elif __unix__
	#define GE_OS_UNIX
#elif defined(_POSIX_VERSION)
	#define GE_OS_POSIX
#else
	#define GE_OS_UNKNOWN
#endif


//Use an ID based system, this allows for template specialization based platform code
#define GE_OS_ID_UNKNOWN	0
#define GE_OS_ID_WINDOWS	1
#define GE_OS_ID_OSX		2
#define GE_OS_ID_LINUX		3
#define GE_OS_ID_IOS		4
#define GE_OS_ID_ANDROID	5
//Will add more later...

#ifdef GE_OS_WINDOWS
	#define GE_OS_ID GE_OS_ID_WINDOWS
#elif defined(GE_OS_APPLE) && !defined(GE_OS_IOS)
	#define GE_OS_ID GE_OS_ID_OSX
#elif defined(GE_OS_ANDROID)
	#define GE_OS_ID GE_OS_ID_ANDROID
#elif defined(GE_OS_LINUX)
	#define GE_OS_ID GE_OS_ID_LINUX
#elif defined(GE_OS_IOS) || defined(GE_OS_IOS_SIMULATOR)
	#define GE_OS_ID GE_OS_ID_IOS
#else
	#define GE_OS_ID GE_OS_ID_UNKNOWN
#endif

#endif // !_WINDOW_MANAGER_H