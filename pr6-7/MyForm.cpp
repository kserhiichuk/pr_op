#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;
using namespace System::Threading;

[STAThreadAttribute]
int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	pr67::MyForm form;
	Application::Run(% form);
}

System::Void pr67::MyForm::btn1_add_number_click(System::Object^ sender, System::EventArgs^ e) {
	String^ n = numberEntry1->Text;
	try {
		numberEntry1->Text = "";
		validate_number_input(n);
		int number = Convert::ToInt32(n);
		file1->add(number);
		numbers_1->Items->Add(n);
	}
	catch (const char* s) {
		String^ message = marshal_as<String^>(s);
		String^ title = "Помилка";
		MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void pr67::MyForm::btn2_add_number_click(System::Object^ sender, System::EventArgs^ e) {
	String^ n = numberEntry2->Text;
	try {
		numberEntry2->Text = "";
		validate_number_input(n);
		int number = Convert::ToInt32(n);
		file2->add(number);
		numbers_2->Items->Add(n);
	}
	catch (const char* s) {
		String^ message = marshal_as<String^>(s);
		String^ title = "Помилка";
		MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void pr67::MyForm::number_entered(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Ви можете вводити тільки цілі числа!");
		e->Handled = true;
	}
}

System::Void pr67::MyForm::number_inc_entered(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b' && e->KeyChar != '-') {
		MessageBox::Show("Ви можете вводити тільки цілі числа!");
		e->Handled = true;
	}
}

System::Void pr67::MyForm::show_file3(System::Object^ sender, System::EventArgs^ e) {
	String^ n = number_to_increase->Text;
	try {
		validate_number_input(n);
		int number = Convert::ToInt32(n);
		numbers_file3->Items->Clear();
		file3->clear();
		file3->write_from_another(number, file1, file2);
		int size;
		int* numbers = file3->read(size);
		for (int i = 0; i < size; i++) {
			numbers_file3->Items->Add(numbers[i]);
		}
		delete[] numbers;
	}
	catch (const char* s) {
		String^ message = marshal_as<String^>(s);
		String^ title = "Помилка";
		MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void pr67::MyForm::button_clear_click(System::Object^ sender, System::EventArgs^ e) {
	try {
	file1->clear();
	file2->clear();
	file3->clear();
	numbers_1->Items->Clear();
	numbers_2->Items->Clear();
	numbers_file3->Items->Clear();
	number_to_increase->Text = "";
	}
	catch (const char* s) {
		String^ message = marshal_as<String^>(s);
		String^ title = "Помилка";
		MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Void pr67::MyForm::validate_number_input(String^ input) {
	string num_s = marshal_as<std::string>(input);

	if (input == "")
		throw "Введіть ціле число";

	if (num_s.find('-') != -1 && (num_s.find("-", 1) != -1 || num_s.find("-") > 0))
		throw "Введено зайвий символ!";

	if (num_s.length() > 6 && num_s[0] != '-') {
		throw "Введене число завелике!\nВведіть число у діапазоні (-1 000 000;1 000 000)";
	}
	if (num_s.length() > 7 && num_s[0] == '-') {
		throw "Введене число замале\nВведіть число у діапазоні (-1 000 000;1 000 000)";
	}
}
