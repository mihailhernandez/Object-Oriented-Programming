#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <stdint.h>

const unsigned int MAX_MINUTES = 60;
const unsigned int MAX_SECONDS = 60;
const unsigned int MAX_HOURS = 24;

class Clock {

private:  

	int hour;
	int minute;
	int second;

public:   

	Clock();
	Clock(int, int, int); 
	int getHour() const;   
	void setHour(int);
	int getMinute() const; 
	void setMinute(int); 
	int getSecond() const; 
	void setSecond(int);
	void print() const; 
	void nextTick(); 
	void syncTime();
	Clock operator+(const Clock& clock);
}; 

#endif
