#ifndef CSCI261_AVAILABLETIMEBLOCK_H
#define CSCI261_AVAILABLETIMEBLOCK_H

using namespace std;

#include "vector"
#include <ctime>

class Person;
class EventTime;

class AvailableTimeBlock
{
private:
    vector<Person*> _owners;
    EventTime* _startEvent;
    EventTime* _endEvent;
public:
    AvailableTimeBlock(vector<Person*> owners, EventTime* startEvent, EventTime* endEvent);

    const vector<Person*> &getOwners() const;

    const EventTime &getStartEvent() const;

    const EventTime &getEndEvent() const;

    bool doesOverlap(AvailableTimeBlock);

    AvailableTimeBlock getOverlapBlock(AvailableTimeBlock);
};


#endif //CSCI261_AVAILABLETIMEBLOCK_H
