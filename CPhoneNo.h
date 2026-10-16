//ver 5.0 
//20241117
//name

#pragma once
#include "process.h"
#include <string>
#include "..\\Лаба4\laba4.h"
class CPhoneNo // класс
{
public: //данные члены доступны из любой функции
	CPhoneNo(); //конструктор
	~CPhoneNo(); //деструктор

public: //данные члены доступны из любой функции
	ULL Phone : 63; // Переменная Phone может хранить положительные целые числа 
	ULL Plus : 1; //Переменная Plus хранит одно значение
	int PrintPNs() const; // функция для вывода номера телефона
	int ReadPNs(); // функция для чтения

};

