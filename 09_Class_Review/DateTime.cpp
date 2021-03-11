#include <iostream>
using namespace std;

#include "DateTime.h"

DateTime::DateTime(
	int m, int d, int y, int hr, int min, int sec
)
{
	setDate(m, d, y);
	setTime(hr, min, sec);
}

void DateTime::setDate(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

void DateTime::setMonth(int m)
{
	month = m <= 12 && m >= 1 ? m : 1;
}

void DateTime::setYear(int y)
{
	year = y > 1900 ? y : 1900;
}

void DateTime::setDay(int d)
{
	day = d > 0 && d < 32 ? d : 1;
}

void DateTime::nextDay()
{
	setDay(day + 1);
	if (day == 1) {
		setMonth(month + 1);
		if (month == 1) {
			setYear(year + 1);
		}
	}
}

void DateTime::setTime(int hr, int min , int sec)
{
	setHour(hr);
	setMinute(min);
	setSecond(sec);
}

void DateTime::setHour(int h)
{
	hour = h >= 0 && h < 24 ? h : 0;
}

void DateTime::setMinute(int m)
{
	minute = m >= 0 && m < 60 ? m : 0;
}

void DateTime::setSecond(int s)
{
	second = s >= 0 && s < 60 ? s : 0;
}

void DateTime::tick()
{
	setSecond(second + 1);
	if (second == 0) {
		setMinute(minute + 1);
		if (minute == 0) {
			setHour(hour + 1);
		}if (hour == 0) {
			nextDay();
		}
	}
}


int DateTime::getMonth()
{
	return month;
}

int DateTime::getYear()
{
	return year;
}

int DateTime::getDay()
{
	return day;
}

int DateTime::getHour()
{
	return hour;
}

int DateTime::getMinute()
{
	return minute;
}

int DateTime::getSecond()
{
	return second;
}

void DateTime::printStandard()
{
	cout << ((hour % 12 == 0) ? 12 : hour % 12) << ':'
		<< (minute < 10 ? "0" : "") << minute << ':'
		<< (hour < 12 ? " AM " : " PM ")
		<< month << '-' << day <<'-' << year << endl;
}

void DateTime::printUniversal()
{
	cout << (hour < 10 ? "0" : "") << hour << ':'
		<< (minute < 10 ? "0" : "") << minute << ':'
		<< (second < 10 ? "0" : "") << second << "    "
		<< month << '-' << day << '-' << year << endl;
} 

bool DateTime::leapYear()
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true; 
	}
	else
	{
		return false; 
	}
} 

int DateTime::monthDays()
{
	const int days[12] = {
	   31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (month == 2 && leapYear()) ? 29 : days[(month - 1)];
} 