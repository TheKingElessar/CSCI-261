/* CSCI 261 Lab 8C: Calendar Classes
 *
 * Author: Nathan Panzer
 *
 * Focus on defining a Date and an Event class from scratch.
 */

#include <iostream>
#include "Date.h"
#include "Event.h"

using namespace std;

int main()
{
    Date date1;
    Event event1(date1, "Event1", "Location1");
    event1.print();

    Date date2(2012, 8, 28);
    Event event2(date2, "Event2", "Location2");
    event2.print();

    Event event3;
    event3.print();


    return 0;
}