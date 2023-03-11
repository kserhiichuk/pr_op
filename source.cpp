#include "functions.h"

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (argc != 3  || strcmp(argv[1], "-mode") )
        cout << "Передайте параметри командного рядка: -mode FilePointer (FileStream)";

    else if (!strcmp(argv[2], "FileStream"))
        do {
            string filename,
                newfilename;
            bool newfile = true;

            while (newfile) {
                newfile = false;
                cout << "Введіть назву файлу(без розширення):";
                cin >> filename;
                //Якщо такий файл існує, то виводиться його вміст та варіанти дій
                if (fileExists(filename)) {
                    cout << endl << "Вміст файлу:" << endl;
                    outputFile(filename);
                    int choice;
                    cout << "Працювати з цим файлом(1), доповнити цей файл(2), вибрати інший файл(3): ";
                    cin >> choice;
                    while (choice < 1 || choice > 3) {
                        cout << endl << "Введіть 1, 2 або 3:";
                        cin >> choice;
                    }
                    if (choice == 2) appendFile(filename);
                    else if (choice == 3) newfile = true;
                }
                else {//інакше створюється новий файл
                    createFile(filename);
                    appendFile(filename);
                }
            }
            newfilename = filename + "_changed";
            cout << endl << endl << "Початковий файл:" << endl;
            outputFile(filename);
            replaceLetters(filename, newfilename);
            findDuplicates(newfilename);
            cout << endl << "Створений файл:" << endl;
            outputFile(newfilename);
            cout << endl << "Щоб спробувати ще раз, натисніть ENTER" << endl;
        } while (_getch() == 13);

    else if (!strcmp(argv[2], "FilePointer"))
        do {
            char filename[NAME_SIZE],
                newfilename[NAME_SIZE];
            bool newfile = true;

            while (newfile) {
                newfile = false;
                cout << "Введіть назву файлу(без розширення):";
                cin >> filename;

                if (fileExists(filename)) {
                    cout << endl << endl << "Вміст файлу:" << endl;
                    outputFile(filename);
                    int choice;
                    cout << endl << "Працювати з цим файлом(1), доповнити цей файл(2), вибрати інший файл(3): ";
                    cin >> choice;
                    while (choice < 1 || choice > 3) {
                        cout << endl << "Введіть 1, 2 або 3:";
                        cin >> choice;
                    }
                    if (choice == 2) appendFile(filename);
                    else if (choice == 3) newfile = true;
                }
                else {
                    createFile(filename);
                    appendFile(filename);
                }
            }
            sprintf(newfilename, "%s_changed", filename);
            cout << endl << endl << "Початковий файл:" << endl;
            outputFile(filename);
            replaceLetters(filename, newfilename);
            findDuplicates(newfilename);
            cout << endl << "Створений файл:" << endl;
            outputFile(newfilename);
            cout << endl << "Щоб спробувати ще раз, натисніть ENTER" << endl;
        } while (_getch() == 13);

    else cout << "Невідомий режим" << endl << "Допустимі режими: FilePointer, FileStream";
    return 0;
}
