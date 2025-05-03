#include "Employee.h"
#include <sstream>
#include <iomanip>

Employee::Employee(const string& firstName, const string& lastName, double salary, double raisePercent)
    : Person(firstName, lastName), salary(salary), raisePercent(raisePercent) {}

void Employee::raisePay() {
    salary += salary * (raisePercent / 100);
}

double Employee::getSalary() const {
    return salary;
}

string Employee::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2) << salary;
    return getFullName() + " " + ss.str();
}
