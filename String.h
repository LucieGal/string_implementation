class String {
    public:
        String();
        ~String();
        char* str();

        size_t capacity();
        bool empty();
        void reserve(size_t n);

    private:
        size_t capacity_ = 0;
        int size_ = 0;
        char* str_;
};