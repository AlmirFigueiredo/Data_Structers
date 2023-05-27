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

private:
    T data[N];
};
