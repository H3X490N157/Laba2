#include "sequence.h"
#include "array_sequence.h"
#include "linked_list_sequence.h" 
#include "immutable_list_sequence.h"
using namespace std;

//добавил тесты для конструкторов и поддердку pragma once в .h
void test_ConstructorsArraySequence() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);//всегда 
    ArraySequence<int> seqFromArray(arr, arrSize);
    for (int i = 0; i < arrSize; ++i) {
        assert(seqFromArray.Get(i) == arr[i]);
    }

    DynamicArray<int> dynArr(arr, arrSize);
    ArraySequence<int> seqFromDynArr(dynArr);
    for (int i = 0; i < arrSize; ++i) {
        assert(seqFromDynArr.Get(i) == dynArr.Get(i));
    }

    ArraySequence<int> seqFromSeq(seqFromArray);
    for (int i = 0; i < arrSize; ++i) {
        assert(seqFromSeq.Get(i) == seqFromArray.Get(i));
    }
}

void test_ConstructorsLinkedListSequence() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = arrSize = sizeof(arr) / sizeof(arr[0]);//всегда ;
    LinkedListSequence<int> seqFromArray(arr, arrSize);
    for (int i = 0; i < seqFromArray.GetLength(); ++i) {
        assert(seqFromArray.Get(i) == arr[i]);
    }

    LinkedListSequence<int> seqFromSeq(seqFromArray);
    for (int i = 0; i < seqFromSeq.GetLength(); ++i) {
        assert(seqFromSeq.Get(i) == arr[i]);
    }

    LinkedListSequence<int> emptySeq;
    assert(emptySeq.GetLength() == 0);

}


void test_LinkedList() {
    LinkedList<int> list;
    assert(list.GetLength() == 0);

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
    assert(list[1] == 2);
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
    arr.Append(5);
    assert(arr[5] == 5);
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

void test_ImmutableLinkedListSequence() {
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
    cout << "Выберите тесты для запуска:\n";
    cout << "1 - тесты для Array\n";
    cout << "2 - тесты для LinkedList\n";
    cout << "3 - тесты для SequenceType-структур\n";
    cout << "4 - все тесты сразу\n";
    cout << "q - выход\n";
    ///для тренировки попробовал новый вид UI, который отличается от предыдущего (в этой лабе через switch, в той через if)
    char choice = 'x';
    while (choice){
        cin >> choice;
        bool breaker = false;
        switch (choice) {
            case '1':
                test_ConstructorsArraySequence();
                test_DynamicArray();
                test_ArraySequence();
                cout << "Тесты для Array успешно завершены\n";
                break;
            case '2':
                test_ConstructorsLinkedListSequence();
                test_LinkedList();
                test_LinkedListSequence();
                test_ImmutableLinkedListSequence();
                cout << "Тесты для LinkedList успешно завершены\n";
                break;
            case '3':
                test_LinkedListSequence();
                test_ArraySequence();
                test_ImmutableLinkedListSequence();
                cout << "Тесты для SequenceType-структур успешно завершены\n";
                break;
            case '4':
                test_ConstructorsLinkedListSequence();
                test_ConstructorsArraySequence();
                test_LinkedList();
                test_DynamicArray();
                test_LinkedListSequence();
                test_ArraySequence();
                test_ImmutableLinkedListSequence();
                cout << "Это - абсолютный успех на всех тестах!" << endl;
                break;
            case 'q':
                cout << "Работа программы завершена\n";
                breaker = true;
                break;
            default:
                cout << "Некорректный ввод\n";
                break;
        }
        if (breaker){
            break;
        }
    }
    return 0;
}

