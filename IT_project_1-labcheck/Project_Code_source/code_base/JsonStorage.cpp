#include "JsonStorage.h"
#include "Models.h"
#include <fstream>
#include <sstream>

using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

//Метод экранирования строки для JSON
//Метод JsonEscape подготавливает строку к безопасной записи в JSON-файл.
String^ JsonStorage::JsonEscape(String^ str)
{
	return str->Replace("\\", "\\\\")->Replace("\"", "\\\"");
}

// Обратное экранирование строки
//Метод UnescapeJson выполняет обратное преобразование после чтения данных из JSON-файла.
String^ JsonStorage::UnescapeJson(String^ str)
{
	if (String::IsNullOrEmpty(str))
		return str;

	return str->Replace("\\\"", "\"")->Replace("\\\\", "\\");
}

//Метод загрузки данных из JSON в ListView
//Метод LoadListViewFromJsonSimple загружает сохранённые лабораторные работы из JSON-файла и восстанавливает их в интерфейсе программы.
void JsonStorage::LoadListViewFromJsonSimple(ListView^ listView, String^ filePath)
{
	try
	{
		if (!File::Exists(filePath)) //Сначала проверяется наличие JSON-файла:
		{
			MessageBox::Show("Файл не найден!", "Ошибка");
			return;
		}

		String^ jsonContent = File::ReadAllText(filePath); //Файл полностью считывается в строку
		listView->Items->Clear(); //Перед загрузкой старые элементы ListView очищаются

		// Разбиваем на строки
		array<String^>^ lines = jsonContent->Split('\n'); //Содержимое разбивается по символу переноса строки:

		//Далее выполняется построчная обработка.
		for each (String ^ line in lines)
		{
			String^ trimmed = line->Trim();

			// Ищем строки с объектами
			//Проверяются строки, содержащие: "text" Такие строки считаются объектами лабораторных работ.
			if (trimmed->StartsWith("{") && trimmed->Contains("\"text\":"))
			{
				// Извлекаем текст между "text":" и следующей кавычкой
				int textStart = trimmed->IndexOf("\"text\":\"") + 8;
				int textEnd = trimmed->IndexOf("\"", textStart);
				if (textStart > 8 && textEnd > textStart)
				{
					String^ mainText = trimmed->Substring(textStart, textEnd - textStart);
					mainText = UnescapeJson(mainText);

					//Создание ListViewItem. На основе считанного текста создаётся новый элемент таблицы:
					ListViewItem^ item = gcnew ListViewItem(mainText);

					// Ищем subitems
					int subStart = trimmed->IndexOf("\"subitems\":[");
					if (subStart != -1)
					{
						int subBegin = trimmed->IndexOf("[", subStart) + 1;
						int subEnd = trimmed->IndexOf("]", subBegin);

						if (subBegin > subStart && subEnd > subBegin)
						{
							String^ subPart = trimmed->Substring(subBegin, subEnd - subBegin);
							array<String^>^ subItems = subPart->Split(',');
							for each (String ^ sub in subItems)
							{
								String^ cleanSub = sub->Trim()->Trim('"');
								cleanSub = UnescapeJson(cleanSub);
								item->SubItems->Add(cleanSub);
							}
						}
					}
					//Добавление элемента в таблицу
					listView->Items->Add(item);
				}
			}
		}
		//После завершения загрузки выводится количество восстановленных элементов.
		MessageBox::Show(String::Format("Загружено {0} элементов!", listView->Items->Count),
			"Успех");
	}
	//Блок:
	catch (Exception^ ex)
	{	//перехватывает ошибки: чтения файла, повреждённого JSON, ошибок обработки строк
		MessageBox::Show("Ошибка: " + ex->Message); //и выводит сообщение пользователю.
	}
}
//Метод сохранения ListView в JSON-файл
//Метод SaveListViewToJsonManual выполняет ручную сериализацию данных из ListView в JSON-формат и сохраняет их в файл.
void JsonStorage::SaveListViewToJsonManual(ListView^ listView, String^ filePath)
{
	//Для формирования JSON используется:
	StringBuilder^ sb = gcnew StringBuilder(); //StringBuilder позволяет эффективно собирать большую строку по частям.
	sb->AppendLine("{");
	sb->AppendLine("  \"items\": [");

	for (int i = 0; i < listView->Items->Count; i++) //Перебор элементов таблицы
	{
		ListViewItem^ item = listView->Items[i];
		sb->Append("    {");
		sb->Append("\"text\":\"" + JsonEscape(item->Text) + "\"");

		if (item->SubItems->Count > 1) //Если у элемента есть дополнительные колонки ->
		{
			sb->Append(", \"subitems\":[");
			for (int j = 1; j < item->SubItems->Count; j++) // -> В него записываются все SubItems, начиная с индекса 1, так как индекс 0 уже хранится в "text".
			{
				sb->Append("\"" + JsonEscape(item->SubItems[j]->Text) + "\"");
				if (j < item->SubItems->Count - 1) sb->Append(",");
			}
			sb->Append("]");
		}

		sb->Append("}");
		if (i < listView->Items->Count - 1) sb->Append(",");
		sb->AppendLine();
	}

	sb->AppendLine("  ]");
	sb->AppendLine("}");
	//Запись в файл после завершения сборки JSON:
	File::WriteAllText(filePath, sb->ToString()); //всё содержимое сохраняется в указанный файл.
}

//Метод удаления выбранного элемента
//Метод RemoveSelectedItem удаляет выбранную лабораторную работу из ListView и обновляет JSON-файл.
void JsonStorage::RemoveSelectedItem(ListView^ listView, String^ filePath)
{
	//Сначала проверяется : Выбран ли хотя бы один элемент в таблице.
	if (listView->SelectedItems->Count > 0)
	{
		//Если элемент выбран :
		listView->Items->Remove(listView->SelectedItems[Id]);
		//Сохранение изменений. Это обновляет JSON-файл и сохраняет новое состояние данных.
		SaveListViewToJsonManual(listView, filePath);
	}
	else
	{
		//Если пользователь не выбрал элемент:
		MessageBox::Show("Выберите элемент для удаления!");
	}
}
//Упрощённый метод сохранения ListView в JSON
//Метод Save выполняет базовое сохранение элементов ListView в JSON-файл.
void JsonStorage::Save(ListView^ listView, String^ filePath)
{
	StringBuilder^ sb = gcnew StringBuilder();

	sb->AppendLine("{");
	sb->AppendLine("  \"items\": [");

	for (int i = 0; i < listView->Items->Count; i++)
	{
		ListViewItem^ item = listView->Items[i];

		sb->Append("    {\"text\":\"" + item->Text + "\"}");

		if (i < listView->Items->Count - 1)
			sb->Append(",");

		sb->AppendLine();
	}

	sb->AppendLine("  ]");
	sb->AppendLine("}");

	File::WriteAllText(filePath, sb->ToString());
}
//Базовый метод загрузки данных
//Метод Load выполняет начальную подготовку для загрузки данных из JSON - файла в ListView.
void JsonStorage::Load(ListView^ listView, String^ filePath)
{
	if (!File::Exists(filePath)) return;

	String^ content = File::ReadAllText(filePath);
	listView->Items->Clear();
}