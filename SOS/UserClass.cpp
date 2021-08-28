#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class User {
private:
	int day;
	int food;
	int water;
	int energy;
	int rice;
	int bottle;
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
		food = 100 - ((level - 1) * 10);
		water = 100 - ((level - 1) * 10);
		energy = 100 - ((level - 1) * 10);
		rice = level;
		bottle = level;
		switch (level) {
		case 1: day = 30; break;
		case 2: day = 50; break;
		case 3: day = 100; break;
		}
	}
	void play() {
		while (day > 0) {
			Phone();
			char check = tolower(_getch());
			system("cls");
			switch (check) {
			case 'i': Bag(); break;
			case 'o': Info(); break;
			case 'p': Map(); break;
			}
		}
	}
	void Bag() {

	}
	void Info() {

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
		cout << "	|	   			|" << endl;
		cout << "	|-------------------------------|" << endl;
		cout << "	|	     20XX년  2월 13일	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________       ________ 	|" << endl;
		cout << "	|   |        |     |	    |	|" << endl;
		cout << "	|   |  가방  |     |  지도  |	|" << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________			|" << endl;
		cout << "	|   |        |			|" << endl;
		cout << "	|   |  상태  |			|" << endl;
		cout << "	|   |________|			|" << endl;
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
		cout << endl << "	1. 잠자기" << endl;
		cout << "	2. 이동하기" << endl;
	}
};