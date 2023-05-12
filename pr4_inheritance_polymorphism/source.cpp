#include"class.h"

int main() {
	int n, m;
	cout << "Enter number of dates dd.mm.yyyy: "; cin >> n;
	TDate1* dates1 = new TDate1[n];
	getDatesFromConsole(n, dates1);

	cout << "Enter number of dates mm-dd-yyyy: "; cin >> m;
	TDate2* dates2 = new TDate2[m];
	getDatesFromConsole(m, dates2);

	cout << endl << "Dates in dd.mm.yyyy format:" << endl;
	printDates(dates1, n);
	cout << endl << "Dates in dd-mm-yyyy format:" << endl;
	printDates(dates2, m);

	cout << endl << "Latest date: ";
	TDate* latest = findLatestDate(n, dates1, m, dates2);
	latest->print();
	
	string datestart, dateend;
	cout << endl << "Enter first date(dd.mm.yyyy): "; cin >> datestart;
	cout << "Enter last date(dd.mm.yyyy): "; cin >> dateend;
	TDate1 start(datestart);
	TDate1 end(dateend);
	cout << endl << "Dates within the period are: " << endl;
	findDatesInPeriod(dates1, n, start, end);
	findDatesInPeriod(dates2, m, start, end);

	delete[] dates1;
	delete[] dates2;
}
