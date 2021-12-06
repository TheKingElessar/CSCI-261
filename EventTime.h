#ifndef CSCI261_EVENTTIME_H
#define CSCI261_EVENTTIME_H

using namespace std;

#include <ctime>

class Person;

class EventTime
{
private:
    static int nextID;

    int _id;
    Person *_owner;
    time_t _time;
    bool _isEnding;

    static int getNextID();

public:
    EventTime();

    EventTime(Person *owner, time_t time, bool isEnding);

    int getID() const;

    const Person &getOwner() const;

    time_t getTime() const;

    /**
     *  @brief  Get whether the EventTime is ending (or beginning).
     *  @return  Whether or not the EventTime is ending.
     *
     *  If the EventTime is the second of a pair, that means it's
     *  ending (as opposed to beginning). This will return true
     *  if this EventTime is the ending one of the pair.
    */
    bool getIsEnding() const;
};


#endif //CSCI261_EVENTTIME_H
