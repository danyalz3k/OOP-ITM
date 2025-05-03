#include "Polygon.h"
using namespace std;

int main() {
    // Create first polygon and set its points
    Polygon p1(4);
    p1.points[0].setX(2); p1.points[0].setY(3);
    p1.points[1].setX(6); p1.points[1].setY(1);
    p1.points[2].setX(12); p1.points[2].setY(9);
    p1.points[3].setX(18); p1.points[3].setY(12);

    // Create second polygon using copy constructor
    Polygon p2(p1);

    // Print points of both polygons
    cout << "Initial Points of p1: ";
    p1.print();
    cout << "Initial Points of p2: ";
    p2.print();

    // Modify points in both polygons
    p1.points[0].setX(5); p1.points[0].setY(7);
    p2.points[2].setX(14); p2.points[2].setY(11);

    // Print updated points of both polygons
    cout << "Updated Points of p1: ";
    p1.print();
    cout << "Updated Points of p2: ";
    p2.print();

    return 0;
}
