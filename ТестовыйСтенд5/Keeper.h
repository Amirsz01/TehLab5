#pragma once
#include "Tray.h"
#include "Sail.h"
#include "Boat.h"
#include <fstream>
/*
Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Base (базовый
класс определяется согласно варианту задания);
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла
*/
class Keeper
{
	Ship** data;
	int size;
public:
	Keeper();
	~Keeper();
	int getSize();
	void add();
	void add(int _type, ifstream& fin);
	void del();
	void save();
	void load();
};