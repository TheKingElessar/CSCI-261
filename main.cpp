/* CSCI 261 Assignment 8: Bubble Bobble
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * The purpose of this assignment is to give you practice animating objects and interacting with them.
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include "Bubble.h"

using namespace sf;

const int WIDTH = 1200;
const int HEIGHT = 720;
const string WINDOW_NAME = "Bubble Bobble";

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_NAME);

    srand(time(nullptr));
    rand();

    /*
     * Create 5 new randomized Bubbles and push them to the vector
     */
    vector<Bubble> bubbleVector;
    for (int i = 0; i < 5; i++)
    {
        Bubble bubble = Bubble(true);
        bubbleVector.push_back(bubble);

        // This gave me so much grief, trying to figure out what was happening to the poor
        // memory addresses. This C++ stuff is messed up. >:(

        // cout << &bubble << " --> " << &(bubbleVector.at(bubbleVector.size() - 1)) << endl;
    }

    while (window.isOpen())
    {
        window.clear(Color::Black);

        /*
         * For each bubble, update position and draw
         */
        for (Bubble &bubble : bubbleVector)
        {
            bubble.updatePosition();
            bubble.checkBounds(WIDTH, HEIGHT);
            window.draw(bubble.getCircleShape());
        }

        window.display();

        /*
         * Events
         */
        Event event{};
        while (window.pollEvent(event))
        {
            /*
             * When window closed
             */
            if (event.type == Event::Closed)
            {
                window.close();
            }

            /*
             * When left mouse button clicked
             */
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    // Use the constructor that just randomizes everything
                    Bubble bubble = Bubble(true);

                    // Then set its position to the center of the mouse cursor
                    bubble.setXPos(event.mouseButton.x - (bubble.getRadius() / 2));
                    bubble.setYPos(event.mouseButton.y - (bubble.getRadius() / 2));

                    bubbleVector.push_back(bubble);
                }
            }

            /*
             * When D key pressed
             */
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::D)
                {
                    if (bubbleVector.empty()) continue;
                    bubbleVector.pop_back();
                }
            }
        }
    }

    return EXIT_SUCCESS;
}