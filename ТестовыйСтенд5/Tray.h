#pragma once
#include "Ship.h"

class Tray : public Ship
{
	int length;
	int wigth;
	int people;
	unsigned int time;
	unsigned int speed;
	string arms;
public:
	Tray();
	~Tray();
	void save(ofstream& fout);
};