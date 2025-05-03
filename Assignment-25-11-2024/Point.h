class Point {
private:
    int x;
    int y;

public:
    // Constructor with default values
    Point(int x = 0, int y = 0);

    // Getter and Setter for x
    int getX() const;
    void setX(int x);

    // Getter and Setter for y
    int getY() const;
    void setY(int y);
};