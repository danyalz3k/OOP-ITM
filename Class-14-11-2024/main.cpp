#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {
    std::string filename, month;
    int day, year, x, y, choice;

    std::cout << "Enter the name of the file to write to: ";
    std::cin >> filename;

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return 1;
    }

    std::cout << "Enter the day: ";
    std::cin >> day;
    std::cout << "Enter the month: ";
    std::cin >> month;
    std::cout << "Enter the year: ";
    std::cin >> year;

    Graph graph(day, month, year);

    do {
        std::cout << "Enter x-coordinate: ";
        std::cin >> x;
        std::cout << "Enter y-coordinate: ";
        std::cin >> y;
        graph.addCoordinates(x, y);

        std::cout << "Press 0 to quit or 1 to enter another coordinate: ";
        std::cin >> choice;
    } while (choice != 0);

    graph.writeToFile(outFile);
    std::cout << "Graph coordinates successfully written to " << filename << "." << std::endl;

    outFile.close();
    return 0;
}
