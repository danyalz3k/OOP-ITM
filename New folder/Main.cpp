
#include <iostream>
#include "Light.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of lights to create: ";
    cin >> n;

    // Create dynamic array of lights
    Light* lights = new Light[n];

    // Set shape and brightness for each light
    for (int i = 0; i < n; i++) {
        char shape;
        int brightness;
        cout << "Enter the shape of light " << (i + 1) << ": ";
        cin >> shape;
        cout << "Enter the brightness for light " << (i + 1) << ": ";
        cin >> brightness;

        lights[i].setShape(shape);
        lights[i].setBrightness(brightness);
    }

    // Turn on all the lights
    for (int i = 0; i < n; i++) {
        lights[i].turnOn();
    }

    // Display all the lights
    for (int i = 0; i < n; i++) {
        lights[i].display();
    }

    // Clean up: turn off all the lights and delete the array
    delete[] lights;

    return 0;
}