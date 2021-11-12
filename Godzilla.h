//
// Created by nathanpanzer on 11/12/2021.
//

#ifndef CSCI261_GODZILLA_H
#define CSCI261_GODZILLA_H

#include <ctime>
#include "string"

using namespace std;

class Godzilla
{

private:

    string name;
    double health;
    double power;

public:
    Godzilla();

    Godzilla(string name, double health, double power);

    void setName(string newName);

    void setHealth(double newHealth);

    void setPower(double newPower);

    string getName() const;

    double getHealth() const;

    double getPower() const;
};


#endif //CSCI261_GODZILLA_H
