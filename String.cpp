#include "String.h"
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <iostream>

String::String(){
    capacity_ = 10;
    size_ = 5;
    str_ = new char[size_+1]{'H', 'e', 'l', 'l', 'o', '\0'};
}

String::String(const char* input_string){
    if (input_string== nullptr){
        capacity_ = 10;
        size_ = 0;
        str_ = new char[capacity_];
        str_[0] = '\0';
        return;
    }

    size_ = std::strlen(input_string);

    // The default capacity is the nearest multiple of 10
    size_t temp = std::ceil((size_+1)/10)*10;
    if (temp > max_size_){
        temp = max_size_;        
    }
    capacity_ = temp; // need to add a barrier for max_size later >> done

    str_ = new char[capacity_];
    std::strcpy(str_, input_string);
}

String::String(const String& c_str){
	capacity_ = c_str.capacity_;
	size_ = c_str.size_;
	str_ = new char[size_+1];
    str_ = c_str.str_;
    
}

String::~String(){
    delete str_;
}

size_t String::size() const{
    return size_;
}

size_t String::max_size() const{
    return max_size_;
}


void String::resize(size_t new_size, char filler){
    if (new_size > max_size_){
        throw std::length_error("Length Error in resize: new_size greater than max_size_");
    }
        
    if (size_ < new_size){
        if (capacity_ <= new_size){
            reserve(new_size+1);
        }
        for (size_t i = size_; i < new_size; ++i){
            str_[i] = filler;
        }
        str_[new_size] = '\0';

    }else if (size_ > new_size){
        str_[new_size] = '\0';
    }

   size_ = new_size;
}


char* String::c_str(){
    return str_;
}



size_t String::capacity(){
    return capacity_;
}

void String::clear(){
	char* clear_ = new char[1]{'\0'};
    delete str_;
	str_ = clear_;
    size_ = 0;
}


bool String::empty(){
    if (size_ == 0){
        return true;
    } else {
        return false;
    }
}

	

void String::reserve(size_t n){
    if (n > max_size_){
        n = max_size_;
    }
    
    capacity_ = n;

    char* temp = new char[n];
    if ( size_+1 > n ) {
        size_ = n-1;
    }

    for (int i = 0; i < (int) size_+1; ++i){ 
        temp[i] = str_[i];
    }

    delete str_;
    str_ = temp;
}


String& String::operator=(const char c){
	resize(1);
    delete str_;
	str_ = new char [2] {c, '\0'};
	return *this;
}


String& String::operator=(const String& str){
    if (this != &str){
        if (str.size() > capacity_){
            delete str_;
            capacity_ = str.size();
            str_ = new char[capacity_ +1];
        }

        size_ = str.size();
        for (size_t i = 0; i<size_; ++i){
            str_[i] = str.str_[i];
        }
        str_[size_] = '\0';
    }
    return *this;
}

String& String::operator=(const char* s){ 
    
    int size = 0;
    while (s[size] != '\0') size++;

    char c = s[0];
    int i = 0;

    if (size == (int) max_size_) {
        throw std::length_error("Length Error: string's size greater than max_size_");
    }
    resize(size+1, '.');
    while (c != '\0'){
        c = s[i];
        if (i > (int) capacity_){
            reserve(i+10);
        }
        str_[i] = c;
        ++i;
    }
    size_ = i;
    return *this;
}

String operator+(const String& str, const char* s){
 	String new_str(str);

    std::cout << new_str.size() << std::endl;
	int size = 2;                               // to take into account the '\0'
    while (s[size] != '\0') size++;

    size_t new_size = str.size() + size;
    
    std::cout << new_str.c_str() << std::endl;
    std::cout << s << std::endl;
    std::cout << new_size << std::endl;
	if (new_size > str.max_size()){
		throw std::length_error("Length Error: resulting string's size would be greater than max_size_");
	} else {
        if (new_size > new_str.capacity()){
            new_str.reserve( 10 + new_size );
        }
		for (int i=0; i< size + 1; i++){
			new_str.c_str() [i + str.size()] = s[i];
		}
		
	}
	return new_str;
}


// String operator+(const String& str, char s){
//     String new_str;

//     size_t new_size = str.size() + 1;
//     	if (new_size+1 > str.max_size()){
//     		throw std::length_error("Length Error: resulting string's size would be greater than max_size_");
//     	} else {
//             for (int i=0; i < (int) str.size()-1; ++i){
//                 new_str.str_[i] = str.str_[i];
//             }
//         }
//     new_str.str_[str.size()] = s;
//     new_str.str_[new_str.size()] = '\0';

//     return new_str;
// }


String operator+(const String& str1, const String& str2){
    String new_str(str1);
    String next_string(str2);
    size_t size = str1.size() + str2.size();

    new_str.reserve(10 + size);        

    

    int size_str1 = (int) str1.size();
    char c = next_string.c_str()[0];
    int i = 0;
    if (size > new_str.max_size()){
        throw std::length_error("Length Error: resulting string's size would be greater than max_size_");
    } else {
        while (c != '\0'){
            c = next_string.c_str()[i];
            // std::cout << c << std::endl;
            new_str.c_str()[size_str1 + i] = c;
            // std::cout << new_str.c_str() << std::endl;
            ++i;
        }
    }
    // std::cout << new_str.c_str()[19] << std::endl;
    return new_str;
}
