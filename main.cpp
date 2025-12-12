#include "String.h"
#include <iostream>

int main(){
    String str;
    std::cout << str.str() << std::endl;
    std::cout << str.size() << std::endl;

    str.reserve(15);
    std::cout << str.str() << std::endl;
    std::cout << str.capacity() << std::endl;

    str.reserve(3);
    std::cout << str.str() << std::endl;
    std::cout << str.capacity() << std::endl;


    return 0;
};