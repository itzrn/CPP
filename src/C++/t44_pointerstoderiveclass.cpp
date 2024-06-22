#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Base{
    public:
        int var_base=10;
        void getData(void){
            cout<<"This is the base class variable value ->"<<this->var_base<<endl;
        }
};

class Derived : public Base{
    public:
        int var_derived=11;
        void getData(void){
            cout<<"This is the derived class variable value from Base class ->"<<this->var_base<<endl;
            cout<<"This is the derived class variable value ->"<<this->var_derived<<endl;
        }
};

int main() {
    /*
        Base class pointer can point to derived class reference
        but using this base class pointer you can only call the function of base class
        this is called late binding
    */

    Base *base_class_pointer;
    Base base_obj;
    Derived derived_obj;

    // here pointer is of base class and object is of derived class
    // pointer jis class ka hota ha uska function acces hota ha us pointer se
    base_class_pointer = &derived_obj;
    base_class_pointer->getData();


    Derived *derived_class_pointer;
    derived_class_pointer = &derived_obj;
    derived_class_pointer->getData(); // this function of base class will get override with derived class


    // the above technique is called run time polymorphism, at run time the pointer decide which function will get call
    // this is the default behaviour
    
    return 0;
}