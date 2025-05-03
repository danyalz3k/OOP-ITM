#include "Coordinate.h"
#include <fstream>

Coordinate::Coordinate() : x(0), y(0) {}

void Coordinate::setX(int x) {
    this->x = x;
}

void Coordinate::setY(int y) {
    this->y = y;
}

void Coordinate::writeToFile(std::ofstream& outFile) const {
    outFile << "(" << x << "," << y << ")" << std::endl;
}
