#include "functions.h"

//перевірка існування файлу
int fileExists(string name) {
	ifstream file(name + ".txt");
	if (file) {
		file.close();
		return 1;
	}
	else return 0;
}
int fileExists(char* name) {
	char filename[NAME_SIZE];
	sprintf(filename, "%s.txt", name);
	FILE* file = fopen(filename, "r");
	if (file) {
		fclose(file);
		return 1;
	}
	else return 0;
}

//створення файлу
void createFile(string name) {
	ofstream file(name + ".txt");
	if (!file) {
		cout << "Помилка створення файлу...";
	}
	else file.close();
}
void createFile(char* name) {
	char filename[NAME_SIZE];
	sprintf(filename, "%s.txt", name);
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		cout << "Помилка створення файлу...";
	} else fclose(file);
}

//додавання рядків у файл
void appendFile(string name) {
	ofstream outFile(name + ".txt", ios::app);
	string line;
	cin.ignore();
	do {
		cout << endl << "Введіть рядок: ";
		getline(cin, line);
		outFile << line << endl;
		cout << "Бажаєте добавити ще один рядок? Так - Enter, Ні - Esc";
	} while (_getch() != 27);
	outFile.close();
}
void appendFile(char* name) {
	char filename[NAME_SIZE],
		 line[LINE_SIZE];
	sprintf(filename, "%s.txt", name);
	FILE* outFile = fopen(filename, "a");
	cin.ignore();
	do {
		cout << endl << "Введіть рядок: ";
		fgets(line, LINE_SIZE, stdin);
		fputs(line, outFile);
		cout << "Бажаєте добавити ще один рядок? Так - Enter, Ні - Esc";
	} while (_getch() != 27);
	fclose(outFile);
}

//виведення вмісту файлу
void outputFile(string name) {
	ifstream inFile(name + ".txt");
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}
	inFile.close();
}
void outputFile(char* name) {
	char filename[NAME_SIZE],
		 line[LINE_SIZE];
	sprintf(filename, "%s.txt", name);
	FILE* inFile = fopen(filename, "r");
	while (fgets(line, LINE_SIZE, inFile)) {
		cout << line;
	}
	fclose(inFile);
}

//перестановка великих літер на початок рядка, у зворотньому порядку
void replaceLetters(string name, string newname) {
	ifstream inFile(name + ".txt");
	ofstream outFile(newname + ".txt");
	string line;
	 
	while (getline(inFile, line)) {
		string upper_letters,
			other_characters;
		//розділення на дві групи символів
		for (char c : line)
			if ((c > 64 && c < 91) || (c > -65 && c < -32) || c == -78 || c == -81 || c == -86)// А=-64...Я=-33, І=-78, Ї=-81, Є=-86
				upper_letters += c;
			else other_characters += c;

		//перевернення групи великих літер
		size_t n = upper_letters.length();
		for (int i = 0; i < n/2; i++)
			swap(upper_letters[i], upper_letters[n - 1 - i]);

		// запис символів у файл
		outFile << upper_letters << other_characters << endl;
	}
	inFile.close();
	outFile.close();
}
void replaceLetters(char* name, char* newname) {
	char filename[NAME_SIZE],
		newfilename[NAME_SIZE],
		line[LINE_SIZE];

	sprintf(filename, "%s.txt", name);
	sprintf(newfilename, "%s.txt", newname);
	FILE* inFile = fopen(filename, "r");
	FILE* outFile = fopen(newfilename, "w");

	while (fgets(line, LINE_SIZE, inFile)) {
		char upper_letters[LINE_SIZE],
			other_characters[LINE_SIZE];
		int upper_count = 0,
			other_count = 0;
		//розділення на дві групи символів
		for (int i = 0; line[i] != '\n'; i++) {
			char c = line[i];
			if ((c > 64 && c < 91) || (c > -65 && c < -32) || c == -78 || c == -81 || c == -86)
				upper_letters[upper_count++] = c;
			else other_characters[other_count++] = c;
		}
			
		upper_letters[upper_count] = '\0';
		other_characters[other_count] = '\0';

		//перевернення групи великих літер
		int n = upper_count;
		for (int i = 0; i < n / 2; i++) {
			char temp = upper_letters[i];
			upper_letters[i] = upper_letters[n - 1 - i];
			upper_letters[n - 1 - i] = temp;
		}
		// запис символів у файл
		fprintf(outFile, "%s%s\n", upper_letters, other_characters);
	}
	fclose(outFile);
	fclose(inFile);
}

//пошук великих літер дублікатів
void findDuplicates(string name) {
	ifstream inFile(name + ".txt");
	string tempname = name + "_temp.txt";
	ofstream outFile(tempname);
	string line;

	while (getline(inFile, line)) {
		string upper_letters,
			other_characters;
		//розділення на дві групи символів
		for (char c : line)
			if ((c > 64 && c < 91) || (c > -65 && c < -32) || c == -78 || c == -81 || c == -86)
				upper_letters += c;
			else other_characters += c;

		//пошук дублікатів
		char prev_char = upper_letters[0],
			c;
		int count = 1;
		string result;
		size_t n = upper_letters.length();
		
			for (int i = 1; i < n;i++) {
				c = upper_letters[i];
				if (c == prev_char)
					count++;
				else {
						result += prev_char;
					if (count > 1) 
						result += "[" + to_string(count) + "]";
					count = 1;
					prev_char = c;
				}
			}
			result += prev_char;
			if (count > 1) 
				result += "[" + to_string(count) + "]";
		
		// запис символів у файл
		outFile << result << other_characters << endl;
	}
	inFile.close();
	outFile.close();
	name += ".txt";
	//видалення файлу та зміна імені тимчасового файлу на імя того файлу
	remove(name.c_str());
	rename(tempname.c_str(), name.c_str());
}
void findDuplicates(char* name) {
	char filename[NAME_SIZE],
		tempfilename[NAME_SIZE],
		line[LINE_SIZE];

	sprintf(filename, "%s.txt", name);
	sprintf(tempfilename, "%s_temp.txt", name);

	FILE* inFile = fopen(filename, "r");
	FILE* outFile = fopen(tempfilename, "w");

	while (fgets(line, LINE_SIZE, inFile)) {
		char upper_letters[LINE_SIZE],
			other_characters[LINE_SIZE];
		int upper_count = 0,
			other_count = 0;
		//розділення рядка на дві групи символів
		for (int i = 0; line[i] != '\n'; i++) {//line[i] != '\0'
			char c = line[i];
			if ((c > 64 && c < 91) || (c > -65 && c < -32) || c == -78 || c == -81 || c == -86)
				upper_letters[upper_count++] = c;
			else other_characters[other_count++] = c;
		}

		upper_letters[upper_count] = '\0';
		other_characters[other_count] = '\0';

		
		char result[LINE_SIZE],
			prev_char = upper_letters[0],
			c;
		int count = 1,
			n = upper_count,
			result_count = 0;
		//пошук дублікатів
			for (int i = 1; i < n+1; i++) {
				c = upper_letters[i];
				if (c == prev_char)
					count++;
				else {
					result[result_count++] = prev_char;
					if (count > 1) {
						char count_str[6];
						sprintf(count_str, "[%d]", count);
						result[result_count] = '\0';
						strcat(result, count_str);
						result_count += strlen(count_str);
					}
					count = 1;
					prev_char = c;
				}
			}
			result[result_count++] = prev_char;
			if (count > 1) {
				char count_str[6];
				sprintf(count_str, "[%d]", count);
				result[result_count] = '\0';
				strcat(result, count_str);
				result_count += strlen(count_str);
			}
		
		// запис перетворених рядків у тимчасовий файл
		fprintf(outFile, "%s%s\n", result, other_characters);
	}
	
	fclose(inFile);
	fclose(outFile);
	//видалення файлу та зміна імені тимчасового файлу на імя того файлу
	remove(filename);
	rename(tempfilename, filename);
}
