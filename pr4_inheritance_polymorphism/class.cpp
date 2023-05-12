#include"class.h"

TDate1::TDate1(string date) {
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

TDate2::TDate2(string date) {
    month = stoi(date.substr(0, 2));
    day = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

bool TDate::operator>(const TDate other) const {
    if (year > other.year) 
        return true;
    else if (year == other.year && month > other.month) 
        return true;
    else if (year == other.year && month == other.month && day > other.day)
            return true;
    else return false;
}

bool TDate::operator<(const TDate other) const {
    return !(*this > other);
}

bool TDate::operator==(const TDate other) const {
    return (year == other.year && month == other.month && day == other.day);
}

int TDate::isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else return 0;
}

int TDate::daysInMonth(int month, int year) {
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

void TDate::increaseDate(int days, int months = 0, int years = 0) {
    day += days;
    month += months;
    year += years;
   
    while (month > 12) {
        month -= 12;
        ++year;
    }
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            year++;
            month = 1;
        }
    }
}

void TDate::decreaseDate(int days, int months = 0, int years = 0) {
    day -= days;
    month -= months;
    year -= years;

    while (month < 1) {
        month += 12;
        --year;
    }
    while (day < 1) {
        --month;
        if (month < 1) {
            --year;
            month = 12;
        }
        day += daysInMonth(month, year);
    }
}

void TDate::print() { 
    cout << "Day: " << day << "  Month: " << month << "  Year: " << year; }

void TDate1::print() {
    printf("%02d.%02d.%04d", day, month, year);
}

void TDate2::print() {
    printf("%02d-%02d-%04d", month, day, year);
}

TDate* findLatestDate( int n, TDate* dates1, int m, TDate* dates2) {
    TDate* latest = &dates1[0];
    for (int i = 1; i < n; i++) {
        if (dates1[i] < *latest)
            latest = &dates1[i];
    }
    for (int i = 0; i < m; i++) {
        if (dates2[i] < *latest)
            latest = &dates2[i];
    }
    return latest;
}

void findDatesInPeriod(TDate* dates, int n, TDate1 start, TDate1 end) {
    for (int i = 0; i < n; i++) {
        if (dates[i] < end && dates[i] > start) {
            dates[i].print();
            cout << endl;
        }
    }
}

void printDates(TDate* dates, int n) {
    for (int i = 0; i < n; i++) {
        dates[i].print();
        cout << endl;
    }
}
