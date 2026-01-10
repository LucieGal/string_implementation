#include "String.h"
#include <iostream>

using std::cout;
using std::endl;

int test_student_A();

int main(){

    String str;
    cout << str.c_str() << endl;
    cout << str.size() << endl;

    String stp(str);
    cout<<stp.c_str()<<endl;
    cout<<stp.size()<<endl;

    cout << endl << "###### TESTING RESIZE ######" << endl;
    String stH("1234567890");
    cout << "Before: " << stH.c_str() << endl;
    stH.resize(5);
    cout << "After: " << stH.c_str() << endl;
	stH.resize(10, '.');
	cout << "And then: " << stH.c_str() << endl;
    cout << endl;


    str.reserve(15);
    cout << str.c_str() << endl;
    cout << str.capacity() << endl;

    str.reserve(3);
    cout << str.c_str() << endl;
    cout << str.capacity() << endl;

    char* s = new char[16]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '!', '\0'};
    str = s;
    cout << str.c_str() << endl;
    
    String str2;
	cout << str2.c_str() << endl;
    String str3;
	cout << str3.c_str() << endl;
	str3 = str + str2;
	cout << "Test + operator between 2 strings" << endl;   // not working
    cout << str3.c_str() << endl;

    char* test;
    test = new char[4]{'a','b','c','\0'};
    String custom(test);
    cout << custom.c_str() << endl;
    cout << custom.size() << endl;
    cout << custom.max_size() << endl;
    delete test;
    delete s;

	
	test_student_A();
	
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
	char* c = new char('m');
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


	delete c;
	delete char_array;
	return 0;


}
