#include<iostream>
using namespace std;
#include<string>

class Shop{
    int id;
    float price;

    public:
        Shop(){}
        Shop(int id, float price):id(id), price(price){}
        void getData(){
            cout<<"The id of the item is -> "
            <<this->id<<endl;
            cout<<"The price of the item is -> "<<this->price<<endl;
        }
};

int main(){
    Shop *ptr = new Shop[3];
    for(int i=0; i<3; i++){
        int p,q;
        cout<<"Enter the value of p and q ->"<<endl;
        cin>>p>>q;
        *(ptr+i) = Shop(p, q);
        ptr->getData();
        // ptr++; // or instead in above line *(ptr+i) = Shop(p, q);
    }

    return 0;
}