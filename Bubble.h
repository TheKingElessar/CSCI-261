#ifndef PROJECT_BUBBLE_H
#define PROJECT_BUBBLE_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Bubble
{
private:
    CircleShape circleShape;
    double xDir = 0;
    double yDir = 0;
    float radius = 20;
public:
    Bubble();

    Bubble(float, float);

    void updatePosition();

    const CircleShape &getCircleShape() const;

    void setCircleShape(const CircleShape &circleShape);

    double getXDir() const;

    void setXDir(double xDir);

    double getYDir() const;

    void setYDir(double yDir);

    float getXPos();

    float getYPos();

    float getRadius();

    void setRadius(float);

    void checkBounds(const int WIDTH, const int HEIGHT);

    void setXPos(float x);

    void setYPos(float y);

    void setColor(Color &color);
};


#endif