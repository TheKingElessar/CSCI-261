#include "Star.h"

Star::Star(float x, float y, float brightness)
{
    this->x = x;
    this->y = y;
    this->brightness = brightness;
}

Star::Star()
{
    this->x = 0;
    this->y = 0;
    this->brightness = 0;
}

float Star::getX() const
{
    return x;
}

void Star::setX(float x)
{
    Star::x = x;
}

float Star::getY() const
{
    return y;
}

void Star::setY(float y)
{
    Star::y = y;
}

float Star::getBrightness() const
{
    return brightness;
}

void Star::setBrightness(float brightness)
{
    Star::brightness = brightness;
}
