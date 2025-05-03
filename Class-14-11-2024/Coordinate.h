#include <fstream>

class Coordinate {
public:
    Coordinate();            // Constructor
    void setX(int x);        // Set x-coordinate
    void setY(int y);        // Set y-coordinate
    void writeToFile(std::ofstream& outFile) const; // Write coordinate to file

private:
    int x;
    int y;
};
