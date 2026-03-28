#pragma once
#include <windows.h>

namespace bebe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(58, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(58, 102);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(179, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(58, 154);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(179, 20);
			this->textBox3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(122, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ââåäèòå ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(122, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Ââåäèòå ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(122, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Ââåäèòå ";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			listView1->View = View::Details;
			listView1->FullRowSelect = true;
			listView1->GridLines = true;

			listView1->Columns->Add("ID", 50);
			listView1->Columns->Add("Íàçâàíèå", 150);
			listView1->Columns->Add("Ñòàòóñ", 120);
			listView1->Columns->Add("Äåäëàéí", 120);
			listView1->Columns->Add("Êîììåíòàðèé", 250);
			listView1->Columns->Add("×òî íóæíî ñäåëàòü: ", 350);

			ListViewItem^ item1 = gcnew ListViewItem("1");
			item1->SubItems->Add("Ëàáà 0.0 ( test )");
			item1->SubItems->Add("done");
			item1->SubItems->Add("01.01.2000");
			item1->SubItems->Add("ààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààà");

			listView1->Items->Add(item1);

		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: int currentValue;


	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ToolStripMenuItem^ ghToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ äîáàâèòüÐàáîòóToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;








	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->ghToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äîáàâèòüÐàáîòóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(0, 27);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1041, 734);
			this->listView1->TabIndex = 6;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// ghToolStripMenuItem
			// 
			this->ghToolStripMenuItem->Name = L"ghToolStripMenuItem";
			this->ghToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->ghToolStripMenuItem->Text = L"Ñïðàâêà";
			this->ghToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ghToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// äîáàâèòüÐàáîòóToolStripMenuItem
			// 
			this->äîáàâèòüÐàáîòóToolStripMenuItem->Name = L"äîáàâèòüÐàáîòóToolStripMenuItem";
			this->äîáàâèòüÐàáîòóToolStripMenuItem->Size = System::Drawing::Size(112, 20);
			this->äîáàâèòüÐàáîòóToolStripMenuItem->Text = L"Äîáàâèòü ðàáîòó";
			this->äîáàâèòüÐàáîòóToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::äîáàâèòüÐàáîòóToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ghToolStripMenuItem,
					this->helpToolStripMenuItem, this->äîáàâèòüÐàáîòóToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1041, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1041, 764);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"LABTOP";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
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
		"Ýòî ïðîãðàììà äëÿ ó÷åòà ëàáîðàòîðíûõ ðàáîò.\n\n"
		"Ôóíêöèè:\n"
		"- Äîáàâëåíèå ëàáîðàòîðíûõ\n"
		"- Ïðîñìîòð ñòàòóñà\n"
		"- Îòêðûòèå ïàïîê",
		"Ñïðàâêà",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Ðàáîòà ñ ïðîãðàììîé:");
}
private: System::Void äîáàâèòüÐàáîòóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = listView1->Items->Count + 1;

	ListViewItem^ item = gcnew ListViewItem(id.ToString());

	item->SubItems->Add("Íîâàÿ ëàáîðàòîðíàÿ");
	item->SubItems->Add("not started");
	item->SubItems->Add("—");
	item->SubItems->Add("");

	listView1->Items->Add(item);
	/*
	MyForm1^ form = gcnew MyForm1();
	form->ShowDialog();*/
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {

}
};
}
