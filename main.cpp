/* CSCI 261 Lab 7A: SFML Drawing
 *
 * Author: Nathan Panzer
 *
 * For this assignment, you have the opportunity to play with the power that SFML (a special framework called Simple and Fast Multimedia Library) offers.
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 640), "Underwatch");

    std::srand(time(nullptr));
    std::rand();
    int targetX = 320 + rand() % 100;
    int targetY = 320 + rand() % 100;
    int points = 0;

    Font arialFont;
    if (!arialFont.loadFromFile("data/arial.ttf"))
    {
        return -1;
    }

    while (window.isOpen())
    {
        window.clear(Color::Black);

        CircleShape targetCircle;
        targetCircle.setPosition(targetX, targetY);
        targetCircle.setRadius(25);
        targetCircle.setFillColor(Color::Yellow);
        window.draw(targetCircle);

        RectangleShape treeTrunk;
        treeTrunk.setPosition(400, 200);
        treeTrunk.setFillColor(Color::Blue);
        treeTrunk.setSize(Vector2f(25, 150));
        window.draw(treeTrunk);

        Text treeLabel;
        treeLabel.setFont(arialFont);
        treeLabel.setString("its a FREAKING tree");
        treeLabel.setPosition(400, 90);
        treeLabel.setCharacterSize(15);
        treeLabel.setFillColor(Color::White);
        window.draw(treeLabel);

        Text bitcoinLabel;
        bitcoinLabel.setFont(arialFont);
        bitcoinLabel.setString(
                "gonna start packaging a bitcoin miner in my\ncsci261 assignments to take advantage\nof the nice TAs\n\nsorry");
        bitcoinLabel.setPosition(400, 550);
        bitcoinLabel.setCharacterSize(10);
        bitcoinLabel.setFillColor(Color::White);
        window.draw(bitcoinLabel);

        for (int i = 0; i < 10; i++)
        {
            RectangleShape newBranch;
            int x = 400;
            int y = 200;
            int angle = 45;
            if (i % 2 != 0)
            {
                y += 10 * (i - 1) + 7;
                x = 425;
                angle = -45;
            }
            else
            {
                y += 10 * i;
            }

            newBranch.setPosition(x, y);
            newBranch.setFillColor(Color::Green);
            newBranch.setSize(Vector2f(10, 50));
            newBranch.setRotation(angle);
            window.draw(newBranch);
        }

        Text gameLabel;
        gameLabel.setFont(arialFont);
        gameLabel.setString("Click the dumb idiot circle to kill it! :)");
        gameLabel.setPosition(80, 460);
        gameLabel.setCharacterSize(25);
        gameLabel.setFillColor(Color::White);
        window.draw(gameLabel);

        Text pointsLabel;
        pointsLabel.setFont(arialFont);
        pointsLabel.setString("Points: " + std::to_string(points));
        pointsLabel.setPosition(100, 100);
        pointsLabel.setCharacterSize(25);
        pointsLabel.setFillColor(Color::White);
        window.draw(pointsLabel);

        window.display();

        Event event;
        while (window.pollEvent(event))
        {      // ask the window if any events occurred
            if (event.type == Event::Closed)
            { // if event type is a closed event
                // i.e. they clicked the X on the window

                window.close();                 // then close our window
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (abs(event.mouseButton.x - targetX - targetCircle.getRadius()) < targetCircle.getRadius())
                {
                    if (abs(event.mouseButton.y - targetY - targetCircle.getRadius()) < targetCircle.getRadius())
                    {
                        targetX = rand() % 640;
                        targetY = rand() % 640;
                        points++;
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}