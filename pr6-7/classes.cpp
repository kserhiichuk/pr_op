#include"classes.h"

File::File(string name) {
    filename = name + ".bin";
    file.open(filename, ios::out | ios::binary);
    file.close();
}

void File::add(int number) {
    file.open(filename, ios::app | ios::binary);
    is_open();
 
    file.write(reinterpret_cast<char*>(&number), sizeof(int));
    file.close();
}

int* File::read(int& size) {
    file.open(filename, ios::binary | ios::in);
    is_open();

    file.seekg(0, ios::end);
    size = file.tellg() / sizeof(int);
    file.seekg(0, ios::beg);

    int* numbers = new int[size];
    file.read(reinterpret_cast<char*>(numbers), size * sizeof(int));
    file.close();
    return numbers;
}

void File::write_from_another(int number_to_increase, File* fin1, File* fin2) {
    fin1->file.open(fin1->get_filename(), ios::binary | ios::in);
    fin1->is_open();

    fin2->file.open(fin2->get_filename(), ios::binary | ios::in);
    fin2->is_open();

    file.open(filename, ios::binary | ios::out | ios::app);
    is_open();

    int number1, number2;
    bool found_common_number = false;

    while (fin1->file.read(reinterpret_cast<char*>(&number1), sizeof(int))) {
        while (fin2->file.read(reinterpret_cast<char*>(&number2), sizeof(int))) {
            if (number1 == number2) {
                found_common_number = true;
                int result = number1 * number_to_increase;

                if (result >= MAX) {
                    fin1->file.close();
                    fin2->file.close();
                    file.close();
                    throw "OVERFLOW!";
                }
                else if (result <= MIN) {
                    fin1->file.close();
                    fin2->file.close();
                    file.close();
                    throw "UNDERFLOW!";
                }

                file.write(reinterpret_cast<char*>(&result), sizeof(int));
                break; 
            }
        }
        fin2->file.clear();  // Reset the EOF flag for fin2
        fin2->file.seekg(0, ios::beg);  
    }


    fin1->file.close();
    fin2->file.close();
    file.close();

    if (!found_common_number) 
        throw "No common numbers found!";
}

string File::get_filename() {
    return filename;
}

void File::clear() {
    file.open(filename, ios::binary | ios::out);
    is_open();
    file.close();
}

void File::is_open() {
    if (!file.is_open())
        throw "Не вдалось відкрити файл!";
}
