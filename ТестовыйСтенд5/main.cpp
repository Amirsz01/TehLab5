#include <iostream>
#include "Keeper.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Keeper Konten;
	int menu;
	do
	{
		system("cls");
		cout << "----------------------------------" << endl
			<< "               ����               " << endl
			<< "----------------------------------" << endl
			<< "���-�� ��������� � ���������� : [" << Konten.getSize() << "]" << endl
			<< "[1] �������� �������" << endl
			<< "[2] ��������� ������ � ����" << endl
			<< "[3] �����" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			Konten.add();
			break;
		case 2:
			Konten.save();
			break;
		case 3:
			return 0;
		default:
			break;
		}
		/*����*/
	} while (true);
}