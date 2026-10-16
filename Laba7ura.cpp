//ver 7.0 
//20241212
// Laba7ura.cpp 

#include <iostream>
#include "..\lab5\CPhoneNo.h"
#include "..\lab5\CPhoneRec.h"
#include "process.h" //для работы с потоками и процессами
#include <vector> //для динамического массива
#include <iomanip> //для модификатора setw
#include <fstream> //для работы с файлами
#include <string> //для строк
#include "PhoneBook.h"
std::string path = "PhBook.txt"; //вводим файл, в который будем записывать данные 

int main()
{
	CPhoneBook bk; //Создаем объект bk типа CPhoneBook
	bk.Read(); //функция чтения
	bk.Add();//функция заполнения массива
	bk.Sort(); //функция сортировки
	bk.Print(); //функция вывода массива
	bk.Write(); //функция записи массива в файл
	bk.Find(); //функция поиска контакта


	std::cout << "I`m CPhoneNo Bye\n"; //выводит прощание с пользователем
	system("pause"); // завершение программы
	return 0; // конец программы
}
