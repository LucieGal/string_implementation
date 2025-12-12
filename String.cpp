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

size_t String::size(){
    return size_;
}

size_t String::max_size(){
    return max_size_;
}

/*
void String::resize(size_t new_size, char filler){
    //size_t current = size_; //probably not interesting
    if (size_ > new_size){

    }
}
*/

char* String::str(){
    return str_;
}