#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;

class Employee {

	string name;
	string birthdate; // у форматі ММ-ДД-РРРР

public:
	Employee();
	Employee(string, string);
	int GetYear() {
		return stoi(birthdate.substr(6));
	}
	int GetMonth() {
		return stoi(birthdate.substr(0, 2));
	}
	int GetDay() {
		return stoi(birthdate.substr(3, 2));
	}
	void getAge(string);
	void output();
};

unsigned getNumberOfWorkers();
bool ValidDate(string);
void FillArray(Employee*, unsigned );
string GetDateToCompare();
void FindOldest(Employee*, unsigned, string);



/*Розробити клас "працівник", який характеризується ПІБ працівника, Датою його народження (у форматі ММ-ДД-РРРР).
Створити масив об'єктів даного класу. Визначити найстаршого працівника(на вказану дату).*/
