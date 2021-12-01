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
    validate();
}

int Date::getMonth() const
{
    return _month;
}

void Date::setMonth(int month)
{
    _month = month;
    validate();
}

int Date::getDay() const
{
    return _day;
}

void Date::setDay(int day)
{
    _day = day;
    validate();
}

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
    validate();
}

Date::Date()
{
    this->setDefault();
}

void Date::setDefault()
{
    _year = 1950;
    _month = 12;
    _day = 30;
}

void Date::validate()
{
    if (_year < 0)
    {
        cerr << "Year is less than 0. Setting to default values." << endl;
        this->setDefault();
    }
    if (_day > 31)
    {
        cerr << "Day greater than 31. Setting to default values." << endl;
        this->setDefault();
    }
    if (_day < 1)
    {
        cerr << "Day is less than 1. Setting to default values." << endl;
        this->setDefault();
    }
    if (_month > 12)
    {
        cerr << "Month greater than 12. Setting to default values." << endl;
        this->setDefault();
    }
    if (_month < 1)
    {
        cerr << "Month is less than 1. Setting to default values." << endl;
        this->setDefault();
    }
}
