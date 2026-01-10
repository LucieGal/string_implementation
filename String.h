#include <cstdlib>

class String {
    public:
        String();
        String(const char* input_string);
        String(const String& c_str);
        ~String();

        char* c_str();
        void clear();
        bool empty();
        size_t capacity();
        size_t size() const;
        size_t max_size() const;
        void reserve(size_t n);
        void resize(size_t new_size, char filler = '\0');

	//String operator=(char c);
        String& operator=(const String& str);
        String& operator=(const char* s); 
        
         
    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;

        static const size_t max_size_ = 100;
};


String operator+(const String& str1, const char* s);
String operator+(const String& str1, char s);
String operator+(const String& str1, const String& str2);