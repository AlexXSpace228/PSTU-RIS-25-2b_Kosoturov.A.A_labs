#pragma once

using namespace System;
using namespace System::Windows::Forms;

public ref class JsonStorage
{
public:

	static String^ JsonEscape(String^ str);

	static String^ UnescapeJson(String^ str);

	static void LoadListViewFromJsonSimple(ListView^ listView, String^ filePath);

	static void SaveListViewToJsonManual(ListView^ listView, String^ filePath);
	
    static void RemoveSelectedItem(ListView^ listView, String^ filePath);
	
    static void Save(ListView^ listView, String^ filePath);

    static void Load(ListView^ listView, String^ filePath);
}; 