#pragma once

class DateTime
{
public:
	DateTime(int = 1, int = 1, int = 1900, int = 0, int = 0, int = 0);
	void setDate(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	void nextDay();
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void tick();

	int getMonth();
	int getYear();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();

	void printStandard();
	void printUniversal();

private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	bool leapYear();
	int monthDays();
};