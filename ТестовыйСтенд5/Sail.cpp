#include "Sail.h"

Sail::Sail()
{
	cout << "----------------------------------\n     ���������� ���������     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);
		cout << "������� �������� ��������� = ";
		cin >> this->name;
		cout << "������� ��� ��������� = ";
		cin >> this->typeSail;
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
		cout << "������� ����� ��������� = ";
		cin >> this->_long;
		if (this->_long < 0)
		{
			throw (string)"����� �� ����� ���� ������������";
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
	cout << "��� ������ ���������� ������ Sail" << endl;
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