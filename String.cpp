# include "String.h"

String::String(){
    capacity_ = 6;
    size_ = 5;
    // char* foo = "Hello World";
    str_ = new char[size_+1]{'H', 'e', 'l', 'l', 'o', '\0'};
};


String::~String(){
    delete str_;
}

size_t String::size(){
    return size_;
}

size_t String::max_size(){
    return max_size_;
}

char* String::str(){
    return str_;
}

size_t String::capacity(){
    return capacity_;
}

bool String::empty(){
    if (size_ == 0){
        return true;
    } else {
        return false;
    }
}

void String::reserve(size_t n){
    capacity_ = n;
    char* temp = new char[n];
    if ( size_+1 > n ) {
        size_ = n-1;
    };

    for (int i = 0; i < (int) size_+1; ++i){ 
        temp[i] = str_[i];
    };

    str_ = temp;
}