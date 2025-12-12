#include <cstdlib>

class String {
    public:
        String();
        ~String();
        char* str();

        size_t capacity();
        bool empty();
        void reserve(size_t n);

        size_t size();

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;
        static size_t const max_size_ = 100;
};
