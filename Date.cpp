#include <iostream>
#include "Date.h"

using namespace std;

int Date::getYear() const
{
    return _year;
}

void Date::setYear(int year)
{
    _year = year;
}

int Date::getMonth() const
{
    return _month;
}

void Date::setMonth(int month)
{
    _month = month;
}

int Date::getDay() const
{
    return _day;
}

void Date::setDay(int day)
{
    _day = day;

}

Date::Date(int year, int month, int day)
{
    this->setYear(year);
    this->setMonth(month);
    this->setDay(day);
}

Date::Date()
{
    this->setDefault();
}

void Date::setDefault()
{
    this->setYear(1950);
    this->setMonth(12);
    this->setDay(30);
}

void Date::validate()
{
    if (_year < 0)
    {
        cerr << "Year is less than 0. Setting to default values." << endl;
        this->setDefault();
    }
    if (_day > Date::MONTH_DAYS[this->getMonth() - 1])
    {
        cerr << "Day greater than " << Date::MONTH_DAYS[this->getMonth() - 1] << ". Setting to default values." << endl;
        this->setDefault();
    }
    if (_day < 1)
    {
        cerr << "Day is 0 or less. Setting to default values." << endl;
        this->setDefault();
    }
    if (_month > 12)
    {
        cerr << "Month greater than 12. Setting to default values." << endl;
        this->setDefault();
    }
    if (_month < 1)
    {
        cerr << "Month is 0 or less. Setting to default values." << endl;
        this->setDefault();
    }
}
