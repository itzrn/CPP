#include <iostream>
using namespace std;

class Base1 {
    public:
        void great(){
            cout<<"How are you?"<<endl;
        }
};

class Base2 {
    public:
        void great(){
            cout<<"Kasa ho?"<<endl;
        }
};

class Derived : public Base1, public Base2 {
    public:
        void great(){ 
            // if great fun of derived class have its own body then the function will get override on base class
            Base1 :: great();
            // cout<<"Hum bhi hai bhai Derived class ka great"<<endl;
        }
}d;

int main() {
    d.great();
    return 0;
}
