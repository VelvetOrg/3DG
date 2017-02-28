#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>

#include "types.h"
#include "str.h"

//Allows for a file stream to be sent data to
//Wrapper for C FILE*
//TODO: Make this structure versatile
class OutputFile
{
private:
	//Make the copy-constructor illegal!
	//Super pro technique
	OutputFile(const OutputFile& cpy) { };

public:
	//Interacting with the file stream
	OutputFile(GE_STR filepath);
	~OutputFile(); //Important, the file should close even if something goes wrong with the program

	void Close();

	void Write(GE_STR text); //Just write the string as is into the file
	void WriteC(GE_CHAR text); //Write a single char into the file
	void WriteLine(GE_STR text, GE_CHAR end = GE_STR_LITERAL_NEWLINE); //Adds a new line or escape char at the end
	
	//Formatted writing
	void WriteF(GE_STR format, ...) { } //TODO: IF YOU DO THIS YOU ARE OFFICIALLY A GOD

	//Statics

	//Gets the number of LogFiles's open at once
	static GE_BYTE GetOpenFileCount();

	//Getter
	GE_STR GetPath() const;
private:

	//Just wrapping around this stuff
	GE_STR _path = nullptr;
	FILE* _file = nullptr;

	//We need to keep track of how many LogFile instances are open at once
	static GE_BYTE _activeOpenFiles;
};

#endif // !_FILE_H