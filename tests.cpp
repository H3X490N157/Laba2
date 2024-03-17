#include <bits/stdc++.h>
#include "sequence.h"
#include "array_sequence.h"
#include "linked_list_sequence.h" 
using namespace std;
///Заметки и вольные корректировки

//0. Для уменьшения объёма кода испльзовал bits и импортировал namespace std. Для ускорения и оптимизации можно и перписать заголовки 
//1. Заменил в указании class на template в шаблоне, добавил использование указателей, так как это стилистически корректно и удобно
//2. Ввёл кастомную ноду для упрощения операция со списком
//3. Отрицательный size (доп.баллы будут?)
//4. Перегрузка оператора [] 
//5. Отсутствует шаблонное ручное тестирование (начало кода закоменчено)
//6. Примечание: в ТЗ для  2.1 (Динамического Массива) отсутствуют полностью методы добавления/удаления (не стал делать допом, так как есть в DynArrSeq)

//Заменить указатели на ссылки
//const-ccылки на аппенд, препенд, инсёрт
//



void test_LinkedList() {
    LinkedList<int> list;

    list.Append(1);
    assert(list.GetLength() == 1);
    assert(list.GetFirst() == 1);
    assert(list.GetLast() == 1);

    list.Prepend(0);
    assert(list.GetLength() == 2);
    assert(list.GetFirst() == 0);
    assert(list.GetLast() == 1);

    list.InsertAt(2, 1);
    assert(list.GetLength() == 3);
    assert(list.Get(1) == 2);
    assert(list.GetFirst() == 0);
    assert(list.GetLast() == 1);

}

void test_DynamicArray() {
    DynamicArray<int> arr(3);

    assert(arr.GetSize() == 3);

    arr.Set(0, 1);
    arr.Set(1, 2);
    arr.Set(2, 3);
    assert(arr.Get(0) == 1);
    assert(arr.Get(1) == 2);
    assert(arr.Get(2) == 3);

    arr.Resize(5);
    assert(arr.GetSize() == 5);
    assert(arr.Get(0) == 1);
    assert(arr[1] == 2);
    assert(arr.Get(2) == 3);
}

void test_LinkedListSequence() {
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    LinkedListSequence<int> seq(list);

    assert(seq.GetFirst() == 1);
    assert(seq.GetLast() == 2);

    assert(seq.Get(0) == 1);
    assert(seq[1] == 2);

    seq.Append(3);
    assert(seq.GetLength() == 3);
    assert(seq.GetLast() == 3);

    seq.Prepend(0);
    assert(seq.GetLength() == 4);
    assert(seq.GetFirst() == 0);

    seq.InsertAt(4, 2);
    assert(seq.GetLength() == 5);
    assert(seq[2] == 4);
}

void test_ArraySequence() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> dynamicArray(arr, 5);

    ArraySequence<int> arraySequence(dynamicArray);

    assert(arraySequence.GetFirst() == 1);
    assert(arraySequence.GetLast() == 5);

    assert(arraySequence.Get(2) == 3);
    assert(arraySequence[2] == 3);

    assert(arraySequence.GetLength() == 5);

    arraySequence.Append(6);
    assert(arraySequence.GetLast() == 6);
    arraySequence.Prepend(0);
    assert(arraySequence.GetFirst() == 0);

    arraySequence.InsertAt(4, 1);
    assert(arraySequence[2] == 1);
}

int main() {
    test_LinkedList();
    test_DynamicArray();
    test_LinkedListSequence();
    test_ArraySequence();
    cout << "Это - успех!" << endl;
    return 0;
}