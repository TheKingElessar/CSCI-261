#ifndef SFML_TEMPLATE_STAR_H
#define SFML_TEMPLATE_STAR_H


class Star
{
private:
    float x;
    float y;
    float brightness;
public:
    Star();

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getBrightness() const;

    void setBrightness(float brightness);

    Star(float x, float y, float brightness);
};


#endif //SFML_TEMPLATE_STAR_H
