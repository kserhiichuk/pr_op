#include"class.h"

Date::Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    day = ltm->tm_mday;
    month = ltm->tm_mon + 1;
    year = ltm->tm_year + 1900;
}
Date::Date(string date) {
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6));
}
Date::Date(int _year) {
    srand(time(nullptr));
    year = _year;
    month = rand() % 12 + 1;
    day = rand() % daysInMonth(month, year) + 1;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date:: print(int i) const{
    cout.fill('0');
    cout << "Date " << i << " : " << setw(2) << day << "." << setw(2) << month << "." << year << endl;
}

int Date::isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else return 0;
}

int Date::daysInMonth(int month, int year) {
    if (month == 2) {
        return 28 + isLeapYear(year);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int Date::daysLeftInYear() {
    int daysLeft = daysInMonth(month, year) - day; // рахуємо, скільки днів залишилось у поточному місяці
    for (int i = month + 1; i <= 12; i++) {
        daysLeft += daysInMonth(i, year); // додаємо дні з наступних місяців
    }
    return daysLeft;
}

Date Date::operator++() {
    ++month;
    if (month > 12) {
        month = 1;
        ++year;
    }
    return *this;
}

Date  Date:: operator++(int) {
    Date temp = *this;
    ++day;
    if (day > daysInMonth(month, year)) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
    return temp;
}

bool Date::operator>(const Date other) const {
    if (year > other.year) {
        return true;
    }
    else if (year < other.year) {
        return false;
    }
    else {
        if (month > other.month) {
            return true;
        }
        else if (month < other.month) {
            return false;
        }
        else {
            return day > other.day;
        }
    }
}

