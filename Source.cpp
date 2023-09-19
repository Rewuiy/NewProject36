#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <stdio.h>
#include<string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
struct UAV // структура БЛА
{
	
	bool is_available;
	double x, y;
	double velocity;
	double heading;
	string name;
	string type;
	int position_number;
	UAV()
	{
		position_number = 0;
		is_available = false;
	}
	UAV(const string& Type, const int& Position, const string& Name)
	{
		position_number = Position;
		type = Type;
		name = Name;
		is_available = true;
		x = 5; y = 5;
		heading = 0.7854; 
		velocity = 0.1;
	}
	/*void calculate_coordinates()
	{
		x += velocity * cos(heading) * 1;
		y += velocity * sin(heading) * 2;
	}*/
};

void close_connection(SOCKET& Client_Socket)
{
	shutdown(Client_Socket, SD_BOTH);
	closesocket(Client_Socket);
	WSACleanup();
}
int receive_message(SOCKET& ClientConn)
{
	bool connected = true;
	while (connected)
	{
		int state;
		string message;
		size_t message_size;
		state = recv(ClientConn, (char*)&message_size, sizeof(size_t), 0); // получить размер принимаемого сообщения от клиента
		if (state == SOCKET_ERROR) // если ошибка получения
		{
			cout << "Размер сообщения не принят.\n"; // вывести диагностическое сообщение
			close_connection(ClientConn);
			connected = false;
			continue;
		}
		else
		{
			cout << message_size << endl;
		}
		char* temporary = new char[message_size + 1];
		temporary[message_size] = '\0';
		state = recv(ClientConn, temporary, message_size, 0); // получить сообщение в строке от клиента
		if (state == SOCKET_ERROR) // если ошибка получения
		{
			cout << "Сообщение не получено.\n"; // вывести диагностическое сообщение
			close_connection(ClientConn);
			connected = false;
			continue;
		}
		for (size_t i = 0; i < message_size; i++)
		{
			message += temporary[i];
		}
		cout << "Полученное сообщение: " << message << endl;
		if (message == "connected")
		{
			return 5;
		}
		message.clear();
		message_size = 0;
	}
}
bool send_message(SOCKET& ClientConn, const string& message)
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
		close_connection(ClientConn);
		return -1;
	}
	state = send(ClientConn, message.c_str(), message_size, 0);
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		cout << "Сообщение не отправлено.\n"; // вывести диагностическое сообщение
		close_connection(ClientConn);
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

	//Key constants
	const char SERVER_IP[] = "127.0.0.2";
	const short SERVER_PORT_NUM = 80;				// Enter Listening port on Server side

	// Key variables for all program
	int erStat;										// For checking errors in sockets functions

	//IP in string format to numeric format for socket functions. Data is in "ip_to_num"
	in_addr ip_to_num;
	inet_pton(AF_INET, SERVER_IP, &ip_to_num);


	// WinSock initialization
	WSADATA wsData;
	erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0)
	{
		return 1;
	}

	// Socket initialization
	SOCKET Client_Socket = socket(AF_INET, SOCK_STREAM, 0);

	if (Client_Socket == INVALID_SOCKET)
	{
		//cout << "Error initialization socket # " << WSAGetLastError() << endl;
		closesocket(Client_Socket);
		WSACleanup();
	}


	// Establishing a connection to Server
	sockaddr_in Server_Information;

	ZeroMemory(&Server_Information, sizeof(Server_Information));

	Server_Information.sin_family = AF_INET;
	Server_Information.sin_addr = ip_to_num;
	Server_Information.sin_port = htons(SERVER_PORT_NUM);

	// установка соединения
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
	send_message(Client_Socket, "GRCS");  // отправить сообщение о готовности к соединению

	string decision;
	getline(cin, decision);
	if (decision == "send")
	{
		bool t = false;
		bool connected = true;
		while (connected)
		{
			if (t == false)
			{
				string m;
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
				t = true;
			}

			/*if (send_message(Client_Socket) == -1)
			{
				connected == false;
				continue;
			}*/
		}
	}
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)send_message, LPVOID(Client_Socket), 0, 0);
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)receive_message, LPVOID(Client_Socket), 0, 0);
	

	closesocket(Client_Socket);
	WSACleanup();
	return 0;
}