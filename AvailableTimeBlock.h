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
    vector<Person *> _owners;
    EventTime *_startEvent;
    EventTime *_endEvent;
public:
    AvailableTimeBlock();

    AvailableTimeBlock(vector<Person *> owners, EventTime *startEvent, EventTime *endEvent);

    const vector<Person *> &getOwners() const;

    const EventTime &getStartEvent() const;

    const EventTime &getEndEvent() const;

    /**
     *  @brief  Returns whether this AvailableTimeBlock overlaps with another one.
     *  @param  otherBlock AvailableTimeBlock to test against.
     *  @return  Whether or not the two AvailableTimeBlocks overlap.
     *
     *  If the two AvailableTimeBlocks both have the same period of time
     *  in their time block, this will return true. For example:
     *   - 12/08/21 15:00 22:30
     *   - 12/08/21 17:30 21:00
     *  Overlap from 17:30 to 21:00, so this will return true.
    */
    bool doesOverlap(const AvailableTimeBlock& otherBlock);

    /**
     *  @brief  Returns the AvailableTimeBlock where this AvailableTimeBlock overlaps with another.
     *  @param  otherBlock AvailableTimeBlock to test against.
     *  @return  The AvailableTimeBlock where they overlap.
     *
     *  If the two AvailableTimeBlocks both have the same period of time
     *  in their time block, this will return the AvailableTimeBlock for
     *  that block. For example:
     *   - 12/08/21 15:00 22:30
     *   - 12/08/21 17:30 21:00
     *  Overlap from 17:30 to 21:00, so this will return an AvailableTimeBlock
     *  of that block.
    */
    AvailableTimeBlock getOverlapBlock(AvailableTimeBlock otherBlock);
};


#endif //CSCI261_AVAILABLETIMEBLOCK_H
