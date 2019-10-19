#include "Boat.h"

Boat::Boat()
{
	cout << "----------------------------------\n     Добавление катера     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);
		cout << "Введите матеариал корпуса катера = ";
		cin >> this->material;
		cout << "Введите ходовые качества = ";
		cin >> this->_class;
		cout << "Введите количество экипажа = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"Количество экипажа не может быть отрицательным";
		}
		cout << "[1]Мирный или [2]Военный = ";
		cin >> this->destination;
		if (this->destination < 1 || this->destination > 2)
		{
			throw (string)"Неверное назначение парусника";
		}
		cout << "Введите скорость парусника = ";
		cin >> this->speed;
		if (this->speed < 0)
		{
			throw (string)"Скорость не может быть отрицательна";
		}
	}
	catch (string err)
	{
		cout << "ERROR: " + err;
	}
}

Boat::Boat(ifstream& fin)
{
	setType(1);
	fin >> this->destination >> this->material >> this->speed >> this->people >> this->_class;
}

Boat::~Boat()
{
	cout << "Был вызван деструктор класса Boat" << endl;
}

void Boat::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->destination << endl
		<< this->material << endl
		<< this->speed << endl
		<< this->people << endl
		<< this->_class << endl;
}