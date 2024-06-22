#include<iostream>
using namespace std;

// Destructor never takes an argument nor does it return any value 
int count=0;

class num{
    public:
        num(){
            count++;
            cout<<"This is the time when constructor is called for object number"<<count<<endl;
        }

        ~num(){
            cout<<"This is the time when my destructor is called for object number"<<count<<endl; // the red line are warning
            count--;
        }
};

    /*
    let there be an object which you created, and at some instance there is no use of
    then it is a good practice to destroy that object 
    which actually taking memory dynamically

    destructor never take any argument nor return any value
    this get run by compiler implicitly 
    */

int main(){
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    { // while entryinh this block constructor get called
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;

        // n2 and n3 is inside the block so n2 and n3 will get destruct when the block get ends
    } // while exiting destructor get called
    cout<<"Back to main"<<endl;
    return 0;
}
