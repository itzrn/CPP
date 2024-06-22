#include<iostream>
using namespace std;

// user defined data type
struct employee { // in java we need to make anotheer class for abstract data type
  /* data */
  int id; //4bye
  char fav_char; // 1 byte
  float salary; // 4 byte

  // in struct we have used 9 byte to keep the data of any employee
};

// another way to make userdefind datat type
typedef struct foodDetail{
  string name;
  int count;
} fd;

union money{ // union is used for better memory management
  // anyone of the thing will get used amoung them, as the memory is shared
  int rice;
  int pounds;
  char car;

  // soo according to the situation you use the data daye and with that size only memory will get allocate
};

int main(){
  // like this we can make many number of employee containing there info
  struct employee aryan;
  aryan.id = 1;
  aryan.fav_char='i';
  aryan.salary=865.50f;

  cout<<aryan.salary<<endl;



  // now fooDetail can easly be used as, fd is working as datatype
  fd aalu;
  aalu.name = "Potato";
  aalu.count = 100; 

  cout<<"aalu name -> "<<aalu.name<<endl;
  cout<<"aalu count ->"<<aalu.count<<endl;


  // union
  union money m1;
  m1.rice = 34;
  // m1.car = 'c' // if this line will get used then 'cout<<m1.rice<<endl;' wil print garbage value, but you will get correct value m1.car.
  cout<<m1.rice<<endl;


  // this can be study latter
  enum Meal{breakfast, lunch, dinner};
  Meal me1 = breakfast;

  return 0;
}