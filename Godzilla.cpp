//
// Created by nathanpanzer on 11/12/2021.
//

#include <iostream>
#include "Godzilla.h"

Godzilla::Godzilla()
{
    srand(time(nullptr));
    rand();
    this->name = "Godzilla";
    this->health = rand() % 51 + 50;
    this->power = rand() % 16 + 10;
}

Godzilla::Godzilla(string name, double health, double power)
{
    this->name = name;

    if (health > 0)
    {
        this->health = health;
    }
    else
    {
        this->health = rand() % 51 + 50;
    }

    if (power > 0)
    {
        this->power = power;
    }
    else
    {
        this->power = rand() % 16 + 10;
    }
}

void Godzilla::setName(string newName)
{
    this->name = newName;
}

void Godzilla::setHealth(double newHealth)
{
    this->health = newHealth;
}

void Godzilla::setPower(double newPower)
{
    if (newPower > 0)
    {
        this->power = newPower;
    }
}

string Godzilla::getName() const
{
    return this->name;
}

double Godzilla::getHealth() const
{
    return this->health;
}

double Godzilla::getPower() const
{
    return this->power;
}

void Godzilla::attack(Godzilla &victim)
{
    victim.setHealth(victim.getHealth() - this->power);
    cout << this->name << " attacks " << victim.getName() << endl;
    if (victim.getHealth() < 0)
    {
        cout << victim.getName() << " has been vanquished." << endl;
    }
}