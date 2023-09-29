#include"Start_Screen.h" // подключение первого окна формы
using namespace System;
using namespace System::Windows::Forms; // пространство имён, предоставляющее доступ к функциям формы

// функция перехода на основную страницу программы
System::Void TRSPUAVC::Start_Screen::start_button_Click(System::Object^ sender, System::EventArgs^ e) // функция перехода на основной экран
{
	this->Hide(); // закрыть эту страницу
	Next_Page->Show(); // открыть следующую
}
System::Void TRSPUAVC::Start_Screen::connection_start_Click(System::Object^ sender, System::EventArgs^ e) // функция установки соединения с НДПУ и ПУ ГБУ
{
	if (check_systems() == false) // если клиенты не подключены
	{
		diagnostics_message->Hide();
		issue_message->Show(); // вывести диагностическое сообщение об ошибке
		start_button->Enabled = false;
	}
	else // при успешном подключении клиентов
	{
		diagnostics_message->Hide();
		readiness_message->Show(); // вывести диагностическое сообщение 
	}
}

[STAThreadAttribute] // обязательное требование для обмена сообщениями с сервером сообщений Windows с компонентами COM - системные диалоги
void main(cli::array<String^>^ arguments)
{
	Application::EnableVisualStyles(); // включает визуальные стили для приложения
	Application::SetCompatibleTextRenderingDefault(false); // задаёт по умолчанию значения для свойств определённых компонентов управления
	TRSPUAVC::Start_Screen Page;
	Application::Run(% Page); // запуск приложения
	return;
}

bool check_systems() // функция проверки установки соединения сервера с клиентом
{
	const char IP_SERV[] = "127.0.0.2";			// IP-адрес сервера
	const int PORT_NUM = 80;				    // номер порта сервера

	// перевод значения IP-адреса из формата char* в необходимый для обработки функциями библиотеки WinSock
	in_addr IP_to_numeric;
	inet_pton(AF_INET, IP_SERV, &IP_to_numeric);

	// инициализация переменных из библиотеки WinSock
	WSADATA wsData;
	WSAStartup(MAKEWORD(2, 2), &wsData);

	// инициализация серверного сокета
	ServSock = socket(AF_INET, SOCK_STREAM, 0);
	if (ServSock == INVALID_SOCKET)
	{
		closesocket(ServSock);
		WSACleanup();
	}

	// связывание серверного сокета
	sockaddr_in servInfo;
	ZeroMemory(&servInfo, sizeof(servInfo));	// Initializing servInfo structure
	servInfo.sin_family = AF_INET;
	servInfo.sin_addr = IP_to_numeric;
	servInfo.sin_port = htons(PORT_NUM);

	if (bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo)) != 0)
	{
		closesocket(ServSock);
		WSACleanup();
	}
	
	if (listen(ServSock, SOMAXCONN) != 0)
	{
		closesocket(ServSock);
		WSACleanup();
	}

	// создание клиентских сокетов и приёма сообщений
	sockaddr_in clientInfo;
	ZeroMemory(&clientInfo, sizeof(clientInfo));

	size_t counter = 0;
	SOCKET New_Connection;
	int clientInfo_size = sizeof(clientInfo);
	for (size_t index = 0; index < 2; index++)
	{
		New_Connection = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size); // подключение нового клиента
		if (New_Connection == INVALID_SOCKET)
		{
			continue;
		}
		else
		{
			Clients[index] = New_Connection; // запись в массив клиентов нового соединения
			receive_message(Clients[index], ServSock); // прием сообщений
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Client_Handler, LPVOID(index), 0, 0); // создание нового потока для обработки взаимодействия с i-ым клиентом
			counter++;
		}
	}
	return true;
}
