#include<iostream>
using namespace std;
#include<string>

/*
Protected access modifiers are similar to the private access modifiers but protected access modifiers can be accessed in the derived class whereas private access modifiers cannot be accessed in the derived class. A table is shown below which shows the behavior of access modifiers when they are derived “public”, “private”, and “protected”.

 	                     Public Derivation      	 Private Derivation    	    Protected Derivation
Private members           	Not Inherited              	Not Inherited              	Not Inherited              
Protected members           Protected                   Private                     Protected                    
Public members           	Public	                    Private                     Protected 

As shown in the table,

If the class is inherited in public mode then its private members cannot be inherited in child class.
If the class is inherited in public mode then its protected members are protected and can be accessed in child class.
If the class is inherited in public mode then its public members are public and can be accessed inside child class and outside the class.
If the class is inherited in private mode then its private members cannot be inherited in child class.
If the class is inherited in private mode then its protected members are private and cannot be accessed in child class.
If the class is inherited in private mode then its public members are private and cannot be accessed in child class.
If the class is inherited in protected mode then its private members cannot be inherited in child class.
If the class is inherited in protected mode then its protected members are protected and can be accessed in child class.
If the class is inherited in protected mode then its public members are protected and can be accessed in child class.
*/

class Base{
    protected: // private hi ha but inherit ho jyega, but you can not call using object
        int a;
    
    private:
        int b;
    

};

class Derived : protected Base{
    
};

int main(){
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}