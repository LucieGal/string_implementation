# include "String.h"

String::String(){
    capacity_ = 15;
    size_ = 11;
    // char* foo = "Hello World";
    str_ = new char*;
    str_ =  "Hello World";
};