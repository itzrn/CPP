// this is use to store the Dice info and give the randon number of each chance

#ifndef DICE_H
#define DICE_H

#include <cstdlib>//or #include <iostream>, to use rand, srand
#include <ctime> // this is used to calculate the current time
using namespace std;

class dice {
public:
    dice() { // keeping the default value to be 6, a dice have 6 number as max
        srand(time(0)); // Seed for random number generator
    }
    int get_dice_value() const{
        return (rand() % 6) + MIN;
    }

private:
    static const int MIN = 1; //  in this context means that MIN is a class-level variable, not tied to any particular instance of the class
    // This allows MIN to be accessed using the class name itself (ClassName::MIN) without needing an instance of the class.
    // const means MIN cannot be modified once it is initialized.
};


/*
     Being static means the function/variable belongs to the class itself rather than to instances (objects) of the class


     if there is a static variable in a function then that variable lifetime is through out the whole class
     but it is not accessable using this you can change other variable : like ->

     class test{
        int b=0;
        public:
            void start(){
                static int a = 10;
                a++;

                b=a; 
                this can't be done bcz
                try to assign b = a; inside start(), it implies that a (being static) is 
                shared among all instances of test, but b belongs to a specific instance of test. 
                This is not allowed because static variables cannot directly access non-static member 
                variables or belong to an instance of a class.
            }
     };
*/

#endif
