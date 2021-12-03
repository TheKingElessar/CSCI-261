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
    Person* _owner;
    time_t _time;
    bool _isEnding;

    static int getNextID();
public:
    EventTime(Person* owner, time_t time, bool isEnding);

    EventTime();

    static void initID();

    int getID() const;

    const Person &getOwner() const;

    time_t getTime() const;

    bool getIsEnding() const;
};


#endif //CSCI261_EVENTTIME_H
