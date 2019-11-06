#include "Boat.h"

Boat::Boat()
{
	cout << "----------------------------------\n     Добавление катера     \n----------------------------------" << endl << endl;
	try
	{
		setType(3);
		cout << "Введите матеариал корпуса катера = ";
		cin.ignore(256, '\n');
		getline(cin, material);
		if(material == "")
			throw (string)"Материал не может быть пустым";
		cout << "Введите ходовые качества = ";
		getline(cin, _class);
		if (_class == "")
			throw (string)"Ходовые качества не могут быть пустыми";
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
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Boat::Boat(ifstream& fin)
{
	setType(3);
	fin >> this->destination;
	fin.ignore(256, '\n');
	getline(fin, material);
	fin >> this->speed >> this->people;
	fin.ignore(256, '\n');
	getline(fin, _class);
}

Boat::~Boat()
{
	cout << "Был вызван деструктор класса Boat" << endl;
}

void Boat::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Материал" << endl
			<< "[2] Ходовые качества" << endl
			<< "[3] Экипаж" << endl
			<< "[4] Назначение" << endl
			<< "[5] Скорость" << endl
			<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:
			cout << material << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Материал не может быть пустым";
			material = sTmp;
			break;
		case 2:
			cout << _class << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Ходовые качества не могут быть пустыми";
			_class = sTmp;
			break;
		case 3:
			cout << people << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Количество экипажа не может быть отрицательным";
			}
			people = iTmp;
			break;
		case 4:
			if (destination == 1)
			{
				cout << "Мирный" << endl;
			}
			else
			{
				cout << "Военный" << endl;
			}
			cout << "Новое значение [1/2]: ";
			cin >> iTmp;
			if (iTmp < 1 || iTmp > 2)
			{
				throw (string)"Назначение должно быть [1/2]";
			}
			destination = iTmp;
			break;
		case 5:
			cout << speed << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Скорость не может быть отрицательным";
			}
			speed = iTmp;
			break;
		default:
			break;
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
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

void Boat::print(ostream& out)
{
	out << "----------------------------------\n        Катер        \n----------------------------------" << endl;
	if (this->destination == 1)
	{
		out << "Назначение : Мирный" << endl;
	}
	else
	{
		out << "Назначение : Военный" << endl;
	}
	out << "Материал : " << this->material << endl
		<< "Скорость : " << this->speed << endl
		<< "Экипаж : " << this->people << endl
		<< "Ходовые качества : " << this->_class << endl;
}
