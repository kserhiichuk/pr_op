#include "functions.h"

int main() {
	string filename,
		newfilename;
	do {
		cout << "Enter filename: "; cin >> filename;
		newfilename = filename + "_changed.bin";
		filename += ".bin";

		if (fileExists(filename)) {
			outputFile(filename);
			cout << endl << "Do you want to append this file? Yes - Enter, No - any key";
			if (_getch() == 13) {
				appendFile(filename);
				outputFile(filename);
			}
		}
		else {
			createFile(filename);
			appendFile(filename);
			outputFile(filename);
		}

		createNewFileWithSpecificWorkers(filename, newfilename);
		cout << endl << endl << "Employees who applied for a job at this company under the age of 25 and worked at it for at least 10 years" << endl;
		outputFile(newfilename);
		outputBirthdayInGivenMonth(filename);
		cout << "Press ENTER to continue, ANY KEY to finish" << endl;
	} while (_getch() == 13);
	return 0;
}
