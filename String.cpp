# include "String.h"

String::String(){
    capacity_ = 6;
    size_ = 6;
    // char* foo = "Hello World";
    str_ = new char[6]{'H', 'e', 'l', 'l', 'o', '\0'};
};

size_t String::size(){
    return size_-1;
}

char* String::str(){
    return str_;
}