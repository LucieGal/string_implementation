#include <cstdlib>

class String {
    public:
        String();
        char* str();

        size_t size();
        size_t max_size();

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;
        static const size_t max_size_ = 100;
};