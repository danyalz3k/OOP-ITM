#include <iostream>
#include <fstream>   // For file handling
#include <vector>    // For storing Employee objects
#include "Employee.h"

using namespace std;

// Function to read employee data from a file.
vector<Employee> readEmployeeData(const string& filePath) {
    vector<Employee> employees; // To store all employees
    ifstream file(filePath);    // Input file stream

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return employees; // Return empty vector if file fails to open
    }

    string lastName, firstName;
    double salary, raisePercent;

    // Read data line by line
    while (file >> lastName >> firstName >> salary >> raisePercent) {
        employees.emplace_back(firstName, lastName, salary, raisePercent);
    }

    file.close(); // Close the file after reading
    return employees;
}

// Function to write updated employee data to a file.
void writeEmployeeData(const string& filePath, const vector<Employee>& employees) {
    ofstream file(filePath); // Output file stream

    if (!file.is_open()) {
        cerr << "Error writing to file!" << endl;
        return;
    }

    // Write each employee's info to the file
    for (const auto& emp : employees) {
        file << emp.getInfo() << endl;
    }

    file.close(); // Close the file after writing
}

int main() {
    string inputFile = "raise_stats.txt";   // File containing original data
    string outputFile = "raise_output.txt"; // File to store updated data

    // Step 1: Read employees from file
    vector<Employee> employees = readEmployeeData(inputFile);

    // Step 2: Apply pay raises to each employee
    for (auto& emp : employees) {
        emp.raisePay();
    }

    // Step 3: Write updated employee data back to file
    writeEmployeeData(outputFile, employees);

    cout << "Updated salary data written to " << outputFile << endl;
    return 0; // Indicate successful execution
}
