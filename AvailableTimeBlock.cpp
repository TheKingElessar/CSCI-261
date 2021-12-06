#include "AvailableTimeBlock.h"
#include "EventTime.h"

#include <utility>

using namespace std;

const vector<Person *> &AvailableTimeBlock::getOwners() const
{
    return _owners;
}

const EventTime &AvailableTimeBlock::getStartEvent() const
{
    return *_startEvent;
}

const EventTime &AvailableTimeBlock::getEndEvent() const
{
    return *_endEvent;
}

AvailableTimeBlock::AvailableTimeBlock(vector<Person *> owners, EventTime *startEvent, EventTime *endEvent)
{
    _owners = std::move(owners);
    _startEvent = startEvent;
    _endEvent = endEvent;
}

bool AvailableTimeBlock::doesOverlap(const AvailableTimeBlock &otherBlock)
{
    // If one starts after the other ends, they don't overlap.
    if (this->getStartEvent().getTime() > otherBlock.getEndEvent().getTime() ||
        otherBlock.getStartEvent().getTime() > this->getEndEvent().getTime())
    {
        return false;
    }

    // Otherwise, they always overlap.
    return true;
}

AvailableTimeBlock::AvailableTimeBlock() = default;