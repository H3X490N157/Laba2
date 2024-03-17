#include <bits/stdc++.h>
using namespace std; 

///Заметки и вольные корректировки

//0. Для уменьшения объёма кода испльзовал bits и импортировал namespace std. Для ускорения и оптимизации можно и перписать заголовки 
//1. Заменил в указании размеров тип int на тип size_t, class на template в шаблоне, так как это стилистически корректно
//2. Ввёл кастомную ноду для упрощения операция со списком
//3. Отрицательный size (доп.баллы будут?)
//4. Перегрузка оператора [] для Dynamic Array и LinkedList

template <typename T>
class Sequence {
public:
    virtual ~Sequence() {} 
    virtual T* GetFirst() = 0;
    virtual T* GetLast() = 0;
    virtual T* Get(size_t index) = 0;
    virtual T* operator[](size_t index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, size_t index) = 0;
};

template <class T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class DynamicArray {
private:
    T* array;
    size_t size;

public:
    DynamicArray(T* items, size_t count) : size(count) {
        array = new T[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = items[i];
        }
    }

    DynamicArray(size_t newSize) : size(newSize) {
        array = new T[size];
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) : size(dynamicArray.size) {
        array = new T[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = dynamicArray.array[i];
        }
    }

    ~DynamicArray() {
        delete[] array;
    }

    size_t GetSize() {
        return size;
    }

    T* Get(size_t index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Некорректный индекс");
        }
        return &array[index];
    }

    T* operator[](size_t index) {
        return Get(index);
    }

    void Set(size_t index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Некорректный индекс");
        }
        array[index] = value;
    }

    void Resize(size_t newSize) {
        T* newArray = new T[newSize];
        size_t copySize = newSize < size ? newSize : size;
        for (size_t i = 0; i < copySize; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        size = newSize;
    }

};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    size_t size;

public:
    LinkedList(T* items, int count) : head(nullptr), size(0) {
        for (int i = count - 1; i >= 0; --i) {
            Prepend(items[i]);
        }
    }

    LinkedList() : head(nullptr), size(0) {}

    LinkedList(const LinkedList<T>& list) : head(nullptr), size(0) {
        Node<T>* current = list.head;
        while (current) {
            Append(current->data);
            current = current->next;
        }
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    T* GetFirst() {
        if (!head) {
            throw out_of_range("Некорректный индекс");
        }
        return &head->data;
    }

    T* GetLast() {
        if (!head) {
            throw out_of_range("Некорректный индекс");
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        return &current->data;
    }

    T* Get(size_t index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Некорректный индекс");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return &current->data;
    }

    T* operator[](size_t index) {
        return Get(index);
    }

    size_t GetLength() {
        return size;
    }

    void Append(T item) {
        Node<T>* newNode = new Node<T>(item);
        if (!head) {
            head = newNode;
        } 
        else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void Prepend(T item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void InsertAt(T item, size_t index) {
        if (index < 0 || index > size) {
            throw out_of_range("Некорректный индекс");
        }
        if (index == 0) {
            Prepend(item);
            return;
        } 
        if (index == size) {
            Append(item);
            return;
        } 
        Node<T>* newNode = new Node<T>(item);
        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    LinkedList<T>* Concat(LinkedList<T>* list) {
        LinkedList<T>* finalList = new LinkedList<T>(*this);
        Node<T>* current = list->head;
        while (current) {
            finalList->Append(current->data);
            current = current->next;
        }
        return finalList;
    }

    LinkedList<T>* GetSubList(size_t startIndex, size_t endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size || endIndex >= size || startIndex > endIndex) {
            throw out_of_range("Некорректные индексы");
        }
        LinkedList<T>* sublist = new LinkedList<T>();
        Node<T>* current = head;

        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        
        for (int i = startIndex; i <= endIndex; ++i) {
            sublist->Append(current->data);
            current = current->next;
        }
        
        return sublist;
    }
};

template <typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> array;

public:
    ArraySequence(T* items, size_t count) : array(items, count) {}

    ArraySequence() : array(0) {}

    //В задании была допущена ошибка (ошибка ли?), требующая создания ArraySequence от LinkedList

    ArraySequence(DynamicArray<T>& vec) : array(vec.GetSize()) {
        for (size_t i = 0; i < vec.GetSize(); ++i) {
            array.Set(i, *(vec.Get(i)));
        }
    }

    ArraySequence(LinkedList<T>& list) : array(list.GetLength()) {
        for (size_t i = 0; i < list.GetLength(); ++i) {
            array.Set(i, *(list.Get(i)));
        }
    }

    T* GetFirst() override {
        return array.Get(0);
    }

    T* GetLast() override {
        return array.Get(array.GetSize() - 1);
    }

    T* Get(size_t index) override {
        return array.Get(index);
    }

    T* operator[](size_t index) override {
        return array.Get(index);
    }

    int GetLength() override {
        return static_cast<int>(array.GetSize());
    }

    void Append(T item) override {
        array.Resize(array.GetSize() + 1);
        array.Set(array.GetSize() - 1, item);
    }

    void Prepend(T item) override {
        array.Resize(array.GetSize() + 1);
        for (size_t i = array.GetSize() - 1; i > 0; --i) {
            array.Set(i, *(array.Get(i - 1)));
        }
        array.Set(0, item);
    }

    void InsertAt(T item, size_t index) override {
        array.Resize(array.GetSize() + 1);
        for (size_t i = array.GetSize() - 1; i > index; --i) {
            array.Set(i, *(array.Get(i - 1)));
        }
        array.Set(index, item);
    }

    ArraySequence<T>* GetSubsequence(ArraySequence<T>* sequence, int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= sequence->GetLength() || endIndex >= sequence->GetLength() || startIndex > endIndex) {
            throw out_of_range("Некорректные индексы");
            }
        ArraySequence<T>* subsequence = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(*(sequence->Get(i)));
            }
        return subsequence;
    }
};

