#pragma once
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
struct UAV // структура БЛА
{
	string type; // тип БЛА
	int number; // номер в списке доступных
	string name; // имя БЛА
};
inline UAV Strikers[2]; // массив ударных БЛА
inline UAV Spotters[2]; // массив БЛА - корректировщиков
inline UAV Repeaters[2]; // массив БЛА - ретрансляторов
inline UAV Radio_Recon[2]; // массив БЛА - радиотехнической разведки
inline UAV Electronic_Recon[2]; // массив БЛА - радиоэлектронной разведки

inline SOCKET Clients[2]; // клиенты - НДПУ и ПУ ГБУ
inline SOCKET ServSock; // сервер - ВзПУ
void close_connection(SOCKET& Client_Connection, SOCKET& Server_Socket); // функция корректного прерывания соединения
int receive_message(SOCKET& ClientConn, SOCKET& ServSock); // функция приёма сообщений
int send_message(SOCKET& ClientConn, SOCKET& ServSock); // функция отправки сообщений
void Client_Handler(int index); // функция - обработчик взаимодействий с клиентами