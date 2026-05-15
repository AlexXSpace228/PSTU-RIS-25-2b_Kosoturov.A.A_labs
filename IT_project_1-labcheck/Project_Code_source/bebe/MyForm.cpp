#include "MAIN_Form.h"
using namespace System;
using namespace System::Windows::Forms;

// Атрибут [STAThread] обязателен для приложений с Windows Forms.
// Он указывает, что модель потоков COM для приложения — однопоточный апартамент.
[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    bebe::MAIN_Form^ mainForm = gcnew bebe::MAIN_Form();
    Application::Run(mainForm);
}