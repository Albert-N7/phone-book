//ver 6.0 
//20241130
//name
#pragma once
#include "CPhoneNo.h"
#include <string>
#include <vector>
class CPhoneRec:public CPhoneNo //данные члены доступны из любой функции
{
public: //данные члены доступны из любой функции
	CPhoneRec();
	~CPhoneRec();
public:
	std::string Nick; // тип данных для имени - строка 
	int ReadPhrec(); // функция обрабатывающая введённое оператором значение
	
	int PrintPhRec();// Выводит имя и номер контакта

	int PrintPhRec(int NameMaxLen) const;
	// Выводит имя и номер контакта, и проверяет длину максимального имени

	bool operator <(const CPhoneRec &right); // сравнивает объекты класса
	void swap(CPhoneRec& right);
};
int Sort6(std::vector<CPhoneRec>& PhBook);
void PrintPhoneBook(const std::vector<CPhoneRec>& PhBook);

