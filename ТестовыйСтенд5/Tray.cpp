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
	}
	catch (string err)
	{
		cout << "ERROR: " + err;
	}
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

/*ofstream& operator<<(ofstream& f, Tray& obj)
{
	f << obj.getType() << endl
		<< obj.length << endl
		<< obj.wigth << endl
		<< obj.people << endl
		<< obj.time << endl
		<< obj.speed << endl
		<< obj.arms << endl;
	return f;
}*/