#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Normal member function
    void print() {
        std::cout << "Printing shape." << std::endl;
    }
};

// Concrete classes derived from Shape
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    // Shape* cannot be instantiated directly because it's abstract
    // Shape shape; // Error: Cannot instantiate abstract class

    Circle circle;
    Square square;

    circle.draw(); // Output: Drawing a circle.
    square.draw(); // Output: Drawing a square.

    return 0;
}
