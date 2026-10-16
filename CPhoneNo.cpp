//ver 5.0 
//20241117
//name

#include "CPhoneNo.h"
#include <iostream>

CPhoneNo::CPhoneNo() //конструктор
	: Plus(0)
	, Phone(0LL)
{
	
}

CPhoneNo::~CPhoneNo() // деструктор
{
	
}

int CPhoneNo::PrintPNs()  const// вводим функцию класса
{
	PNs pP(Phone,Plus); // локальная переменная pP с номером и плюсом

	return ::PrintPNs(&pP); // возвращается к функции для вывода номера телефона
}

int CPhoneNo::ReadPNs() // функция класса, работающая на основе структуры и функции лабы №4
{
	PNs pP; // переменная pP
	::ReadPNs(pP); //функция для чтения переменной pP

	Phone = pP.Phone; // сокращения для телефона
	Plus = pP.Plus; // и для плюса

	return 0;
}
