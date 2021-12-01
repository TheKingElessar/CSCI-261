#include <iostream>
#include <iomanip>
#include "Event.h"

const Date &Event::getDate() const
{
    return _date;
}

void Event::setDate(const Date &date)
{
    Event::_date = date;
}

const string &Event::getTitle() const
{
    return _title;
}

void Event::setTitle(const string &title)
{
    Event::_title = title;
}

const string &Event::getLocation() const
{
    return _location;
}

void Event::setLocation(const string &location)
{
    Event::_location = location;
}

Event::Event()
{
    Date date;
    this->_date = date;
    this->_title = "";
    this->_location = "";
}

Event::Event(Date date, string title, string location)
{
    this->_date = date;
    this->_title = title;
    this->_location = location;
}

void Event::print() const
{
    // MM/DD/YYYY: Title (_location)
    cout << setw(2) << setfill('0') << this->_date.getMonth() << "/" << setw(2) << setfill('0') << this->_date.getDay()
         << "/" << setw(4) << setfill('0') << this->_date.getYear() << ": " << this->getTitle() << " ("
         << this->getLocation() << ")" << endl;
}
