#ifndef CSCI261_PERSON_H
#define CSCI261_PERSON_H

using namespace std;

#include <string>
#include <vector>

class AvailableTimeBlock;
class EventTime;

using namespace std;

class Person
{
private:
    string _name;
    vector<AvailableTimeBlock*> _timeBlocks;
public:
    Person(string name, vector<AvailableTimeBlock*> timeBlocks);

    Person();

    const string &getName() const;

    const vector<AvailableTimeBlock*> &getTimeBlocks() const;

    void addTimeBlock(AvailableTimeBlock*);
};


#endif //CSCI261_PERSON_H
