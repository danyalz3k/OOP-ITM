#include "Polygon.h"
using namespace std;

// Constructor
Polygon::Polygon(int n) : numPoints(n) {
    points = new Point[numPoints]; // Allocate memory for points
}

// Copy Constructor
Polygon::Polygon(const Polygon& other) : numPoints(other.numPoints) {
    points = new Point[numPoints]; // Allocate memory for the new array
    for (int i = 0; i < numPoints; ++i) {
        points[i] = other.points[i]; // Copy each point
    }
}

// Destructor
Polygon::~Polygon() {
    delete[] points; // Deallocate memory
}

// Print function
void Polygon::print() const {
    for (int i = 0; i < numPoints; ++i) {
        cout << "(" << points[i].getX() << "," << points[i].getY() << ")";
        if (i < numPoints - 1) cout << " ";
    }
    cout << endl;
}
