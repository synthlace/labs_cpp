#include <iostream>
#include <cmath>

template <class T>
class Vector {
public:
    explicit Vector(size_t size) : size(size), data(new T[size]()) {}
    Vector(const Vector& other) : size(0), data(0) {
        copyFrom(other);
    }
    Vector& operator=(const Vector& other) {
        return copyFrom(other);
    }
    virtual ~Vector() {
        delete[] data;
    }
    Vector& copyFrom(const Vector& v) {
        if (this != &v) {
            delete[] data;
            size = v.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }
    size_t getSize() const {
        return size;
    }
    double getLength() const {
        double length = 0;
        for (size_t i = 0; i < getSize(); ++i) {
            length = pow(data[i], 2.0);
        }
        return sqrt(length);
    }
    const T& get(size_t i) const {
        return data[i];
    }
    T& get(size_t i) {
        return data[i];
    }
    const T& operator[](size_t i) const {
        return data[i];
    }
    T& operator[](size_t i) {
        return data[i];
    }
private:
    size_t size;
    T* data;
};

template <class T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& v) {
    stream << "[";
    for (size_t i = 0; i < v.getSize(); ++i) {
        stream << v[i];
        if (i < v.getSize() - 1) {
            stream << ", ";
        }
    }
    return stream << "]";
}

size_t max(size_t a, size_t b) {
    return ((a > b) ? a : b);
}

size_t min(size_t a, size_t b) {
    return ((a < b) ? a : b);
}

template <class T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
    const Vector<T>& minVector = (a.getSize() < b.getSize()) ? a : b;
    const Vector<T>& maxVector = (a.getSize() >= b.getSize()) ? a : b;
    size_t minSize = min(a.getSize(), b.getSize());
    size_t maxSize = max(a.getSize(), b.getSize());
    Vector<T> result(maxSize);

    for (size_t i = 0; i < minSize; ++i) {
        result[i] = minVector[i] + maxVector[i];
    }

    for (size_t i = minSize; i < maxSize; ++i) {
        result[i] = maxVector[i];
    }
    return result;
}

template <class T>
Vector<T> operator-(const Vector<T>& v) {
    Vector<T> result(v);
    for (size_t i = 0; i < result.getSize(); ++i) {
        result[i] = -result[i];
    }
    return result;
}

template <class T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b) {
    return operator+(a, -b);
}

template <class T>
bool operator==(const Vector<T>& a, const Vector<T>& b) {
    return a.getLength() == b.getLength();
}

template <class T>
bool operator!=(const Vector<T>& a, const Vector<T>& b) {
    return !operator=(a, b);
}

template <class T>
bool operator<(const Vector<T>& a, const Vector<T>& b) {
    return a.getLength() < b.getLength();
}

template <class T>
bool operator>(const Vector<T>& a, const Vector<T>& b) {
    return a.getLength() > b.getLength();
}

template <class T>
bool operator<=(const Vector<T>& a, const Vector<T>& b) {
    return a.getLength() <= b.getLength();
}

template <class T>
bool operator>=(const Vector<T>& a, const Vector<T>& b) {
    return a.getLength() >= b.getLength();
}

int main(int, char**) {
    Vector<int> a(5), b(6);
    a[4] = 1;
    b[5] = 2;
    std::cout << (a - b) << std::endl;
    return 0;
}