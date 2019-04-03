#include <iostream>
#include <iomanip>
#include <time.h>

#include "Clock.hpp"

const char FILL_TIME_WITH = '0';
const unsigned int PRECISION = 2;

Clock::Clock()
{
	hour = minute = second = 0;
}

Clock::Clock(int hours, int minutes, int seconds)
{
	setHour(hours);
	setMinute(minutes);
	setSecond(seconds);
}

int Clock::getHour() const
{
	return hour;
}

void Clock::setHour(int hours)
{
	if (hours < 0 || hours > MAX_HOURS)
		hours = 0;
	hour = hours;
}

int Clock::getMinute() const
{
	return minute;
}

void Clock::setMinute(int minutes) 
{
	if (minutes < 0 || minutes > MAX_MINUTES)
		minutes = 0;
	minute = minutes;
}

int Clock::getSecond() const
{
	return second;
}

void Clock::setSecond(int seconds)
{
	if (seconds < 0 || seconds > MAX_SECONDS)
		seconds = 0;
	second = seconds;
}

void Clock::print() const
{
	std::cout << std::setfill(FILL_TIME_WITH) 
			  << std::setw(PRECISION) << hour << ":" 
			  << std::setw(PRECISION) << minute << ":" 
			  << std::setw(PRECISION) << second << std::endl;
}

void Clock::nextTick()
{
	++second;
	if (second >= 60)
	{
		second = 0;
		++minute;
	}

	if (minute >= 60)
	{
		minute = 0;
		++hour;
	}

	if (hour >= 24)
		hour = 0;
}

void Clock::syncTime()
{
	time_t curTime;
	time(&curTime);

	tm* timeInfo;
	timeInfo = localtime(&curTime);
	setHour(timeInfo->tm_hour);
	setMinute(timeInfo->tm_min);
	setSecond(timeInfo->tm_sec);
}

Clock Clock::operator+(const Clock & other)
{
	this->setSecond(second + other.getSecond());
	this->setMinute(minute + other.getMinute());
	this->setHour(hour + other.getHour());
	return *this;
}
