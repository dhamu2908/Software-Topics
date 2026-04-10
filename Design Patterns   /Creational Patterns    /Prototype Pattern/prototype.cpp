#include <iostream>
using namespace std;

// Prototype Base Class
class Shape {
public:
    virtual Shape* clone() = 0;   // Prototype method
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Concrete Prototype: Circle
class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    // Copy constructor (used for cloning)
    Circle(const Circle& other) {
        radius = other.radius;
    }

    Shape* clone() override {
        return new Circle(*this); // invokes copy constructor
    }

    void draw() override {
        cout << "Circle with radius: " << radius << endl;
    }
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    Rectangle(const Rectangle& other) {
        width = other.width;
        height = other.height;
    }

    Shape* clone() override {
        return new Rectangle(*this);
    }

    void draw() override {
        cout << "Rectangle: " << width << " x " << height << endl;
    }
};

// Client Code
int main() {
    // Original objects (prototypes)
    Shape* circle1 = new Circle(10);
    Shape* rect1 = new Rectangle(5, 8);

    // Clone objects
    Shape* circle2 = circle1->clone();
    Shape* rect2 = rect1->clone();

    // Use cloned objects
    circle2->draw();
    rect2->draw();

    // Clean up
    delete circle1;
    delete circle2;
    delete rect1;
    delete rect2;

    return 0;
}
