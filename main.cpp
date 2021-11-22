/* CSCI 261 Lab 00: LabName
 *
 * Author: Nathan Panzer
 *
 * Longer description
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>

using namespace sf;

const int WIDTH = 640;
const int HEIGHT = 640;
const string WINDOW_NAME = "Window";

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_NAME);

    while (window.isOpen())
    {
        window.clear(Color::Black);

        /*
         * Draw objects
         */

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