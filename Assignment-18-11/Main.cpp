#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;

vector<Employee> readEmployeeData(const string& filePath) {
    vector<Employee> employees;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return employees;
    }

    string lastName, firstName;
    double salary, raisePercent;

    while (file >> lastName >> firstName >> salary >> raisePercent) {
        employees.emplace_back(firstName, lastName, salary, raisePercent);
    }

    file.close();
    return employees;
}

void writeEmployeeData(const string& filePath, const vector<Employee>& employees) {
    ofstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error writing to file!" << endl;
        return;
    }

    for (const auto& emp : employees) {
        file << emp.getInfo() << endl;
    }

    file.close();
}

int main() {
    string inputFile = "raise_stats.txt";
    string outputFile = "raise_output.txt";

    vector<Employee> employees = readEmployeeData(inputFile);

    for (auto& emp : employees) {
        emp.raisePay();
    }

    writeEmployeeData(outputFile, employees);

    cout << "Updated salary data written to " << outputFile << endl;
    return 0;
}
