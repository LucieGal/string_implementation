#include "String.h"
#include <cstring>
#include <cmath>

String::String(){
    capacity_ = 6;
    size_ = 5;
    // char* foo = "Hello World";
    str_ = new char[size_+1]{'H', 'e', 'l', 'l', 'o', '\0'};
};

String::String(char* input_string){
    String s;
    size_ = std::strlen(input_string);
    capacity_ = std::ceil(size_+1/10)*10; // need to add a barrier for max_size later
    str_ = input_string;
}

String::~String(){
    delete str_;
};

size_t String::size(){
    return size_;
}

size_t String::max_size(){
    return max_size_;
};

/*
void String::resize(size_t new_size, char filler){
    //size_t current = size_; //probably not interesting
    if (size_ > new_size){

    }
}
*/

char* String::str(){
    return str_;
};

String::String(const String& c){
	capacity_ = c.capacity_;
	size_ = c.size_;
	str_ = c.str_ ;
};

size_t String::capacity(){
    return capacity_;
}

bool String::empty(){
    if (size_ == 0){
        return true;
    } else {
        return false;
    };
};

void String::reserve(size_t n){
    if (n > max_size_){
        n = max_size_;
    };
    
    capacity_ = n;

    char* temp = new char[n];
    if ( size_+1 > n ) {
        size_ = n-1;
    };

    for (int i = 0; i < (int) size_+1; ++i){ 
        temp[i] = str_[i];
    };

    str_ = temp;
};


void String::operator=(const char* s){
    char c = s[0];
    int i = 0;
    while (c != '\0'){
        c = s[i];
        if (i > (int) capacity_){
            reserve(i+10);
        }
        str_[i] = c;
        ++i;
    };
}

// void String::operator+(const String& str1, const String& str2){
//     String temp(str1.c_str());
//     temp.reserve(40);
//     int size_str1 = (int) str1.size();
//     char c = str2[0];
//     int i = 0;
//     while (c != '\0'){
//         c = str2[i];
//         if (i > (int) capacity_){
//             reserve(i+10);
//         }
//         str_[size_str1 + i] = c;
//         ++i;
//     };

//     size_ = str1.size() + str2.size()
//     str_ = temp;
// };
