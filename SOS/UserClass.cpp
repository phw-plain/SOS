#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
using namespace std;

class Item {
private:
public:
	static int cnt;		// 아이템 총 갯수
	Item() {
		cnt++; 
	}
	virtual int getCnt() {
		return cnt;
	}
	// 순수 가상 함수 = 이름 출력
	virtual string getName() = 0;
};
class Water : public Item {
private:
	static int cnt;
public:
	Water() {
		cnt++;
	}
	int getCnt() {
		return cnt;
	}
	string getName() {
		return "생수";
	}
};
class Food : public Item {
private:
	static int cnt;
public:
	Food() {
		cnt++;
	}
	int getCnt() {
		return cnt;
	}
	string getName() {
		return "식량";
	}
};
class User {
private:
	int month;		// 월
	int day;		// 일
	int s_day;		// 생존 해야 하는 일자
	int survive;	// 총 생존 날짜
	int water;		// 수분 수치
	int food;		// 배고픔 수치
	int energy;		// 에너지 수치
	int money;		// 보유 돈
	bool message;	// 메세지 여부
	Item* item[12];		// 아이템
	

	int position = 0;	// 현재 역 위치
	string map[16] = {
		"국화", "장미", "난초", "동백", "매화",
		"모란", "벚꽃", "수련", "안개", "연꽃",
		"팬지", "백합", "철쭉", "수국", "카라",
		"박하"
	};
public:static bool bagpull[12];
	User(int level) {
		ItemAdd(1, 0);
		ItemAdd(1, 1);
		ItemAdd(2, 2);
		food = 100 - ((level - 1) * 10);
		water = 100 - ((level - 1) * 10);
		energy = 100 - ((level - 1) * 10);
		s_day = 30;							// 생존해야 하는 날짜
		survive = 1;						// 생존한 날짜
		month = 2;							// 월
		day = 13;							// 일
		money = 10000;						// 보유 돈
		message = true;
	}
	bool play() {
		while (s_day > 0) {
			PlaySound(TEXT("playbgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			Phone();
			char check = tolower(_getch());
			system("cls");
			PlaySound(NULL, 0, 0);
			switch (check) {
				case 'b': Bag(); break;
				case 'm': Map(); break;
				case '1': NextDay(); break;
				case '2': Move(); break;
				case '3': Message(); break;
			}
			if (!DieCheck()) {
				break;
			}
		}
		if (survive == day) return true;
		else return false;
	}
	void Bag() {
		string check[12] = { "--", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };
		int key = 0, k = 0;
		while (k != 13) {
			cout << "	      ____" << endl;
			cout << "	     / /＼＼" << endl;
			cout << "____________/_/___＼＼___________" << endl;
			cout << "|				|" << endl;
			// 아이템 이름 출력
			cout << "|";
			for (int i = 0; i < 3; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			// 아이템 선택 창
			cout << "|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[0] << "       " << check[1] << "       " << check[2];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "|_______________________________|" << endl;
			cout << "|				|" << endl;
			cout << "|";
			for (int i = 3; i < 6; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[3] << "       " << check[4] << "       " << check[5];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "|_______________________________|" << endl;
			cout << "|				|" << endl;
			cout << "|";
			for (int i = 6; i < 9; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[6] << "       " << check[7] << "       " << check[8];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "|_______________________________|" << endl;
			cout << "|				|" << endl;
			cout << "|";
			for (int i = 9; i < 12; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[9] << "       " << check[10] << "       " << check[11];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "|_______________________________|" << endl;
			do {
				k = _getch();
			} while (k != 13 && k != 75 && k != 77);
			if (key != 11 && k == 77) {
				check[key] = "  ";
				check[++key] = "--";
			}
			else if (key != 0 && k == 75) {
				check[key] = "  ";
				check[--key] = "--";
			}
			else if (k == 13) {
				ItemUse(key); 
				// 아이템 사용 미구현
				// 해당 칸에 아이템이 있는 경우 -> 이벤트 발생 o
				// 해당 칸에 아이템이 없는 경우 -> 이벤트 발생 x 다시 가방으로 ㄱㄱ
				// 이벤트는 [아이템이름]을 사용하시겠습니까?
				// (O or X) O : 000증가 , x는 다시 가방으로 ㄱㄱ
			}
			system("cls");
		}
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
		cout << "	_________________________________							_________________" << endl;
		cout << "	|	   			|							||　|∧,,∧	|" << endl;
		cout << "	|-------------------------------|							||＿|*－ω-)	|" << endl;
		cout << "	|	     20XX년  " << month << "월 " << day << "일	|							||  |ｏ♥ｏ	|" << endl;
		cout << "	|				|							||￣|━ J	|" << endl;
		cout << "	|    ________       ________ 	|							|_______________|" << endl;
		cout << "	|   |        |     |	    |	|"<< endl;
		cout << "	|   |  가방  |     |  지도  |	|							보유 돈 : " << money << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  상태  ---------	|";
		if (message)cout << "\t\t         ∧＿∧";
		cout << endl << "	|      수분	       " << water << "	|";
		if (message)cout << "\t\t         ('ω')";
		cout << endl << "	|      배고픔          " << food << "	|";
		if (message)cout << "\t\t   ┏━━━━ ∪━ ∪━━━━┓";
		cout << endl << "	|      에너지          " << energy << "	|";
		if (message)cout << "\t\t   ┃ ＼　　　　 ／ ┃";
		cout << endl << "	|   ________________________	|";
		if (message)cout << "\t\t   ┃　 ＼　♡ ／   ┃";
		cout << endl << "	|				|";
		if (message)cout << "\t\t   ┃　／ ＼＿／ ＼ ┃";
		cout << endl << "	|				|";
		if (message)cout << "\t\t   ┗━━━━━━━━━━━━━━━┛";
		cout << endl << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|";
		if (message)cout << "\t\t      메세지 도착!!";
		if (survive < 10) cout << endl << "	|  | " << survive << "일차,                  |	|" << endl;
		else if (survive < 100) cout << endl << "	|  | " << survive << "일차,                 |	|" << endl;
		cout << "	|  | 언제쯤 나갈 수 있을까.. |	|" << endl;
		cout << "	|  |_________________________|	|" << endl;
		cout << "	|				|							    [1] 취침 하기" << endl;
		cout << "	|				|							    [2] 이동 하기" << endl;
		cout << "	|-------------------------------|							    [3] 문자 읽기" << endl;
		cout << "	|	        ○		|							    [B] 가방 열기" << endl;
		cout << "	|_______________________________|							    [M] 지도 열기" << endl;
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
		// message 여부
		message = false;
		// 화면에 보여지는 그림
		cout << "\n\n\n\n\n\n";
		PlaySound(TEXT("sleep.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
		cout << "\t\t\t\t\t\t∩――――∩" << endl;
		cout << "\t\t\t\t\t\t|| ∧ ∧　||" << endl;
		cout << "\t\t\t\t\t\t||(*´ -`)//" << endl;
		cout << "\t\t\t\t\t\t| / ^ ⌒⌒づ`￣＼" << endl;
		cout << "\t\t\t\t\t\t   (ノ　　⌒  ＼ ＼" << endl;
		cout << "\t\t\t\t\t\t ＼　　 || ￣￣￣￣￣ ||" << endl;
		cout << "\t\t\t\t\t\t   ＼, /|| ――――― ||" << endl;
		cout << "\n\n\t\t\t\t\t\t     ";
		const char* a = "휴 식 중 . . .";
		textcolor(LIGHTMAGENTA, BLACK);
		for (int j = 0; j < strlen(a); j++) {
			Sleep(400);
			cout << a[j];
		}
		textcolor(WHITE, BLACK);
		Sleep(2000);
		PlaySound(NULL, 0, 0);
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "													휴식 완료!!" << endl;
		Sleep(2000);
		system("cls");
	}
	void Move() {
		// 이동하기를 누를 시 에너지 절반 감소
		// 수분 배고픔 20~40 사이의 감소(rand이용)
		// position 변경 -> 역 이름을 입력 받고 -> for문을 이용해서 역 위치 int 찾는다. -> 현재 역은 지운다 -> 다음역으로 이동
		// 변수를 새로 선언해서 한번 사용시 몇일동안 이용 불가능 하게 만든다.
		// 이동하기 사운드 넣으면 좋을 듯
		
		// 화면에 보여지는 그림
		cout << "\n\n\n\n\n\n";
		PlaySound(TEXT("subway.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
			Sleep(400);
			cout << a[j];
		}
		textcolor(WHITE, BLACK);
		Sleep(2000);
		PlaySound(NULL, 0, 0);
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "													이동 완료!!" << endl;
		Sleep(2000);
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
	void ItemAdd(int id, int k) {
		// 아이템을 생성해주는 메소드
		for (int i = 0; i < 12; i++) {
			cout << "check" << !bagpull[i] << endl;
			if (!bagpull[i]) {
				switch (id) {
				case 1: item[k] = new Water();
					break;
				case 2: item[k] = new Food();
					break;
				}
				bagpull[i] = true;
				break;
			}
			else {
				cout << "가방 공간이 부족합니다." << endl;
			}
		}
	}
	void ItemUse(int key) {
		// 아이템 사용 미구현
		// 해당 칸에 아이템이 있는 경우 -> 이벤트 발생 o
		// 해당 칸에 아이템이 없는 경우 -> 이벤트 발생 x 다시 가방으로 ㄱㄱ
		// 이벤트는 [아이템이름]을 사용하시겠습니까?
		// (O or X) O : 000증가 , x는 다시 가방으로 ㄱㄱ
	}
	void Message() {
		if (message) {
			cout << "메세지 출력 중 입니다." << endl;
		}
		else {
			cout << "메세지가 존재하지 않습니다." << endl;
		}
		system("pause");
		system("cls");
	}
};