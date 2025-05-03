#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string firstName;
    string lastName;

public:
    Person(const string& firstName, const string& lastName);
    string getFullName() const;
};

#endif // PERSON_H
