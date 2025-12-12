#include "String.h"
#include <iostream>

int main(){
    String str;
    std::cout << str.str() << std::endl;
    std::cout << str.size() << std::endl;
    String stp = str;
    std::cout<<stp.str()<<std::endl;
    std::cout<<stp.size()<<std::endl;
    return 0;
};
