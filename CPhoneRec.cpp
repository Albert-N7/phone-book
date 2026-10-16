//ver 6.0 
//20241130
//name

#include "CPhoneRec.h"
#include <iostream>
#include <iomanip>



CPhoneRec::CPhoneRec() //конструктор
{

}
CPhoneRec::~CPhoneRec() //деструктор
{

}
int CPhoneRec::ReadPhrec() //функция класса, основана на функции из lab4
{
	ReadPNs(); // функция для чтения введённых значений
	std::cout << ("Please input your nickname\n"); //введите имя контакта
	std::cin >> Nick; //получает данные введенные пользователем
	
    return 0;
}

int CPhoneRec::PrintPhRec() // Функция для вывода: имени, номера, двоичного кода
{
	PrintPhRec(Nick.size()); // по allghn
	return 0;
}

int CPhoneRec::PrintPhRec(int NameMaxLen) const // Функция для вывода: имени и номера
{
	
	std::cout << std::string(" ") << std::setw(NameMaxLen) <<  Nick; // выводит Ник и выделяет определенное количество элементов строки под него
	
	std::cout << '|'; // вывод границы столбика
	
	PrintPNs(); // выводит номер телефона
	std::cout << ("|") << std::endl; // вывод границы столбика

	return 0;
}



bool CPhoneRec::operator<(const CPhoneRec& right) //функция сравнения введенных строк
{
	std::string strL(Nick), strR(right.Nick);  //тип данных - произвольная строка, содержащая сиволы алфавита
	StrUpper(strL); //приводит первую букву первого имени к прописной
	StrUpper(strR); //приводит первую букву второго имени к прописной

	
	return strL < strR;
}
void CPhoneRec::swap(CPhoneRec& right) //Функция для перестановки
{
	CPhoneRec glass = right; //создаем объект glass типа CPhoneRec, который принимает значение объекта right для последующего обмена
	right = *this; //значения текущего объекта заменяются значениями объекта right
	*this = glass; //текущий объект this получает значения, сохраненные в объекте glass
}

int Sort6(std::vector<CPhoneRec>& PhBook) //функция сортировки
{
	int nSw = 0; // Вводим переменную, которая считает количество обменов

	for (int i = 0; i < PhBook.size() - 1; i++)//цикл для, исключающий последний элемент 
	{
		int nNotSorted = 0; //Переменная, для количества элементов, которые были переставлены местами за один проход, если 0 то массив отсортирован
		for (int j = PhBook.size() - 1; i < j; j--)  //цикл для сортировки элементов в обратном порядке, он проходит по всем неотсортированным элементам
		{
			if (PhBook[j] < PhBook[j - 1]) //Если данный элемент меньше прошлого меняем местами, с помощью swap()
			{
				PhBook[j].swap(PhBook[j - 1]);//обмен значениями между [j] и [j-1]
				nNotSorted++; // Увеличивает количество переставленых местами элементов
			}
		}
		if (nNotSorted == 0) //если количество неотсортированных элементов равно 0
			break; //выходим из цикла
		nSw += nNotSorted; //добавляем к количеству обменов количество отсортированных элементов
		
#ifdef _DEBUG
		
		std::cout << "Iteration No " << i + 1 << std::endl; //Вывод строки, которая считает количество проведенных обменов
		PrintPhoneBook(PhBook); //вывод промежуточной таблицы значений 
		
#endif
	}

	std::cout << "count swap: " << nSw << std::endl; //выводит количество 
	
	return nSw;//Возвращаем количество обменов
	
}

void PrintPhoneBook(const std::vector<CPhoneRec>& PhBook) //функция для вывода телефонной книжки
{
	int maxName = 0; //вводим переменную, которая будет содержать количество символов в имени

	for (auto it = PhBook.begin(); it != PhBook.end(); it++) // цикл для 
		if (it->Nick.size() > maxName) //если размер имени больше максимальной длины
			maxName = it->Nick.size(); //максимальная длина равна размеру


	int d = 1; // Вводим счетчик контактов 
	std::cout << "Num"
		<< std::setw(5) << "Name" << std::setw(maxName - 2) << " "
		<< std::setw(6) << "Number" << std::endl; // вывод шапки таблицы, с помощью использования манипулятора setw, который задает определенную длину значения для вводимого элемента



	for (int i = 0; i < PhBook.size(); i++) //цикл для вывода таблицы
	{
		std::cout << std::setw(3) << d; // вывод порядкового номера, с помощью манипулятора setw, который выделил для этого 3 элемента строки
		std::cout << '|'; //выводит границу столбика
		PhBook[i].PrintPhRec(maxName); // функция для вывода имени и номера контакта
		//std::cout << std::endl; // перевод строки на следующую
		d++;// увеличение порядкового номера на единицу
	}


}