#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Item {
private:
	int id;				// ������ ��ȣ
	const char* name;	// ������ �̸�
public:
	static int cnt;		// ������ �� ����
	Item(int id, const char* name) : id(id), name(name) { cnt++; }
	const char* getName() {
		return name;
	}

};
class User {
private:
	int month;
	int day;
	int s_day;		// ���� �ؾ� �ϴ� ����
	int survive;	// �� ���� ��¥
	int water;		// ���� ��ġ
	int food;		// ����� ��ġ
	int energy;		// ������ ��ġ

	Item* item[12];		// ������
	int position = 0;	// ���� �� ��ġ
	string map[16] = {
		"��ȭ", "���", "����", "����", "��ȭ",
		"���", "����", "����", "�Ȱ�", "����",
		"����", "����", "ö��", "����", "ī��",
		"����"
	};
	static int cnt;		// ���� �ǹ�??
public:
	User(int level) {
		item[0] = new Item(1, "����");
		item[1] = new Item(1, "����");
		food = 100 - ((level - 1) * 10);
		water = 100 - ((level - 1) * 10);
		energy = 100 - ((level - 1) * 10);
		s_day = 30;
		survive = 1;
		month = 2;
		day = 13;
	}
	bool play() {
		while (s_day > 0) {
			Phone();
			char check = tolower(_getch());
			system("cls");
			switch (check) {
			case 'b': Bag(); break;
			case 'm': Map(); break;
			case '1': NextDay(); break;
			case '2': Move(); break;
			}
			if (!DieCheck()) {
				break;
			}
			// ���� ����� �������� ���� ��� �Լ� ����
		}
		if (survive == day) return true;
		else false;
	}
	void Bag() {
		cout << "	      ____" << endl;
		cout << "	     / /����" << endl;
		cout << "____________/_/___����___________" << endl;
		cout << "|				|" << endl;
		cout << "|";
		for (int i = 0; i < 3; i++) {
			if (i < Item::cnt)
				cout << item[i]->getName() << "	   ";
			else
				cout << "	  ";
		}
		cout << "\t";
		cout << "|" << endl;
		cout << "|				|" << endl;
		cout << "|_______________________________|" << endl;
		cout << "|				|" << endl;
		cout << "|";
		for (int i = 3; i < 6; i++) {
			if (i < Item::cnt)
				cout << item[i]->getName() << "	   ";
			else
				cout << "	  ";
		}
		cout << "\t";
		cout << "|" << endl;
		cout << "|				|" << endl;
		cout << "|_______________________________|" << endl;
		cout << "|				|" << endl;
		cout << "|";
		for (int i = 6; i < 9; i++) {
			if (i < Item::cnt)
				cout << item[i]->getName() << "	   ";
			else
				cout << "	  ";
		}
		cout << "\t";
		cout << "|" << endl;
		cout << "|				|" << endl;
		cout << "|_______________________________|" << endl;
		cout << "|				|" << endl;
		cout << "|";
		for (int i = 9; i < 12; i++) {
			if (i < Item::cnt)
				cout << item[i]->getName() << "	   ";
			else
				cout << "	  ";
		}
		cout << "\t";
		cout << "|" << endl;
		cout << "|				|" << endl;
		cout << "|_______________________________|" << endl;
		_getch();
		system("cls");
	}
	void Map() {
		cout << "\n\n\n";
		cout << "   ------" << map[0] << "��-------" << map[1] << "��-------" << map[2] << "��-------" << map[3] << "��-------" << map[4] << "��-------" << map[5] << "��-----" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << " " << map[15] << "��										  " << map[6] << "��" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << " " << map[14] << "��										  " << map[7] << "��" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << "   ------" << map[13] << "��-------" << map[12] << "��-------" << map[11] << "��-------" << map[10] << "��-------" << map[9] << "��-------" << map[8] << "��-----" << endl;
		cout << "\n\n���� �� : " << map[position] << "��" << endl;
		_getch();
		system("cls");
	}
	void Phone() {
		cout << "	_________________________________" << endl;
		cout << "	|	   			|	1. ���ڱ�" << endl;
		cout << "	|-------------------------------|	2. �̵��ϱ�" << endl;
		cout << "	|	     20XX��  " << month << "�� " << day << "��	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________       ________ 	|" << endl;
		cout << "	|   |        |     |	    |	|" << endl;
		cout << "	|   |  ����  |     |  ����  |	|" << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  ����  ---------	|" << endl;
		cout << "	|      ����	       " << water << "	|" << endl;
		cout << "	|      �����          " << food << "	|" << endl;
		cout << "	|      ������          " << energy << "	|" << endl;
		cout << "	|   ________________________	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|" << endl;
		if (survive < 10) cout << "	|  | " << survive << "����,                  |	|" << endl;
		else if (survive < 100) cout << "	|  | " << survive << "����,                 |	|" << endl;
		cout << "	|  | ������ ���� �� ������.. |	|" << endl;
		cout << "	|  |_________________________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|-------------------------------|" << endl;
		cout << "	|	        ��		|" << endl;
		cout << "	|_______________________________|" << endl;
	}
	void NextDay() {
		survive++;
		day++;
		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31) {
				month++;
				day = 1;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (day > 30) {
				month++;
				day = 1;
			}
			break;
		default:
			if (day > 28) {
				month++;
				day = 1;
			}
		}
		// ���� ����� 10~20 ������ ����(rand�̿�)
		food -= (rand() % 19 + 1);
		water -= (rand() % 19 + 1);

		energy += 20;
		if (energy > 100) energy = 100;
	}
	void Move() {
		// �̵��ϱ⸦ ���� �� ������ ���� ����
		// ���� ����� 20~40 ������ ����(rand�̿�)
		// position ���� -> �� �̸��� �Է� �ް� -> for���� �̿��ؼ� �� ��ġ int ã�´�. -> ���� ���� ����� -> ���������� �̵�
		// ������ ���� �����ؼ� �ѹ� ���� ���ϵ��� �̿� �Ұ��� �ϰ� �����.
	}
	bool DieCheck() {
		bool answer = true;
		if (water <= 10 || food <= 10 || energy <= 10) {		// 90% Ȯ���� ���
			if ((rand() % 99 + 1) < 90) answer = false;
		}
		else if (water <= 20 || food <= 20 || energy <= 20) {	// 70% Ȯ���� ���
			if ((rand() % 99 + 1) < 70) answer = false;
		}
		else if (water <= 30 || food <= 30 || energy <= 30) {	// 65% Ȯ���� ���
			if ((rand() % 99 + 1) < 65) answer = false;
		}
		return answer;
	}
};