#include "Graph.h"

Graph::Graph(int day, std::string month, int year)
    : date(day, month, year), size(0) {}

void Graph::addCoordinates(int x, int y) {
    if (size < 100) {
        coords[size].setX(x);
        coords[size].setY(y);
        ++size;
    }
}

void Graph::writeToFile(std::ofstream& outFile) {
    date.writeToFile(outFile);
    for (int i = 0; i < size; ++i) {
        coords[i].writeToFile(outFile);
    }
}
