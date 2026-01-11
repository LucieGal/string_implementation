#include "String.h"
#include <iostream>
#include <cassert>
#include <cstring>

using std::cout;
using std::endl;

int test_student_A();
int test_student_B();
int test_student_C();

int main(){

    char* test;
    test = new char[4]{'a','b','c','\0'};
    String custom(test);
    cout << custom.c_str() << endl;
    cout << custom.size() << endl;
    cout << custom.max_size() << endl;
    //delete[] test;
    //delete[] s;

	
	test_student_A();
	test_student_B();
	test_student_C();
	
	return 0;     
	// j'ai rajouté des delete mas je pense que des copy d'elements sont mal fait parceque j'ai un message de double free 
	// mais aucune idee à quelle ligne sans valgrind...
};

int test_student_A(){
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Test de Student A"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Test de copy cobstructor et de c_str"<<std::endl;
	String str("test");
	String new_str(str);
	std::cout<<"new_str est "<<new_str.c_str()<<std::endl;
	std::cout<<std::endl;

	
	std::cout<<"Test de size"<<std::endl;
	std::cout<<"La taille de str est "<<str.size()<<std::endl;
	std::cout<<std::endl;

	 
	std::cout<<"Test de clear"<<std::endl;
	std::cout<<"Le str avant clear() "<<str.c_str()<<std::endl;
	str.clear();
	std::cout<<"Le str après clear() "<<str.c_str()<<std::endl;
	std::cout<<std::endl;
	
	std::cout<<"Test d'opérator=(char)"<<std::endl;
	String Str;
	char* c = new char[2]{'m', '\0'};
	std::cout<<"Notre str est "<<Str.c_str()<<std::endl;
	std::cout<<"on le transforme en str m"<<std::endl;
	Str = c;
	std::cout<<"Notre str maintenant est "<<Str.c_str()<<std::endl;
	std::cout<<"Avec une size de "<<Str.size()<<std::endl;
	std::cout<<std::endl;


	
	std::cout<<"Test d'opérateur+(const string&, const char*)"<<std::endl;
	String str1("string1");
	char* char_array = new char[12]{' ','e','t',' ','p','a','s',' ','s','t','r','\0'};
	std::cout<<"Notre str est : "<<str1.c_str()<<std::endl;
	std::cout<<"Notre char* est : "<<char_array<<std::endl;
	String str2 = str1 + char_array;
	std::cout<<"Ensemble ils forment : "<<str2.c_str()<<std::endl;
	std::cout<<std::endl;


	delete[] c;
	delete[] char_array;
	return 0;
}

void test_custom_ctor(){
	const char* char1 = "Hello World!"; //Lenght is 12.
	String str1(char1);
	assert(str1.size() == 12);

	String str1b("Hello World!");
	assert(str1b.size() == 12);
	
	const char* char2 = "";
	String str2(char2);
	assert(str2.size() == 0);
	assert(str2.empty());

	try{
		const char* char3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent est tellus, placerat nec lacus nec, cursus vestibulum."; //Is more than 100 characters-long
		String str3(char3);
		assert(false);
	}
	catch (const std::length_error&){
		assert(true);
	}
}

void test_length(){
	String str1("Hello");
	assert(str1.length() == 5);

	String str2("");
	assert(str2.length() == 0);

	String str3(str1);
	assert(str3.length() == 5);
}

void test_max_size(){
	String str1("Hello");
	assert(str1.max_size() == 100);

	String str2;
	assert(str2.max_size() == 100);

	String str3(str1);
	assert(str3.max_size() == 100);
}

void test_resize(){
	String str1("Hello");

	str1.resize(15); //purposefully outside of capacity_
	assert(str1.length() == 15);
	assert(str1.c_str()[5] =='\0');

	str1.resize(2);
	assert(str1.length() == 2);
	assert(strcmp(str1.c_str(), "He") == 0);

	str1.resize(8, 'x');
	assert(str1.length() == 8);
	assert(strcmp(str1.c_str(), "Hexxxxxx") == 0);

	str1.resize(0);
	assert(str1.length() == 0);
	assert(str1.empty());

	try{
		str1.resize(101);
		assert(false);
	}
	catch (const std::length_error&){
		assert(true);
	}
}

void test_operatorBeq(){

}

void test_operatorBpl(){

}

int test_student_B(){
	cout << "\n###### Testing Student B ######" << endl;
	test_custom_ctor();
	cout << "Testing of the custom ctor: passed!" << endl;
	test_length();
	cout << "Testing of the length function: passed!" << endl;
	test_max_size();
	cout << "Test of the max_size function: passed!" << endl;
	test_resize();
	cout << "Test of the resize function: passed!" << endl;
	test_operatorBeq();
	cout << "Test of the = operator (string&) function: passed!" << endl;
	test_operatorBpl();
	cout << "Test of the + operator (srting& + string&): passed!" << endl;
	
	return 0;
}

int test_student_C(){
	/*
	    capacity()
        empty()
        reserve(size_t)
        operator=(const char*)
        operator+(const string&, const string&)

	*/
	cout << endl;
	cout << "Test student C" << endl;
	cout << endl;
	
	String str;
	cout << "The string capacity is : ";
	cout << str.capacity() << endl;
	cout << endl;

	cout << "Is the string empty? " << str.empty() << endl;
	str.clear();
	cout << "And after a clear? " << str.empty() << endl;	
	cout << endl;

	cout << "Lets reserve a bit of space." << endl;
	str.reserve(15);
    cout << "Capacity is now " << str.capacity() << endl;
	cout << endl;

	cout << "Test of the = operator (with char*)" << endl;
	char* s = new char[16]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '!', '\0'};
    str = s;
    cout << str.c_str() << endl;
	cout << endl;

	char* test = new char[4]{'a','b','c','\0'};
	String str2 (test);

	cout << str.c_str() << " + " << str2.c_str() << " = ";
	String str3;
	str3 = str + str2;
	cout << str3.c_str() << endl;

	return 0;
}
