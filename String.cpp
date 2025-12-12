# include "String.h"

String::String(){
    capacity_ = 6;
    size_ = 6;
    // char* foo = "Hello World";
    str_ = new char[6]{'H', 'e', 'l', 'l', 'o', '\0'};
};

String::~String(){
    delete str_;
}

char* String::str(){
    return str_;
}

int String::capacity(){
    return capacity_;
}

bool String::empty(){
    if (size_ == 0){
        return true;
    } else {
        return false;
    }
}