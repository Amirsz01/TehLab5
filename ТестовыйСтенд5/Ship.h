#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Ship
{
	int type;
public:
	void setType(int _type);
	int getType();
	virtual void save(ofstream& fout) = 0;
	virtual ~Ship() = 0;
};