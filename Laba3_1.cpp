#include <iostream>
#include <stdexcept>

class VectorOfFloat {
public:
    VectorOfFloat() : size(1), data(new float[size]()) {}
    VectorOfFloat(size_t size) : size(size), data(new float[size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = float(i);
        }
    }
    VectorOfFloat(int size, float initializer) : size(size),
        data(new float[size]) {
        setAllTo(initializer);
    }
    VectorOfFloat(const VectorOfFloat& other) {
        copyFrom(other);
    }
    VectorOfFloat& operator=(const VectorOfFloat& other) {
        return copyFrom(other);
    }
    virtual ~VectorOfFloat() {
        delete[] data;
    }
    float& get(size_t position) {
        if (position >= size) {
            throw std::out_of_range("index went out of range");
        }
        return data[position];
    }
    const float& get(size_t position) const {
        if (position >= size) {
            throw std::out_of_range("index went out of range");
        }
        return data[position];
    }
    void set(size_t position) {
        if (position >= size) {
            throw std::out_of_range("index went out of range");
        }
        data[position] = 0;
    }
    void set(size_t position, float value) {
        if (position >= size) {
            throw std::out_of_range("index went out of range");
        }
        data[position] = value;
    }
    size_t getSize() const { return size; }
    void setAllTo(float value) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = float(value);
        }
    }
    VectorOfFloat& copyFrom(const VectorOfFloat& other) {
        if (this != &other) {
            size = other.size;
            delete[] data;
            data = new float[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    static size_t getMaximumSize() { return static_cast<size_t>(-1); }
private:
    size_t size;
    float* data;
};

std::ostream& operator<<(std::ostream& stream, const VectorOfFloat& v) {
    stream << "[";
    for (size_t i = 0; i < v.getSize(); ++i) {
        stream << v.get(i);
        if (i < v.getSize() - 1) stream << ", ";
    }
    return stream << "]";
}

int main(int argc, char* argv[]) {
    VectorOfFloat v(10);
    v.set(9);
    v.set(3, 4);
    std::cout << v << std::endl;
    return 0;
}
