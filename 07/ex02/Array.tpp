#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n) {
    if (_size > 0)
        _array = new T[_size]();
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _size(other._size) {
    if (_size > 0) {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        T* newArray = NULL;
        if (other._size > 0) {
            newArray = new T[other._size];
            for (unsigned int i = 0; i < other._size; i++) {
                newArray[i] = other._array[i];
            }
        }
        delete[] _array;
        _array = newArray;
        _size = other._size;
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] _array;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _array[index];
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif