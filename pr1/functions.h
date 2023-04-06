#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 50
#define LINE_SIZE 200
using namespace std;

int fileExists(string name);
int fileExists(char* name);

void createFile(string name);
void createFile(char* name);

void appendFile(string name);
void appendFile(char* name);

void outputFile(string name);
void outputFile(char* name);

void replaceLetters(string name, string newname);
void replaceLetters(char* name, char* newname);

void findDuplicates(string name);
void findDuplicates(char* name);
