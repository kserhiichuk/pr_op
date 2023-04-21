#include"my_class.h"

unsigned getNumberOfWorkers() {
    unsigned size;
    bool valid;
    do {
        cout << "Введіть кількість працівників (макс. 50): ";
        cin >> size;
        if (size >= 1 && size <= 50) valid = true;
        else {
            cout << "Помика!";
            valid = false;
        }
    } while (!valid);
    return size;
}

bool LeapYear(int year) {
    return ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0));//якщо виконується одна з умов, то рік високосний
}

bool ValidDate(string date) {
    bool LeapYear(int);
    bool valid;

    int day = stoi(date.substr(3, 2));
    int month = stoi(date.substr(0, 2));
    int year = stoi(date.substr(6));
    bool leap_year = LeapYear(year);

    if (day > 31 || day < 1)
        valid = false;
    else if (month < 1 || month > 12)
        valid = false;
    else if (year < 1800 || year > 2023)
        valid = false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        valid = false;
    else if (leap_year && month == 2 && day > 29)
        valid = false;
    else if (!leap_year && month == 2 && day > 28)
        valid = false;
    else valid = true;

    return valid;
}

string GetDateToCompare() {
    string date;
    bool valid;
    do {
        cout << endl << "Введіть дату, щоб знайти найстаршого працівника (ММ-ДД-РРРР): ";
        cin >> date;
        if (ValidDate(date)) valid = true;
        else {
            valid = false;
            cout << "Ви ввели неправильну дату. Спробуйте знову..." << endl;
        }
    } while (!valid);

    return date;
}
