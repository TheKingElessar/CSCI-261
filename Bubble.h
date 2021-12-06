#ifndef PROJECT_BUBBLE_H
#define PROJECT_BUBBLE_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Bubble
{
private:
    CircleShape _circleShape;
    double _xDir = 0;
    double _yDir = 0;
    float _radius = 20;
public:

    /*********************************
     *          CONSTRUCTORS         *
     *********************************/
    Bubble();

    Bubble(float, float);

    explicit Bubble(bool);

    /*********************************
     *            MOVEMENT           *
     *********************************/
    void checkBounds(const int WIDTH, const int HEIGHT);

    void updatePosition();

    /*********************************
     *            SETTERS            *
     *********************************/

    void setCircleShape(const CircleShape &circleShape);

    void setXDir(double xDir);

    void setYDir(double yDir);

    void setRadius(float);

    void setXPos(float x);

    void setYPos(float y);

    void setColor(Color &color);

    /*********************************
     *            GETTERS            *
     *********************************/

    const CircleShape &getCircleShape() const;

    double getXDir() const;

    double getYDir() const;

    float getXPos();

    float getYPos();

    float getRadius();
};


#endif