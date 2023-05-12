#pragma once
#include<iostream>
#include<string>
using namespace std;

class TDate {
protected:
	int day,
		month,
		year;
	int daysInMonth(int, int);
	int isLeapYear(int);
public:
	TDate() : day(1), month(1), year(2023) {}
	bool operator>(const TDate) const;
	bool operator<(const TDate) const;
	bool operator==(const TDate) const;
	void increaseDate(int, int, int);
	void decreaseDate(int, int, int);
	virtual void print();
};

// DD.MM.YYYY
class TDate1 : public TDate {
public:
	TDate1() {}
	TDate1(string);
	void print();
};

// MM-DD-YYYY
class TDate2 : public TDate {
public:
	TDate2() {}
	TDate2(string);
	void print();
};

TDate* findLatestDate(int, TDate*, int, TDate*);
void findDatesInPeriod(TDate*, int, TDate1, TDate1);
void printDates(TDate* dates, int n);
template<typename T>
void getDatesFromConsole(int n, T* dates) {
	for (int i = 0; i < n; i++) {
		string date;
		cout << "Date " << i + 1 << " : "; cin >> date;
		dates[i] = T(date);
	}
}
