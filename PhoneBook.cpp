//ver 7.0 
//20241212
//PhoneBook.cpp

#include "PhoneBook.h"
#include <iostream>
#include "..\lab5\CPhoneNo.h"
#include "..\lab5\CPhoneRec.h"
#include "process.h" //для работы с потоками и процессами
#include <vector> //для динамического массива
#include <iomanip> //для модификатора setw
#include <fstream> //для работы с файлами
#include <string> //для строк
CPhoneBook::CPhoneBook() //конструктор
{
	m_path = "PhoneBook.txt"; //Записываем файл, предназначенный для хранения контактов, в переменную 
}

CPhoneBook::~CPhoneBook() //деструктор
{
}

void CPhoneBook::Read() //функция чтения
{
	std::ifstream inFile;  //Ввод файла
	inFile.open(m_path); //Открываем файл
	if (inFile.is_open()) //если файл открыт выполняем:
	{
		do //цикл do while 
		{
			CPhoneRec rec; //Создаем объект rec класса CPhoneRec, в котором храняться имена и номера контактов
			inFile >> rec.Nick; //читаем имя контакта
			if (rec.Nick.empty()) // Если имя пустое, цикл прерывается
				break;
			std::string sPk; //вводим строку sPk которая отвечает за номер контакта
			inFile >> sPk; //записываем номер в строку sPk
			if ('+' == sPk[0])//если первый символ "+"
			{
				rec.Plus = 1; // устанавливается данное выражение
				sPk.erase(0, 1); //"+" удаляется из строки sPk
			}

			char* pE; // указывает на последний преобразованный символ 
			rec.Phone = strtoll(sPk.c_str(), &pE, 10); //преобразует строку sPk в длинное целое число
			
		} while (inFile.eof());
		inFile.close(); //закртыие файла после чтения
	}
}

void CPhoneBook::Add()
{
	int maxName = 0; //Вводим переменную maxName, равную 0
	do {
			CPhoneRec Phone; // Создаем объект Phone типа CPhoneRec
			Phone.ReadPhrec(); //Функция, отвечающая за вывод предложения о вводе номера. И получает введённые данные от пользователя 
			if (0 == Phone.Phone) // если введённое значение "0" программа завершается
			{
				break;
			}
			m_book.push_back(Phone);// добавляет элемент в массив
			if (Phone.Nick.size() > maxName) // посмотрели размер введенного имени
				maxName = Phone.Nick.size(); // сравнили длину имени с размером
	
	} while (1);
}

int CPhoneBook::Sort() //Вводим функцию сортировки
{
	return Sort6(m_book); //Обращаемся у уже определенной в Лабе 6 функции
}

void CPhoneBook::Print() //Вводим функцию печати
{
	PrintPhoneBook(m_book); //Обращаемся к функции вывода таблицы 
}

void CPhoneBook::Write()  //функция Write класса CPhoneBook
{
	CPhoneRec Phone; //Создает объект Phone класса CPhoneRec
	int maxName = 0; //Вводим переменную maxName, равную нулю
	struct PNs; //объявляем структуру PNs
	std::ofstream oFile(m_path); //Создается объект oFile типа std::ofstream, который предназначен для записи данных в файл. 
	
	if (!oFile.is_open()) //Если файл не был успешно открыт  
	{
		std::cout << "Error, the file could not be opened for writing"; //Выводится сообщение об ошибки 
		return; //прерывается
	}

	for (auto it = m_book.begin(); it != m_book.end(); it++) // цикл для 
		if (it->Nick.size() > maxName) //если размер имени больше максимальной длины
			maxName = it->Nick.size(); //максимальная длина равна размеру
	int d = 1; // Вводим счетчик контактов 
	
	oFile << "Num"
		<< std::setw(5) << "Name" << std::setw(maxName - 2) << " "
		<< std::setw(6) << "Number" << std::endl; // вывод шапки таблицы, с помощью использования манипулятора setw, который задает определенную длину значения для вводимого элемента

	for (int i = 0; i < m_book.size(); i++) //цикл для вывода таблицы
	{
		oFile << std::setw(3) << d; // Запись порядкового номера, с помощью манипулятора setw, который выделил для этого 3 элемента строки
		
		oFile << std::string(" ") << std::setw(maxName) << m_book[i].Nick; //Записываем имя контакта в файл
		// Преобразуем номер телефона в строку
		std::string phoneNumber = '+' + std::to_string(m_book[i].Phone);
		if (m_book[i].Plus) // Если номер начинается с '+'
		{
			oFile << std::string(" ") << std::setw(16) << phoneNumber; // выводим переменную phoneNumber в которой содержится знак "+" и номер
		}
		else
		{
			oFile << std::string(" ") << std::setw(16) << m_book[i].Phone; // Выводим номер телефона
		}
		oFile << std::endl; // перевод строки на следующую
		d++;// увеличение порядкового номера на единицу
	}
	std::cout << "successful writing to a file!"; //Проведена успешная запись в файл
	std::cout << std::endl; //перевод строки
	oFile.close();// закрываем файл для записи

}

int CPhoneBook::Find() //Вводим функцию поиска
{
	while (true) //выполняется пока не станет ложным
	{
		std::cout << "Please define name to find (if you want leave, write 0)\n"; //Введите имя контакта, который хотите найти (0 выход из программы)
	
		std::string sF; //определяем строку sF
		std::cin >> sF; //Записываем введенное значение в строку sF

		if (sF == "0") //если введенное имя равно нулю - выход из программы
		{ 
			return 0; // Выход из функции
		}

		CPhoneRec rcF; //Вводим объект rcF класса CPhoneRec
		rcF.Nick = sF; //строка sF отвечает за имя контакта
		int left = 0, right = m_book.size() - 1, middle; //вводим переменные (начало массива, конец и середина)
		bool bFind = false;		//Вводим булевскую переменную 
	
		do //выполняем поиск контакта методом дихотомии(пока количество данных в конце массива больше или равно количеству данных вначале)
		{
			middle = (left + right) / 2; //середина - среднее арифмитическое значение
			if (m_book[middle] < rcF) //если имя находится в правой части массива
			{
				left = middle + 1; //Ищем в начале 

			}
			else if (rcF < m_book[middle]) //иначе если
			{
				right = middle - 1; // Ищем в левой части массива

			}
			else //иначе
			{
				rcF = m_book[middle]; //имя находиться в середине
				if (rcF.Plus) //если первый символ номера "+" выводим номер со знаком
					std::cout << "ura pobeda, derzhite nomer: +" << rcF.Phone << std::endl;
				else// если номер без знака, оставляем просто номер
					std::cout << "ura pobeda, derzhite nomer: " << rcF.Phone << std::endl;
				bFind = true; //поиск выполнен
				break;//выход из цикла
			}

		} while (left <= right);

		if (!bFind) //если имя не удалось найти - повторяем поиск
		{
			std::cout << "Ne nashel :(" << std::endl;
			std::cout << "Try again" << std::endl;
		}
		
	}

}
