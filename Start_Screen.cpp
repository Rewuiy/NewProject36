#include"Start_Screen.h" // подключение первого окна формы
//#include"SocketsInfo.h"
using namespace System;
using namespace System::Windows::Forms; // пространство имён, предоставляющее доступ к функциям работы с окнами

// функция перехода на основную страницу программы
System::Void TRSPUAVC::Start_Screen::start_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide(); // закрыть эту страницу
	Next_Page->Show(); // открыть следующую
}
using namespace System;
using namespace System::Windows::Forms; // пространство имён, предоставляющее доступ к функциям работы с окнами

[STAThreadAttribute] // обязательное требование для обмена сообщениями с сервером сообщений Windows с компонентами COM - системные диалоги
void main(cli::array<String^>^ arguments)
{
	Application::EnableVisualStyles(); // включает визуальные стили для приложения
	Application::SetCompatibleTextRenderingDefault(false); // задаёт по умолчанию значения для свойств определённых компонентов управления
	TRSPUAVC::Start_Screen Page;
	Application::Run(% Page); // запуск приложения
	return;
}