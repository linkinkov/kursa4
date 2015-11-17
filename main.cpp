#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <windows.h>
#include <fstream>
#include <map>
#include <list>

using namespace std;

struct Znak
{
	string secondn;
	string name;
	string zodiac;
	size_t bday[3];
};

void AddNew(vector<Znak> & data);
void ShowAll(const vector<Znak> & data);
int GetZodiacNo(string zodiac);
void SortZodiac(vector<Znak> & data);
void ShowDate(const vector<Znak> & data);
void ExpDB(vector<Znak> & data);
void ImpDB(vector<Znak> & data);
void Edit(vector<Znak> & data);
void Remove(vector<Znak> & data);


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Znak> book;
	bool isExit = true;
	while (isExit) {
		char key;
		cout << "----------------------------\n" << "    Меню: \n" << "1 - Добавить новую запись\n" << "2 - Показать все записи\n" << "3 - Сортировка по зодиаку\n"
			<< "4 - Найти по Фамилии\n" << "5 - Экспорт Базы\n" << "6 - Импорт Базы\n" << "7 - Редактировать запись\n" << "8 - Удалить запись\n" << "0 - Выход\n" << "----------------------------\n";
		cin >> key;
		switch (key) {
		case '1':
			AddNew(book);
			break;
		case '2':
			ShowAll(book);
			break;
		case '3':
			SortZodiac(book);
			break;
		case '4':
			ShowDate(book);
			break;
		case '5':
			ExpDB(book);
			break;
		case '6':
			ImpDB(book);
			break;
		case '7':
			Edit(book);
			break;
		case '8':
			Remove(book);
			break;
		case '0':
			ExpDB(book);
			isExit = false;
			break;
		}

	}
	return 0;
}


void AddNew(vector<Znak> & data) {
	Znak tmp;
	cout << "Введите фамилию: ";
	cin >> tmp.secondn;
	cout << "Введите имя: ";
	cin >> tmp.name;
	cout << "Введите дату рождения через пробел: ";
	while (true) {
		cin >> tmp.bday[0];
		if (!cin) {
			cout << "Вы ввели не число, введите недостающие символы. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	while (true) {
		cin >> tmp.bday[1];
		if (!cin) {
			cout << "Вы ввели не число, введите недостающие символы. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	while (true) {
		cin >> tmp.bday[2];
		if (!cin) {
			cout << "Вы ввели не число, введите недостающие символы. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if ((tmp.bday[0] >= 21 && tmp.bday[1] == 3) || (tmp.bday[0] <= 19 && tmp.bday[1] == 4))
		tmp.zodiac = "Овен";
	else if ((tmp.bday[0] >= 20 && tmp.bday[1] == 4) || (tmp.bday[0] <= 20 && tmp.bday[1] == 5))
		tmp.zodiac = "Телец";
	else if ((tmp.bday[0] >= 21 && tmp.bday[1] == 5) || (tmp.bday[0] <= 20 && tmp.bday[1] == 6))
		tmp.zodiac = "Близнецы";
	else if ((tmp.bday[0] >= 21 && tmp.bday[1] == 6) || (tmp.bday[0] <= 22 && tmp.bday[1] == 7))
		tmp.zodiac = "Рак";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 7) || (tmp.bday[0] <= 22 && tmp.bday[1] == 8))
		tmp.zodiac = "Лев";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 8) || (tmp.bday[0] <= 22 && tmp.bday[1] == 9))
		tmp.zodiac = "Дева";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 9) || (tmp.bday[0] <= 22 && tmp.bday[1] == 10))
		tmp.zodiac = "Весы";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 10) || (tmp.bday[0] <= 21 && tmp.bday[1] == 11))
		tmp.zodiac = "Скорпион";
	else if ((tmp.bday[0] >= 22 && tmp.bday[1] == 11) || (tmp.bday[0] <= 21 && tmp.bday[1] == 12))
		tmp.zodiac = "Стрелец";
	else if ((tmp.bday[0] >= 22 && tmp.bday[1] == 12) || (tmp.bday[0] <= 19 && tmp.bday[1] == 1))
		tmp.zodiac = "Козерог";
	else if ((tmp.bday[0] >= 20 && tmp.bday[1] == 1) || (tmp.bday[0] <= 18 && tmp.bday[1] == 2))
		tmp.zodiac = "Водолей";
	else if ((tmp.bday[0] >= 19 && tmp.bday[1] == 2) || (tmp.bday[0] <= 20 && tmp.bday[1] == 3))
		tmp.zodiac = "Рыба";
	else
		tmp.zodiac = "Не верно заданно";

	data.push_back(tmp);
}

