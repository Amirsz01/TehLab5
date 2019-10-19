#include "Tray.h"

Tray::Tray()
{
	cout << "----------------------------------\n   ���������� ��������� �����\n----------------------------------" << endl << endl;
	try
	{
		setType(1);
		cout << "������� ����� ����� = ";
		cin >> this->length;
		if (!this->length || this->length < 0)
		{
			throw (string)"����� ����� ����� ���� ��� ������������";
		}
		cout << "������� ������ ����� = ";
		cin >> this->wigth;
		if (!this->wigth || this->wigth < 0)
		{
			throw (string)"������ ����� ����� ���� ��� ������������";
		}
		cout << "������� ���������� ������� = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"���������� ������� �� ����� ���� �������������";
		}
		cout << "������� ���������� ������� ������������ ��� ����� = ";
		cin >> this->time;
		cout << "������� �������� ����� = ";
		cin >> this->speed;
		cout << "������� ���������� ����� : ";
		cin >> this->arms;
	}
	catch (string err)
	{
		cout << "ERROR: " + err;
	}
}

Tray::~Tray()
{
	cout << "��� ������ ���������� ������ Tray" << endl;
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