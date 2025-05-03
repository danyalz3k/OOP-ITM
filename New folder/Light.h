class Light {
private:
    char shape;
    bool state; // true if on, false if off
    int brightness;

public:
    // Constructors
    Light(); // Default constructor
    Light(char s); // Constructor with shape
    Light(char s, int b); // Constructor with shape and brightness

    // Destructor
    ~Light();

    // Member functions
    void turnOn();
    void turnOff();
    void brighten();
    void dim();
    void display() const;

    // Setters and getters
    void setShape(char s);
    char getShape() const;
    void setBrightness(int b);
    int getBrightness() const;
};
