#include<iostream>
#include "timee.h"


int main(){
    timee a(9, 9);
    timee b(1, 1);
    a = 2 * b;
    std::cout << a << b;
    return 0;
}