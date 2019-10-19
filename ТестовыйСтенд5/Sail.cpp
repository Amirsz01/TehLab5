#include "Sail.h"

Sail::Sail()
{
	cout << "----------------------------------\n     Добавление парусника     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);
		cout << "Введите название парусника = ";
		cin >> this->name;
		cout << "Введите тип парусника = ";
		cin >> this->typeSail;
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
		cout << "Введите длину парусника = ";
		cin >> this->_long;
		if (this->_long < 0)
		{
			throw (string)"Длина не может быть отрицательна";
		}
	}
	catch (string err)
	{
		cout << "ERROR: " + err;
	}
}

Sail::Sail(ifstream& fin)
{
	setType(2);
	fin >> this->name >> this->typeSail >> this->destination >> this->_long >> this->speed >> this->people;
}

Sail::~Sail()
{
	cout << "Был вызван деструктор класса Sail" << endl;
}

void Sail::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->name << endl
		<< this->typeSail << endl
		<< this->destination << endl
		<< this->_long << endl
		<< this->speed << endl
		<< this->people << endl;
}