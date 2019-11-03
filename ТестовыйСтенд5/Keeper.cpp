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
	try
	{
		cout << "Выберите класс наследника: " << endl
			<< "[1] Лодка" << endl
			<< "[2] Парусник" << endl
			<< "[3] Катер" << endl
			<< "Ваш выбор: ";
		cin >> type;
		if (type > 3 || type < 1)
		{
			throw (string)"Выбран не правильный класс наследника";
		}
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
		if (tmp[size]->isError())
		{
			cout << "Элемент небыл добавлен из-за ошибки" << endl;
			system("pause");
			return;
		}
		size++;
		if (data)
			delete[] data;
		data = tmp;
		cout << "Элемент успешно добавлен" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
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
}

void Keeper::del()
{
	int index;
	if (!size)
	{
		cout << "[INFO] Контейнер пуст! Загрузите файлы из файла или добавьте новые элементы." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Подводная лодка" << endl;
				break;
			case 2:
				cout << "Парусник" << endl;
				break;
			case 3:
				cout << "Катер" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Выберите элемент для удаления: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Выбранного элемента не существует";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Элемент удален успешно" << endl;
			size--;
			system("pause");
			return;
		}
		Ship** tmp = new Ship * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "Элемент удален успешно" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	cout << "Элементы успешно сохранены в файл" << endl;
	system("pause");
}

void Keeper::load()
{
	ifstream fin("output.txt");
	if(fin.fail())
	{
		cout << "Файл пустой!" << endl;
		system("pause");
		return;
	}
	int type = 0;
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
		{
			break;
		}
		add(type, fin);
	}
	fin.close();
	cout << "Элементы успешно загружены из файла" << endl;
	system("pause");
}

ostream& operator<<(ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		cout << "[INFO] Контейнер пуст! Загрузите файлы из файла или добавьте новые элементы." << endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->print(out);
	}
	system("pause");
	return out;
}