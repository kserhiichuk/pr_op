#include<iostream>
#include<string>
#include<iomanip>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Date {
    int day,
        month,
        year;
    int daysInMonth(int, int);
    int isLeapYear(int);
public:
    Date();// ініціалізує поточною датою
    Date(string);
    Date(int); // генерує дату на заданий рік

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void print(int) const;    
   
    int daysLeftInYear();

    Date operator++();
    Date operator++(int);
    bool operator>(const Date other) const;
};


/*Визначити клас "Дата" для роботи із датами в межах року. Членами класу є число, місяць та рік. 
Реалізувати для нього декілька конструкторів, геттери, метод визначення терміну, що залишився до кінця року. 
Перевантажити оператори: префіксний "++" для збільшення кількості місяців на 1, постфіксний "++" - ДЛЯ збільшення кількості днів на 1;
">" - для порівняння дат. Створити три об'єкта- дати (D1, D2, D3), використовуючи різні конструктори. 
Збільшити дату D1 на 1 місяць, а дату D2 - на 1 день. З'ясувати, яка із цих дат (D1 чи D2) більш пізня. 
Для дати D3 визначити термін, що залишився до кінця року.*/
