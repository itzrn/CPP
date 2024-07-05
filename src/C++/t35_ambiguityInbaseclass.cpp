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
            

            // the bellow two line solve the amibiguity by using scope resolution operator '::'
            Base1 :: great();
            // Base2 :: great();


            // cout<<"Hum bhi hai bhai Derived class ka great"<<endl;
            // if great fun of derived class have its own body then the function will get override on base class, like above
        }
}d;

int main() {
    d.great();
    return 0;
}
