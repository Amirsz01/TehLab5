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
			<< "[2] Удалить элемент" << endl
			<< "[3] Сохранить данные в файл" << endl
			<< "[4] Загрузить данные из файла" << endl
			<< "[5] Вывести данные из контейнера" << endl
			<< "[0] Выход" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			Konten.add();
			break;
		case 2:
			Konten.del();
			break;
		case 3:
			Konten.save();
			break;
		case 4:
			Konten.load();
			break;
		case 5:
			cout << Konten;
			break;
		case 0:
			return 0;
		default:
			break;
		}
		/*Меню*/
	} while (true);
}