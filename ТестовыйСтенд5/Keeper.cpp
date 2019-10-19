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
		<< "[2] Парусник" << endl
		<< "[3] Катер" << endl
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
	case 3:
		tmp[size] = new Boat;
		break;
	default:
		break;
	}
	size++;
	if(data)
		delete[] data;
	data = tmp;
	cout << "Элемент успешно добавлен" << endl;
	system("pause");
}

void Keeper::add(int _type, ifstream &fin)
{
	Ship** tmp = new Ship * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}
	switch (_type)
	{
	case 1:
		tmp[size] = new Tray(fin);
		break;
	case 2:
		tmp[size] = new Sail(fin);
		break;
	case 3:
		tmp[size] = new Boat(fin);
		break;
	default:
		break;
	}
	size++;
	if (data)
		delete[] data;
	data = tmp;
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
	ifstream fin("output.txt");
	int type = 0;
	/*if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";*/
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
			break;
		add(type, fin);
	}
	fin.close();
	system("pause");
}