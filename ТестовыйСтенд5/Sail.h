#pragma once
#include "Ship.h"
/*
��� ���������,
��������, ������ ��� �������, ����� �������, �������� �����������,
������
*/
class Sail : public Ship
{
	string name;
	string typeSail;
	int destination;
	int _long;
	int speed;
	int people;
public:
	Sail();
	~Sail();
	void save(ofstream& fout);
};