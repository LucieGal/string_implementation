# include "String.h"

String::String(){
    capacity_ = 6;
    size_ = 5;
    // char* foo = "Hello World";
    str_ = new char[size_+1]{'H', 'e', 'l', 'l', 'o', '\0'};
};

size_t String::size(){
    return size_;
}

size_t String::max_size(){
    return max_size_;
}

char* String::str(){
    return str_;
}