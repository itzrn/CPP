#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0)); // this change the value based on the current time
    for(int i=0; i<5; i++){
        cout<<(rand()%6)+1<<endl; // generating random value from 1 to 6
    }
    return 0;
}
