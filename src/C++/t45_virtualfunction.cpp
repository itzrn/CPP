#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Base{
    public:
        int var_base=10;
        virtual void getData(void){
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
    Base *base_class_pointer;
    Base base_obj;
    Derived derived_obj;

    base_class_pointer = &derived_obj;
    base_class_pointer->getData();

    // virtual function is used to override the default behaviour of run time polymorphism
    // polymorphism is a property by which objects beclong to different classes respond to same message
    return 0;
}