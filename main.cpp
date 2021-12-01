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

const int WIDTH = 640;
const int HEIGHT = 640;
const string WINDOW_NAME = "Bubble Bobble";

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_NAME);

    srand(time(nullptr));
    rand();

    vector<Bubble> bubbleVector;
    for (int i = 0; i < 5; i++)
    {
        float xDir = (rand() / RAND_MAX) * 2.5;
        float yDir = (rand() / RAND_MAX) * 2.5;
        cout << "xDir: " << xDir << endl;
        int radius = rand() % (50 - 40) + 10;
        int startX = rand() % (400 - 100) + 100;
        int startY = rand() % (400 - 100) + 100;

        Bubble bubble(xDir, yDir);
        bubble.setXPos(startX);
        bubble.setYPos(startY);
        bubble.setRadius(radius);

        Color color(rand() % 255, rand() % 255, rand() % 255);
        bubble.setColor(color);

        bubbleVector.push_back(bubble);
    }

    while (window.isOpen())
    {
        window.clear(Color::Black);

        for (Bubble bubble : bubbleVector)
        {
            bubble.updatePosition();
            bubble.checkBounds(WIDTH, HEIGHT);
            window.draw(bubble.getCircleShape());
        }

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