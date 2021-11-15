#include <iostream>                             // for standard input/output

using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library

using namespace sf;                             // using the sf namespace

int main()
{
    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window(VideoMode(640, 640), "Underwatch");

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop
    std::srand(time(nullptr));
    std::rand();
    int targetX = rand() % 640;
    int targetY = rand() % 640;
    int points = 0;

    while (window.isOpen())
    {
        window.clear(Color::Black);           // clear the contents of the old frame
        // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************
// Draw a circle object called targetCircle and color it yellow
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

        Font arialFont;
        if (!arialFont.loadFromFile("data/arial.ttf"))
        {
            return -1;
        }

        Text label1;
        label1.setFont(arialFont);
        label1.setString("its a FREAKING tree");
        label1.setPosition(400, 90);
        label1.setCharacterSize(15);
        label1.setFillColor(Color::White);
        window.draw(label1);

        Text label2;
        label2.setFont(arialFont);
        label2.setString("gonna start packaging a bitcoin miner in my\ncsci261 assignments to take advantage\nof the nice TAs\n\nsorry");
        label2.setPosition(400, 550);
        label2.setCharacterSize(10);
        label2.setFillColor(Color::White);
        window.draw(label2);

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
// Draw a text object calledlabel
        Text label;
        label.setFont(arialFont);
        label.setString("Click the dumb idiot circle to kill it! :)");
        label.setPosition(80, 460);
        label.setCharacterSize(25);
        label.setFillColor(Color::White);
        window.draw(label);

        Text pointsLabel;
        pointsLabel.setFont(arialFont);
        pointsLabel.setString("Points: " + std::to_string(points));
        pointsLabel.setPosition(100, 100);
        pointsLabel.setCharacterSize(25);
        pointsLabel.setFillColor(Color::White);
        window.draw(pointsLabel);
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

    return EXIT_SUCCESS;                        // report our program exited successfully
}