//Забил на дописываниеt
template <typename Z>
void Ui(){
    /*int input; может заменить тип на 0
    cout << "Выберите тип структуры данных:" << endl;
    cout << "1. DynamicArray" << endl;
    cout << "2. LinkedList" << endl;
    cout << "Введите Ваше значение";
    cin >> input;
    if (input != 1 && input != 2) {
        cerr << "Некорректный ввод. Завершение программы." << endl;
        return;
    }

    cout << "Выбрано: " << (input == 1 ? "DynamicArray" : "LinkedList") << endl;
    int num; 
    if (input == 1) {
        cout << "Введите количество элементов DynamicArray и сами элементы через пробел (например, 1 2 3): ";
        int inp;

        cin >> inp;
        if (inp < 0){
            throw out_of_range("Такое число членов взять нельзя");
        }
        DynamicArray<Z>* dynamicArray;
        vector<Z> elements;
        Z element;
        while (inp--) {
            elements.push_back(element);
        }
        dynamicArray = new DynamicArray<Z>(elements.data(), elements.size());

        cout <<  endl;
        cout << "1. Получить первый элемент" << endl;
        cout << "2. Получить последний элемент" << endl; 
        cout << "3. Получить элемент по индексу" << endl;
        cout << "4. Добавить элемент в конец" << endl; 
        cout << "5. Добавить элемент в начало" << endl;
        cout << "6. Вставить элемент по индексу" << endl;
        cout << "7. Получить длину структуры данных" << endl;
        cout << "0. Выйти" << endl;

        while (false) {
            int case_;
            Z element;
            cout << endl << "Выберите операцию: ";
            cin >> case_;
            if (case_ == 1) {
                cout << "Первый элемент: " << *(dynamicArray->GetFirst()) << endl;
            } 
            else if (case_ == 2) {
                cout << "Последний элемент: " << *(dynamicArray->GetLast()) << endl;
            } 
            else if (case_ == 3) {
                cout << "Введите индекс: ";
                int index;
                cin >> index;
                cout << "Элемент по индексу " << index << ": " << *(dynamicArray->Get(index)) << endl;
            }
            else if (case_ == 4) {
                cout << "Введите элемент для добавления в конец: ";
                cin >> element;
                dynamicArray->Append(element);
                cout << "Элемент добавлен в конец." << endl;
            }
            else if (case_ == 5) {
                cout << "Введите элемент для добавления в начало: ";
                cin >> element;
                dynamicArray->Prepend(element);
                cout << "Элемент добавлен в начало." << endl;
            }
            else if (case_ == 6) {
                cout << "Введите индекс для вставки элемента: ";
                int index;
                cin >> index;
                cout << "Введите элемент для вставки: ";
                cin >> element;
                dynamicArray>InsertAt(element, index);
                cout << "Элемент вставлен по индексу " << index << "." << endl;
            }
            else if (case_ == 7) {
                cout << "Длина структуры данных: " << dynamicArray->GetLength() << endl;
            } 
            else if (case_ == 0) {
                delete dynamicArray;
                cout << "Программа завершена." << endl;
            }
            else {
                cerr << "Некорректный ввод. Повторите попытку." << endl;
            }
        }
    }
 
    else {
        cout << "Введите количество элементов LinkedList и сами элементы через пробел (например, 1 2 3): ";
        cin >> num;
        LinkedList<int>* linkedList;
        vector<int> elements;
        int element;
        while (num--) {
            elements.push_back(element);
        }
        linkedList = new LinkedList<int>(elements.data(), elements.size());
        sequence = new LinkedListSequence<int>(*linkedList);
        delete linkedList;
    }*/
}