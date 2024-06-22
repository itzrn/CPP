#include<iostream>
#include<string>
using namespace std;

class Shop{
  int itemId[100];
  int itemPrice[100];
  int counter;

  public:
    void initCounter(){
      counter=0;
    }

    void setPrice(void);
    void displayPrice(void);
} dukaan;


void Shop :: setPrice(){
  cout<<"Enter Id of your item no "<<counter+1<<" -> "<<endl;
  cin>>itemId[counter];
  cout<<"Enter price of your item"<<endl;
  cin>>itemPrice[counter];
  counter++;
}

void Shop ::displayPrice(){
  for(int i=0; i<this->counter; i++){
    cout<<"The price of item with id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
  }
}

int main(){
  dukaan.initCounter();
  dukaan.setPrice();
  dukaan.setPrice();
  dukaan.setPrice();
  dukaan.setPrice();
  dukaan.displayPrice();
  return 0;
}