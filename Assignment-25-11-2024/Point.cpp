// Implementation of Point class
#include "Point.h"

// Constructor
Point::Point(int x, int y) : x(x), y(y) {}

// Getter for x
int Point::getX() const {
    return x;
}

// Setter for x
void Point::setX(int x) {
    this->x = x;
}

// Getter for y
int Point::getY() const {
    return y;
}

// Setter for y
void Point::setY(int y) {
    this->y = y;
}
