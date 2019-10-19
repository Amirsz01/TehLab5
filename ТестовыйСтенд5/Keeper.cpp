#include "Keeper.h"

Keeper::Keeper()
{
	this->data = nullptr;
	this->size = 0;
}

Keeper::~Keeper()
{
	delete[] data;
}

int Keeper::getSize()
{
	return size;
}

void Keeper::add()
{
	int type; // Тип наследника
	cout << "Выберите класс наследника: " << endl
		<< "[1] Лодка" << endl
		<< "Ваш выбор: ";
	cin >> type;
	Ship** tmp = new Ship * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}
	switch (type)
	{
	case 1:
		tmp[size] = new Tray;
		break;
	case 2:
		tmp[size] = new Sail;
		break;
	default:
		break;
	}
	size++;
	if(data)
		delete[] data;
	data = tmp;
	cout << "Элемент успешно добавлен";
	system("pause");
}

void Keeper::del()
{
}

void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
}

void Keeper::load()
{
}