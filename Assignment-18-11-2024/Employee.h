#include "Person.h"

// Derived class from Person to represent employees.
class Employee : public Person {
private:
    double salary;         // Current salary
    double raisePercent;   // Percentage raise to be applied

public:
    // Constructor to initialize all employee details.
    Employee(const string& firstName, const string& lastName, double salary, double raisePercent);

    // Function to calculate and apply the salary raise.
    void raisePay();

    // Retrieve the current salary after the raise.
    double getSalary() const;

    // Retrieve full information for an employee.
    string getInfo() const;
};
