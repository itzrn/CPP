#include<iostream>
using namespace std;
#include<string>

class Number{
    int a;
    public:
        Number(){}
        Number(int a){
            this->a=a;
        }

        Number(Number& obj){ // this will work as copy constructor
            cout<<"Constructor got copied"<<endl;
            this->a = obj.a;
        }


}test1(10), test2(test1);

int main(){
    
}