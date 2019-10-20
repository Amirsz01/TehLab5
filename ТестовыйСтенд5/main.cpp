#include <iostream>
#include "Keeper.h"
#include <windows.h>
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
			<< "               МЕНЮ               " << endl
			<< "----------------------------------" << endl
			<< "Кол-во элементов в контейнере : [" << Konten.getSize() << "]" << endl
			<< "[1] Добавить элемент" << endl
			<< "[2] Сохранить данные в файл" << endl
			<< "[3] Загрузить данные из файла" << endl
			<< "[4] Вывести данные из контейнера" << endl
			<< "[0] Выход" << endl;
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
			Konten.load();
			break;
		case 4:
			cout << Konten;
			break;
		case 0:
			return 0;
		default:
			break;
		}
		system("pause");
		/*Меню*/
	} while (true);
}