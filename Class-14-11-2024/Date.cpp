#include "Date.h"

Date::Date(int day, std::string month, int year)
    : day(day), month(month), year(year) {}

void Date::writeToFile(std::ofstream& outFile) const {
    outFile << day << " " << month << " " << year << std::endl;
}
