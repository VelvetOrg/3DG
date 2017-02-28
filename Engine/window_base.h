#ifndef _WINDOW_BASE_H
#define _WINDOW_BASE_H

#include "types.h"
#include "platform.h"



//Using a bit-shift-able model to allow multiple styles to be combined together
//This does not use all styles in AINPI, rather ones useful to a game engine
enum Styles
{

};

//Currently just the OS dependent windows implementation
class Window
{
public:
	Window(GE_USHORT width, GE_USHORT height, GE_STR title);
	Window(const Window& cpy); //Implements a deep copy constructor
	~Window();

	void Create();
	void Destroy();

	//Getters and setters
	GE_STR GetTitle() const;
	GE_SHORT GetWidth() const;
	GE_SHORT GetHeight() const;

private:
	GE_STR _title;
	GE_SHORT _width;
	GE_SHORT _height;

	//Window setting make take two forms:
	enum _WindowSettingsStates { Instantiated=0, Initialized=1 };

	//OS variables
	//TODO: use a packed struct for this

	/* HINSTANCE */ GE_VOIDP _hinstance = nullptr;	//Stores the programs ID in the OS
	/* HWND */		GE_VOIDP _handle = nullptr;		//Stores the created win32 window context
};

#endif // !_WINDOW_BASE_H