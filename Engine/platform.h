#ifndef _WINDOW_MANAGER_H
#define _WINDOW_MANAGER_H

//Core logic found here: http://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor
/*
OS_WINDOWS		> Windows
OS_WINDOWS64	> Windows 64 bit
OS_WINDOWS32	> Window 32 bit (possibly 16 bit)

OS_APPLE		> Some kind of apple platform
OS_IOS_SIMULATOR> Running an IOS simulator
OS_IOS			> IOS install or IOS simulator
OS_MACOS		> An mac platform, most likely OSX
OS_OSX			> An mac platform, most likely OSX
OS_APPLE_UNKNOWN> Some unknown apple platform

OS_ANDROID		> Android phone OS
OS_LINUX		> Running the Linux kernel
OS_UNIX			> Unix based OS
OS_UNIX_STYLE	> 99% sure it's a Unix based OS
OS_POSIX		> POSIX based Linux
OS_UNKNOWN		> Some autistic OS
OS_BSD			> Berkeley Software Distribution
*/

#if !defined(_WIN32) && (defined(WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
	#define _WIN32
#endif

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#define OS_UNIX_STYLE
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
	#include <sys/param.h>
	#if defined(BSD)
		#define OS_BSD
	#endif
#endif

#ifdef _WIN32
	#define OS_WINDOWS
	#ifdef _WIN64
		#define OS_WINDOWS64
	#else
		#define OS_WINDOWS32
	#endif // _WIN64

#elif __APPLE__
	#define OS_APPLE

	//https://opensource.apple.com/source/CarbonHeaders/CarbonHeaders-18.1/TargetConditionals.h
	#include "TargetConditionals.h"

	#if TARGET_IPHONE_SIMULATOR
		#define OS_IOS_SIMULATOR
		#define OS_IOS
	#elif TARGET_OS_IPHONE
		#define OS_IOS
	#elif TARGET_OS_MAC
		#define OS_MACOS
		#define OS_OSX
	#else
		#define OS_APPLE_UNKNOWN
	#endif
#elif defined(__ANDROID__)
	#define OS_ANDROID
#elif __linux__
	#define OS_LINUX
#elif __unix__
	#define OS_UNIX
#elif defined(_POSIX_VERSION)
	#define OS_POSIX
#else
	#define OS_UNKNOWN
#endif


//Use an ID based system, this allows for template specialization based platform code
#define OS_ID_UNKNOWN	0
#define OS_ID_WINDOWS	1
#define OS_ID_OSX		2
#define OS_ID_LINUX		3
#define OS_ID_IOS		4
#define OS_ID_ANDROID	5
//Will add more later...

#ifdef OS_WINDOWS
	#define OS_ID OS_ID_WINDOWS
#elif defined(OS_APPLE) && !defined(OS_IOS)
	#define OS_ID OS_ID_OSX
#elif defined(OS_ANDROID)
	#define OS_ID OS_ID_ANDROID
#elif defined(OS_LINUX)
	#define OS_ID OS_ID_LINUX
#elif defined(OS_IOS) || defined(OS_IOS_SIMULATOR)
	#define OS_ID OS_ID_IOS
#else
	#define OS_ID OS_ID_UNKNOWN
#endif

#endif // !_WINDOW_MANAGER_H