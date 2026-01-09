#include <cstdlib>

class String {
    public:
        String();
        String(char* input_string);
        String(const String& c);
        ~String();

        char* str();
        bool empty();
        size_t capacity();
        size_t size();
        size_t max_size();

        void reserve(size_t n);
        void resize(size_t new_size, char filler);

        void operator=(const char* s);
        
    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_ = new char[10]{};

        static const size_t max_size_ = 100;
};


String operator+(const String& str1, const String& str2);