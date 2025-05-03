#include <string>
using namespace std;

// Base class for handling common person-related data.
class Person {
protected:
    string firstName; // Employee's first name
    string lastName;  // Employee's last name

public:
    // Constructor to initialize a Person's name.
    Person(const string& firstName, const string& lastName);

    // Returns the full name in "First Last" format.
    string getFullName() const;
};
