#include <iostream>
#include <climits>
using namespace std;

template <class T>
class vector{

    public:
        T *arr;
        int size;
        vector(int size){
            this->size=size;
            arr = new T[size];
        }

        T dotProduct(vector &v){
            T d=0;
            for(int i=0; i<size; i++){
                d += this->arr[i]*v.arr[i];
            }

            return d;
        }
};

vector<int> v1(3), v2(3);

int main() {
    
    v1.arr[0]=4;
    v1.arr[1]=3;
    v1.arr[2]=1;
    v2.arr[0]=1;
    v2.arr[1]=0;
    v2.arr[2]=1;

    int a = v1.dotProduct(v2);
    cout<<a<<endl;
    return 0;
}