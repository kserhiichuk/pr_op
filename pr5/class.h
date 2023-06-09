#pragma once
#include<iostream>
#include<string>

using namespace std;


template <typename T>
class Deque {

private:
    T* data;  
    int size; 
    int head; 
    int tail; 
    int count; 

public:
    class Iterator {
    private:
        int current; // Індекс поточного елемента в деку
        Deque<T>& deque;
    public:
        Iterator(Deque<T>& deque, int current) : deque(deque), current(current) {}

        Iterator& operator++() {
            current = (current + 1) % deque.size;
            return *this;
        }

        Iterator& operator--() {
            current = (current + deque.size - 1) % deque.size;
            return *this;
        }

        T& operator*() {
            return deque.data[current];
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

    };

    Iterator begin() {
        return Iterator(*this, head);
    }

    Iterator end() {
        return Iterator(*this, tail);
    }

    Deque(int maxSize = 100) {
        size = maxSize;
        head = -1;
        tail = -1;
        count = 0;
        data = new T[size];
    }

    Deque(const Deque& other) {
        size = other.size;
        head = other.head;
        tail = other.tail;
        count = other.count;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Deque() {
        delete[] data;
    }

    void push_head(T element) {
        if (isFull()) {
            cout << "Дек переповнений!" << endl;
            return;
        }

        if (head == -1)
            head = tail = 0;
        else
            head = (head + size - 1) % size;

        data[head] = element;
        count++;
    }

    void push_tail(T element) {
        if (isFull()) {
            cout << "Дек переповнений!" << endl;
            return;
        }

        if (head == -1)
            head = tail = 0;
        else
            tail = (tail + 1) % size;

        data[tail] = element;
        count++;
    }

    T pop_head() {
        if (isEmpty()) {
            cout << "Дек порожній!" << endl;
            return T();
        }

        int poped_element = head;
        head = (head + 1) % size;
        count--;

        if (isEmpty())
            clear();

        return data[poped_element];
    }

    T pop_tail() {
        if (isEmpty()) {
            cout << "Дек порожній!" << endl;
            return T();
        }
        int poped_element = tail;
        tail = (tail + size - 1) % size;
        count--;

        if (isEmpty())
            clear();

        return data[poped_element];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return (count == size);
    }

    void clear() {
        head = -1;
        tail = -1;
        count = 0;
    }
};

template<typename T>
Deque<T> fill_deque() {
    int maxSize;
    cout << "Введіть розмір дека: ";
    cin >> maxSize;

    Deque<T> deque(maxSize);

    T element;
    for (int i = 1; i <= maxSize; i++) {
        cout << "Введіть елемент " << i << ": ";
        cin >> element;
        deque.push_tail(element);
    }

    return deque;
}

template<typename T>
void print_deque_from_head( Deque<T>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек порожній!" << endl;
        return;
    }
    else {
        typename Deque<T>::Iterator it = deque.begin();
        cout << "Дек у прямому порядку: ";
        while (it != deque.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << *it;
        cout << endl;
    }
}

template<typename T>
void print_deque_from_tail(Deque<T>& deque) {
    if (deque.isEmpty()) {
        cout << "Дек порожній!" << endl;
        return;
    }
    else {
        typename Deque<T>::Iterator it = deque.end();
        cout << "Дек у зворотньому порядку: ";
        while (it != deque.begin()) {
            cout << *it << " ";
            --it;
        }
        cout << *it;
        cout << endl;
    }

}

template<typename T>
void run_menu() {
    //Deque<T> deque = fill_deque<T>();
    int maxSize;
    cout << "Введіть розмір дека: ";
    cin >> maxSize;

    Deque<T> deque(maxSize);

    bool exit = false;
        cout << "\nМеню:\n";
        cout << "1. Додати елемент з початку\n";
        cout << "2. Додати елемент з кінця\n";        
        cout << "3. Видалити елемент з початку\n";
        cout << "4. Видалити елемент з кінця\n";
        cout << "5. Вивести у прямому порядку\n";
        cout << "6. Вивести у зворотньому порядку\n";
        cout << "7. Дізнатись, чи дек порожній\n";
        cout << "8. Очистити дек\n";
        cout << "9. Вийти з програми\n";


    while (!exit) {
        cout << "---------------------------\n";
        cout << "Виберіть опцію: ";
        int choice;        
        cin >> choice;
        switch (choice) {
        case 1: {
            if (deque.isFull())
                cout << "Дек повний!";
            else {
                T element;
                cout << "Введіть елемент: ";
                cin >> element;
                deque.push_head(element);
                cout << "Елемент додано на початок дека." << endl;
            }
            break;
        }
        case 2: {
            if (deque.isFull())
                cout << "Дек повний!";
            else {
                T element;
                cout << "Введіть елемент: ";
                cin >> element;
                deque.push_tail(element);
                cout << "Елемент додано на кінець дека." << endl;
            }
            break;
        }
        case 3: {
            T element = deque.pop_head();
            if (!deque.isEmpty()) 
                cout << "Видалений елемент з початку: " << element << endl;
      
            break;
        }
        case 4: {
            T element = deque.pop_tail();
            if (!deque.isEmpty()) 
                cout << "Видалений елемент з кінця: " << element << endl;
            
            break;
        }
        case 5: {
            print_deque_from_head(deque);
            break;
        }
        case 6: {
            print_deque_from_tail(deque);
            break;
        }
        case 7: {
            if (deque.isEmpty())
                cout << "Дек порожній!" << endl;
            else
                cout << "Дек не порожній!" << endl;
            break;
        }
        case 8: {
            deque.clear();
            cout << "Дек очищено!" << endl;
            break;
        }
        case 9: {
            exit = true;
            break;
        }
        default: {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }
        }
    }
}

/*Спроектувати АТД "Дек на базі кільцевого масиву" для контейнера, що містить дані довільного типу.
Інтерфейс АТД включає такі обов'язкові операції: 
	- перевірка дека на пустоту, 
	- очищення дека, 
	- видалення елемента із дека, 
	- включення нового елемента у дек, 
	- ітератор для доступу до елементів дека з операціями: 
		1) встановлення на початок дека, 
		2) встановлення в кінець дека, 
		4) перехід до попереднього елемента дека, 
		4) перехід до наступного елемента дека.*/
