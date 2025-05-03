#include "Person.h"

// Initialize a Person with their first and last names.
Person::Person(const string& firstName, const string& lastName)
    : firstName(firstName), lastName(lastName) {}

// Concatenate first and last names for display.
string Person::getFullName() const {
    return firstName + " " + lastName;
}
