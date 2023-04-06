#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<conio.h>
#include <ctime>
using namespace std;

struct Date;
struct Worker;
bool fileExists(string);
void createFile(string);
void appendFile(string);
Worker getWorkerFromFile(ifstream& file, size_t nameLength);
void outputWorker(Worker);
void outputFile(string);
Date getCurrentDate();
void outputBirthdayInGivenMonth(string);
void createNewFileWithSpecificWorkers(string, string);

/*
Створити файл із списком працівників підприємства: прізвище, дата народження, дата прийому на роботу.
Вивести список працівників, у яких день народження у поточному місяці та
які пропрацювали на підприємстві не менше 5-ти років. Створити новий файл
з інформацією про співробітників, які оформилися на роботу на дане підприємство
у віці не старше 25-ти років та пропрацювали на ньому не менше 10-ти років.*/
