#ifndef _TIMING_H
#define _TIMING_H
/*
#include "types.h"
#include <time.h>

//Holds the date formatting
#define GE_TIMING_TIME_FORMAT "%02d:%02d:%02d"
#define GE_TIMING_DATE_FORMAT "%02d-%02d-%04d"

#define GE_TIMING_TIME_BUFFER_SIZE 9
#define GE_TIMING_DATE_BUFFER_SIZE 11

//Used to wrap around the old C TM* struct
class Time
{
public:
	//Overloaded constructor
	Time(GE_UCHAR h, GE_UCHAR m, GE_UCHAR s);
	Time(tm* cpy);

	//Takes in a buffer, to remind the programmer that it is heap allocated
	//Recommended buffer-size: GE_TIMING_TIME_BUFFER_SIZE
	//Converts the time into a formatted string:
	//Format: HH:MM:SS
	void ToString(GE_CHAR* buffer, GE_USHORT bufferSize = GE_TIMING_TIME_BUFFER_SIZE);

	//Gets a time object representing the current time
	static Time Local();
	static Time UTC();

	//Simple getters
	GE_UCHAR GetSeconds() const;
	GE_UCHAR GetMinutes() const;
	GE_UCHAR GetHours() const;

private:
	GE_UCHAR _seconds;
	GE_UCHAR _minutes;
	GE_UCHAR _hours;
};

//Used to wrap around the old C TM* struct
class Date
{
public:
	//Overloaded constructor
	Date(GE_UCHAR d, GE_UCHAR m, GE_UCHAR y);
	Date(tm* cpy);

	//Takes in a buffer, to remind the programmer that it is heap allocated
	//Recommended buffer-size: GE_TIMING_DATE_BUFFER_SIZE
	//Converts the time into a formatted string:
	//Format: DD-MM-YYYY
	void ToString(GE_CHAR* buffer, GE_USHORT bufferSize = GE_TIMING_DATE_BUFFER_SIZE);

	//Gets a time object representing the current time
	static Date Local();
	static Date UTC();

	//Simple getters
	GE_UCHAR GetDays() const;
	GE_UCHAR GetMonths() const;
	GE_UINT16 GetYears() const;

private:
	GE_UCHAR _day;
	GE_UCHAR _month;
	GE_UINT16 _year;
};

// 'convenient' macros
#define GE_LOCAL_DATE	(Date::Local())
#define GE_LOCAL_TIME	(Time::Local())
#define GE_UTF_DATE		(Date::UTC())
#define GE_UTF_TIME		(Time::UTC())
*/
#endif