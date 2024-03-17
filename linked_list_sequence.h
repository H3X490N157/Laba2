#include <bits/stdc++.h>
#include "linked_list.h"

template <typename T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    LinkedListSequence(T& items, int count) : list(items, count) {}

    LinkedListSequence() : list() {}

    LinkedListSequence(LinkedList<T>& linkedList) : list(linkedList) {}

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

    void Append(T item) override {
        list.Append(item);
    }

    void Prepend(T item) override {
        list.Prepend(item);
    }

    void InsertAt(T item, int index) override {
        list.InsertAt(item, index);
    }

    LinkedListSequence<T> GetSubsequence(int startIndex, int endIndex) {
    if (startIndex < 0 || endIndex < 0 || startIndex >= GetLength() || endIndex >= GetLength() || startIndex > endIndex) {
        throw std::out_of_range("Некорректные индексы");
    }
    }

};