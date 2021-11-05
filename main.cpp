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
        treeTrunk.setPosition(400, 500);
        treeTrunk.setFillColor(Color::Blue);
        treeTrunk.setSize(Vector2f(25, 100));

// Draw a text object calledlabel
        Font myFont;
        if (!myFont.loadFromFile("data/arial.ttf"))
        {
            return -1;
        }
        Text label;
        label.setFont(myFont);
        label.setString("Click the dumb idiot circle to kill it! :)");
        label.setPosition(100, 520);
        label.setCharacterSize(25);
        label.setFillColor(Color::White);
        window.draw(label);

        Text pointsLabel;
        pointsLabel.setFont(myFont);
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