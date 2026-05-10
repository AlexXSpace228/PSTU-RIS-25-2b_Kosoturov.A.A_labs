#pragma once
#include <fstream>
#include <vector>
#include <list>
#include "INPUT_LAB_Form.h"
#include "JsonStorage.h"
#include "LabService.h"

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
	
	public ref class MAIN_Form : public System::Windows::Forms::Form
	{
	public:
		MAIN_Form(void)
		{
			InitializeComponent();
			listView1->View = View::Details;
			listView1->FullRowSelect = true;
			listView1->GridLines = true;
			listView1->Columns->Add("ID", 50);
			listView1->Columns->Add("Название", 150);
			listView1->Columns->Add("Статус", 120);
			listView1->Columns->Add("Дедлайн", 120);
			listView1->Columns->Add("Комментарий", 250);
			listView1->Columns->Add("Что нужно сделать", 250);
			listView1->Columns->Add("Расположение",120);

			JsonStorage::LoadListViewFromJsonSimple(listView1, "1tgf.json");
		}

	protected:
		~MAIN_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		List<String^>^ GetFilesWithMultipleExtensions(String^ folderPath, array<String^>^ extensions)
		{
			List<String^>^ files = gcnew List<String^>();

			for each (String ^ ext in extensions)
			{
				array<String^>^ found = Directory::GetFiles(folderPath, "*" + ext);

				for each (String ^ file in found)
				{
					files->Add(file);
				}
			}

			return files;
		}

	private: int currentValue;

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ToolStripMenuItem^ ghToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьРаботуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ УдалитьРаботуToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->ghToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьРаботуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->УдалитьРаботуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(0, 27);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1041, 734);
			this->listView1->TabIndex = 6;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MAIN_Form::listView1_SelectedIndexChanged);
			this->listView1->DoubleClick += gcnew System::EventHandler(this, &MAIN_Form::listView1_DoubleClick);
			this->ghToolStripMenuItem->Name = L"ghToolStripMenuItem";
			this->ghToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->ghToolStripMenuItem->Text = L"Справка";
			this->ghToolStripMenuItem->Click += gcnew System::EventHandler(this, &MAIN_Form::ghToolStripMenuItem_Click);
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MAIN_Form::helpToolStripMenuItem_Click);
			this->добавитьРаботуToolStripMenuItem->Name = L"добавитьРаботуToolStripMenuItem";
			this->добавитьРаботуToolStripMenuItem->Size = System::Drawing::Size(112, 20);
			this->добавитьРаботуToolStripMenuItem->Text = L"Добавить работу";
			this->добавитьРаботуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MAIN_Form::добавитьРаботуToolStripMenuItem_Click);
			this->УдалитьРаботуToolStripMenuItem->Name = L"УдалитьРаботуToolStripMenuItem";
			this->УдалитьРаботуToolStripMenuItem->Size = System::Drawing::Size(104, 20);
			this->УдалитьРаботуToolStripMenuItem->Text = L"Удалить работу";
			this->УдалитьРаботуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MAIN_Form::УдалитьРаботуToolStripMenuItem_Click);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4)
			{
				this->ghToolStripMenuItem,
				this->helpToolStripMenuItem, this->добавитьРаботуToolStripMenuItem, this->УдалитьРаботуToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1041, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MAIN_Form::menuStrip1_ItemClicked);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),static_cast<System::Int32>(static_cast<System::Byte>(64)),static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1041, 764);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"LABTOP";
			this->Load += gcnew System::EventHandler(this, &MAIN_Form::MyForm_Load);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &MAIN_Form::MyForm_Resize);
			this->Resize += gcnew System::EventHandler(this, &MAIN_Form::MyForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
	int margin = 5;

	listView1->SetBounds(
		margin,
		menuStrip1->Height + margin,
		this->ClientSize.Width - 2 * margin,
		this->ClientSize.Height - menuStrip1->Height - 2 * margin
	);
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void ghToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Это программа для учета лабораторных работ.\n\n"
		"Функции:\n"
		"- Добавление лабораторных\n"
		"- Просмотр статуса\n"
		"- Открытие папок",
		"Справка",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Работа с программой:");
}
private: System::Void УдалитьРаботуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	JsonStorage::RemoveSelectedItem(listView1, "1tgf.json");
}
private: System::Void добавитьРаботуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	INPUT_LAB_Form^ form = gcnew INPUT_LAB_Form();
	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK && form->gettextBox1()->Text != "" && form->IsDateLaterThanTodayDateOnly(form->getdateTimePicker1()))
	{
		int maxId = 0;

		for each (ListViewItem ^ item in listView1->Items)
		{
			int temp;
			if (Int32::TryParse(item->Text, temp))
			{
				if (temp > maxId) maxId = temp;
			}
		}

		int id = maxId + 1;

		ListViewItem^ item = gcnew ListViewItem(id.ToString());

		item->SubItems->Add(form->gettextBox1()->Text);
		item->SubItems->Add(" ");

		item->SubItems->Add(form->getdateTimePicker1()->Text);
		if (form->gettextBox3()->Text == "") {
			form->gettextBox3()->Text = " ";
		}
		item->SubItems->Add(form->gettextBox3()->Text);
		item->SubItems->Add("fff");
		item->SubItems->Add(form->gettextBox2()->Text);
		array<String^>^ files = gcnew array<String^>{ ".txt", ".doc", ".xls" };
		List<String^>^ geter = GetFilesWithMultipleExtensions(form->gettextBox2()->Text, files);

		if (geter->Count == 0) {
			item->BackColor = System::Drawing::Color::Yellow;
		}
		// Цвет лабы в списке

		listView1->Items->Add(item);
		JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {

}
private: System::Void listView1_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	ListView^ listView = (ListView^)sender;

	if (listView->SelectedItems->Count > 0)
	{
		ListViewItem^ selectedItem = listView->SelectedItems[0];

		LabItem^ lab = LabService::FromListViewItem(selectedItem);

		System::Windows::Forms::DialogResult statusChange = MessageBox::Show(
			"Название лабораторной: " + lab->Title + "\n\n"
			"Статус выполнения: " + lab->Status + "\n"
			"Срок до: " + lab->Deadline + "\n"
			"\n=================================\n"
			"Комментарий: " + lab->Comment + "\n"
			"Что нужно сделать: " + lab->Task + "\n"
			"Расположение файлов:\n" + lab->Path + "\n"
			"\n=================================\n\n"
			"Вы сдали лабораторную работу?\n"
			"Выберите ОК или Отмена \\/ \\/\n"
			,
			"",
			MessageBoxButtons::OKCancel
		);
		if (statusChange == System::Windows::Forms::DialogResult::OK) {
			selectedItem->SubItems[2]->Text = "done";
			JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
		}
		else if (statusChange == System::Windows::Forms::DialogResult::Cancel) {
			selectedItem->SubItems[2]->Text = "not";
			JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
		}
	}
}
};
}
