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
		cout << "   ------&&역-------&&역-------&&역-------&&역-------&&역-------&&역-----" << endl;
		cout << "   |									|" << endl;
		cout << "   |									|" << endl;
		cout << "  &&역						                       &&역" << endl;
		cout << "   |									|" << endl;
		cout << "   |									|" << endl;
		cout << "  &&역						                       &&역" << endl;
		cout << "   |									|" << endl;
		cout << "   |									|" << endl;
		cout << "   ------&&역-------&&역-------&&역-------&&역-------&&역-------&&역-----" << endl;
		cout << "\n\n현재 역 : " << "&&역" << endl;
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