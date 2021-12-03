#include "AvailableTimeBlock.h"

#include <utility>

using namespace std;

const vector<Person*> &AvailableTimeBlock::getOwners() const
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

AvailableTimeBlock::AvailableTimeBlock(vector<Person*> owners, EventTime* startEvent, EventTime* endEvent)
{
    _owners = std::move(owners);
    _startEvent = startEvent;
    _endEvent = endEvent;
}
