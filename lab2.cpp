/*№17
Создать класс Goods (товар). В классе должны быть представлены поля: наименование товара, дата оформления,
цена товара, количество единиц товара, номер накладной, по которой товар поступил на склад.
Реализовать методы изменения цены товара, изменения количества товара, вычисления стоимости товара.
Метод toString() должен выдавать в виде строки стоимость товара.
Пересыпкина М.А.*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <cstring>

#define LIMIT 3

using namespace std;

class Goods
{
private:
	string name;
	string date;
	int price;
	int quantity; //количество единиц товара
	int cons_num; //номер накладной
public:
	Goods() { price = 0; quantity = 0; cons_num = 0; };
	void Read(); // ввод данных о товаре
	void Display(); // печать данных о товаре 
	void Price_change(); //изменение цены товара
	void Quantity_change(); //изменение количества товара
	void Count_cost(int pr, int qu); //вычисление стоимости товара
};

string InputDate()
{
	string date;
	string array[LIMIT];
	size_t position = 0;
	int index = 0;
	bool isLeap = false;
	bool isValidDate = true;
	int day, month, year;

	cin >> date;

	while ((position = date.find('.')) != string::npos) {
		string token = date.substr(0, position);
		array[index] = token;
		date.erase(0, position + 1);
		index += 1;
	}
	array[index] = date;

	day = atoi(array[0].c_str());
	month = atoi(array[1].c_str());
	year = atoi(array[2].c_str());

	if (year <= 0)
	{
		//isValidDate = false;
		cout << "Некорректные данные" << endl;
		return 0;
	}
	else
	{
		if (year % 4 == 0 || (year % 100 == 0 && year % 400 != 0))
			isLeap = true;

		if (day < 1 || day > 31) 
		{
			//isValidDate = false;
			cout << "Некорректные данные" << endl;
			return 0;
		}

		if (month < 1 || month > 12)
		{
			//isValidDate = false;
			cout << "Некорректные данные" << endl;
			return 0;
		}
		
		if (month == 2 && day > 29 && isLeap == true)
		{
			//isValidDate = false;
			cout << "Некорректные данные" << endl;
			return 0;
		}

		if (month == 2 && day > 28 && isLeap == false) 
		{
			//isValidDate = false;
			cout << "Некорректные данные" << endl;
			return 0;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) 
			{
				//isValidDate = false;
				cout << "Некорректные данные" << endl;
				return 0;
			}
		}
	}

	/*if (!isValidDate)
	{
		cout << "Некорректная дата!" << endl;
		return 0;
	}
	else*/
		return date;
}

//ввод товара
void Goods::Read()
{
	cout << "Введите наименование товара " << endl;
	cin >> name;
	/*cout << "Введите дату оформления товара " << endl;
	cin >> date;*/
	
	/*char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(buffer, 80, format, timeinfo);
	cout << "Введите дату " << buffer << endl;*/

	cout << "Введите дату оформления товара" << endl;
	date = InputDate();

	cout << "Введите цену товара " << endl;
	cin >> price;
	cout << "Введите количество единиц товара " << endl;
	cin >> quantity;
	cout << "Введите номер накладной, по которой товар поступил на склад " << endl;
	cin >> cons_num;
	cout << endl;
}

//печать товара
void Goods::Display()
{
	cout << "Наименование товара: " << name << endl;
	cout << "Дата оформления товара: " << date << endl;
	cout << "Цена товара: " << price << endl;
	cout << "Количество единиц товара: " << quantity << endl;
	cout << "Номер накладной, по которой товар поступил на склад: " << cons_num << endl;
	Count_cost(Goods::price, Goods::quantity);
	cout << endl;
}

//Изменение цены товара
void Goods::Price_change()
{
	cout << "Изменение цены товара" << endl;
	cout << "Введите новую цену товара " << endl;
	cin >> price;
	cout << endl;
}

//Изменение количества единиц товара
void Goods::Quantity_change()
{
	cout << "Изменение количества единиц товара" << endl;
	cout << "Введите новое количество товара товара " << endl;
	cin >> quantity;
	cout << endl;
}

//Вычисление стоимости товара
void Goods::Count_cost(int pr, int qu)
{
	int cost = pr * qu;
	cout << "Стоимость товара: " << cost << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Goods gd;
	int number;

	for (; ;)
	{
		cout << "Меню" << endl;
		cout << "1 - Ввод данных о товаре" << endl;
		cout << "2 - Вывод данных о товаре" << endl;
		cout << "3 - Изменение цены товара" << endl;
		cout << "4 - Изменение количества товара" << endl;
		cout << "5 - Вычисление стоимости товара" << endl;
		cout << "6 - Выход" << endl << endl;
		cout << "Выберете необходимое действие" << endl;
		cin >> number;

		switch (number)
		{
		case 1: gd.Read(); break;
		case 2: gd.Display(); break;
		case 3: gd.Price_change(); break;
		case 4: gd.Quantity_change(); break;
		case 5: 
		{
			int pr, qu;
			cout << "Введите цену товара " << endl;
			cin >> pr;
			cout << "Введите количество единиц товара " << endl;
			cin >> qu;
			gd.Count_cost(qu, pr);
			cout << endl;
			break;
		}
		case 6: exit(1); break;
		default: cout << "Некорретный ввод" << endl; break;
		}
		getchar();

	}

    return 0;
}

