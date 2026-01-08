#include "String.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    String str;
    cout << str.c_str() << endl;
    cout << str.size() << endl;

    String stp = str;
    cout<<stp.c_str()<<endl;
    cout<<stp.size()<<endl;

    cout << endl << "###### TESTING RESIZE ######" << endl;
    String stH("1234567890");
    cout << "Before: " << stH.c_str() << endl;
    stH.resize(5);
    cout << "After: " << stH.c_str() << endl;
    cout << endl;

    str.reserve(15);
    cout << str.c_str() << endl;
    cout << str.capacity() << endl;

    // str.reserve(3);
    // cout << str.str() << endl;
    // cout << str.capacity() << endl;

    char* s = new char[16]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '!', '\0'};
    str = s;
    cout << str.c_str() << endl;
    

    // A tester avec c-string constructor
    
    // String str2;
    // str = str + str2;
    // cout << str.c_str() << endl;

/*
    cout << str.max_size() << endl;

    char* test;
    test = new char[4]{'a','b','c','\0'};
    String custom(test);
    cout << custom.c_str() << endl;
    cout << custom.size() << endl;
    cout << custom.max_size() << endl;
    delete test;
    return 0;
*/

	
};
