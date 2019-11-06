#pragma once
#include "Ship.h"

class Tray : public Ship
{
	int length;
	int wigth;
	int people;
	int time;
	int speed;
	string arms;
public:
	Tray();
	Tray(ifstream &fin);
	~Tray();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};