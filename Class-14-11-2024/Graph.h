#include <string>
#include <fstream>
#include "Coordinate.h"
#include "Date.h"

class Graph {
public:
    Graph(int day, std::string month, int year);
    void addCoordinates(int x = 0, int y = 0);
    void writeToFile(std::ofstream& outFile);

private:
    int size;
    Coordinate coords[100];
    Date date;
};
