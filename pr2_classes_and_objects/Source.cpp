#include"my_class.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		unsigned size;
		string date;
		size = getNumberOfWorkers();
		Employee* employees = new Employee[size];
		FillArray(employees, size);
		date = GetDateToCompare();
		FindOldest(employees, size, date);
		delete[] employees;
		cout << endl << "Хочете спробувати знову? Так - ENTER, Ні - будь-яка клавіша" << endl ;
	} while (_getch() == 13);
}
