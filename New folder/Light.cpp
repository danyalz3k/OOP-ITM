#include <iostream>
#include "Light.h"

using namespace std;

// Default constructor
Light::Light() : shape('*'), state(false), brightness(5) {}

// Constructor with shape
Light::Light(char s) : shape(s), state(false), brightness(5) {}

// Constructor with shape and brightness
Light::Light(char s, int b) : shape(s), state(false) {
    if (b < 1) brightness = 1;
    else if (b > 10) brightness = 10;
    else brightness = b;
}

// Destructor
Light::~Light() {
    turnOff();
    cout << "Light with shape '" << shape << "' has been destroyed." << endl;
}

// Turn the light on
void Light::turnOn() {
    state = true;
    cout << "Light with shape '" << shape << "' has been turned on." << endl;
}

// Turn the light off
void Light::turnOff() {
    state = false;
    cout << "Light with shape '" << shape << "' has been turned off." << endl;
}

// Brighten the light
void Light::brighten() {
    if (brightness < 10) {
        brightness++;
    }
}

// Dim the light
void Light::dim() {
    if (brightness > 1) {
        brightness--;
    }
}

// Display the light
void Light::display() const {
    if (state) {
        for (int i = 0; i < brightness; i++) {
            cout << shape;
        }
        cout << endl;
    } else {
        cout << "Light is off." << endl;
    }
}

// Set shape
void Light::setShape(char s) {
    shape = s;
}

// Get shape
char Light::getShape() const {
    return shape;
}

// Set brightness
void Light::setBrightness(int b) {
    if (b >= 1 && b <= 10) {
        brightness = b;
    }
}

// Get brightness
int Light::getBrightness() const {
    return brightness;
}
