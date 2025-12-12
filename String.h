#include <cstdlib>

class String {
    public:
        String();
        char* str();

        size_t size();
	
	String(const String& c);
	
    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        char* str_;
        static size_t const max_size_ = 100;
};
