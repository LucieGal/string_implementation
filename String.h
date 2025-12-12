#include <cstdlib>

class String {
    public:
        String();
        ~String();
        String(const String& c);
        char* str();

        size_t capacity();
        bool empty();
        void reserve(size_t n);

        size_t size();


        size_t max_size();

        
    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;

        static const size_t max_size_ = 100;

};
