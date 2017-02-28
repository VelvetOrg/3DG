#ifndef _LOGGING_H
#define _LOGGING_H

#include "timing.h"
#include "types.h"

#include <stdio.h>

//Default log file properties
#define GE_LOGGING_DEFAULT_LOG "engine.tlog"
#define GE_LOGGING_MODE "w"

//Character literals
#define GE_STR_LITERAL_CARRIAGE_RETURN '\r'
#define GE_STR_LITERAL_HORIZONTALTAB '\t'
#define GE_STR_LITERAL_SINGLE_QUOTE '\''
#define GE_STR_LITERAL_DOUBLE_QUOTE '\"'
#define GE_STR_LITERAL_VERTICALTAB '\v'
#define GE_STR_LITERAL_BACKSPACE '\b'
#define GE_STR_LITERAL_FORM_FEED '\f'
#define GE_STR_LITERAL_BACKSLASH '\\'
#define GE_STR_LITERAL_NEWLINE '\n'
#define GE_STR_LITERAL_ALERT '\a'
#define GE_STR_LITERAL_NULL '\0'

#define GE_LOGGING_BUFFER_SIZE 256

//This represents the formatting of each log line
//Explanation of this macro madness:
/*
- There is a list of macros, for example:
- GE_LOGGING_FORMAT_DATE
- GE_LOGGING_FORMAT_TIME
- These simply define the existence of some variable
- The value they store is useless
- Then the value of these is redefined to be some variable inside the function call
- The logging format order is then placed in a sprintf_s call.
*/
#define GE_LOGGING_FORMAT_DATE "date"
#define GE_LOGGING_FORMAT_TIME "time"
#define GE_LOGGING_FORMAT_TYPE "type"
#define GE_LOGGING_FORMAT_DATA "data"

#define GE_LOGGING_FORMAT "%s %s|%s|thread: 1|%s"
#define GE_LOGGING_FORMAT_ORDER \
    GE_LOGGING_FORMAT_TIME, \
    GE_LOGGING_FORMAT_DATE, \
    GE_LOGGING_FORMAT_TYPE, \
    GE_LOGGING_FORMAT_DATA

//Stores the types of logging
//TODO: ENUM style lookup system
#define GE_LOGGING_TYPE_LIST \
	X(INFO)		\
	X(WARNING)	\
	X(ERROR)	\
	X(FATAL_ERROR)

enum LoggingTypes
{
#define X(n) n,
	GE_LOGGING_TYPE_LIST
#undef X
};

//Allows for a file stream to be sent data to
//Wrapper for C FILE*
class LogFile
{
private:
	//Make the copy-constructor illegal!
	//Super pro technique
	LogFile(const LogFile& cpy) { };

public:
	//Interacting with the file stream
	LogFile(GE_STR filepath);
	~LogFile(); //Important, the file should close even if something goes wrong with the program
	
	void Close(); 

	//Logging the data
	void Write(GE_STR message, LoggingTypes logType = LoggingTypes::INFO);
	void RawWrite(GE_STR plainText, GE_CHAR end = GE_STR_LITERAL_NEWLINE);

	//Statics
	static GE_BYTE GetActiveOpenFiles(); //Gets the number of LogFiles's open at once

	//Getter
	GE_STR GetPath() const;

	//There is a global LogFile instance
	static LogFile* logging;
private:

	GE_STR _path = nullptr;
	FILE* _file = nullptr;

	//We need to keep track of how many LogFile instances are open at once
	static GE_BYTE _activeOpenFiles;
};

//Define a macro so that logging is easy to type
#define GE_LOGGER (*LogFile::logging)

#define GE_LOG_RAW(n)			GE_LOGGER.RawWrite(n);
#define GE_LOG_INFO(n)			GE_LOGGER.Write(n, INFO);
#define GE_LOG_ERROR(n)			GE_LOGGER.Write(n, ERROR);
#define GE_LOG_WARNING(n)		GE_LOGGER.Write(n, WARNING);
#define GE_LOG_FATAL_ERROR(n)	GE_LOGGER.Write(n, FATAL_ERROR);

#define GE_LOG_OPEN_FILES		LogFile::GetActiveOpenFiles()

#endif // !_LOGGING_H