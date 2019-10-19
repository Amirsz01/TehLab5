#include "Boat.h"

Boat::Boat()
{
	cout << "----------------------------------\n     ���������� ������     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);
		cout << "������� ��������� ������� ������ = ";
		cin >> this->material;
		cout << "������� ������� �������� = ";
		cin >> this->_class;
		cout << "������� ���������� ������� = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"���������� ������� �� ����� ���� �������������";
		}
		cout << "[1]������ ��� [2]������� = ";
		cin >> this->destination;
		if (this->destination < 1 || this->destination > 2)
		{
			throw (string)"�������� ���������� ���������";
		}
		cout << "������� �������� ��������� = ";
		cin >> this->speed;
		if (this->speed < 0)
		{
			throw (string)"�������� �� ����� ���� ������������";
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
	cout << "��� ������ ���������� ������ Boat" << endl;
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