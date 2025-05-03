#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    double salary;
    double raisePercent;

public:
    Employee(const string& firstName, const string& lastName, double salary, double raisePercent);
    void raisePay();
    double getSalary() const;
    string getInfo() const;
};

#endif // EMPLOYEE_H
