#pragma once
#include <iostream>
#include<fstream>

using namespace std;

#define MAX 1000000
#define MIN -1000000

class File {
    fstream file;
    string filename;

public:
    File(string name);
    void add(int);
    int* read(int&);
    void write_from_another(int, File* , File*);
    string get_filename();
    void clear();
    void is_open();
};
