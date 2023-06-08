#pragma once
#include<string>
#include<msclr/marshal_cppstd.h>
using namespace std;
#include"classes.h"

namespace pr67 {

	File* file1;
	File* file2;
	File* file3;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			file1 = new File("file1");
			file2 = new File("file2");
			file3 = new File("file3");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn1_add_number;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ numberEntry1;
	private: System::Windows::Forms::ListBox^ numbers_1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ numberEntry2;
	private: System::Windows::Forms::Button^ btn2_add_number;
	private: System::Windows::Forms::ListBox^ numbers_2;
	private: System::Windows::Forms::TextBox^ number_to_increase;
	private: System::Windows::Forms::Button^ btn_clear;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ numbers_file3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn1_add_number = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numberEntry1 = (gcnew System::Windows::Forms::TextBox());
			this->numbers_1 = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numberEntry2 = (gcnew System::Windows::Forms::TextBox());
			this->btn2_add_number = (gcnew System::Windows::Forms::Button());
			this->numbers_2 = (gcnew System::Windows::Forms::ListBox());
			this->number_to_increase = (gcnew System::Windows::Forms::TextBox());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numbers_file3 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn1_add_number
			// 
			this->btn1_add_number->BackColor = System::Drawing::Color::DodgerBlue;
			this->btn1_add_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn1_add_number->ForeColor = System::Drawing::SystemColors::Window;
			this->btn1_add_number->Location = System::Drawing::Point(27, 122);
			this->btn1_add_number->Name = L"btn1_add_number";
			this->btn1_add_number->Size = System::Drawing::Size(148, 45);
			this->btn1_add_number->TabIndex = 0;
			this->btn1_add_number->Text = L"Додати";
			this->btn1_add_number->UseVisualStyleBackColor = false;
			this->btn1_add_number->Click += gcnew System::EventHandler(this, &MyForm::btn1_add_number_click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(243, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Файл 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(685, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 31);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Файл 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(25, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Ціле число";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::DarkBlue;
			this->label6->Location = System::Drawing::Point(220, 249);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(208, 31);
			this->label6->TabIndex = 7;
			this->label6->Text = L"У скільки разів ";
			// 
			// numberEntry1
			// 
			this->numberEntry1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numberEntry1->Location = System::Drawing::Point(27, 82);
			this->numberEntry1->Name = L"numberEntry1";
			this->numberEntry1->Size = System::Drawing::Size(148, 34);
			this->numberEntry1->TabIndex = 10;
			this->numberEntry1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::number_entered);
			// 
			// numbers_1
			// 
			this->numbers_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numbers_1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->numbers_1->FormattingEnabled = true;
			this->numbers_1->ItemHeight = 29;
			this->numbers_1->Location = System::Drawing::Point(195, 40);
			this->numbers_1->Name = L"numbers_1";
			this->numbers_1->Size = System::Drawing::Size(197, 178);
			this->numbers_1->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label7->Location = System::Drawing::Point(478, 48);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 31);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Ціле число";
			// 
			// numberEntry2
			// 
			this->numberEntry2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numberEntry2->Location = System::Drawing::Point(480, 82);
			this->numberEntry2->Name = L"numberEntry2";
			this->numberEntry2->Size = System::Drawing::Size(148, 34);
			this->numberEntry2->TabIndex = 15;
			this->numberEntry2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::number_entered);
			// 
			// btn2_add_number
			// 
			this->btn2_add_number->BackColor = System::Drawing::Color::DodgerBlue;
			this->btn2_add_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn2_add_number->ForeColor = System::Drawing::SystemColors::Window;
			this->btn2_add_number->Location = System::Drawing::Point(480, 122);
			this->btn2_add_number->Name = L"btn2_add_number";
			this->btn2_add_number->Size = System::Drawing::Size(148, 45);
			this->btn2_add_number->TabIndex = 16;
			this->btn2_add_number->Text = L"Додати";
			this->btn2_add_number->UseVisualStyleBackColor = false;
			this->btn2_add_number->Click += gcnew System::EventHandler(this, &MyForm::btn2_add_number_click);
			// 
			// numbers_2
			// 
			this->numbers_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numbers_2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->numbers_2->FormattingEnabled = true;
			this->numbers_2->ItemHeight = 29;
			this->numbers_2->Location = System::Drawing::Point(634, 40);
			this->numbers_2->Name = L"numbers_2";
			this->numbers_2->Size = System::Drawing::Size(197, 178);
			this->numbers_2->TabIndex = 17;
			// 
			// number_to_increase
			// 
			this->number_to_increase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->number_to_increase->Location = System::Drawing::Point(249, 324);
			this->number_to_increase->Name = L"number_to_increase";
			this->number_to_increase->Size = System::Drawing::Size(148, 34);
			this->number_to_increase->TabIndex = 18;
			this->number_to_increase->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::number_inc_entered);
			// 
			// btn_clear
			// 
			this->btn_clear->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_clear->ForeColor = System::Drawing::SystemColors::Window;
			this->btn_clear->Location = System::Drawing::Point(216, 424);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(212, 45);
			this->btn_clear->TabIndex = 19;
			this->btn_clear->Text = L"Очистити все";
			this->btn_clear->UseVisualStyleBackColor = false;
			this->btn_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DodgerBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Window;
			this->button2->Location = System::Drawing::Point(205, 373);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(233, 45);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Показати файл 3";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::show_file3);
			// 
			// numbers_file3
			// 
			this->numbers_file3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numbers_file3->ForeColor = System::Drawing::Color::MidnightBlue;
			this->numbers_file3->FormattingEnabled = true;
			this->numbers_file3->ItemHeight = 29;
			this->numbers_file3->Location = System::Drawing::Point(455, 259);
			this->numbers_file3->Name = L"numbers_file3";
			this->numbers_file3->Size = System::Drawing::Size(197, 265);
			this->numbers_file3->TabIndex = 21;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DarkBlue;
			this->label4->Location = System::Drawing::Point(250, 280);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(142, 31);
			this->label4->TabIndex = 22;
			this->label4->Text = L"збільшити";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label5->Location = System::Drawing::Point(497, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 31);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Файл 3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(867, 550);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numbers_file3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btn_clear);
			this->Controls->Add(this->number_to_increase);
			this->Controls->Add(this->numbers_2);
			this->Controls->Add(this->btn2_add_number);
			this->Controls->Add(this->numberEntry2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->numbers_1);
			this->Controls->Add(this->numberEntry1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn1_add_number);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void number_entered(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void btn1_add_number_click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn2_add_number_click(System::Object^ sender, System::EventArgs^ e);
private: System::Void number_inc_entered(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void show_file3(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_clear_click(System::Object^ sender, System::EventArgs^ e);
private: void validate_number_input(String^);
};

}

