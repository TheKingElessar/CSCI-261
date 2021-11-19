/* CSCI 261 Assignment 7: Stargate
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * Your task for this assignment is to read in a star data file, store the data in a list of objects, make modifications to the data, and then draw a star map.
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include <fstream>
#include "Star.h"

using namespace sf;

const int WIDTH = 640;
const int HEIGHT = 640;

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Stargate");

    /*
     * Open stars file
     */
    ifstream starsFile;
    starsFile.open("stars.txt");
    if (starsFile.fail())
    {
        cerr << "Error opening stars.txt. Exiting." << endl;
        return -1;
    }

    /*
     * Read stars file and create vector of Star objects
     */
    vector<Star> starVec;
    float inX;
    float maxBrightness = 0;
    while (starsFile >> inX)
    {
        float inY, inBrightness;
        float skip;
        starsFile >> inY >> skip >> inBrightness >> skip >> skip;
        if (inBrightness < 0. || inBrightness > 8.) continue;
        if (inBrightness > maxBrightness) maxBrightness = inBrightness;

        Star newStar(inX, inY, inBrightness);
        starVec.push_back(newStar);
    }

    while (window.isOpen())
    {
        window.clear(Color::Black);

        /*
         * Draw each star
         */
        for (Star star : starVec)
        {
            CircleShape starShape;
            starShape.setRadius(2);
            starShape.setPosition(Vector2f(star.getTransformedX(WIDTH), star.getTransformedY(HEIGHT)));
            starShape.setFillColor(star.getGrayscaleColor(maxBrightness));
            window.draw(starShape);
        }

        window.display();

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