void ShowAll(const vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		for (size_t i = 0; i<data.size(); i++) {
			cout << "Фамилия: " << data.at(i).secondn << "\n";
			cout << "Имя: " << data.at(i).name << "\n";
			cout << "Зодиак: " << data.at(i).zodiac << "\n";
			cout << "День Рождения: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
				<< data.at(i).bday[2] << "\n\n";
		}
	}

}
/*
int GetZodiacNo(string zodiac) {
	if (zodiac == "Овен")
		return 1;
	else if (zodiac == "Телец")
		return 2;
	else if (zodiac == "Близнецы")
		return 3;
	else if (zodiac == "Рак")
		return 4;
	else if (zodiac == "Лев")
		return 5;
	else if (zodiac == "Дева")
		return 6;
	else if (zodiac == "Весы")
		return 7;
	else if (zodiac == "Скорпион")
		return 8;
	else if (zodiac == "Стрелец")
		return 9;
	else if (zodiac == "Козерог")
		return 10;
	else if (zodiac == "Водолей")
		return 11;
	else if (zodiac == "Рыба")
		return 12;
	return 1;
}
*/

int GetZodiacNo(string zodiac) {
	static const map<string, int>table = { 
		{ "Овен",1 },
		{ "Телец",2 },
		{ "Близнецы",3 },
		{ "Рак",4 },
		{ "Лев",5 },
		{ "Дева",6 },
		{ "Весы",7 },
		{ "Скорпион",8 },
		{ "Стрелец",9 },
		{ "Козерог",10 },
		{ "Водолей",11 },
		{ "Рыба",12 } };
	auto pos = table.find(zodiac);
	return pos == table.end() ? -1 : pos->second;
}

void SortZodiac(vector<Znak> & data) {
	Znak tmp;
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		for (size_t i = 0; i < data.size() - 1; ++i) {
			for (size_t j = 0; j < data.size() - 1; ++j) {
				if (GetZodiacNo(data.at(j + 1).zodiac) < GetZodiacNo(data.at(j).zodiac)) {
					tmp = data.at(j + 1);
					data.at(j + 1) = data.at(j);
					data.at(j) = tmp;
				}
			}
		}
		ShowAll(data);
	}
}

void ShowDate(const vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "Введите фамилию: ";
		cin >> sname;
		cout << "---- Результаты поиска -----\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "Фамилия: " << data.at(i).secondn << "\n";
				cout << "Имя: " << data.at(i).name << "\n";
				cout << "Зодиак: " << data.at(i).zodiac << "\n";
				cout << "День Рождения: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n\n";
				isFind = true;
			}
		}
		if (!isFind)
			cout << "Ничего не найдено :(\n";
	}
}


void ImpDB(vector<Znak> & data) {
	Znak tmp;
	ifstream fin("db.txt", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cout << "Баз данных не существует или не может быть открытой.\n";
	}
	else {
		while (true) {
			fin >> tmp.secondn >> tmp.name >> tmp.zodiac >> tmp.bday[0] >> tmp.bday[1] >> tmp.bday[2];
			if (fin.fail()) break;
			data.push_back(tmp);
		}
		fin.close();
		cout << "Импорт в базу данных осуществлен!\n";
	}
}

