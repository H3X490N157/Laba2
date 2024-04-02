#include <bits/stdc++.h>
#pragma once
#include "linked_list.h"

template <typename T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    LinkedListSequence(T& items, int count) : list(items, count) {}

    LinkedListSequence() : list() {}

    LinkedListSequence(LinkedList<T>& linkedList) : list(linkedList) {}

    LinkedListSequence(T* items, int count) : list() {
        for (int i = count - 1; i >= 0; --i) {
            list.Prepend(items[i]);
        }
    }

    template<typename SequenceType>
    LinkedListSequence(const SequenceType& sequence) : list() {
        for (int i = 0; i < sequence.GetLength(); ++i) {
            list.Append(sequence.Get(i));
        }
    }
    

    T& GetFirst() override {
        return list.GetFirst();
    }

    T& GetLast() override {
        return list.GetLast();
    }

    T& Get(int index) override {
        return list.Get(index);
    }

    T& operator[](int index) override {
        return list.Get(index);
    }

    int GetLength() override {
        return static_cast<int>(list.GetLength());
    }
    
    void Append(T item) {
        list.Append(item);
    }

    void Prepend(T item) override {
        list.Prepend(item);
    }

    void InsertAt(T item, int index) override {
        list.InsertAt(item, index);
    }

};