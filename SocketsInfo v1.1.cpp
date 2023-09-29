#include"SocketsInfo.h"

// функция корректного прерывания соединения
void close_connection(SOCKET& Client_Connection, SOCKET& Server_Socket)
{
	shutdown(Client_Connection, SD_BOTH);
	closesocket(Server_Socket);
	closesocket(Client_Connection);
	WSACleanup();
}

// приём сообщений от клиента и их обработка
int receive_message(SOCKET& ClientConn, SOCKET& ServSock)
{
	int state;
	string message;
	size_t message_size;
	state = recv(ClientConn, (char*)&message_size, sizeof(size_t), 0); // получить размер принимаемого сообщения от клиента
	if (state == SOCKET_ERROR) // если ошибка получения
	{
		close_connection(ClientConn, ServSock);
		return -1;
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
		close_connection(ClientConn, ServSock);
		return -1;
	}
	for (size_t i = 0; i < message_size; i++)
	{
		message += temporary[i];
	}
	if (message == "GRCS" || message == "CCG")
	{
		return 5;
	}
	if (message[0] == '1') // радиотехническая разведка
	{
		int a = stoi(message.substr(1, 2)) - 10;
		Electronic_Recon[a].type = "1";
		Electronic_Recon[a].number = a;
		Electronic_Recon[a].name = message.substr(3, message.size() - 3);
	}
	if (message[0] == '2')  // радиоэлектронная разведка
	{
		int a = stoi(message.substr(1, 2)) - 10;
		Radio_Recon[a].type = "2";
		Radio_Recon[a].number = a;
		Radio_Recon[a].name = message.substr(3, message.size() - 3);
	}
	if (message[0] == '3') // ретранслятор
	{
		int a = stoi(message.substr(1, 2)) - 10;
		Repeaters[a].type = "3";
		Repeaters[a].number = a;
		Repeaters[a].name = message.substr(3, message.size() - 3);
	}
	if (message[0] == '4') // корректировщики огня
	{
		int a = stoi(message.substr(1, 2)) - 10;
		Spotters[a].type = "4";
		Spotters[a].number = a;
		Spotters[a].name = message.substr(3, message.size() - 3);
	}
	if (message[0] == '5') // ударные
	{
		int a = stoi(message.substr(1, 2)) - 10;
		Strikers[a].type = "5";
		Strikers[a].number = a;
		Strikers[a].name = message.substr(3, message.size() - 3);
	}

	message.clear();
	message_size = 0;
	return 0;
}

// отправить сообщение клиентам
int send_message(SOCKET& ClientConn, SOCKET& ServSock)
{
	string message;
	size_t message_size;
	int state;
	getline(cin, message);
	if (message == "close connection")
	{
		close_connection(ClientConn, ServSock);
		return -1;
	}
	message_size = message.size();
	state = send(ClientConn, (char*)&message_size, sizeof(size_t), 0); // отправить клиенту размер сообщения
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		close_connection(ClientConn, ServSock);
		return -1;
	}
	state = send(ClientConn, message.c_str(), message_size, 0); // отправить сообщение
	if (state == SOCKET_ERROR) // если ошибка отправления
	{
		close_connection(ClientConn, ServSock);
		return -1;
	}
	message.clear();
	message_size = 0;
	return 0;
}

// функция - обработчик взаимодействий с клиентами
void Client_Handler(int index)
{
	bool connected = true; // показатель соединения
	while (connected)
	{
		if (receive_message(Clients[index], ServSock) == -1) // если сообщение не получено
		{
			connected = false;
			continue;
		}
	}
	closesocket(Clients[index]); // закрыть сокет
}
