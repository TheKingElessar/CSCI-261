/* CSCI 261 Lab 6b: Polar to Cartesian
 *
 * Author: Nathan Panzer
 *
 *  One of the limitations of functions is that they can only return a single value. There are two ways we can solve this limitation - one involving Pass-by-Value and the other involving Pass-by-Reference.
 */
#include<cmath>
#include <iostream>

using namespace std;

struct CartesianPoint
{
    double x;
    double y;
};

struct PolarCoordinate
{
    double radius;
    double theta;
};

CartesianPoint polarToCartesianPBV(PolarCoordinate polarCoordinate);

PolarCoordinate cartesianToPolarPBV(CartesianPoint cartesianPoint);

void polarToCartesianPBR(double radius, double angle, double &xCoord, double &yCoord);

void cartesianToPolarPBR(double xCoord, double yCoord, double &radius, double &angle);

int main()
{
    cout << "Choose conversion:" << endl;
    cout << "  1. Cartesian to Polar" << endl;
    cout << "  2. Polar to Cartesian" << endl;
    cout << "Input: ";
    int chosenConversion;
    cin >> chosenConversion;

    switch (chosenConversion)
    {
        case 1:
        {
            CartesianPoint cartesianPoint{};
            cout << "X-Value: ";
            cin >> cartesianPoint.x;
            cout << "Y-Value: ";
            cin >> cartesianPoint.y;

            cout << "PBV:" << endl;
            PolarCoordinate polarCoordinate = cartesianToPolarPBV(cartesianPoint);
            cout << "Radius: " << polarCoordinate.radius << endl;
            cout << "Angle (theta): " << polarCoordinate.theta << " radians" << endl;

            cout << "PBR:" << endl;
            double radius;
            double angle;
            cartesianToPolarPBR(cartesianPoint.x, cartesianPoint.y, radius, angle);
            cout << "Radius: " << radius << endl;
            cout << "Angle (theta): " << angle << endl;

            break;
        }
        case 2:
        {
            PolarCoordinate polarCoordinate{};
            cout << "Radius: ";
            cin >> polarCoordinate.radius;
            cout << "Angle (theta) in radians: ";
            cin >> polarCoordinate.theta;
            cout << endl;

            cout << "PBV:" << endl;
            CartesianPoint cartesianPoint = polarToCartesianPBV(polarCoordinate);
            cout << "X-Value: " << cartesianPoint.x << endl;
            cout << "Y-Value: " << cartesianPoint.y << endl;

            cout << "PBR:" << endl;
            double x;
            double y;
            polarToCartesianPBR(polarCoordinate.radius, polarCoordinate.theta, x, y);
            cout << "X-Value: " << x << endl;
            cout << "Y-Value: " << y << endl;

            break;
        }
    }

    return 0;
}

CartesianPoint polarToCartesianPBV(const PolarCoordinate polarCoordinate)
{
    CartesianPoint cartesianPoint{};
    cartesianPoint.x = polarCoordinate.radius * cos(polarCoordinate.theta);
    cartesianPoint.y = polarCoordinate.radius * sin(polarCoordinate.theta);
    return cartesianPoint;
}

PolarCoordinate cartesianToPolarPBV(const CartesianPoint cartesianPoint)
{
    PolarCoordinate polarCoordinate{};
    polarCoordinate.radius = sqrt(cartesianPoint.x * cartesianPoint.x + cartesianPoint.y * cartesianPoint.y);
    polarCoordinate.theta = atan(cartesianPoint.y / cartesianPoint.x);
    return polarCoordinate;
}

void polarToCartesianPBR(const double radius, const double angle, double &xCoord, double &yCoord)
{
    xCoord = radius * cos(angle);
    yCoord = radius * sin(angle);
}

void cartesianToPolarPBR(const double xCoord, const double yCoord, double &radius, double &angle)
{
    radius = sqrt(xCoord * xCoord + yCoord * yCoord);
    angle = atan(yCoord / xCoord);
}