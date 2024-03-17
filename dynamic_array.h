#include <bits/stdc++.h>
using namespace std; 

template <typename T>
class DynamicArray {
private:
    T* array;
    int size;

public:
    DynamicArray(const T* items, int count) : size(count) {
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = items[i];
        }
    }

    DynamicArray(int newSize) : size(newSize) {
        array = new T[size];
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) : size(dynamicArray.size) {
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = dynamicArray.array[i];
        }
    }

    ~DynamicArray() {
        delete[] array;
    }

    int GetSize() const {
        return size;
    }

    T& Get(int index) {
        if (index < 0){
            index += size;
        }
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс");
        }
        return array[index];
    }

    T& operator[](int index) {
        return Get(index);
    }

    void Set(int index, T value) {
        if (index < 0){
            index += size;
        }
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс");
        }
        array[index] = value;
    }

    void Resize(int newSize) {
        T* newArray = new T[newSize];
        int copySize = newSize < size ? newSize : size;
        for (int i = 0; i < copySize; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        size = newSize;
    }
};