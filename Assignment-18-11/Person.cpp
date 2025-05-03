#include "Person.h"

Person::Person(const string& firstName, const string& lastName)
    : firstName(firstName), lastName(lastName) {}

string Person::getFullName() const {
    return firstName + " " + lastName;
}
