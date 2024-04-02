#include <bits/stdc++.h>
#pragma once
using namespace std; 

template <typename T>
class DynamicArray {
private:
    T* array;
    int capacity;
    int size;
    static const int limit = 2048;

    void Reserve(int newCapacity) {
        if (newCapacity <= capacity) {
            capacity = newCapacity; //для произвольного вызова Reserve в случае наличия дальнейших модификаций
            return;
        }
        T* newArray = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public: 
    DynamicArray(const T* items, int count) : capacity(count), size(count) {
        if (capacity < 1){
            throw std::out_of_range("Некорректный размер");
        }
        array = new T[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = items[i];
        }
    }

    DynamicArray(int initial_capacity) : capacity(initial_capacity + 1), size(initial_capacity) {
        array = new T[capacity];
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) : capacity(dynamicArray.capacity), size(dynamicArray.size) {
        array = new T[capacity];
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

    int GetCapacity() const {
        return capacity;
    }

    T& Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс");
        }
        return array[index];
    }

    T& operator[](int index) {
        return Get(index);
    }

    void Set(int index, T value) { 
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс");
        }
        array[index] = value;
    }

    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("Размер не может быть отрицательным");
        }
        if (newSize > capacity) {
            if (newSize > limit){
                Reserve(newSize + limit);
            }
            else{
                Reserve(newSize * 2);
            }
        }
        size = newSize;
    }

    void Append(T item){
        Resize(size + 1);
        array[size] = item;
        size++; 
    }

    
};
