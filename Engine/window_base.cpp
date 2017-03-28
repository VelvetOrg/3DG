#include "window_base.h"
/*
#include "debug.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

//Defining window styles
//TODO: make platform independent
#define GE_WIN_STYLE_ACCEPT_FILES 0x00000010L
#define GE_WIN_STYLE_APPWINDOW 0x00040000L
#define GE_WIN_STYLE_CLIENTEDGE 0x00000200L
#define GE_WIN_STYLE_COMPOSITED 0x02000000L
#define GE_WIN_STYLE_CONTEXTHELP 0x00000400
#define GE_WIN_STYLE_CONTROLPARENT 0x00010000L
#define GE_WIN_STYLE_DLGMODALFRAME 0x00000001L
#define GE_WIN_STYLE_LAYERED 0x00080000
#define GE_WIN_STYLE_LAYOUTRTL 0x00400000L
#define GE_WIN_STYLE_LEFT 0x00000000L
#define GE_WIN_STYLE_LEFTSCROLLBAR 0x00004000L
#define GE_WIN_STYLE_LTRREADING 0x00000000L
#define GE_WIN_STYLE_MDICHILD 0x00000040L
#define GE_WIN_STYLE_NOACTIVATE 0x08000000L
#define GE_WIN_STYLE_NOINHERITLAYOUT 0x00100000L
#define GE_WIN_STYLE_NOPARENTNOTIFY 0x00000004L
#define GE_WIN_STYLE_NOREDIRECTIONBITMAP 0x00200000L
#define GE_WIN_STYLE_RIGHT 0x00001000L
#define GE_WIN_STYLE_RIGHTSCROLLBAR 0x00000000L
#define GE_WIN_STYLE_RTLREADING 0x00002000L
#define GE_WIN_STYLE_STATICEDGE 0x00020000L
#define GE_WIN_STYLE_TOOLWINDOW 0x00000080L
#define GE_WIN_STYLE_TOPMOST 0x00000008L
#define GE_WIN_STYLE_TRANSPARENT 0x00000020L
#define GE_WIN_STYLE_WINDOWEDGE 0x00000100L
#define GE_WIN_STYLE_OVERLAPPEDWINDOW (GE_WIN_STYLE_WINDOWEDGE | GE_WIN_STYLE_CLIENTEDGE)
#define GE_WIN_STYLE_PALETTEWINDOW (GE_WIN_STYLE_WINDOWEDGE | GE_WIN_STYLE_TOOLWINDOW | GE_WIN_STYLE_TOPMOST)

#include <windows.h> //Evil include

//Default properties of a window
#define GE_WIN_WINDOW_CLASS_NAME L"wnd"
#define GE_WIN_REGCLASS_BAD_STR "Could not register the window class"
#define GE_WIN_REGCLASS_BAD NULL

// ~ Implementation for the OS independent window model ~
Window::Window(GE_USHORT width, GE_USHORT height, GE_STR title)
{
	_width = width;
	_height = height;
	_title = title;

	//Determine the programs instance
	_hinstance = static_cast<GE_VOIDP>(GetModuleHandle(NULL));

	//Create the window data class
	WNDCLASS _windowContainer = {};

	_windowContainer.lpfnWndProc = nullptr; //TODO: implement window callback
	_windowContainer.lpszClassName = GE_WIN_WINDOW_CLASS_NAME;
	_windowContainer.hInstance = static_cast<HINSTANCE>(_hinstance);

	if (RegisterClass(&_windowContainer) == GE_WIN_REGCLASS_BAD)
	{ Debug::FatalError(GE_WIN_REGCLASS_BAD_STR); }

	return;
};

//TODO: Implement destructor and deep copy constructor
Window::Window(const Window& cpy) { return; }
Window::~Window() { return; };

void Window::Create()
{
	//Create the window, via WINAPI function call
	/* Legal since:

		typedef HANDLE HWND
		typedef VOIDP HANDLE
		typedef void* VOIDP
		typedef void* GE_VOIDP

		thus GE_VOIDP == HWND;
	//

	_handle = CreateWindowEx(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	
};
void Window::Destroy() { Debug::FatalError("Unknown operating system"); };

GE_SHORT Window::GetHeight() const { return this->_height; };
GE_SHORT Window::GetWidth() const { return this->_width; };
GE_STR Window::GetTitle() const { return this->_title; };
*/