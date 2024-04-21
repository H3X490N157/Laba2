#pragma once
#include "dynamic_array.h"
using namespace std; 

template <typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T*> array; 
    static const int limit = 2048;

public:
    ArraySequence(const T* items, int count) : array(count) { 
    for (int i = 0; i < count; ++i) {
        T* mutablePtr = const_cast<T*>(&items[i]);//гипер-костыль через приведение типа const T* к T*
        array.Set(i, mutablePtr); 
    }
}

    ArraySequence() : array(0) {}

    ArraySequence(DynamicArray<T>& vec) : array(vec.GetSize()) {
        for (int i = 0; i < vec.GetSize(); ++i) {
            array.Set(i, &(vec.Get(i))); 
        }
    }

    //создал конструктор от произвольного класса, наследующего от Sequence
    template<typename SequenceType>
    ArraySequence(const SequenceType& sequence) {
        int length = sequence.GetLength();
        array.Resize(length);
        for (int i = 0; i < length; ++i) {
            array.Set(i, &(sequence.Get(i))); 
        }
    }

    T& GetFirst() override {
        return *(array.Get(0));
    }

    T& GetLast() override {
        return *(array.Get(array.GetSize() - 1));
    }

    T& Get(int index) override {
        return *(array.Get(index));
    }

    T& operator[](int index) override {
        return *(array.Get(index));
    }

    int GetLength() override {
        return static_cast<int>(array.GetSize());
    }

    void Append(T item) override {
        if (array.GetSize() > limit){
            array.Resize(array.GetSize() + limit);
        }
        else{
            array.Resize(array.GetSize() * 2);
        }
        array.Set(array.GetSize() - 1, &item);
    }

    void Prepend(T item) override {
        if (array.GetSize() > limit){
            array.Resize(array.GetSize() + limit);
        }
        else{
            array.Resize(array.GetSize() * 2);
        }
        for (int i = array.GetSize() - 1; i > 0; --i) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(0, &item);
    }

    void InsertAt(T item, int index) override {
        if (array.GetSize() > limit){
            array.Resize(array.GetSize() + limit);
        }
        else{
            array.Resize(array.GetSize() * 2);
        }
        for (int i = array.GetSize() - 1; i > index; --i) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(index, &item); 
    }

    ArraySequence<T>& GetSubsequence(ArraySequence<T>& sequence, int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= sequence.GetLength() || endIndex >= sequence.GetLength() || startIndex > endIndex) {
            throw out_of_range("Некорректные индексы");
        }
        ArraySequence<T>& subsequence = *(new ArraySequence<T>());
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence.Append(*(sequence.Get(i))); 
        }
        return subsequence;
    }
};