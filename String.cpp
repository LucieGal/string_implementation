#include "String.h"
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <iostream>

String::String(){
    capacity_ = 10;
    size_ = 5;
    // char* foo = "Hello World"; >> Should we delete this?
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
    //!\\ Don't know if the loop below is useful given it is
    //    supposed to throw a std::length_error in this case,
    //    but I don't know how to do this by myself :/ 
    //    Found it :), not sure of myself though
    if (new_size > max_size_){
        //new_size = max_size_;
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

String::String(const String& c_str){
	capacity_ = c_str.capacity_;
	size_ = c_str.size_;
	str_ = new char[size_+1];
}

size_t String::capacity(){
    return capacity_;
}

void String::clear(){
	char* clear_ = new char[1]{'\0'};
	str_ = clear_;
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

    str_ = temp;
}

String operator=(const char c){
	str_.clear();
	str_ = new char[2]{c,'\0'};
	return str_;
}

/*
void String::operator=(const String& str){
    if (*this != str){
        if (str.size() > capacity_){

        }

    }
}
*/

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
    }
}

 String operator+(const String& str, const char* s){
 	String new_str;
	
    	size_t new_size = str.size() + sizeof(s);
    	if (new_size > str.max_size()){
    		std::cout<<"Erreur"<<std::endl;
    	}
    	else {
    		for (size_t i=0; i < str.size(); i++){
    			new_str.str_[i] = str.str_[i];
    		}
    		for (size_t i=0; i< sizeof(s) + 1; i++){
    			new_str.str_[i + str.size()] = s[i];
    		}
    		
    	}
    	return new_str;
}

/*
void String::operator+(String& str1, char s){

}
*/

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
//     }

//     size_ = str1.size() + str2.size()
//     str_ = temp;
// }
