#include"class.h"

int main() {
	string date;
	int year;

	cout << "Enter Date [dd.mm.yyyy]: "; cin >> date;
	cout << "Enter year : "; cin >> year;

	Date D1(date);
	Date D2(year);
	Date D3;

	cout << endl << "\t----Dates before changes----" << endl;
	D1.print(1);
	D2.print(2);
	D3.print(3);

	++D1;
	D2++;

	cout << endl << "\t----Dates after changes----" << endl;
	D1.print(1);
	D2.print(2);
	if (D1 > D2) 
		cout << "Date 1 is later than Date 2" << endl;
	else if (D2 > D1) 
		cout << "Date 2 is later than Date 1"  << endl;
	else 
		cout << "Date 1 and Date 2 are the same" << endl;
	
	cout << "Days remaining until the end of the year from Date 3: " << D3.daysLeftInYear() << endl;
	return 0;
}
