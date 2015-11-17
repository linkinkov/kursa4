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
		cout << "----------------------------\n" << "    ����: \n" << "1 - �������� ����� ������\n" << "2 - �������� ��� ������\n" << "3 - ���������� �� �������\n"
			<< "4 - ����� �� �������\n" << "5 - ������� ����\n" << "6 - ������ ����\n" << "7 - ������������� ������\n" << "8 - ������� ������\n" << "0 - �����\n" << "----------------------------\n";
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
	cout << "������� �������: ";
	cin >> tmp.secondn;
	cout << "������� ���: ";
	cin >> tmp.name;
	cout << "������� ���� �������� ����� ������: ";
	while (true) {
		cin >> tmp.bday[0];
		if (!cin) {
			cout << "�� ����� �� �����, ������� ����������� �������. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	while (true) {
		cin >> tmp.bday[1];
		if (!cin) {
			cout << "�� ����� �� �����, ������� ����������� �������. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	while (true) {
		cin >> tmp.bday[2];
		if (!cin) {
			cout << "�� ����� �� �����, ������� ����������� �������. \n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if ((tmp.bday[0] >= 21 && tmp.bday[1] == 3) || (tmp.bday[0] <= 19 && tmp.bday[1] == 4))
		tmp.zodiac = "����";
	else if ((tmp.bday[0] >= 20 && tmp.bday[1] == 4) || (tmp.bday[0] <= 20 && tmp.bday[1] == 5))
		tmp.zodiac = "�����";
	else if ((tmp.bday[0] >= 21 && tmp.bday[1] == 5) || (tmp.bday[0] <= 20 && tmp.bday[1] == 6))
		tmp.zodiac = "��������";
	else if ((tmp.bday[0] >= 21 && tmp.bday[1] == 6) || (tmp.bday[0] <= 22 && tmp.bday[1] == 7))
		tmp.zodiac = "���";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 7) || (tmp.bday[0] <= 22 && tmp.bday[1] == 8))
		tmp.zodiac = "���";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 8) || (tmp.bday[0] <= 22 && tmp.bday[1] == 9))
		tmp.zodiac = "����";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 9) || (tmp.bday[0] <= 22 && tmp.bday[1] == 10))
		tmp.zodiac = "����";
	else if ((tmp.bday[0] >= 23 && tmp.bday[1] == 10) || (tmp.bday[0] <= 21 && tmp.bday[1] == 11))
		tmp.zodiac = "��������";
	else if ((tmp.bday[0] >= 22 && tmp.bday[1] == 11) || (tmp.bday[0] <= 21 && tmp.bday[1] == 12))
		tmp.zodiac = "�������";
	else if ((tmp.bday[0] >= 22 && tmp.bday[1] == 12) || (tmp.bday[0] <= 19 && tmp.bday[1] == 1))
		tmp.zodiac = "�������";
	else if ((tmp.bday[0] >= 20 && tmp.bday[1] == 1) || (tmp.bday[0] <= 18 && tmp.bday[1] == 2))
		tmp.zodiac = "�������";
	else if ((tmp.bday[0] >= 19 && tmp.bday[1] == 2) || (tmp.bday[0] <= 20 && tmp.bday[1] == 3))
		tmp.zodiac = "����";
	else
		tmp.zodiac = "�� ����� �������";

	data.push_back(tmp);
}

void ShowAll(const vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "������ ����������\n";
	}
	else {
		for (size_t i = 0; i<data.size(); i++) {
			cout << "�������: " << data.at(i).secondn << "\n";
			cout << "���: " << data.at(i).name << "\n";
			cout << "������: " << data.at(i).zodiac << "\n";
			cout << "���� ��������: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
				<< data.at(i).bday[2] << "\n\n";
		}
	}

}
/*
int GetZodiacNo(string zodiac) {
	if (zodiac == "����")
		return 1;
	else if (zodiac == "�����")
		return 2;
	else if (zodiac == "��������")
		return 3;
	else if (zodiac == "���")
		return 4;
	else if (zodiac == "���")
		return 5;
	else if (zodiac == "����")
		return 6;
	else if (zodiac == "����")
		return 7;
	else if (zodiac == "��������")
		return 8;
	else if (zodiac == "�������")
		return 9;
	else if (zodiac == "�������")
		return 10;
	else if (zodiac == "�������")
		return 11;
	else if (zodiac == "����")
		return 12;
	return 1;
}
*/

int GetZodiacNo(string zodiac) {
	static const map<string, int>table = { 
		{ "����",1 },
		{ "�����",2 },
		{ "��������",3 },
		{ "���",4 },
		{ "���",5 },
		{ "����",6 },
		{ "����",7 },
		{ "��������",8 },
		{ "�������",9 },
		{ "�������",10 },
		{ "�������",11 },
		{ "����",12 } };
	auto pos = table.find(zodiac);
	return pos == table.end() ? -1 : pos->second;
}

void SortZodiac(vector<Znak> & data) {
	Znak tmp;
	if (data.size() == 0) {
		cout << "������ ����������\n";
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
		cout << "������ ����������\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "������� �������: ";
		cin >> sname;
		cout << "---- ���������� ������ -----\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "�������: " << data.at(i).secondn << "\n";
				cout << "���: " << data.at(i).name << "\n";
				cout << "������: " << data.at(i).zodiac << "\n";
				cout << "���� ��������: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n\n";
				isFind = true;
			}
		}
		if (!isFind)
			cout << "������ �� ������� :(\n";
	}
}


