class String {
    public:
        String();
        char* str();
    private:
        int capacity_ = 0;
        int size_ = 0;
        char* str_;
};