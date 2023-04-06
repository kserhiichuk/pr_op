#include "functions.h"

struct Date {
        int day,
            month,
            year;
};

struct Worker {
    string name;
    Date birthDate;
    Date employmentDate;
};

bool fileExists(string name) {
    ifstream  file(name, ios::binary);
    if (file) {
        file.close();
        return true;
    }
    else return false;
}

void createFile(string name) {
    ofstream file(name, ios::binary);
    if (!file) {
        cout << "File wasn`t created.Try again...";
    }
    else file.close();
}

bool leapYear(int year) {
    return ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0));//якщо виконується одна з умов, то рік високосний
}

bool validDate(int day, int month, int year) {
    bool leapYear(int);
    bool leap_year = leapYear(year);
    bool valid;

    if (day > 31 || day < 1)
        valid = false;
    else if (month < 1 || month > 12)
        valid = false;
    else if (year < 1900 || year > 2023)
        valid = false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        valid = false;
    else if (leap_year && month == 2 && day > 29)
        valid = false;
    else if (!leap_year && month == 2 && day > 28)
        valid = false;
    else valid = true;

    return valid;
}

Worker getWorkerFromConsole() {
    bool validDate(int, int, int);
    Worker w;
    bool valid = false;

    cout << endl << "Enter the employee`s last name: ";
    cin >> w.name;
    cin.ignore();

    cout << "\t---Enter the date of birth----" << endl;
    do {
        cout << "[dd.mm.yyyy] : ";
        scanf_s("%d.%d.%d", &w.birthDate.day, &w.birthDate.month, &w.birthDate.year);
        if (validDate(w.birthDate.day, w.birthDate.month, w.birthDate.year)) valid = true;
        else {
            valid = false;
            cout << "You entered the wrong date. Try again..." << endl;
        }
    } while (!valid);
   
    cout << "\t---Enter the date of employment---\n";
    do{
        cout << "[dd.mm.yyyy] : ";
        scanf_s("%d.%d.%d", &w.employmentDate.day, &w.employmentDate.month, &w.employmentDate.year);
        if (!validDate(w.employmentDate.day, w.employmentDate.month, w.employmentDate.year) || w.employmentDate.year <= w.birthDate.year) {
            valid = false;
            cout << "You entered the wrong date. Try again..." << endl;
        }
        else valid = true;
    } while (!valid);

    return w;
}

void appendFile(string name) {
    Worker getWorkerFromConsole();
    
    ofstream file(name, ios::binary | ios::app);
    
    do {
        Worker w = getWorkerFromConsole();
        size_t nameLength = w.name.size();
        file.write((char*)(&nameLength), sizeof(nameLength));//записуємо у файл розмір прізвища 
        file.write((char*)(w.name.c_str()), nameLength);
        file.write((char*)(&(w.birthDate)), sizeof(Date));
        file.write((char*)(&(w.employmentDate)), sizeof(Date));
        cout << "Do you want to add another employee? Yes - Enter, No - any key" << endl;
    } while (_getch() == 13);

    file.close();
}

Worker getWorkerFromFile(ifstream &file, size_t nameLength) {
    Worker w;
    char* buf = new char[nameLength];
    file.read(buf, nameLength);
    w.name = string(buf, nameLength);
    delete[] buf;
    file.read((char*)(&(w.birthDate)), sizeof(Date));
    file.read((char*)(&(w.employmentDate)), sizeof(Date));
    return w;
}

void outputWorker(Worker w) {
    cout << "\t" << setw(35) << left << w.name;
    cout.fill('0');
    cout << right << "\t" << setw(2) << w.birthDate.day << "." << setw(2) << w.birthDate.month << "." << setw(2) << w.birthDate.year << "\t";
    cout << "\t" << setw(2) << w.employmentDate.day << "." << setw(2) << w.employmentDate.month << "." << setw(2) << w.employmentDate.year << endl;
    cout.fill(' ');
}

