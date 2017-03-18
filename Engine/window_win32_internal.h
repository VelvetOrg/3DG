#ifndef _WINDOW_WIN32_INTERNAL_H
#define _WINDOW_WIN32_INTERNAL_H

/*
#include <windows.h> //Need a cleaner way, don't just include all of it cunt

//Literally all crap code that needs to be rewritten
namespace
{
	LRESULT CALLBACK windowsCallback(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
	{
		LRESULT ret = NULL;

		if (message == WM_DESTROY || message == WM_CLOSE) { OutputDebugStringA("Closed"); } //Window closed
		else if (message == WM_ACTIVATEAPP) { OutputDebugStringA("Active"); } //Window is focused
		
		ret = DefWindowProcA(window, message, wparam, lparam);
		return ret;
	}

	void InstantiateWindow()
	{
		WNDCLASS window = {};

		window.style = CS_OWNDC; //Don't bother getting and releasing window dc
		window.hInstance = GetModuleHandle(NULL);
		window.lpfnWndProc = windowsCallback;
		window.lpszClassName = (LPCWSTR)"Title";

		if (!RegisterClass(&window)) { OutputDebugStringA("Could not register window"); }
		else
		{
			HWND windowHandle = CreateWindowEx(
				NULL,
				window.lpszClassName,
				(LPCWSTR)"Name",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				NULL,
				NULL, 
				GetModuleHandle(NULL),
				NULL);

			if (windowHandle)
			{
				MSG message;
				for (;;)
				{
					BOOL result = GetMessage(&message, 0, 0, 0);
					if (result > 0)
					{
						TranslateMessage(&message);
						DispatchMessage(&message);
					}
					else { break; }
				}
			}
		}
	}
}
*/
#endif // !_WINDOW_WIN32_INTERNAL_H
