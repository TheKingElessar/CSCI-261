#ifndef CSCI261_EVENT_H
#define CSCI261_EVENT_H

using namespace std;

#include <string>
#include "Date.h"

class Event
{
public:
    Event();

    Event(Date, string, string);

    void print() const;

    const Date &getDate() const;

    void setDate(const Date &date);

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getLocation() const;

    void setLocation(const string &location);

private:
    Date _date;
    string _title;
    string _location;
};


#endif