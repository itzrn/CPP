#include <iostream>
#include "classfirst.h"
using namespace std;

int main() {
    classfirst myObject;
    myObject.publicMethod();
    int result = myObject.add(5, 3);
    cout << "5 + 3 = " << result << endl;
    return 0;
}
