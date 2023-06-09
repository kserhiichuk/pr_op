#include"class.h"
#include<windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << " 1. int    2. float   3. string\nВиберіть тип змінних: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		run_menu<int>();
		break;
	}
	case 2: {
		run_menu<float>();
		break;
	}
	case 3: {
		run_menu<string>();
		break;
	}
	default: {
		cout << "Невірний вибір типу змінних." << endl;
		break;
	}
	}

	return 0;
}

