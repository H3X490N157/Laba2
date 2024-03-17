
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList(T* items, int count) : head(nullptr), size(0) {
        for (int i = count - 1; i >= 0; --i) {
            Append(items[i]);
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

    T& GetFirst() {
        if (!head) {
            throw std::out_of_range("Некорректный индекс");
        }
        return head->data;
    }

    T& GetLast() {
        if (!head) {
            throw std::out_of_range("Некорректный индекс");
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        return current->data;
    }

    T& Get(int index) {
        if (index < 0){
            index += size;
        }
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    T& operator[](int index) {
        return Get(index);
    }

    int GetLength() const {
        return size;
    }

    void Append(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void Prepend(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void InsertAt(const T& item, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Некорректный индекс");
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
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    LinkedList<T>* Concat(const LinkedList<T>* list) const {
        LinkedList<T>* finalList = new LinkedList<T>(*this);
        Node<T>* current = list->head;
        while (current) {
            finalList->Append(current->data);
            current = current->next;
        }
        return finalList;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size || endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("Некорректные индексы");
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
