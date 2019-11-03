#include "Tray.h"

Tray::Tray()
{
	cout << "----------------------------------\n   Добавление подводной лодки\n----------------------------------" << endl << endl;
	try
	{
		setType(1);
		cout << "Введите длину лодки = ";
		cin >> this->length;
		if (!this->length || this->length < 0)
		{
			throw (string)"Длина лодки равна нулю или отрицательна";
		}
		cout << "Введите ширину лодки = ";
		cin >> this->wigth;
		if (!this->wigth || this->wigth < 0)
		{
			throw (string)"Ширина лодки равна нулю или отрицательна";
		}
		cout << "Введите количество экипажа = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"Количество экипажа не может быть отрицательным";
		}
		cout << "Введите количество времени проведенного под водой = ";
		cin >> this->time;
		cout << "Введите скорость лодки = ";
		cin >> this->speed;
		cout << "Введите вооружение лодки : ";
		cin >> this->arms;
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Tray::Tray(ifstream& fin)
{
	setType(1);
	fin >> this->length  >> this->wigth >> this->people >> this->speed >> this->time >> this->arms;
}

Tray::~Tray()
{
	cout << "Был вызван деструктор класса Tray" << endl;
}

void Tray::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->length << endl
		<< this->wigth << endl
		<< this->people << endl
		<< this->speed << endl
		<< this->time << endl
		<< this->arms << endl;
}

void Tray::print(ostream& out)
{
	out << "----------------------------------\n    Подводная лодка    \n----------------------------------" << endl
		<< "Длина лодки : " << length << endl
		<< "Ширина лодки : " << wigth << endl
		<< "Экипаж : " << people << endl
		<< "Время под водой : " << time << endl
		<< "Скорость : " << speed << endl
		<< "Вооружение : " << arms << endl;
}