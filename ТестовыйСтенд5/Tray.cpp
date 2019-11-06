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
		if (this->time < 0)
		{
			throw (string)"Время не может быть отрицательным";
		}
		cout << "Введите скорость лодки = ";
		cin >> this->speed;
		if (this->speed < 0)
		{
			throw (string)"Скорость не может быть отрицательным";
		}
		cin.ignore(256, '\n');
		cout << "Введите вооружение лодки : ";
		getline(cin, this->arms);
		if(arms == "")
			throw (string)"Вооружение не может быть пустым";
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
	fin >> this->length  >> this->wigth >> this->people >> this->speed >> this->time;
	fin.ignore(256, '\n');
	getline(fin, arms);
}

Tray::~Tray()
{
	cout << "Был вызван деструктор класса Tray" << endl;
	system("pause");
}

void Tray::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Длина" << endl
			<< "[2] Ширина" << endl
			<< "[3] Экипаж" << endl
			<< "[4] Скорость" << endl
			<< "[5] Время под водой" << endl
			<< "[6] Вооружение" << endl
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
			cout << length << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"Длина лодки равна нулю или отрицательна";
			}
			length = iTmp;
			break;
		case 2:
			cout << wigth << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"Ширина лодки равна нулю или отрицательна";
			}
			wigth = iTmp;
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
			cout << speed << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Скорость не может быть отрицательным";
			}
			speed = iTmp;
			break;
		case 5:
			cout << time << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Время не может быть отрицательным";
			}
			time = iTmp;
			break;
		case 6:
			cout << arms << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if(sTmp == "")
				throw (string)"Вооружение не может быть пустым";
			arms = sTmp;
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