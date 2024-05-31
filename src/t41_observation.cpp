#include <map>
#include <iostream>
using namespace std;
class T{
    public:
        int a;
        int b;
};
int main() {
    T *ptr = new T[2];
    T *ptrTemp = ptr; // on increasing the pointer ptr value will get update(according to the bellow techinque), so to retrive the starting index of array object using a temproary variable
    while(ptr != nullptr){ // this loop will go infinite, the reason is ptr gets a location in RAM
    // even on inceresing the address, so u need to externally but a loop for 2 times to terminate
        cout<<"Aryan"<<endl;
        int c, d;
        cin>>c>>d;
        ptr->a=c;
        ptr->b=d;
        ptr++;
    }

    return 0;
}
