#pragma once
#include <fstream>
#include <vector>
#include <list>

namespace bebe {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	/// 

	public ref class INPUT_LAB_Form : public System::Windows::Forms::Form
	{
	public:
		INPUT_LAB_Form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~INPUT_LAB_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::Name_of_LAB);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(89, 166);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(223, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::Commentary);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(134, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Дедлайн";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 169);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Комментарий";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Название";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(30, 253);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(55, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Отчет";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::report_FLB);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(31, 232);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(85, 17);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"Блок схема";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::Block_diagramm_FLB);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(137, 232);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(45, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"Код";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::Code_FLB);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(137, 253);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(56, 17);
			this->checkBox4->TabIndex = 10;
			this->checkBox4->Text = L"IDEF0";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::IDEF0_FLB);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 276);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 19);
			this->button1->TabIndex = 11;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &INPUT_LAB_Form::OK_button_FLB);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(86, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 18);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Что нужно сделать";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 91);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Расположение";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(89, 140);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(223, 20);
			this->dateTimePicker1->TabIndex = 17;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::DeadLine);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &INPUT_LAB_Form::folderBrowserDialog1_HelpRequest);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(89, 88);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(191, 20);
			this->textBox2->TabIndex = 18;
			this->textBox2->Text = L"Введите путь или выберите ->";
			this->textBox2->Click += gcnew System::EventHandler(this, &INPUT_LAB_Form::folderBrowserDialog1_HelpRequest);
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &INPUT_LAB_Form::Input_of_path_LAB);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Location = System::Drawing::Point(286, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(26, 19);
			this->button2->TabIndex = 19;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &INPUT_LAB_Form::Choosing_Path_Of_LAB);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(333, 305);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &INPUT_LAB_Form::MyForm1_Load);
			this->DoubleClick += gcnew System::EventHandler(this, &INPUT_LAB_Form::folderBrowserDialog1_HelpRequest);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) { }

	private: System::Void Name_of_LAB(System::Object^ sender, System::EventArgs^ e) { String^ name = textBox1->Text; }

	private: System::Void Commentary(System::Object^ sender, System::EventArgs^ e) { String^ comm = textBox3->Text; } // комментарий

	private: System::Void report_FLB(System::Object^ sender, System::EventArgs^ e) { char Box1 = checkBox1->Checked; } //отчет

	private: System::Void Block_diagramm_FLB(System::Object^ sender, System::EventArgs^ e) { char Box2 = checkBox2->Checked; } //блок схема

	private: System::Void Code_FLB(System::Object^ sender, System::EventArgs^ e) { char Box3 = checkBox3->Checked; }//код 

	private: System::Void IDEF0_FLB(System::Object^ sender, System::EventArgs^ e) { char Box4 = checkBox4->Checked; } //idef0

	private: System::Void OK_button_FLB(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	} // кнопак OK

	private: System::Void Input_of_path_LAB(System::Object^ sender, System::EventArgs^ e) { String^ targeter = textBox2->Text; } //расположение

	private: System::Void Choosing_Path_Of_LAB(System::Object^ sender, System::EventArgs^ e) {
		folderBrowserDialog1->Description = "Выберите папку с лабораторной";
		if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox2->Text = folderBrowserDialog1->SelectedPath;
		}
	}

	private: System::Void folderBrowserDialog1_HelpRequest(System::Object^ sender, System::EventArgs^ e) { }

	private: System::Void DeadLine(System::Object^ sender, System::EventArgs^ e) { } //дедлайн

	public:
		TextBox^ gettextBox1() { return textBox1; }

		TextBox^ gettextBox3() { return textBox3; }

		TextBox^ gettextBox2() { return textBox2; }

		String^ getCode_FLB() { return (checkBox3->Checked).ToString(); }

		String^ getIDEF0_FLB() { return (checkBox4->Checked).ToString(); }

		String^ getreport_FLB() { return (checkBox1->Checked).ToString(); }

		String^ getBlock_diagramm_FLB() { return (checkBox2->Checked).ToString(); }

		DateTimePicker^ getdateTimePicker1() {
			return dateTimePicker1;
		}
		bool IsDateLaterThanTodayDateOnly(DateTimePicker^ datePicker)
		{
			DateTime selectedDate = datePicker->Value.Date;
			DateTime todayDate = DateTime::Today;
			return selectedDate > todayDate;
		}
	};
}