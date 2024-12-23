#include "Date.h"

bool Date::isLeapYear()
{
	if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0)
		return true;
	else
		return false;
}

int Date::monthDays()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2)
		return isLeapYear() ? 29 : 28;
	else if
		(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return -1;
}

void Date::nextDate()
{
	if (day == 31 && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	else if (day == monthDays()) {
		day = 1;
		month++;
	}
	else
		day++;
}

void Date::prevDate()
{
	if (day == 1 && month == 1) {
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1) {
		month--;
		day = monthDays();
	}
	else
		day--;
}

Date::Date()
{
	tm* obj = new tm;
	time_t now = time(NULL);
	localtime_s(obj, &now);
	this->day = obj->tm_mday;
	this->month = obj->tm_mon + 1;
	this->year = obj->tm_year + 1900;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	if (!this->valid())
	{
		this->year = 1900;
		this->month = 1;
		this->day = 1;
	}

}

Date::Date(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}

Date::~Date()
{
}

void Date::showDate()
{
	cout << this->year << "-" << this->month / 10 << this->month % 10
		<< "-" << this->day / 10 << this->day % 10 << endl;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const&
{
	return year;
}

void Date::setMonth(int month)
{
	if (month >= 1 && month <= 12)
		this->month = month;
}

int Date::getMonth() const&
{
	return month;
}

void Date::setDay(int day)
{
	if (day >= 1 && day <= monthDays())
		this->day = day;
}

int Date::getDay() const&
{
	return day;
}

bool Date::valid()
{

	return  (month >= 1 && month <= 12 && day >= 1 && day <= monthDays()) ? true : false;
}

bool Date::operator==(const Date& obj) const&
{
	return (this->year == obj.year && this->month == obj.month && this->day == obj.day) ? true : false;
}

bool Date::operator!=(const Date& obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
		return true;
	else if (this->year == obj.year && this->month > obj.month)
		return true;
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& obj) const&
{
	return !(*this > obj) && *this != obj;
}

bool Date::operator>=(const Date& obj) const&
{
	return *this > obj || *this == obj;
}

bool Date::operator<=(const Date& obj) const&
{
	return *this < obj || *this == obj;
}

Date& Date::operator=(const Date& obj)
{
	this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
	return *this;
}

Date& Date::operator+=(int n)
{
	for (int i = 0; i < n; i++)
		this->nextDate();
	return*this;
	
}

Date& Date::operator-=(int n)
{
	for (int i = 0; i < n; i++)
		this->prevDate();
	return*this;
	
}

Date Date::operator+(int n)
{
	Date tmp(*this);
	for (int i = 0; i < n; i++)
		tmp.nextDate();
	return tmp;
}

Date Date::operator-(int n)
{
	Date tmp(*this);
	for (int i = 0; i < n; i++)
		tmp.prevDate();
	return tmp;
}

Date& Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int n)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int n)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.year<<"." << t.month/10<<t.month%10<<"." << t.day/10<<t.day%10;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	do {
		cout << "YYYY MM DD: ";
		is >> t.year >> t.month >> t.day;
	} while (!t.valid());
	return is;
}
