#include <string>
#include <fstream>

class Date {
public:
    Date(int day, std::string month, int year);
    void writeToFile(std::ofstream& outFile) const;

private:
    int day;
    std::string month;
    int year;
};
