#include "Date.h"
#include "Coordinate.h"
#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string filename, monthInput;
    int dayInput, yearInput, choice, xInput, yInput;

    cout << "Enter the name of the file to write to: ";
    getline(cin, filename);
    cout << "\nEnter the day (e.g., 7, 22, 25 etc.): ";
    cin >> dayInput;
    cout << "Enter the month (e.g., March, November etc.): ";
    cin >> monthInput;
    cout << "Enter the year (e.g., 2017): ";
    cin >> yearInput;
    cout << endl;

    Graph graph(dayInput, monthInput, yearInput);

    do {
        cout << "Enter x-coordinate: ";
        cin >> xInput;
        cout << "Enter y-coordinate: ";
        cin >> yInput;
        graph.addPoint(xInput, yInput);
        cout << "Press 0 to quit or 1 to enter another coordinate: ";
        cin >> choice;
    } while (choice != 0);

    ofstream myFile(filename, ios::app);
    graph.saveToFile(myFile);
    cout << "\nGraph coordinates successfully written to: " << filename << endl;
}
