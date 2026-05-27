// Подключение форм, JSON-хранилища, бизнес-логики и моделей
#include "INPUT_LAB_Form.h"
#include "JsonStorage.h"
#include "LabService.h"
#include "Models.h"

namespace bebe {

	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	
	public ref class MAIN_Form : public System::Windows::Forms::Form
	{
	public:
		MAIN_Form(void)
		{
			
			//При запуске формы:
			//UI таблицы настраивается
			//Загружаются сохранённые данные
			//Для каждой записи пересчитывается актуальный статус
			
			InitializeComponent();

			listView1->View = View::Details;
			listView1->FullRowSelect = true;
			listView1->GridLines = true;

			//Формируется структура таблицы лабораторных работ
			//Важно: порядок колонок строго соответствует SubItems у ListViewItem
			listView1->Columns->Add("ID", 0); //*
			listView1->Columns->Add("Название", 200);
			listView1->Columns->Add("Статус", 120);
			listView1->Columns->Add("Дедлайн", 120);
			listView1->Columns->Add("Комментарий", 200);
			listView1->Columns->Add("Что нужно сделать", 250);
			listView1->Columns->Add("Расположение",150);
			listView1->Columns->Add("BD", 10);
			listView1->Columns->Add("code", 10);
			listView1->Columns->Add("report", 10);
			listView1->Columns->Add("idef", 10);

			//загрузка сохранённых лабораторных работ из JSON-файла при запуске
			JsonStorage::LoadListViewFromJsonSimple(listView1, "1tgf.json");

			for each(ListViewItem ^ item in listView1->Items)
			{
				LabService::UpdateItemStatus(item);
			}
		}

	protected:
		~MAIN_Form()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ToolStripMenuItem^ ghToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьРаботуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ УдалитьРаботуToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   // ... UI код (без логики)

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
// === АВТО-RESIZE LISTVIEW ===

private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { }

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) { }

private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) { }

private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Руководство пользователя\n\n"
		"1. Добавление лабораторной работы:\n"
		"- Откройте меню 'Добавить работу'\n"
		"- Введите название лабораторной\n"
		"- Укажите дедлайн выполнения\n"
		"- Выберите папку с файлами работы\n"
		"- Отметьте требуемые материалы (код, отчет, схемы и т.д.)\n"
		"- Нажмите OK для сохранения\n\n"

		"2. Контроль выполнения:\n"
		"- После добавления система автоматически проверяет наличие файлов\n"
		"- Статус работы обновляется автоматически\n"
		"- Красный цвет — ошибка или отсутствие файлов\n"
		"- Желтый — работа не готова\n"
		"- Зеленый — работа выполнена\n\n"

		"3. Сдача работы:\n"
		"- Дважды щелкните по записи\n"
		"- Подтвердите сдачу через диалоговое окно\n"
		"- При отсутствии файлов сдача будет отклонена\n\n"

		"4. Управление:\n"
		"- Удаление работ доступно через меню\n"
		"- Данные сохраняются автоматически в JSON-файл\n\n"

		"Система предназначена для автоматизации учета и контроля лабораторных работ.",
		"Help",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}

private: System::Void УдалитьРаботуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { JsonStorage::RemoveSelectedItem(listView1, "1tgf.json"); }

private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
	int margin = 5;
	listView1->SetBounds(
		margin,
		menuStrip1->Height + margin,
		this->ClientSize.Width - 2 * margin,
		this->ClientSize.Height - menuStrip1->Height - 2 * margin
	);
}

private: System::Void ghToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Автоматизированное рабочее место (АРМ) контроля лабораторных работ\n\n"
		"Назначение системы:\n"
		"Программа предназначена для учета, хранения и автоматической проверки выполнения лабораторных работ студентов.\n\n"
		"Основные возможности:\n"
		"- Ведение списка лабораторных работ с параметрами (название, дедлайн, комментарий, путь к файлам)\n"
		"- Хранение данных в JSON-формате с автоматической синхронизацией\n"
		"- Автоматическая проверка выполнения на основе наличия файлов (код, отчет, схемы, IDEF0)\n"
		"- Отображение статуса выполнения с цветовой индикацией\n"
		"- Возможность ручного подтверждения сдачи работы\n\n"
		"Принцип работы:\n"
		"Система анализирует содержимое указанной директории и автоматически обновляет статус лабораторной работы без участия пользователя.",
		"Справка",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}

//Обработчик : добавление лабораторной работы
private: System::Void добавитьРаботуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {	

	//Этот метод реализует полный цикл :
	//ввод ---> валидация ---> проверка файлов ---> формирование записи ---> сохранение

	/*
	Основная логика
	Открывается форма ввода : INPUT_LAB_Form, пользователь вводит данные лабораторной
	Проверяется корректность ввода : форма закрыта с OK, название не пустое, дедлайн не раньше текущей даты
	*/

	INPUT_LAB_Form^ form = gcnew INPUT_LAB_Form();
	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK && form->gettextBox1()->Text != "" && form->IsDateLaterThanTodayDateOnly(form->getdateTimePicker1()))
	{
		int maxId = 0;

		/*
		Генерация ID
		Происходит поиск максимального ID среди существующих элементов:
		перебор всех ListViewItem
		парсинг item->Text
		Новый ID = maxId + 1
		обеспечивает уникальность идентификаторов без базы данных
		*/

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

		item->SubItems->Add(form->gettextBox1()->Text); // Title
		item->SubItems->Add("not");                      // Status (важно!)
		item->SubItems->Add(form->getdateTimePicker1()->Text);
		item->SubItems->Add(form->gettextBox3()->Text);
		item->SubItems->Add(""); // Task пустой — его заполнит сервис
		item->SubItems->Add(form->gettextBox2()->Text);

		// флаги
		item->SubItems->Add(form->getBlock_diagramm_FLB());
		item->SubItems->Add(form->getCode_FLB());
		item->SubItems->Add(form->getreport_FLB());
		item->SubItems->Add(form->getIDEF0_FLB());

		// ВАЖНО: единая точка расчёта логики
		LabService::UpdateItemStatus(item);

		listView1->Items->Add(item);
		JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
	}
}

private: System::Void listView1_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	ListView^ listView = (ListView^)sender;

	if (listView->SelectedItems->Count > 0)
	{
		ListViewItem^ selectedItem = listView->SelectedItems[Id];

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
		if (statusChange == System::Windows::Forms::DialogResult::OK)
		{
			// Проверяем есть ли незавершенные пункты
			if (selectedItem->SubItems[Task]->Text != "Готово к сдаче")
			{
				MessageBox::Show(
					"Не все файлы готовы!\n\n"
					"Осталось сделать:\n" +
					selectedItem->SubItems[Task]->Text,
					"Ошибка"
				);

				return;
			}

			selectedItem->SubItems[Status]->Text = "Выполнено";
			selectedItem->BackColor = System::Drawing::Color::LightGreen;

			JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
		}
		else if (statusChange == System::Windows::Forms::DialogResult::Cancel)
		{
			selectedItem->SubItems[Status]->Text = "Не выполнено";
			selectedItem->BackColor = System::Drawing::Color::Yellow;

			JsonStorage::SaveListViewToJsonManual(listView1, "1tgf.json");
		}
	}
}
};
}