void outputFile(string name) {
    Worker w;
    size_t nameLength;
    ifstream file(name, ios::binary);

    cout << endl << setw(60) << "--------- Contents of the file: " << name << " ---------" << endl;
    cout << setw(15) << "Name" << setw(45) << "Date of birth" << setw(27) << "Date of employment" << endl << endl;
    while (file.read((char*)(&nameLength), sizeof(nameLength))) {

        if (file.eof()) break; // перевірка кінця файлу
        w = getWorkerFromFile(file, nameLength);
        outputWorker(w);
    }
    file.close();
}

int getMonthFromConsole() {
    int month;
    bool valid;
    do {
        cout << endl << "Enter month: "; cin >> month;
        if (month < 1 || month > 12) {
            cout << "You entered the wrong number. Try again..." << endl;
            valid = false;
        }
        else valid = true;
    } while (!valid);
    return month;
}

Date getCurrentDate() {
    Date date;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date.year = 1900 + ltm->tm_year;
    date.month = 1 + ltm->tm_mon;
    date.day = ltm->tm_mday;
    return date;
}

void outputBirthdayInGivenMonth(string name) {
    int getMonthFromConsole();
    ifstream file(name, ios::binary);
    Worker w;
    size_t nameLength;
    int givenMonth = getMonthFromConsole();
    bool birthday = false,
         first = true;
    Date currentDate = getCurrentDate();

    while (file.read((char*)(&nameLength), sizeof(nameLength))) {
        
        if (file.eof()) break; // перевірка кінця файлу
        w = getWorkerFromFile(file, nameLength);

        if (w.birthDate.month == givenMonth) {
            int work_years = currentDate.year - w.employmentDate.year;
            if (w.birthDate.month < w.employmentDate.month || (w.birthDate.month == w.employmentDate.month && w.birthDate.day < w.employmentDate.day)) {
                work_years--;
            }
            if (work_years >= 5) {
                if (first) {
                cout << endl << setw(75) << "--------- Employees whose birthday is in month " << givenMonth << "---------" << endl;
                cout << setw(15) << "Name" << setw(45) << "Date of birth" << setw(27) << "Date of employment" << endl << endl;
                first = false;
                birthday = true;
            }
            outputWorker(w);
            }
        }
    }
    if (!birthday) cout << setw(70) << "------- No one has a bithday in month " << givenMonth << " -------" << endl;

    file.close();
}

void createNewFileWithSpecificWorkers(string name, string newname) {
    ifstream inFile(name, ios::binary);
    ofstream outFile(newname, ios::binary);
    size_t nameLength;
    Worker w;
    Date currentDate = getCurrentDate();

    while (inFile.read((char*)(&nameLength), sizeof(nameLength))) {

        if (inFile.eof()) break; // перевірка кінця файлу

        w = getWorkerFromFile(inFile, nameLength);
        
        // рахуєм скільки років пройшло від працевлаштування до сьогодні
        int work_years = currentDate.year - w.employmentDate.year;
        if (currentDate.month < w.employmentDate.month || (currentDate.month == w.employmentDate.month && currentDate.day < w.employmentDate.day)) {
            work_years--;
        } 
        // якщо працівник пропрацював більше 10 років, то перевіряємо чи він влаштувався у віці менше 25
        if (work_years >= 10) {
            int age = w.employmentDate.year - w.birthDate.year;
            if (age == 25) {
                if (w.employmentDate.month < w.birthDate.month || (w.employmentDate.month == w.birthDate.month && w.employmentDate.day < w.birthDate.day))
                    age--;
            }
            
            if (age < 25) {
                // записуємо робітника у файл
                size_t nameLength = w.name.size();//записує у файл розмір рядка 
                outFile.write((char*)(&nameLength), sizeof(nameLength));
                outFile.write((char*)(w.name.c_str()), nameLength);

                outFile.write((char*)(&(w.birthDate)), sizeof(Date));

                outFile.write((char*)(&(w.employmentDate)), sizeof(Date));
            }
        }
    }
    inFile.close();
    outFile.close();
}
