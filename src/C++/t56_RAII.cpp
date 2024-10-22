#include <iostream>
#include <string.h>
using namespace std;

/*
RAII stands for Resource Acquisition in initialisation

*/

class Wrapper{
    int* a;
    public:
        Wrapper(int* a):a(a){
            initialize();
        }
        ~Wrapper(){
            delete a;
        }
        void initialize(){
            memset(a, 0, sizeof(a));
        }
        int at(int i){
            return a[i];
        }
        void set(int i, int x){
            a[i]=x;
        }
};

int main(){

    Wrapper wr(new int[10]); // this wrapper object is deleting the heap alocated memory automatically, 
    // as a client we no need to delete it, just like in java its already implemented there we no need 
    // to delete any heap allocated mameory
    wr.set(0, 1);
    cout<<wr.at(0)<<endl;
    return 0;
}
