#pragma once
#include "Models.h"

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class LabService
{
public:
	//Метод FromListViewItem используется для преобразования строки интерфейса(ListViewItem) в объект модели LabItem.
    static LabItem^ FromListViewItem(ListViewItem^ item)
    {
		//Создаётся новый объект:
        LabItem^ lab = gcnew LabItem();

		//Для доступа к колонкам используются значения из enum LabColumns

		//Из каждой колонки ListView считываются данные:
		//Поле Id хранится как int, поэтому используется: Int32::Parse(...)
        lab->Id = Int32::Parse(item->SubItems[Id]->Text);
		//Остальные значения сохраняются как строки (String^).
        lab->Title = item->SubItems[Title]->Text;
        lab->Status = item->SubItems[Status]->Text;
        lab->Deadline = item->SubItems[Deadline]->Text;
        lab->Comment = item->SubItems[Comment]->Text;
        lab->Task = item->SubItems[Task]->Text;
        lab->Path = item->SubItems[PAth]->Text;
		//Значения копируются в поля объекта LabItem
        return lab;
    }

	//Метод поиска файлов по расширениям
	//Метод GetFilesWithMultipleExtensions выполняет поиск файлов с указанными расширениями внутри выбранной папки.
	static List<String^>^ GetFilesWithMultipleExtensions(String^ folderPath, array<String^>^ extensions)
	{
		/*
		Входные параметры
			folderPath — путь к директории
			extensions — массив расширений файлов : .txt .doc .drawio .vpd и т.д.
		*/

		//Основная логика:
		//Создаётся список: List<String^>^ files В него будут сохраняться найденные файлы.
		List<String^>^ files = gcnew List<String^>();

		// Проверка корректности пути
		if (String::IsNullOrWhiteSpace(folderPath))
			return files;

		// Проверка существования папки
		if (!Directory::Exists(folderPath))
			return files;

		try
		{
			for each (String ^ ext in extensions)
			{
				array<String^>^ found = Directory::GetFiles(folderPath, "*" + ext);

				for each (String ^ file in found)
				{
					files->Add(file);
				}
			}
		}
		catch (Exception^)
		{
			return files;
		}

		return files;
	}
	//Метод обновления статуса лабораторной работы
	//Метод UpdateItemStatus выполняет автоматическую проверку состояния лабораторной работы на основе файлов в указанной директории.
	static void UpdateItemStatus(ListViewItem^ item)
	{
		//Сначала проверяется : существует ли ListViewItem, содержит ли он необходимое количество колонок
		if (!item || item->SubItems->Count < 11)
			return; //Это защищает программу от ошибок доступа к несуществующим данным.

		String^ path = item->SubItems[LabColumns::PAth]->Text; //Из колонки Path считывается путь:
		bool validPath = !String::IsNullOrWhiteSpace(path) && Directory::Exists(path);
		//проверяется: путь не пустой, папка существует
		//Если путь некорректен: статус = "not", задача = "INVALID PATH", строка подсвечивается красным цветом
		if (!validPath)
		{
			item->SubItems[Status]->Text = "Не выполнено";
			item->SubItems[PAth]->Text = "INVALID PATH";
			item->BackColor = Color::Red;
			return;
		}
		//Из скрытых колонок считываются флаги:нужна ли блок-схема нужен ли код нужен ли отчёт нужен ли IDEF0
		bool needBD = item->SubItems[BD]->Text == "True";
		bool needCode = item->SubItems[Code]->Text == "True";
		bool needReport = item->SubItems[Report]->Text == "True";
		bool needIdef = item->SubItems[IDEF0]->Text == "True";
		bool hasAnyRequirement = needBD || needCode || needReport || needIdef;

		if (!hasAnyRequirement)
		{
			item->SubItems[Status]->Text = "Не выполнено";
			item->SubItems[Task]->Text = "Готово к сдаче";
			item->BackColor = Color::LightYellow;
			return;
		}

		auto drawio = GetFilesWithMultipleExtensions(path, gcnew array<String^>{".drawio"});
		auto txt = GetFilesWithMultipleExtensions(path, gcnew array<String^>{".txt"});
		auto doc = GetFilesWithMultipleExtensions(path, gcnew array<String^>{".doc", ".docx"});
		auto vpd = GetFilesWithMultipleExtensions(path, gcnew array<String^>{".vpd"});

		int missing = 0;
		String^ task = "";

		if (needBD && drawio->Count == 0)
		{
			task += "Блок схема | ";
			missing++;
		}

		if (needCode && txt->Count == 0)
		{
			task += "Код | ";
			missing++;
		}

		if (needReport && doc->Count == 0)
		{
			task += "Отчет | ";
			missing++;
		}

		if (needIdef && vpd->Count == 0)
		{
			task += "IDEF0 | ";
			missing++;
		}

		item->SubItems[Task]->Text = task;

		if (missing == 0 && hasAnyRequirement && validPath)
		{
			// если уже сдано вручную — не трогаем
			if (item->SubItems[Status]->Text == "Выполнено")
			{
				item->BackColor = Color::LightGreen;
				item->SubItems[Task]->Text = "Сдано";
			}
			else
			{
				item->SubItems[Status]->Text = "not";
				item->SubItems[Task]->Text = "Готово к сдаче";

				// мягкий зеленый
				item->BackColor = Color::LightYellow;
			}
		}
		else
		{
			item->SubItems[Status]->Text = "Не выполнено";
			item->SubItems[Task]->Text = task;
			item->BackColor = Color::Yellow;
		}
	}

};