template <typename T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    LinkedListSequence(T* items, size_t count) : list(items, count) {}

    LinkedListSequence() : list() {}

    LinkedListSequence(LinkedList<T>& linkedList) : list(linkedList) {}

    T* GetFirst() override {
        return list.GetFirst();
    }

    T* GetLast() override {
        return list.GetLast();
    }

    T* Get(size_t index) override {
        return list.Get(index);
    }

    T* operator[](size_t index) override {
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

    void InsertAt(T item, size_t index) override {
        list.InsertAt(item, index);
    }

    LinkedListSequence<T>* GetSubsequence(LinkedListSequence<T>* sequence, int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= sequence->GetLength() || endIndex >= sequence->GetLength() || startIndex > endIndex) {
            throw out_of_range("Некорректные индексы");
        }
        LinkedListSequence<T>* subsequence = new LinkedListSequence<T>();
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(*(sequence->Get(i)));
        }
        return subsequence;
    }
};

void Ui(){
    int input;
    cout << "Выберите тип структуры данных:" << endl;
    cout << "1. DynamicArray" << endl;
    cout << "2. LinkedList" << endl;
    cout << "Введите Ваше значение";
    cin >> input;
    if (input != 1 && input != 2) {
        cerr << "Некорректный ввод. Завершение программы." << endl;
    }

    cout << "Выбрано: " << (input == 1 ? "DynamicArray" : "LinkedList") << endl;

    Sequence<int>* sequence;
    if (input== 1) {
        cout << "Введите элементы DynamicArray через пробел (например, 1 2 3): ";
        
        DynamicArray<int>* dynamicArray;
        vector<int> elements;
        int element;
        while (cin >> element) {
            elements.push_back(element);
        }
        dynamicArray = new DynamicArray<int>(elements.data(), elements.size());
        sequence = new ArraySequence<int>(*dynamicArray);
        delete dynamicArray;
    } 
    else {
        cout << "Введите элементы LinkedList через пробел (например, 1 2 3): ";
        
        LinkedList<int>* linkedList;
        vector<int> elements;
        int element;
        while (cin >> element) {
            elements.push_back(element);
        }
        linkedList = new LinkedList<int>(elements.data(), elements.size());
        sequence = new LinkedListSequence<int>(*linkedList);
        delete linkedList;
    }

    cout <<  endl << "Выберите операцию:" << endl;
    cout << "1. Получить первый элемент" << endl;
    cout << "2. Получить последний элемент" << endl; 
    cout << "3. Получить элемент по индексу" << endl;
    cout << "4. Добавить элемент в конец" << endl; 
    cout << "5. Добавить элемент в начало" << endl;
    cout << "6. Вставить элемент по индексу" << endl;
    cout << "7. Получить длину структуры данных" << endl;
    cout << "0. Выйти" << endl;

    while (true) {
        int element;
        cout << endl << "Выберите операцию: ";
        cin >> input;
        switch (input) {
            case 1:
                cout << "Первый элемент: " << *(sequence->GetFirst()) << endl;
                break;
            case 2:
                cout << "Последний элемент: " << *(sequence->GetLast()) << endl;
                break;
            case 3: {
                cout << "Введите индекс: ";
                size_t index;
                cin >> index;
                cout << "Элемент по индексу " << index << ": " << *(sequence->Get(index)) << endl;
                break;
            }
            case 4: {
                cout << "Введите элемент для добавления в конец: ";
                cin >> element;
                sequence->Append(element);
                cout << "Элемент добавлен в конец." << endl;
                break;
            }
            case 5: {
                cout << "Введите элемент для добавления в начало: ";
                cin >> element;
                sequence->Prepend(element);
                cout << "Элемент добавлен в начало." << endl;
                break;
            }
            case 6: {
                cout << "Введите индекс для вставки элемента: ";
                size_t index;
                cin >> index;
                cout << "Введите элемент для вставки: ";
                cin >> element;
                sequence->InsertAt(element, index);
                cout << "Элемент вставлен по индексу " << index << "." << endl;
                break;
            }
            case 7:
                cout << "Длина структуры данных: " << sequence->GetLength() << endl;
                break;
            case 0:
                delete sequence;
                cout << "Программа завершена." << endl;
            default:
                cerr << "Некорректный ввод. Повторите попытку." << endl;
                break; 
        }
    }
}

int main() {
    // Тестирование DynamicArray
    int dynamicArrayItems[] = {1, 2};
    DynamicArray<int>* dynamicArray = new DynamicArray<int>(dynamicArrayItems, 2);
    cout << "Dynamic Array Size: " << dynamicArray->GetSize() << endl;

    // Тестирование LinkedList
    int linkedListItems[] = {3, 4};
    LinkedList<int>* linkedList = new LinkedList<int>(linkedListItems, 2);
    cout << "Linked List Size: " << linkedList->GetLength() << endl;

    // Тестирование ArraySequence
    ArraySequence<int>* arraySequence = new ArraySequence<int>(dynamicArrayItems, 2);
    cout << "Array Sequence Size: " << arraySequence->GetLength() << endl;

    // Тестирование LinkedListSequence
    LinkedListSequence<int>* linkedListSequence = new LinkedListSequence<int>(linkedListItems, 2);
    cout << "Linked List Sequence Size: " << linkedListSequence->GetLength() << endl;

    delete dynamicArray;
    delete linkedList;
    delete arraySequence;
    delete linkedListSequence;
    return 0;
}