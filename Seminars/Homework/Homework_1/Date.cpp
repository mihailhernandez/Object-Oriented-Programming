#include <iostream>
#include <iomanip>

const char DELIMITER = '.';
const char FILL_ZERO = '0';
const unsigned int CHRISTMAS_DAY = 25;
const unsigned int CHRISTMAS_MONTH = 12;
const unsigned int LOWEST_POSSIBLE_DAY = 1;
const unsigned int LOWEST_POSSIBLE_MONTH = 1;
const unsigned int DAY_PRECISION = 2;
const unsigned int MONTH_PRECISION = 2;
const unsigned int MONTHS_IN_A_YEAR = 12;
const unsigned int DAYS_IN_MONTH[MONTHS_IN_A_YEAR] = 
{
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class Date
{

public:

	Date() : day(1), month(1), year(2000), leap_year(true) {}

	Date(const unsigned int day, const unsigned int month, const unsigned int year)
	{
		set_year(year);
		set_month(month);
		set_day(day);
	}

	void print() const
	{
		std::cout << std::setfill(FILL_ZERO)
				  << std::setw(DAY_PRECISION) << day << DELIMITER
				  << std::setw(MONTH_PRECISION) << month << DELIMITER
				  << year << std::endl;
	}

	void set_day(const unsigned int day)
	{
		if (day > days_in_current_month())
			this->day = days_in_current_month();
		else if (day < LOWEST_POSSIBLE_DAY)
			this->day = LOWEST_POSSIBLE_DAY;
		else
			this->day = day;
	}

	void set_month(const unsigned int month)
	{
		if (month < LOWEST_POSSIBLE_MONTH)
			this->month = LOWEST_POSSIBLE_MONTH;
		else if (month > MONTHS_IN_A_YEAR)
			this->month = MONTHS_IN_A_YEAR;
		else
			this->month = month;
	}

	void set_year(const unsigned int year)
	{
		this->year = year;
		leap_year = is_leap_year();
	}

	unsigned int get_day() const
	{
		return day;
	}

	unsigned int get_month() const
	{
		return month; 
	}

	unsigned int get_year() const
	{
		return year;
	}

	bool is_leap_year() const
	{
		return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void add_days(const unsigned int days)
	{
		if (days < 0)
			std::cerr << "Only positive number of days can be added!" << std::endl
					  << "Use remove_days method for negative days."  << std::endl;
		for (int i = 0; i != days; i++, increment_days());
	}

	void remove_days(const unsigned int days)
	{
		if (days < 0)
			std::cerr << "Only positive number of days can be removed!" << std::endl;
		for (int i = 0; i != days; i++, decrement_days()); 
	}

	bool is_later_than(const Date& other) const
	{
		if (this->year > other.get_year())
			return true;
		else if (this->year < other.get_year())
			return false;
		else if (this->year == other.get_year() && this->month > other.get_month())
			return true;
		else if (this->month < other.get_month())
			return false;
		else if (this->month == other.get_month() && this->day > other.get_day())
			return true;
		return false;
	}

	unsigned int days_until_Christmas() const
	{
		Date temp(*this);
		unsigned int days = 0;
		for (;temp.get_day() != CHRISTMAS_DAY || temp.get_month() != CHRISTMAS_MONTH; days++)
			temp.add_days(1);
		return days;
	}

private:

	unsigned int day;
	unsigned int month;
	unsigned int year;
	bool leap_year;

	unsigned int days_in_current_month() const
	{
		return (month == 2 && leap_year) ? 29 : DAYS_IN_MONTH[month - 1];
	}

	void increment_days()
	{

		if (day == days_in_current_month())
		{
			increment_months();
			day = 1;
		}
		else
			day++;
	}

	void increment_months()
	{
		if (month == MONTHS_IN_A_YEAR)
		{
			increment_years();
			month = 1;
		}
		else 
			month++;
	}

	void increment_years()
	{
		year++;
		leap_year = is_leap_year();
	}

	void decrement_days()
	{
		if (day == 1)
		{
			decrement_months();
			day = days_in_current_month();
		}
		else 
			day--;
	}

	void decrement_months()
	{
		if (month == 1)
		{
			decrement_years();
			month = MONTHS_IN_A_YEAR;
		}
		else
			month--;
	}
	
	void decrement_years()
	{
		year--;
		leap_year = is_leap_year();
	}
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << std::setfill(FILL_ZERO) << std::setw(DAY_PRECISION) << date.get_day() << DELIMITER
			<< std::setw(MONTH_PRECISION) << date.get_month() << DELIMITER
			<< date.get_year();
	return os;
}

Date get_difference(const Date& first, const Date& second)
{
	Date difference(0,0,0);
	Date earlier = first.is_later_than(second) ? second : first;
	const Date& latest = first.is_later_than(second) ? first  : second;
	for (;!earlier.is_later_than(latest); earlier.add_days(1), difference.add_days(1));
	return difference;
}
