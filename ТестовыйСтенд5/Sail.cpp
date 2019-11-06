#include "Sail.h"

Sail::Sail()
{
	cout << "----------------------------------\n     Добавление парусника     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);
		cout << "Введите название парусника = ";
		cin.ignore(256, '\n');
		getline(cin, name);
		if(name == "")
			throw (string)"Название не может быть пустым";
		cout << "Введите тип парусника = ";
		getline(cin, typeSail);
		if (typeSail == "")
			throw (string)"Тип не может быть пустым";
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
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Sail::Sail(ifstream& fin)
{
	setType(2);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, typeSail);
	fin >> this->destination >> this->_long >> this->speed >> this->people;
}

Sail::~Sail()
{
	cout << "Был вызван деструктор класса Sail" << endl;
	system("pause");
}

void Sail::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Название" << endl
			<< "[2] Тип" << endl
			<< "[3] Экипаж" << endl
			<< "[4] Назначение" << endl
			<< "[5] Скорость" << endl
			<< "[6] Длина" << endl
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
			cout << name << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Название не может быть пустым";
			name = sTmp;
			break;
		case 2:
			cout << typeSail << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Тип не может быть пустым";
			typeSail = sTmp;
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
		case 6:
			cout << _long << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"Длина лодки равна нулю или отрицательна";
			}
			_long = iTmp;
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

void Sail::print(ostream& out)
{
	out << "----------------------------------\n        Парусник        \n----------------------------------" << endl
		<< "Название : " << this->name << endl
		<< "Тип Парусника : " << this->typeSail << endl;
		if (this->destination == 1)
		{
			out << "Назначение : Мирный" << endl;
		}
		else
		{
			out << "Назначение : Военный" << endl;
		}
		out << "Длина : " << this->_long << endl
		<< "Скорость : " << this->speed << endl
		<< "Экипаж : " << this->people << endl;
}
