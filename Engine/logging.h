#ifndef _LOGGING_H
#define _LOGGING_H

#include "file.h"

//Default log file properties
#define GE_LOGGING_DEFAULT_FILE "engine.tlog"

//X-macros defines the different types of logging
// Logging types:

//ERROR: everything has fell apart, abort mission
//WARN: the process can possibly continue but take caution
//INFO: some important step along the process has finished, explain it
//DEBUG: just general programmer logging
//TRACE: detailed developer messages that are useless to an average person


#define GE_LOGGING_TYPES \
X(ERROR) \
X(WARN)  \
X(INFO)  \
X(DEBUG) \
X(TRACE)

//Declare a global OutputFile object that all logging will be handled with
OutputFile log(GE_LOGGING_DEFAULT_FILE);

/*
#include "timing.h"
#include "types.h"
#include "str.h"

#include <stdio.h>

//Default log file properties
#define GE_LOGGING_DEFAULT_LOG "engine.tlog"

//This represents the formatting of each log line
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
	X(Info)		\
	X(Warning)	\
	X(Error)	\
	X(FatalError)

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
#define X(n) inline void Log##n##F	(GE_STR message) { this->_Write(message, LoggingTypes::##n); };
	GE_LOGGING_TYPE_LIST
#undef X

	void RawLog(GE_STR text, GE_CHAR end = GE_STR_LITERAL_NEWLINE);

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

	//The actual write implementation
	void _Write(GE_STR message, LoggingTypes logType);
};

//Define a macro so that logging is easy to type
#define GE_LOGGER (*LogFile::logging)

#define GE_LOG_RAW(n)			GE_LOGGER.RawWrite(n);
#define GE_LOG_INFO(n)			GE_LOGGER.Write(n, INFO);
#define GE_LOG_ERROR(n)			GE_LOGGER.Write(n, ERROR);
#define GE_LOG_WARNING(n)		GE_LOGGER.Write(n, WARNING);
#define GE_LOG_FATAL_ERROR(n)	GE_LOGGER.Write(n, FATAL_ERROR);

#define GE_LOG_OPEN_FILES		LogFile::GetActiveOpenFiles()
*/
#endif // !_LOGGING_H