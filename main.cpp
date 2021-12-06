/* CSCI 261 Lab 8A: Bouncing Bubble
 *
 * Author: Nathan Panzer
 *
 *  You are going to create a magic bouncing ball to watch as it moves around the screen.
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include "Bubble.h"

using namespace sf;

const int WIDTH = 640;
const int HEIGHT = 640;
const string WINDOW_NAME = "Bouncing Bubble";

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_NAME);

    Bubble bubble(0.075, 0.15);

    while (window.isOpen())
    {
        window.clear(Color::Black);

        bubble.updatePosition();
        bubble.checkBounds(WIDTH, HEIGHT);
        window.draw(bubble.getCircleShape());

        window.display();

        /*
         * Events
         */
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }

    return EXIT_SUCCESS;
}