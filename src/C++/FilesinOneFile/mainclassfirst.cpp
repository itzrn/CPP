#include <iostream>
#include "classfirst.h"

int main() {
    classfirst myObject;
    myObject.publicMethod();
    int result = myObject.add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;
    return 0;
}
