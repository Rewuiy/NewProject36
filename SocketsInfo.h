#pragma once
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
struct UAV
{
	string type;
	int number;
	string name;
};
inline UAV Strikers[2];
inline UAV Spotters[2];
inline UAV Repeaters[2];
inline UAV Radio_Recon[2];
inline UAV Electronic_Recon[2];
inline SOCKET Clients[2];
inline SOCKET ServSock;
void close_connection(SOCKET& Client_Connection, SOCKET& Server_Socket);
int receive_message(SOCKET& ClientConn, SOCKET& ServSock);
int send_message(SOCKET& ClientConn, SOCKET& ServSock);
void Client_Handler(int index);