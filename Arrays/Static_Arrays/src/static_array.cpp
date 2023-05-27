#include <cstddef>
#include <stdexcept> 

template <typename T, std::size_t N>
class StaticArray {
public:
    StaticArray() {
        for (std::size_t i = 0; i < N; i++) {
            data[i] = T();
        }
    }

    std::size_t size() const {
        return N;
    }

    const T& operator[](std::size_t index) const {
        if(index >= N) {
            throw std::out_of_range("Index out of bounds!");
        }
        return data[index];
    }

    T& operator[](std::size_t index) {
        if(index >= N) {
            throw std::out_of_range("Index out of bounds!");
        }
        return data[index];
    }
    
    void modify(std::size_t index, const T& value) {
        if(index >= N) {
            throw std::out_of_range("Index out of bounds!");
        }
        data[index] = value;
    }

    T sum() const {
        T total = T();
        for(std::size_t i = 0; i < N; ++i) {
            total += data[i];
        }
        return total;
    }
    T max() const {
        T max = data[0];
        for(std::size_t i = 1; i < N; ++i) {
            if(max < data[i]) {
                max = data[i];
            }
        }
        return max;
    }
    T min() const {
        T min = data[0];
        for(std::size_t i = 1; i < N; ++i) {
            if(min > data[i]) {
                min = data[i];
            }
        }
        return min;
    }

private:
    T data[N];
};
