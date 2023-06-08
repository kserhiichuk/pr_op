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

void File::write_from_another(int number_to_increase, File* fin) {
    fin->file.open(fin->get_filename(), ios::binary | ios::in);
    fin->is_open();

    file.open(filename, ios::binary | ios::out | ios::app);
    is_open();

    int number;
    while (fin->file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            int result = number_to_increase * number;
            if (result >= MAX) {
                file.close();
                fin->file.close();
                throw "OVERFLOW!";
            }
            else if (result <= MIN) {
                file.close();
                fin->file.close();
                throw "UNDERFLOW!";
            }

            file.write(reinterpret_cast<char*>(&(result)), sizeof(int));
    }
    file.close();
    fin->file.close();
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
