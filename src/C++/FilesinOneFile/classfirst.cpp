#include "classfirst.h"
#include <iostream>

void classfirst::publicMethod() {
    std::cout << "Hello from publicMethod!" << std::endl;
}

int classfirst::add(int a, int b) {
    return a + b;
}
