#include<iostream>
using namespace std;

template <class T>
class Harry
{
public:
    T data;
    Harry(T a)
    {
        data = a;
    }
    void display();
};
 
template <class T>
void Harry<T> :: display(){
    cout<<data;
}
 
void func(int a){
    cout<<"I am first func() "<<a<<endl;
}
 
template<class T>
void func(T a){
    cout<<"I am templatised func() "<<a<<endl;
}

int main()
{
    func(4);  //Exact match takes the highest priority
    func('n'); // this usses the generic function
    return 0;
}

