#include"my_class.h"

Employee::Employee() {
    name = "";
    birthdate = "";
}

Employee::Employee(string name1, string birthdate1) {
    name = name1;
    birthdate = birthdate1;
}

void Employee::getAge(string date) {
    int age = stoi(date.substr(6)) - stoi(birthdate.substr(6)); // від заданого року віднімаємо рік народження
    if (date.substr(0, 2) < birthdate.substr(0, 2)) { // порівнюємо заданий місяць з місяцем народження
        age--;
    }
    else if (date.substr(0, 2) == birthdate.substr(0, 2) && date.substr(3, 2) < birthdate.substr(3, 2)) {// якщо місяці однакові, то порівнюємо дні
        age--;
    }
    cout << endl << "Вік: " << age;
}

void Employee::output() {
    cout << endl << "ПІБ: " << name;
    cout << endl << "Дата народження: " << birthdate;
}

void FillArray(Employee* employees, unsigned size) {

    for (int i = 0; i < size; i++) {
        string name, birthdate;
        bool valid;
        char c;
        cout << endl << "Працівник " << i+1 << endl ;
        
        cout << "ПІБ: ";
        cin.get(c);
        if ( c == '\n') {
            getline(cin, name);
        }
        else {
            name = c;
            while (cin.get(c) && c != '\n') 
                name.push_back(c);
        }

        do {
            cout << "Дата народження (ММ-ДД-РРРР): ";
            getline(cin, birthdate);
            if (ValidDate(birthdate)) valid = true;
            else {
                valid = false;
                cout << "Ви ввели неправильну дату. Спробуйте знову..." << endl;
            }
        } while (!valid);

        employees[i] = Employee(name, birthdate);
    }
}

void SearchTheSameBirthdate(Employee* employees, Employee oldest, int n, unsigned size, string date) {
    for (int i = 0; i < size; i++)
        if (i != n && oldest.GetDay() == employees[i].GetDay() && oldest.GetMonth() == employees[i].GetMonth() && oldest.GetYear() == employees[i].GetYear()) {
            employees[i].output();
            employees[i].getAge(date);
        }
}

void FindOldest(Employee* employees, unsigned size, string date) {
    void SearchTheSameBirthdate(Employee*, Employee, int, unsigned, string);

    int oldestYear = 3000;
    Employee oldestEmployee;
    int n;

    for (int i = 0; i < size; i++) {

        int year = employees[i].GetYear();

        if (year < oldestYear) {
            oldestEmployee = employees[i];
            n = i;
            oldestYear = year;
        }
        else if (year == oldestYear) {

            if (oldestEmployee.GetMonth() > employees[i].GetMonth()) {
                oldestEmployee = employees[i];
                n = i;
            }
            else if (oldestEmployee.GetMonth() == employees[i].GetMonth() && oldestEmployee.GetDay() > employees[i].GetDay()) {
                oldestEmployee = employees[i];
                n = i;
            }
        }
    }
    oldestEmployee.output();
    oldestEmployee.getAge(date);
    SearchTheSameBirthdate(employees, oldestEmployee, n, size, date);
}

