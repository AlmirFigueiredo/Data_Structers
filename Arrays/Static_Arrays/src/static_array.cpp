template <typename T, std::size_t N>
class StaticArray {
    public:
        //Constructor
        StaticArray() {
            data = {};
        }
            
        std::size_t size() const {
            return N;
        }

        

    private:
        T data[N];
};