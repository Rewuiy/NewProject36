#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <stdio.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
struct UAV // структура БЛА
{
	bool is_available; // показатель доступности БЛА
	double x, y; // координаты i-ого БЛА
	double velocity; // величина скорости
	double heading; // угол курса i-ого БЛА
	string name; // имя i-ого БЛА
	string type; // тип БЛА
	int position_number; // номер в списке доступных БЛА данного типа
	UAV() // конструктор по умолчанию
	{
		position_number = 0;
		is_available = false;
	}
	UAV(const string& Type, const int& Position, const string& Name) // инициализирующий конструктор
	{
		position_number = Position;
		type = Type;
		name = Name;
		is_available = true;
		x = 5; y = 5;
		heading = 0.7854;
		velocity = 0.1;
	}
};

void close_connection(SOCKET& Client_Socket) // функция прерывания соединения
{
	shutdown(Client_Socket, SD_BOTH); // прервать работу сокета
	closesocket(Client_Socket); // закрыть сокет
	WSACleanup(); // освободить ресурсы системы
}

bool send_message(SOCKET& ClientConn, const string& message) // функция отправки сообщений ВзПУ БЛА
{
	size_t message_size;
	int state;
	if (message == "close connection")
	{
		close_connection(ClientConn);
		return -1;
	}
	message_size = message.size();
	state = send(ClientConn, (char*)&message_size, sizeof(size_t), 0); // отправить клиенту размер сообщения
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		cout << "Сообщение не отправлено.\n"; // вывести диагностическое сообщение
		close_connection(ClientConn); // прервать соединение
		return -1;
	}
	state = send(ClientConn, message.c_str(), message_size, 0); // отправить сообщение
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		cout << "Сообщение не отправлено.\n"; // вывести диагностическое сообщение
		close_connection(ClientConn); // прервать соединение
		return -1;
	}
}
int main()
{
	// обозначение количества доступных в симуляции БЛА
	size_t number_of_fire_spotters = 2;
	size_t number_of_electronic_intelligence = 2;
	size_t number_of_radar_reconnaissance = 2;
	size_t number_of_strikers = 2;
	size_t number_of_repeaters = 2;

	// объявление массивов БЛА
	UAV** Fire_Spotter = new UAV * [number_of_fire_spotters];
	UAV** Electronic_Intelligence = new UAV * [number_of_electronic_intelligence];
	UAV** Radar_Recoinnaissance = new UAV * [number_of_radar_reconnaissance];
	UAV** Striker = new UAV * [number_of_strikers];
	UAV** Repeater = new UAV * [number_of_repeaters];

	// инициализация массивов БЛА
	for (size_t i = 10; i < 13; i++)
	{
		Fire_Spotter[i - 10] = new UAV("4", i, "Наблюдатель");
		Electronic_Intelligence[i - 10] = new UAV("1", i, "Дозор");
		Radar_Recoinnaissance[i - 10] = new UAV("2", i, "Шпион");
		Striker[i - 10] = new UAV("5", i, "Молот");
		Repeater[i - 10] = new UAV("3", i, "Передатчик");
	}

	const char SERVER_IP[] = "127.0.0.2"; // IP-адрес сервера
	const short SERVER_PORT_NUM = 80;	// номер порта сервера

	// перевод значения IP-адреса из формата char* в необходимый для обработки функциями библиотеки WinSock
	in_addr ip_to_numeric_format;
	inet_pton(AF_INET, SERVER_IP, &ip_to_numeric_format);


	// инициализация переменных из библиотеки WinSock
	WSADATA wsData;
	if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0)
	{
		return 1;
	}

	// инициализация сокета
	SOCKET Client_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Client_Socket == INVALID_SOCKET)
	{
		closesocket(Client_Socket);
		WSACleanup();
	}

	// установка соединения c сервером
	sockaddr_in Server_Information;
	ZeroMemory(&Server_Information, sizeof(Server_Information));
	Server_Information.sin_family = AF_INET;
	Server_Information.sin_addr = ip_to_numeric_format;
	Server_Information.sin_port = htons(SERVER_PORT_NUM);
	if (connect(Client_Socket, (sockaddr*)&Server_Information, sizeof(Server_Information)) != 0) // если функция подключения вернула не нуль
	{
		cout << "Нет соединения с сервером.\n"; // вывести диагностическое сообщение об ошибке
		closesocket(Client_Socket); // закрыть сокет
		WSACleanup(); // освобождение ресурсов системы
		return 1;
	}
	else
	{
		cout << "Соединение с сервером установлено.\n"; // вывести диагностическое сообщение об установке соединения
	}
	send_message(Client_Socket, "GRCS");  // отправить сообщение ВзПУ о готовности к соединению

	string decision;
	getline(cin, decision);
	if (decision == "send") // отправить данные по БЛА на ВзПУ БЛА
	{
		bool connected = true; // показатель установленного соединения
		while (connected)
		{
			string m; // строка - сообщение о состоянии БЛА и других его параметрах
			for (size_t i = 0; i < 2; i++)
			{
				m = Electronic_Intelligence[i]->type + to_string(Electronic_Intelligence[i]->position_number) + " " + Electronic_Intelligence[i]->name;
				send_message(Client_Socket, m);
			}
			m.clear();
			for (size_t i = 0; i < 2; i++)
			{
				m = Radar_Recoinnaissance[i]->type + to_string(Radar_Recoinnaissance[i]->position_number) + " " + Radar_Recoinnaissance[i]->name;
				send_message(Client_Socket, m);
			}
			m.clear();
			for (size_t i = 0; i < 2; i++)
			{
				m = Repeater[i]->type + to_string(Repeater[i]->position_number) + " " + Repeater[i]->name;
				send_message(Client_Socket, m);
			}
			m.clear();
			for (size_t i = 0; i < 2; i++)
			{
				m = Fire_Spotter[i]->type + to_string(Fire_Spotter[i]->position_number) + " " + Fire_Spotter[i]->name;
				send_message(Client_Socket, m);
			}
			m.clear();
			for (size_t i = 0; i < 2; i++)
			{
				m = Striker[i]->type + to_string(Striker[i]->position_number) + " " + Striker[i]->name;
				send_message(Client_Socket, m);
			}
			m.clear();
		}
	}

	closesocket(Client_Socket); // закрыть сокет
	WSACleanup(); // освободить затраченные ресурсы системы
	return 0;
}
