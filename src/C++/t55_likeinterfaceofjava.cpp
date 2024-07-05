#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual int tata()=0;
};


class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
    
    int tata(){
        return 0;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main(int argc, char const *argv[]) {
    // Square s; // you can't make square's object be the Square class is abstruct 
                // class as the virtual function of base class in not defined in the derived class

    Circle c; // now the object of the class can be intatiated, bcz the Circle class is not the abstract class any more
    return 0;
}
