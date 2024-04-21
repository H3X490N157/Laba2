#pragma once
#include "linked_list.h"

template <typename T>
class ImmutableListSequence {
private:
    LinkedList<T> list;

public:
    ImmutableListSequence(T& items, int count) : list(items, count) {}

    ImmutableListSequence() : list() {}

    ImmutableListSequence(LinkedList<T>& linkedList) : list(linkedList) {}

    ImmutableListSequence(T* items, int count) : list() {
        for (int i = count - 1; i >= 0; --i) {
            list.Prepend(items[i]);
        }
    }

    template<typename SequenceType>
    ImmutableListSequence(const SequenceType& sequence) : list() {
        for (int i = 0; i < sequence.GetLength(); ++i) {
            list.Append(sequence.Get(i));
        }
    }
    
    T& GetFirst() const {
        return list.GetFirst();
    }

    T& GetLast() const {
        return list.GetLast();
    }

    T& Get(int index) const {
        return list.Get(index);
    }

    T& operator[](int index) const {
        return list.Get(index);
    }

    int GetLength() const {
        return static_cast<int>(list.GetLength());
    }
    
    // Методы для добавления элементов
    ImmutableListSequence Append(T item) const {
        LinkedList<T> newList(list); // Создаем копию текущего списка
        newList.Append(item); // Добавляем элемент в копию списка
        return ImmutableListSequence(newList); // Возвращаем новый объект ImmutableListSequence с измененным списком
    }

    ImmutableListSequence Prepend(T item) const {
        LinkedList<T> newList(list);
        newList.Prepend(item);
        return ImmutableListSequence(newList);
    }

    ImmutableListSequence InsertAt(T item, int index) const {
        LinkedList<T> newList(list);
        newList.InsertAt(item, index);
        return ImmutableListSequence(newList);
    }
};