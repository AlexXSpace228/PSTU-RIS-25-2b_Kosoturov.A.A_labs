// Этот код должен быть в .cpp файле (например, Source.cpp или Main.cpp)

#include "MyForm.h" // Обязательно подключите заголовочный файл вашей формы

using namespace System;
using namespace System::Windows::Forms;


// Атрибут [STAThread] обязателен для приложений с Windows Forms.
// Он указывает, что модель потоков COM для приложения — однопоточный апартамент.
[STAThread]
void main(array<String^>^ args) {
    // Включаем визуальные стили Windows (чтобы кнопки были красивые, а не как в Windows 98)
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Создаем экземпляр вашей главной формы
    // Замените 'MyProjectName' на имя вашего пространства имен
    // Замените 'MyForm' на имя класса вашей формы
    bebe::MyForm^ mainForm = gcnew bebe::MyForm();

    // Запускаем цикл сообщений приложения с этой формой
    Application::Run(mainForm);
}