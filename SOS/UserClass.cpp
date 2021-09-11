#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
using namespace std;

class Item {
private:
	int id;				// 아이템 번호
	const char* name;	// 아이템 이름
public:
	static int cnt;		// 아이템 총 갯수
	Item(int id, const char* name) : id(id), name(name) { cnt++; }
	const char* getName() {
		return name;
	}

};
class User {
private:
	int month;
	int day;
	int s_day;		// 생존 해야 하는 일자
	int survive;	// 총 생존 날짜
	int water;		// 수분 수치
	int food;		// 배고픔 수치
	int energy;		// 에너지 수치

	Item* item[12];		// 아이템
	int position = 0;	// 현재 역 위치
	string map[16] = {
		"국화", "장미", "난초", "동백", "매화",
		"모란", "벚꽃", "수련", "안개", "연꽃",
		"팬지", "백합", "철쭉", "수국", "카라",
		"박하"
	};
	static int cnt;		// 무슨 의미??
public:
	User(int level) {
		item[0] = new Item(1, "생수");
		item[1] = new Item(1, "생수");
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
			// 수분 배고픔 에너지에 따른 사망 함수 구현
		}
		if (survive == day) return true;
		else false;
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
		cout << "	|	   			|" << endl;
		cout << "	|-------------------------------|" << endl;
		cout << "	|	     20XX년  " << month << "월 " << day << "일	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|    ________       ________ 	|" << endl;
		cout << "	|   |        |     |	    |	|" << endl;
		cout << "	|   |  가방  |     |  지도  |	|" << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  상태  ---------	|" << endl;
		cout << "	|      수분	       " << water << "	|" << endl;
		cout << "	|      배고픔          " << food << "	|" << endl;
		cout << "	|      에너지          " << energy << "	|" << endl;
		cout << "	|   ________________________	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|" << endl;
		if (survive < 10) cout << "	|  | " << survive << "일차,                  |	|" << endl;
		else if (survive < 100) cout << "	|  | " << survive << "일차,                 |	|" << endl;
		cout << "	|  | 언제쯤 나갈 수 있을까.. |	|" << endl;
		cout << "	|  |_________________________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|								[1] 취침 하기" << endl;
		cout << "	|-------------------------------|								[2] 이동 하기" << endl;
		cout << "	|	        ○		|								[B] 가방 열기" << endl;
		cout << "	|_______________________________|								[M] 지도 열기" << endl;
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
		// 수분 배고픔 10~20 사이의 감소(rand이용)
		food -= (rand() % 19 + 1);
		water -= (rand() % 19 + 1);

		energy += 20;
		if (energy > 100) energy = 100;
	}
	void Move() {
		// 이동하기를 누를 시 에너지 절반 감소
		// 수분 배고픔 20~40 사이의 감소(rand이용)
		// position 변경 -> 역 이름을 입력 받고 -> for문을 이용해서 역 위치 int 찾는다. -> 현재 역은 지운다 -> 다음역으로 이동
		// 변수를 새로 선언해서 한번 사용시 몇일동안 이용 불가능 하게 만든다.
		// 이동하기 사운드 넣으면 좋을 듯
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t         Ｏ" << endl;
		cout << "\t\t\t\t\t\t       ｏ" << endl;
		cout << "\t\t\t\t\t\t      °" << endl;
		cout << "\t\t\t\t\t\t     ┳┳ ∩∩" << endl;
		cout << "\t\t\t\t\t\t     ┃┃(-∀-)" << endl;
		cout << "\t\t\t\t\t\t    ┏┻┻┷━ Ｏ┏━┷┓┏━┷┓" << endl;
		cout << "\t\t\t\t\t\t    ┃ 　　 ┠┨  ┠┨  ┃" << endl;
		cout << "\t\t\t\t\t\t    ┃ 　　 ┠┨  ┠┨  ┃" << endl;
		cout << "\t\t\t\t\t\t    ┗◎━━◎┛┗◎┛┗◎┛" << endl;
		cout << "\n\n\t\t\t\t\t\t     ";
		const char* a = "이 동 중 . . .";
		textcolor(LIGHTMAGENTA, BLACK);
		for (int j = 0; j < strlen(a); j++) {
			Sleep(500);
			cout << a[j];
		}
		textcolor(WHITE, BLACK);
		Sleep(3000);
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "													이동 완료!!" << endl;
		Sleep(3000);
		system("cls");
	}
	bool DieCheck() {
		bool answer = true;
		if (water <= 10 || food <= 10 || energy <= 10) {		// 90% 확률로 사망
			if ((rand() % 99 + 1) < 90) answer = false;
		}
		else if (water <= 20 || food <= 20 || energy <= 20) {	// 70% 확률로 사망
			if ((rand() % 99 + 1) < 70) answer = false;
		}
		else if (water <= 30 || food <= 30 || energy <= 30) {	// 65% 확률로 사망
			if ((rand() % 99 + 1) < 65) answer = false;
		}
		return answer;
	}
};