void ImpDB(vector<Znak> & data) {
	Znak tmp;
	ifstream fin("db.txt", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cout << "��� ������ �� ���������� ��� �� ����� ���� ��������.\n";
	}
	else {
		while (true) {
			fin >> tmp.secondn >> tmp.name >> tmp.zodiac >> tmp.bday[0] >> tmp.bday[1] >> tmp.bday[2];
			if (fin.fail()) break;
			data.push_back(tmp);
		}
		fin.close();
		cout << "������ � ���� ������ �����������!\n";
	}
}

void ExpDB(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "������ ����������\n";
	}
	else {
		Znak tmp;
		boolean exit = false;
		int key;
		cout << "��������������� ���������:\n";
		cout << "1 - �������� � ����� �����\n";
		cout << "2 - �������� � ��������������� �������� �����\n";
		cin >> key;

		if (key == 1) {
			ofstream fout("db.txt", ios_base::out | ios_base::app);
			if (!fout.is_open()) {
				cout << "��� ������ �� ���������� ��� �� ����� ���� ��������.\n";
				exit = true;
			}

			else if (data.size() == 0) {
				cout << "������ ����������!";
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
				cout << "������ ������� ������!\n";
			}
		}
		else if (key == 2) {
			ofstream fout("db.txt", ios_base::out | ios_base::trunc);
			if (!fout.is_open()) {
				cout << "��� ������ �� ���������� ��� �� ����� ���� ��������.\n";
				exit = true;
			}

			else if (data.size() == 0) {
				cout << "������ ����������!";
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
				cout << "������ ������� ������!\n";
			}
		}
	}


}

void Edit(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "������ ����������\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "������� ������� ��� ��������������: ";
		cin >> sname;
		cout << "--- ����������� �������� ---\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "�������: " << data.at(i).secondn << "\n";
				cout << "���: " << data.at(i).name << "\n";
				cout << "������: " << data.at(i).zodiac << "\n";
				cout << "���� ��������: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n";
				cout << "----------------------------\n\n";
				cout << "������� �������: ";
				cin >> data.at(i).secondn;
				cout << "������� ���: ";
				cin >> data.at(i).name;
				cout << "������� ���� ��������: ";
				cin >> data.at(i).bday[0] >> data.at(i).bday[1] >> data.at(i).bday[2];
				//�������� ���� � ��������� �������
				if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 3) || (data.at(i).bday[0] <= 19 && data.at(i).bday[1] == 4))
					data.at(i).zodiac = "����";
				else if ((data.at(i).bday[0] >= 20 && data.at(i).bday[1] == 4) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 5))
					data.at(i).zodiac = "�����";
				else if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 5) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 6))
					data.at(i).zodiac = "��������";
				else if ((data.at(i).bday[0] >= 21 && data.at(i).bday[1] == 6) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 7))
					data.at(i).zodiac = "���";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 7) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 8))
					data.at(i).zodiac = "���";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 8) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 9))
					data.at(i).zodiac = "����";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 9) || (data.at(i).bday[0] <= 22 && data.at(i).bday[1] == 10))
					data.at(i).zodiac = "����";
				else if ((data.at(i).bday[0] >= 23 && data.at(i).bday[1] == 10) || (data.at(i).bday[0] <= 21 && data.at(i).bday[1] == 11))
					data.at(i).zodiac = "��������";
				else if ((data.at(i).bday[0] >= 22 && data.at(i).bday[1] == 11) || (data.at(i).bday[0] <= 21 && data.at(i).bday[1] == 12))
					data.at(i).zodiac = "�������";
				else if ((data.at(i).bday[0] >= 22 && data.at(i).bday[1] == 12) || (data.at(i).bday[0] <= 19 && data.at(i).bday[1] == 1))
					data.at(i).zodiac = "�������";
				else if ((data.at(i).bday[0] >= 20 && data.at(i).bday[1] == 1) || (data.at(i).bday[0] <= 18 && data.at(i).bday[1] == 2))
					data.at(i).zodiac = "�������";
				else if ((data.at(i).bday[0] >= 19 && data.at(i).bday[1] == 2) || (data.at(i).bday[0] <= 20 && data.at(i).bday[1] == 3))
					data.at(i).zodiac = "����";
				else
					data.at(i).zodiac = "�� ����� �������";

				isFind = true;
			}
		}
		if (!isFind)
			cout << "������ �� ������� :(\n";
	}
}

void Remove(vector<Znak> & data) {
	if (data.size() == 0) {
		cout << "������ ����������\n";
	}
	else {
		string sname;
		bool isFind = false;
		cout << "������� ������� ��� ��������: ";
		cin >> sname;
		cout << "----- ������� ������ -------\n";
		for (size_t i = 0; i<data.size(); i++) {
			if (data.at(i).secondn == sname) {
				cout << "�������: " << data.at(i).secondn << "\n";
				cout << "���: " << data.at(i).name << "\n";
				cout << "������: " << data.at(i).zodiac << "\n";
				cout << "���� ��������: " << data.at(i).bday[0] << "." << data.at(i).bday[1] << "."
					<< data.at(i).bday[2] << "\n";
				cout << "----------------------------\n\n";
				int key;
				cout << "������� ������?\n";
				cout << "1 - ��\n";
				cout << "2 - ���\n";
				cin >> key;

				if (key == 1) {
					data.erase(data.begin() + i);
					cout << "�������� ���������!\n";
				}
				isFind = true;

			}
		}
		if (!isFind)
			cout << "������ �� ������� :(\n";
	}
}