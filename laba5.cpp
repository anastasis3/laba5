#include "stdafx.h" 
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include "ConsoleApplication7 laba5.h"
using namespace std;


class Mebel {
protected:
	string name;
	int kol;
public:
	Mebel(string name, int kol) {
		(*this).name = name;
		(*this).kol = kol;


	}
	virtual * void get_print(void)
	{
		cout << "�������������: " << (*this).name << " ����������: " << (*this).kol;
	}

	Mebel() { cout << "�����������" << endl; }
	virtual ~Mebel() { cout << "����������" << endl; }
};
class Table : public Mebel {
protected:
	int lenth, width;
	int high;
public:
	Table(string name, int kol, int lenth, int width, int high)
		: Mebel(name, kol)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).lenth = lenth;
		(*this).width = width;
		(*this).high = high;


	}

	void * get_print(void)
	{
		cout << " ������������� �����: " << (*this).name << "\n ���������� ������: " << (*this).kol << "\n ����� �����: " << (*this).lenth
			<< "\n ������ �����: " << (*this).width << "\n ������ �����: " << (*this).high;

	}

};


class bookcase : public Mebel {
protected:
	string type;
	string material2;
public:
	bookcase(string name, int kol, string type, string material2)
		: Mebel(name, kol)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).type = type;
		(*this).material2 = material2;


	}

	void * get_print(void)
	{
		cout << "\n ������������� �����: " << (*this).name << "\n ���������� ������: " << (*this).kol << "\n ��� �����: "
			<< (*this).type << "\n �������� : " << (*this).material2;
	}

	string get_bookcase()
	{
		ostringstream nam;
		nam << "\n ������������� �����: " << (*this).name << "\n ���������� ������: " << (*this).kol << "\n ��� �����: "
			<< (*this).type << "\n �������� : " << (*this).material2;
		return nam.str();
	}
};
void seeCase()
{
	string name; int kol; int lenth; int width;
	string type; string material2;
	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}

	cout << "��� �����: "; cin >> type;
	cout << "�������� : "; cin >> material2;
	bookcase* st = new bookcase(name, kol, type, material2);
	cout << (*st).get_bookcase() << endl;
}

void seeTable()
{
	string name; int kol; int lenth; int width; int high;
	string type; string material2;
	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}
	cout << "����� �����: "; cin >> lenth;
	while (lenth < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> lenth;
	}
	cout << "������ �����: "; cin >> width;
	while (width < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> width;
	}
	cout << "������ �����: "; cin >> high;
	while (high < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> high;
	}
	cout << "���: "; cin >> type;
	cout << "�������� : "; cin >> material2;

	Mebel *p[2];//����� ����������
	bookcase obj1(name, kol, type, material2);//�������
	Table obj2(name, kol, lenth, width, high);
	p[0] = &obj1; // ������������� ������� ���������� 
	p[1] = &obj2;

	cout << "�����   ";
	p[0]->get_print();
	cout << "�����   ";
	p[1]->get_print();

}

int main() {
	setlocale(LC_ALL, "Russian");


	int input;

	do {
		cout << "1. ����\n";
		cout << "2. ����\n";
		cout << "3. Exit\n";
		cout << "��� �����: ";
		cin >> input;


		{
			switch (input) {
			case 1:
				seeTable();
				break;
			case 2:
				seeCase();
				break;
			case 3:
				cout << "����������!\n";
				break;
			default:
				cout << "������\n";
				break;
			}

			cin.get();
		}
	} while (input != 3);


	system("pause>>NUL");
	return 0;
}


