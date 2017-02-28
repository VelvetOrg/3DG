/*
#include "logging.h"
#include <assert.h>

//Setting static's default value
LogFile* LogFile::logging = new LogFile(GE_LOGGING_DEFAULT_LOG); //New instance

GE_BYTE LogFile::_activeOpenFiles = 0;
GE_USHORT LogFile::bufferSize = 256;

LogFile::LogFile(GE_STR filepath) 
{ 
	//Most architectures don't allow too many files to be open at once
	assert(LogFile::_activeOpenFiles < FOPEN_MAX);
	
	//Create
	_path = filepath;
	_file = new FILE();

	fopen_s(&_file, _path, "w");

	//Inc
	LogFile::_activeOpenFiles++;
}

//Clean up
void LogFile::Close()
{
	if(fclose(_file) == EOF)
	{
		printf("Failed"); //TODO: Use throw
	}

	//Remove
	_file = nullptr;

	//Dec
	printf("Closed file!\n");
	LogFile::_activeOpenFiles--;

	//delete this;
}
LogFile::~LogFile() { if (_file != nullptr) { this->Close(); } }

//Out the data into the file
void LogFile::Write(GE_STR message, LoggingTypes logType)
{
	//Determine the date and time
	Time currentTime = GE_UTF_TIME;
	Date currentDate = GE_UTF_DATE;

	GE_CHAR* timeBuffer = new GE_CHAR[GE_TIMING_TIME_BUFFER_SIZE];
	GE_CHAR* dateBuffer = new GE_CHAR[GE_TIMING_DATE_BUFFER_SIZE];

	currentTime.ToString(timeBuffer, GE_TIMING_TIME_BUFFER_SIZE);
	currentDate.ToString(dateBuffer, GE_TIMING_DATE_BUFFER_SIZE);

	//Determine the log type string
	//TODO: make this more efficient
	GE_CHAR* typeBuffer;
#define X(n) #n ,
	
	//New scope
	{
		GE_CHAR* members[] = { GE_LOGGING_TYPE_LIST };

		typeBuffer = members[logType];
	}
#undef X

	//Stores the type of logging
	const GE_CHAR* messageBuffer = message;

	//Redefine
#undef GE_LOGGING_FORMAT_DATE
#undef GE_LOGGING_FORMAT_TIME
#undef GE_LOGGING_FORMAT_TYPE
#undef GE_LOGGING_FORMAT_DATA

#define GE_LOGGING_FORMAT_DATE dateBuffer
#define GE_LOGGING_FORMAT_TIME timeBuffer
#define GE_LOGGING_FORMAT_TYPE typeBuffer
#define GE_LOGGING_FORMAT_DATA messageBuffer

	//We need to fill a buffer to put
	GE_CHAR* buffer = new GE_CHAR[LogFile::bufferSize];

	//Format the actual buffer
	sprintf_s(buffer, LogFile::bufferSize, GE_LOGGING_FORMAT,
		GE_LOGGING_FORMAT_ORDER);

	//Actually write the buffer
	this->RawWrite(buffer);

	//Done
	DELETE_ARR(dateBuffer);
	DELETE_ARR(timeBuffer);
	DELETE_ARR(buffer);
}

//Out the data into the file
void LogFile::RawWrite(GE_STR plainText, GE_CHAR end)
{
	assert(_file != nullptr);

	fputs(plainText, _file);
	fputc(end, _file);
}

//Getters
GE_STR LogFile::GetPath() const { return this->_path; }
GE_BYTE LogFile::GetActiveOpenFiles() { return LogFile::_activeOpenFiles; }
*/