/*�17
������� ����� Goods (�����). � ������ ������ ���� ������������ ����: ������������ ������, ���� ����������,
���� ������, ���������� ������ ������, ����� ���������, �� ������� ����� �������� �� �����.
����������� ������ ��������� ���� ������, ��������� ���������� ������, ���������� ��������� ������.
����� toString() ������ �������� � ���� ������ ��������� ������.
����������� �.�.*/

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
	int quantity; //���������� ������ ������
	int cons_num; //����� ���������
public:
	Goods() { price = 0; quantity = 0; cons_num = 0; };
	void Read(); // ���� ������ � ������
	void Display(); // ������ ������ � ������ 
	void Price_change(); //��������� ���� ������
	void Quantity_change(); //��������� ���������� ������
	void Count_cost(int pr, int qu); //���������� ��������� ������
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
		cout << "������������ ������" << endl;
		return 0;
	}
	else
	{
		if (year % 4 == 0 || (year % 100 == 0 && year % 400 != 0))
			isLeap = true;

		if (day < 1 || day > 31) 
		{
			//isValidDate = false;
			cout << "������������ ������" << endl;
			return 0;
		}

		if (month < 1 || month > 12)
		{
			//isValidDate = false;
			cout << "������������ ������" << endl;
			return 0;
		}
		
		if (month == 2 && day > 29 && isLeap == true)
		{
			//isValidDate = false;
			cout << "������������ ������" << endl;
			return 0;
		}

		if (month == 2 && day > 28 && isLeap == false) 
		{
			//isValidDate = false;
			cout << "������������ ������" << endl;
			return 0;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) 
			{
				//isValidDate = false;
				cout << "������������ ������" << endl;
				return 0;
			}
		}
	}

	/*if (!isValidDate)
	{
		cout << "������������ ����!" << endl;
		return 0;
	}
	else*/
		return date;
}

//���� ������
void Goods::Read()
{
	cout << "������� ������������ ������ " << endl;
	cin >> name;
	/*cout << "������� ���� ���������� ������ " << endl;
	cin >> date;*/
	
	/*char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(buffer, 80, format, timeinfo);
	cout << "������� ���� " << buffer << endl;*/

	cout << "������� ���� ���������� ������" << endl;
	date = InputDate();

	cout << "������� ���� ������ " << endl;
	cin >> price;
	cout << "������� ���������� ������ ������ " << endl;
	cin >> quantity;
	cout << "������� ����� ���������, �� ������� ����� �������� �� ����� " << endl;
	cin >> cons_num;
	cout << endl;
}

//������ ������
void Goods::Display()
{
	cout << "������������ ������: " << name << endl;
	cout << "���� ���������� ������: " << date << endl;
	cout << "���� ������: " << price << endl;
	cout << "���������� ������ ������: " << quantity << endl;
	cout << "����� ���������, �� ������� ����� �������� �� �����: " << cons_num << endl;
	Count_cost(Goods::price, Goods::quantity);
	cout << endl;
}

//��������� ���� ������
void Goods::Price_change()
{
	cout << "��������� ���� ������" << endl;
	cout << "������� ����� ���� ������ " << endl;
	cin >> price;
	cout << endl;
}

//��������� ���������� ������ ������
void Goods::Quantity_change()
{
	cout << "��������� ���������� ������ ������" << endl;
	cout << "������� ����� ���������� ������ ������ " << endl;
	cin >> quantity;
	cout << endl;
}

//���������� ��������� ������
void Goods::Count_cost(int pr, int qu)
{
	int cost = pr * qu;
	cout << "��������� ������: " << cost << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Goods gd;
	int number;

	for (; ;)
	{
		cout << "����" << endl;
		cout << "1 - ���� ������ � ������" << endl;
		cout << "2 - ����� ������ � ������" << endl;
		cout << "3 - ��������� ���� ������" << endl;
		cout << "4 - ��������� ���������� ������" << endl;
		cout << "5 - ���������� ��������� ������" << endl;
		cout << "6 - �����" << endl << endl;
		cout << "�������� ����������� ��������" << endl;
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
			cout << "������� ���� ������ " << endl;
			cin >> pr;
			cout << "������� ���������� ������ ������ " << endl;
			cin >> qu;
			gd.Count_cost(qu, pr);
			cout << endl;
			break;
		}
		case 6: exit(1); break;
		default: cout << "����������� ����" << endl; break;
		}
		getchar();

	}

    return 0;
}

