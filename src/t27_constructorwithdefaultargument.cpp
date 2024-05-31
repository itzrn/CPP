#include<iostream>
using namespace std;
#include<string>

class Simple{
    int a, b;
    public:
        Simple(int a, int b=10){ // using argument as default value
            this->a=a;
            this->b=b;
        }

        void print(){
            cout<<this->a<<endl;
            cout<<this->b<<endl;
        }
}test(8), test2(20, 29);

int main(){
    test.print();
    test2.print();
}