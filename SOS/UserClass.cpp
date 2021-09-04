#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Item {
private:
	int id;
	const char* name;
public:
	static int cnt;
	Item(int id, const char* name) : id(id), name(name) { cnt++; }
	const char* getName() {
		return name;
	}
	int getCnt() {
		return cnt;
	}
	
};
class User {
private:
	int day;
	int food;
	int water;
	int energy;
	Item* item[12];
	int position = 0;
	string map[16] = {
		"��ȭ", "���", "����", "����", "��ȭ", 
		"���", "����", "����", "�Ȱ�", "����", 
		"����", "����", "ö��", "����", "ī��",
		"����"
	};
	static int cnt;
public:
	User(int level) {
		item[0] = new Item(1, "����");
		item[1] = new Item(1, "����");
		food = 100 - ((level - 1) * 10);
		water = 100 - ((level - 1) * 10);
		energy = 100 - ((level - 1) * 10);
		day = 30;
	}
	void play() {
		while (day > 0) {
			Phone();
			char check = tolower(_getch());
			system("cls");
			switch (check) {
			case 'b': Bag(); break;
			case 'm': Map(); break;
			}
		}
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
		cout << "	|	     20XX��  2�� 13��	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________       ________ 	|" << endl;
		cout << "	|   |        |     |	    |	|" << endl;
		cout << "	|   |  ����  |     |  ����  |	|" << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  ����  ---------	|" << endl;
		cout << "	|      ����	       100	|" << endl;
		cout << "	|      �����          100	|" << endl;
		cout << "	|      ������          100	|" << endl;
		cout << "	|   ________________________	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|" << endl;
		cout << "	|  | 1����,                  |	|" << endl;
		cout << "	|  | ������ ���� �� ������.. |	|" << endl;
		cout << "	|  |_________________________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|-------------------------------|" << endl;
		cout << "	|	        ��		|" << endl;
		cout << "	|_______________________________|" << endl;
	}
};