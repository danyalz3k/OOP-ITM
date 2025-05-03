#include "Employee.h"
#include <sstream>   // For stringstream
#include <iomanip>   // For formatting decimal values

// Initialize Employee with full details, calling Person's constructor for names.
Employee::Employee(const string& firstName, const string& lastName, double salary, double raisePercent)
    : Person(firstName, lastName), salary(salary), raisePercent(raisePercent) {}

// Apply the raise by increasing salary by the specified percentage.
void Employee::raisePay() {
    salary += salary * (raisePercent / 100);
}

// Return the updated salary.
double Employee::getSalary() const {
    return salary;
}

// Format employee information: full name and updated salary.
string Employee::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2) << salary; // Ensure salary is formatted to 2 decimal places
    return getFullName() + " " + ss.str();    // Return name and salary as a single string
}
