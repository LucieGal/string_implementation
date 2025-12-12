#include "String.h"
#include <iostream>

int main(){
    String str;
    std::cout << str.str() << std::endl;
    std::cout << str.size() << std::endl;

    str.reserve(15);
    std::cout << str.str() << std::endl;
    std::cout << str.capacity() << std::endl;

    // str.reserve(3);
    // std::cout << str.str() << std::endl;
    // std::cout << str.capacity() << std::endl;

    char* s = new char[16]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '!', '\0'};
    str = s;
    std::cout << str.str() << std::endl;
    

    // A tester avec c-string constructor
    
    // String str2;
    // str = str + str2;
    // std::cout << str.str() << std::endl;


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
