#pragma once
#include "Ship.h"
/*
Для катера определено: назначение, материал корпуса, ходовые
качества, скорость и количество людей, которые могут находится на борту
*/
class Boat : public Ship
{
	int destination;
	string material;
	int speed;
	int people;
	string _class; // Ходовые качества
public:
	Boat();
	Boat(ifstream &fin);
	~Boat();
	void save(ofstream& fout);
};
