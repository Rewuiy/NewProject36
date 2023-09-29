#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <stdio.h>
#include<string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

void close_connection(SOCKET& Client_Socket) // закрыть сокет и освободить ресурсы системы
{
	shutdown(Client_Socket, SD_BOTH); // прервать работу сокета
	closesocket(Client_Socket); // закрыть сокет
	WSACleanup(); // освободить ресурсы системы
}

int send_message(SOCKET& ClientConn) // функция отправки сообщений серверу
{
	string message;
	size_t message_size;
	int state;
	cout << "Сообщение клиента: ";
	getline(cin, message);
	if (message == "close connection")
	{
		close_connection(ClientConn);
		return -1;
	}
	message_size = message.size();
	state = send(ClientConn, (char*)&message_size, sizeof(size_t), 0); // отправить серверу размер сообщения
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		cout << "Сообщение не отправлено.\n"; // вывести диагностическое сообщение
		close_connection(ClientConn); // прервать соединение
		return -1;
	}
	state = send(ClientConn, message.c_str(), message_size, 0); // отправить серверу сообщение
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		cout << "Сообщение не отправлено.\n"; // вывести диагностическое сообщение
		close_connection(ClientConn);
		return -1;
	}
	message.clear();
	message_size = 0;
	return 0;
}
int main()
{
	//Key constants
	const char SERVER_IP[] = "127.0.0.2"; // IP-адрес сервера
	const short SERVER_PORT_NUMBER = 80;	// номер порта сервера

	// перевод значения IP-адреса из формата char* в необходимый для обработки функциями библиотеки WinSock
	in_addr IP_to_numeric;
	inet_pton(AF_INET, SERVER_IP, &IP_to_numeric);


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
		closesocket(Client_Socket); // закрыть сокет
		WSACleanup(); // освободить ресурсы системы
	}

	// установка соединения с сервером
	sockaddr_in Server_Information;
	ZeroMemory(&Server_Information, sizeof(Server_Information));
	Server_Information.sin_family = AF_INET;
	Server_Information.sin_addr = IP_to_numeric;
	Server_Information.sin_port = htons(SERVER_PORT_NUMBER);
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

	send_message(Client_Socket); // отправить на ВзПУ сообщение о готовности к работе
	bool connected = true; // показатель соединения
	while (connected) // пока соединение активно
	{
		if (send_message(Client_Socket) == -1) // если сообщение не отправлено
		{
			connected = false;
			continue;
		}
	}
	closesocket(Client_Socket); // закрыть сокет
	WSACleanup(); // освободить ресурсы системы
	return 0;
}
