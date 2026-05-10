#include "JsonStorage.h"
#include <fstream>
#include <sstream>

using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

String^ JsonStorage::JsonEscape(String^ str)
{
	return str->Replace("\\", "\\\\")->Replace("\"", "\\\"");
}

// Обратное экранирование строки
String^ JsonStorage::UnescapeJson(String^ str)
{
	if (String::IsNullOrEmpty(str))
		return str;

	return str->Replace("\\\"", "\"")->Replace("\\\\", "\\");
}

void JsonStorage::LoadListViewFromJsonSimple(ListView^ listView, String^ filePath)
{
	try
	{
		if (!File::Exists(filePath))
		{
			MessageBox::Show("Файл не найден!", "Ошибка");
			return;
		}

		String^ jsonContent = File::ReadAllText(filePath);
		listView->Items->Clear();

		// Разбиваем на строки
		array<String^>^ lines = jsonContent->Split('\n');

		for each (String ^ line in lines)
		{
			String^ trimmed = line->Trim();

			// Ищем строки с объектами
			if (trimmed->StartsWith("{") && trimmed->Contains("\"text\":"))
			{
				// Извлекаем текст между "text":" и следующей кавычкой
				int textStart = trimmed->IndexOf("\"text\":\"") + 8;
				int textEnd = trimmed->IndexOf("\"", textStart);
				if (textStart > 8 && textEnd > textStart)
				{
					String^ mainText = trimmed->Substring(textStart, textEnd - textStart);
					mainText = UnescapeJson(mainText);

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
								if (!String::IsNullOrEmpty(cleanSub))
									item->SubItems->Add(cleanSub);
							}
						}
					}

					listView->Items->Add(item);
				}
			}
		}

		MessageBox::Show(String::Format("Загружено {0} элементов!", listView->Items->Count),
			"Успех");
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка: " + ex->Message);
	}
}

void JsonStorage::SaveListViewToJsonManual(ListView^ listView, String^ filePath)
{
	StringBuilder^ sb = gcnew StringBuilder();
	sb->AppendLine("{");
	sb->AppendLine("  \"items\": [");

	for (int i = 0; i < listView->Items->Count; i++)
	{
		ListViewItem^ item = listView->Items[i];
		sb->Append("    {");
		sb->Append("\"text\":\"" + JsonEscape(item->Text) + "\"");

		if (item->SubItems->Count > 1)
		{
			sb->Append(", \"subitems\":[");
			for (int j = 1; j < item->SubItems->Count; j++)
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
	File::WriteAllText(filePath, sb->ToString());
}
void JsonStorage::RemoveSelectedItem(ListView^ listView, String^ filePath)
{
	if (listView->SelectedItems->Count > 0)
	{
		listView->Items->Remove(listView->SelectedItems[0]);
		SaveListViewToJsonManual(listView, filePath);
	}
	else
	{
		MessageBox::Show("Выберите элемент для удаления!");
	}
}

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

void JsonStorage::Load(ListView^ listView, String^ filePath)
{
	if (!File::Exists(filePath)) return;

	String^ content = File::ReadAllText(filePath);
	listView->Items->Clear();
}