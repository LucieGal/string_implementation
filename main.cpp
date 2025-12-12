#include "String.h"
#include <iostream>

int main(){
    String str;
    std::cout << str.str() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str.max_size() << std::endl;

    char* test;
    test = new char[4]{'a','b','c','\0'};
    String custom(test);
    std::cout << custom.str() << std::endl;
    std::cout << custom.size() << std::endl;
    std::cout << custom.max_size() << std::endl;
    delete test;
    return 0;
};