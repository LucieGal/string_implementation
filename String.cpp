# include "String.h"

String::String(){
    capacity_ = 6;
    size_ = 6;
    // char* foo = "Hello World";
    str_ = new char[6]{'H', 'e', 'l', 'l', 'o', '\0'};
};

char* String::str(){
    return str_;
}