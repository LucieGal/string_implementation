#include <cstdlib>

class String {
    public:
        String();
        String(char* input_string);
        char* str();

        size_t size();
        size_t max_size();
        void resize(size_t new_size, char filler);

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;
        static const size_t max_size_ = 100;
};