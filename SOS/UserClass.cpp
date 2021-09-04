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
		"국화", "장미", "난초", "동백", "매화", 
		"모란", "벚꽃", "수련", "안개", "연꽃", 
		"팬지", "백합", "철쭉", "수국", "카라",
		"박하"
	};
	static int cnt;
public:
	User(int level) {
		item[0] = new Item(1, "생수");
		item[1] = new Item(1, "생수");
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
		cout << "	     / /＼＼" << endl;
		cout << "____________/_/___＼＼___________" << endl;
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
		cout << "   ------" << map[0] << "역-------" << map[1] << "역-------" << map[2] << "역-------" << map[3] << "역-------" << map[4] << "역-------" << map[5] << "역-----" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << " " << map[15] << "역										  " << map[6] << "역" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << " " << map[14] << "역										  " << map[7] << "역" << endl;
		cout << "   |										    |" << endl;
		cout << "   |										    |" << endl;
		cout << "   ------" << map[13] << "역-------" << map[12] << "역-------" << map[11] << "역-------" << map[10] << "역-------" << map[9] << "역-------" << map[8] << "역-----" << endl;
		cout << "\n\n현재 역 : " << map[position] << "역" << endl;
		_getch();
		system("cls");
	}
	void Phone() {
		cout << "	_________________________________" << endl;
		cout << "	|	   			|	1. 잠자기" << endl;
		cout << "	|-------------------------------|	2. 이동하기" << endl;
		cout << "	|	     20XX년  2월 13일	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________       ________ 	|" << endl;
		cout << "	|   |        |     |	    |	|" << endl;
		cout << "	|   |  가방  |     |  지도  |	|" << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  상태  ---------	|" << endl;
		cout << "	|      수분	       100	|" << endl;
		cout << "	|      배고픔          100	|" << endl;
		cout << "	|      에너지          100	|" << endl;
		cout << "	|   ________________________	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|" << endl;
		cout << "	|  | 1일차,                  |	|" << endl;
		cout << "	|  | 언제쯤 나갈 수 있을까.. |	|" << endl;
		cout << "	|  |_________________________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|-------------------------------|" << endl;
		cout << "	|	        ○		|" << endl;
		cout << "	|_______________________________|" << endl;
	}
};