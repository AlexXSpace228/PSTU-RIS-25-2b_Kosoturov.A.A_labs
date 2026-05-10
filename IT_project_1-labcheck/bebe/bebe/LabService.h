#pragma once
#include "Models.h"

using namespace System;
using namespace System::Windows::Forms;

public ref class LabService
{
public:

    int GetNextId(ListView^ listView)
    {
        int maxId = 0;

        for each (ListViewItem ^ item in listView->Items)
        {
            int id;
            if (Int32::TryParse(item->Text, id))
            {
                if (id > maxId) maxId = id;
            }
        }

        return maxId + 1;
    }

    static void MarkDone(ListViewItem^ item, bool done)
    {
        item->SubItems[2]->Text = done ? "done" : "not";
    }

    static LabItem^ FromListViewItem(ListViewItem^ item)
    {
        LabItem^ lab = gcnew LabItem();

        lab->Id = Int32::Parse(item->SubItems[0]->Text);
        lab->Title = item->SubItems[1]->Text;
        lab->Status = item->SubItems[2]->Text;
        lab->Deadline = item->SubItems[3]->Text;
        lab->Comment = item->SubItems[4]->Text;
        lab->Task = item->SubItems[5]->Text;
        lab->Path = item->SubItems[6]->Text;

        return lab;
    }
};