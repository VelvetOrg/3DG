#include "timing.h"

#include <stdio.h>

#pragma region Time

//Helper function to generate tm time
tm _GenerateCurrentTime(errno_t(*tmCreator)(tm* const, time_t const* const)) 
{
	//Current time
	time_t now = time(NULL);
	struct tm buf;

	//Use the callback, either:
	// localtime_s
	// gmtime_s
	errno_t ern = localtime_s(&buf, &now);
	
	if(ern != NULL) 
	{
		//TODO: throw
		printf("Could not find current time : %i\n", ern);
	}

	return buf;
}

//Just fill values
Time::Time(GE_UCHAR h, GE_UCHAR m, GE_UCHAR s)
{
	//Modulo is hard coded
	this->_hours = h % 25;
	this->_minutes = m % 61;
	this->_seconds = s % 61;
}

//Fill based on a tm object
Time::Time(tm* cpy)
{
	this->_hours = cpy->tm_hour;
	this->_minutes = cpy->tm_min;
	this->_seconds = cpy->tm_sec;
}

//Generate the current time
Time Time::Local()	{ return Time(&_GenerateCurrentTime(&localtime_s)); }
Time Time::UTC()	{ return Time(&_GenerateCurrentTime(&gmtime_s)); }

//Converts the time into a formatted string:
void Time::ToString(GE_CHAR* buffer, GE_USHORT bufferSize)
{
	//HH:MM:SS
	sprintf_s(buffer, bufferSize, GE_TIMING_TIME_FORMAT,
		this->_hours, 
		this->_minutes, 
		this->_seconds);
}

//Simple getters
GE_UCHAR Time::GetSeconds() const { return this->_seconds; }
GE_UCHAR Time::GetMinutes() const { return this->_minutes; }
GE_UCHAR Time::GetHours() const { return this->_hours; }

#pragma endregion

// --- 

#pragma region Date

//Overloaded constructor
Date::Date(GE_UCHAR d, GE_UCHAR m, GE_UCHAR y)
{
	this->_day = d;
	this->_year = y;
	this->_month = m;
}

Date::Date(tm* cpy)
{
	this->_day = cpy->tm_mday;
	this->_month = cpy->tm_mon + 1;
	this->_year = cpy->tm_year + 1900;
}

//Converts the time into a formatted string
void Date::ToString(GE_CHAR* buffer, GE_USHORT bufferSize)
{
	//DD-MM-YYYY
	sprintf_s(buffer, bufferSize, GE_TIMING_DATE_FORMAT,
		this->_day,
		this->_month,
		this->_year);
}

//Generate the current time
Date Date::Local()	{ return Date(&_GenerateCurrentTime(&localtime_s)); }
Date Date::UTC()	{ return Date(&_GenerateCurrentTime(&gmtime_s)); }

//Simple getters
GE_UCHAR Date::GetDays() const { return this->_day; }
GE_UINT16 Date::GetYears() const { return this->_year; }
GE_UCHAR Date::GetMonths() const { return this->_month; }

#pragma endregion