void ExpDB(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		Znak tmp;
		boolean exit = false;
		int key;
		cout << "Экспортирование выполнять:\n";
		cout << "1 - Записать в конец файла\n";
		cout << "2 - Записать с предварительной очисткой файла\n";
		cin >> key;

		if (key == 1) {
			ofstream fout("db.txt", ios_base::out | ios_base::app);
			if (!fout.is_open()) {
				cout << "Баз данных не существует или не может быть открытой.\n";
				exit = true;
			}

			else if (data.size() == 0) {
				cout << "Данные отсутсвуют!";
			}

			else {
				for (size_t i = 0; i < data.size(); i++)
				{
					fout << data.at(i).secondn << "\n";
					fout << data.at(i).name << "\n";
					fout << data.at(i).zodiac << "\n";
					fout << data.at(i).bday[0] << " " << data.at(i).bday[1] << " " << data.at(i).bday[2] << "\n";
				}
				fout.close();
				cout << "Запись успешно прошла!\n";
			}
		}
		else if (key == 2) {
			ofstream fout("db.txt", ios_base::out | ios_base::trunc);
			if (!fout.is_open()) {
				cout << "Баз данных не существует или не может быть открытой.\n";
				exit = true;
			}

			else if (data.size() == 0) {
				cout << "Данные отсутсвуют!";
			}

			else {
				for (size_t i = 0; i < data.size(); i++)
				{
					fout << data.at(i).secondn << "\n";
					fout << data.at(i).name << "\n";
					fout << data.at(i).zodiac << "\n";
					fout << data.at(i).bday[0] << " " << data.at(i).bday[1] << " " << data.at(i).bday[2] << "\n";
				}
				fout.close();
				cout << "Запись успешно прошла!\n";
			}
		}
	}


}

void Edit(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "Введите фамилию для редактирования: ";
		cin >> sname;
		cout << "--- Редактируем значения ---\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "Фамилия: " << data.at(i).secondn << "\n";
				cout << "Имя: " << data.at(i).name << "\n";
				cout << "Зодиак: " << data.at(i).zodiac << "\n";
				cout << "День Рождения: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n";
				cout << "----------------------------\n\n";
				cout << "Введите фамилию: ";
				cin >> data.at(i).secondn;
				cout << "Введите имя: ";
				cin >> data.at(i).name;
				cout << "Введите дату рождения: ";
				cin >> data.at(i).bday[0] >> data.at(i).bday[1] >> data.at(i).bday[2];
				//Проверка даты и изменение зодиака
				if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 3) || (data.at(i).bday[0] <= 19 && data.at(i).bday[1] == 4))
					data.at(i).zodiac = "Овен";
				else if ((data.at(i).bday[0] >= 20 && data.at(i).bday[1] == 4) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 5))
					data.at(i).zodiac = "Телец";
				else if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 5) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 6))
					data.at(i).zodiac = "Близнецы";
				else if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 6) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 7))
					data.at(i).zodiac = "Рак";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 7) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 8))
					data.at(i).zodiac = "Лев";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 8) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 9))
					data.at(i).zodiac = "Дева";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 9) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 10))
					data.at(i).zodiac = "Весы";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 10) || (data.at(i).bday[0] <= 21 && data.at(i).bday[1] == 11))
					data.at(i).zodiac = "Скорпион";
				else if ((data.at(i).bday[0] >= 22 && data.at(i).bday[1] == 11) || (data.at(i).bday[0] <= 21 && data.at(i).bday[1] == 12))
					data.at(i).zodiac = "Стрелец";
				else if ((data.at(i).bday[0] >= 22 && data.at(i).bday[1] == 12) || (data.at(i).bday[0] <= 19 && data.at(i).bday[1] == 1))
					data.at(i).zodiac = "Козерог";
				else if ((data.at(i).bday[0] >= 20 && data.at(i).bday[1] == 1) || (data.at(i).bday[0] <= 18 && data.at(i).bday[1] == 2))
					data.at(i).zodiac = "Водолей";
				else if ((data.at(i).bday[0] >= 19 && data.at(i).bday[1] == 2) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 3))
					data.at(i).zodiac = "Рыба";
				else
					data.at(i).zodiac = "Не верно заданно";

				isFind = true;
			}
		}
		if (!isFind)
			cout << "Ничего не найдено :(\n";
	}
}

void Remove(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "Данные отсутсвуют\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "Введите фамилию для удаления: ";
		cin >> sname;
		cout << "----- Найдена запись -------\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "Фамилия: " << data.at(i).secondn << "\n";
				cout << "Имя: " << data.at(i).name << "\n";
				cout << "Зодиак: " << data.at(i).zodiac << "\n";
				cout << "День Рождения: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n";
				cout << "----------------------------\n\n";
				int key;
				cout << "Удалить запись?\n";
				cout << "1 - Да\n";
				cout << "2 - Нет\n";
				cin >> key;

				if (key == 1) {
					data.erase(data.begin() + i);
					cout << "Удаление завершено!\n";
				}
				isFind = true;

			}
		}
		if (!isFind)
			cout << "Ничего не найдено :(\n";
	}
}