#include "Point.h"
#include <iostream>

class Polygon {
public:
    Point* points; // Dynamically allocated array of Points
    int numPoints; // Number of points in the polygon

    // Constructor with default number of points
    Polygon(int n = 4);

    // Copy constructor
    Polygon(const Polygon& other);

    // Destructor
    ~Polygon();

    // Print function
    void print() const;
};
