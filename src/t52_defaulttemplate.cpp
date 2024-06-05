#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

template <class T1=int, class T2=float>
class Aryan{
    public:
        T1 a;
        T2 b;
};

int main() {
    float a=12.90f;
    printf("This is %.2f\n", a);
    cout << "This is " << fixed << setprecision(2) << a <<endl;
    return 0;
}