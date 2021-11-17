/* CSCI 261 Assignment 7: Stargate
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * Your task for this assignment is to read in a star data file, store the data in a list of objects, make modifications to the data, and then draw a star map.
 */

#include <iostream>                             // for standard input/output

using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
#include <fstream>
#include <io.h>
#include "Star.h"

using namespace sf;                             // using the sf namespace

int main()
{
    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window(VideoMode(640, 640), "SFML Example Window");

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    ifstream starsFile;
    starsFile.open("stars.txt");
    if (starsFile.fail())
    {
        cerr << "Error opening stars.txt. Exiting." << endl;
        return -1;
    }

    // todo: clear invalid stars then KEEP GOING
    vector<Star> starVec;
    float inX;
    while (starsFile >> inX)
    {
        float inY, inBrightness;
        float skip;
        starsFile >> inY >> skip >> inBrightness >> skip >> skip;
        Star newStar(inX, inY, inBrightness);
        starVec.push_back(newStar);
    }

    cout << "Read " << starVec.size() << " stars from file" << endl;

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop
    while (window.isOpen())
    {
        window.clear(Color::Black);           // clear the contents of the old frame
        // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while (window.pollEvent(event))
        {      // ask the window if any events occurred
            if (event.type == Event::Closed)
            { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}