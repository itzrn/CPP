#include<iostream>
using namespace std;
#include<string>

class Complex{
    int real, img;
    public:
        void setData(int real, int img){
            this->real=real;
            this->img=img;
        }
        void getData(void);
}complex;

void Complex :: getData(){
    cout<<"The real part is -> "<< this->real<<endl;
    cout<<"The imaginary part is -> "<< this->img<<endl;
}

int main(){
    // complex.setData(1, 2);
    // complex.getData();
    // Complec *ptr = new Complex; //  another way to create the pointer of class object
    Complex *ptr = &complex; // this is the way to create the pointer of class
    (*ptr).setData(1, 2);
    (*ptr).getData();

    // ptr->getData(); thisis also a way to get the function, '->' means dereferencing
    // so, (*ptr). = ptr->

    Complex *arr = new Complex[4]; // this is the way to create the arry of object

}