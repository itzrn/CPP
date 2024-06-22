#include <iostream>
#include <string>
using namespace std;

// class Aryan;
class Aryan {
    int a, b;
public:
    Aryan() {}
    Aryan(int a, int b) : a(a), b(b) {} // anothrer way to initialize the attribute of class
    //     this->a = a;
    //     this->b = b;
    // }

    Aryan& getObj(){ // this is a way to get the object using this keyword
        return *this;
    }

    void getData() {
        cout << this->a << endl;
        cout << this->b << endl;
    }
};


int main() {
    Aryan *ptr = new Aryan[2];
    ptr[0] = Aryan(10, 20);
    ptr[0].getData();
    ptr[1] = Aryan(10, 20);
    ptr[1].getData();
    // for(int i = 0; i < 2; i++) {
    //     ptr[i] = Aryan(10, 12);
    //     ptr[i].getData();
    // }

    delete[] ptr; // Don't forget to deallocate memory
    return 0;
}