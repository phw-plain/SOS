#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
using namespace std;

class Item {
private:
	int id = 0;
public:
	static int cnt;		// 아이템 총 갯수
	Item() {
		cnt++; 
	}
	virtual int getId() {
		return id;
	}
	virtual int getCnt() {
		return cnt;
	}
	// 순수 가상 함수 = 이름 출력
	virtual string getName() = 0;
};
class Water : public Item {
private:
	int id = 1;
	static int cnt;
public:
	Water() {
		cnt++;
	}
	int getId() {
		return id;
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
	int id = 2;
	static int cnt;
public:
	Food() {
		cnt++;
	}
	int getId() {
		return id;
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
	Item* item[12];		// 아이템
	
	int limit;
	int position;	// 현재 역 위치
	string map[16] = {
		"국화역", "장미역", "난초역", "동백역", "매화역",
		"모란역", "벚꽃역", "수련역", "안개역", "연꽃역",
		"팬지역", "백합역", "철쭉역", "수국역", "카라역",
		"박하역"
	};

	bool message;	// 메세지 여부
	int m_key;
	string messages[4] = {
		"SOS 게임에 오신 것을 환영합니다.\n기본적으로 지급되는 생수와 식량 외에 더 많은 것을 얻고 싶다면 다른 곳으로 움직여야 할 것 입니다.\n당신이 죽음에 도달한다면 알려드리도록 하겠습니다.\n"
		, "수분이 부족하여 위험 상태 입니다.\n빨리 생수를 섭취하지 않는다면 죽을 수도 있겠습니다."
		, "배고픔이 부족하여 위험 상태 입니다.\n빨리 식량을 섭취하지 않는다면 죽을 수도 있겠습니다."
		, "에너지가 부족하여 위험 상태 입니다.\n빨리 취침하지 않는다면 죽을 수도 있겠습니다."
	};
public:static bool bagpull[12];
	//User(int level) {
	User() {
		ItemAdd(1, 0);
		ItemAdd(1, 1);
		ItemAdd(2, 2);
		food = 100;
		water = 100;
		energy = 100;
		s_day = 30;							// 생존해야 하는 날짜
		survive = 1;						// 생존한 날짜
		month = 2;							// 월
		day = 13;							// 일
		money = 10000;						// 보유 돈
		message = true;
		m_key = 0;
		limit = 0;
		position = 0;
	}
	bool play() {
		while (s_day > 0) {
			if(survive == 1) 
			PlaySound(TEXT("playbgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			char check = Phone();
			system("cls");
			PlaySound(NULL, 0, 0);
			switch (check) {
				case 'q': Bag(); break;
				case 'w': Map(); break;
				case '1': NextDay(); break;
				case '2': Message(m_key); break;
			}
			addMessage();
			if (!DieCheck()) {
				break;
			}
		}
		if (survive == day) return false;
		else return true;
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
				if (bagpull[key])
					ItemUse(key);
			}
			system("cls");
		}
	}
	void Map() {
		string m; 
		bool key[16] = { false }; 
		key[position] = true;
		int k = 0;
		while (k != 13) {
			cout << "\n\n\n";
			cout << "   ------";
			if (key[0]) textcolor(MAGENTA, BLACK);
			cout << map[0];
			textcolor(WHITE, BLACK);
			for (int i = 1; i < 6; i++) {
				cout << "-------";
				if (key[i]) textcolor(MAGENTA, BLACK);
				cout << map[i];
				textcolor(WHITE, BLACK);
			}
			cout << "-----" << endl;
			cout << "   |										    |" << endl;
			cout << "   |										    |" << endl;
			if (key[15]) textcolor(MAGENTA, BLACK);
			cout << map[15] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[6]) textcolor(MAGENTA, BLACK);
			cout << map[6] << "" << endl;
			textcolor(WHITE, BLACK);
			cout << "   |										    |" << endl;
			cout << "   |										    |" << endl;
			if (key[14]) textcolor(MAGENTA, BLACK);
			cout << map[14] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[7]) textcolor(MAGENTA, BLACK);
			cout << map[7] << endl;
			textcolor(WHITE, BLACK);
			cout << "   |										    |" << endl;
			cout << "   |										    |" << endl;
			cout << "   ------";
			if (key[13]) textcolor(MAGENTA, BLACK);
			cout << map[13];
			textcolor(WHITE, BLACK);
			for (int i = 12; i > 7; i--) {
				cout << "-------";
				if (key[i]) textcolor(MAGENTA, BLACK);
				cout << map[i];
				textcolor(WHITE, BLACK);
			}
			cout << "-----" << endl;
			cout << "\n\n현재 역 : " << map[position] << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n";
			cout << "												Enter : 선택" << endl;
			cout << "												←,→ : 이동" << endl;
			cout << "												    X : 종료" << endl;
			// 75 left 77 right
			do {
				k = toupper(_getch());
			} while (k != 13 && k != 75 && k != 77 && k != 88);
			if (k == 77 || k == 75) {
				for (int i = 0; i < 16; i++) {
					if (key[i]) {
						key[i] = false;
						if (i == 15 && k == 77)
							key[0] = true;
						else if (i == 0 && k == 75)
							key[15] = true;
						else if(k == 77)
							key[i + 1] = true;
						else
							key[i - 1] = true;
						break;
					}
				}
			}
			else if (k == 88) {
				break;
			}
			system("cls");
		}
		system("cls");
		if (k != 88) {
			for (int i = 0; i < 16; i++) {
				if (key[i])
					k = i;
			}
			Move(map[k], k);
		}
	}
	char Phone() {
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
		cout << "	|				|" << endl;
		cout << "	|				|							    [1] 취침 하기" << endl;
		cout << "	|-------------------------------|							    [2] 문자 읽기" << endl;
		cout << "	|	        ○		|							    [Q] 가방 열기" << endl;
		cout << "	|_______________________________|							    [W] 지도 열기" << endl;
		char check;
		do {
			check = tolower(_getch());
		} while (check != '1' && check != '2' && check != 'w' && check != 'q');
		return check;
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
		food -= (rand() % 11 + 10);
		water -= (rand() % 11 + 10);
		energy += 20;
		// 에너지 증가
		if (energy > 100) energy = 100;
		// 이동 제한 하루 씩 감소
		if (limit != 0) limit--;
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
		Sleep(1000);
		PlaySound(NULL, 0, 0);
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "													휴식 완료!!" << endl;
		Sleep(1000);
		system("cls");
	}
	void Move(string map, int k) {
		if(limit == 0){
			int yn;
			cout << map << " 으로 이동하시겠습니까?" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "												Y : 시작" << endl;
			cout << "												N : 취소" << endl;
			// 이동 yn 구현 필요 
			do {
				yn = tolower(_getch());
			} while (yn != 121 && yn != 110);
			system("cls");
			if (yn == 121) {
				position = k;
				// 몇일동안 이용 불가능
				limit = 5;
				// 하루 지남
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
				// 이동하기를 누를 시 에너지 절반 감소
				// 수분 배고픔 20~40 감소, 에너지 30~40 감소(rand이용) 
				food -= (rand() % 21 + 20);
				water -= (rand() % 21 + 20);
				energy -= (rand() % 11 + 30);
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
				Sleep(1000);
				PlaySound(NULL, 0, 0);
				cout << "\n\n\n\n\n\n\n\n\n\n\n";
				cout << "													이동 완료!!" << endl;
				Sleep(1000);
				system("cls");
				// 최초 역 방문시 가판대 상점을 이용할 수 있음
				Shop();
			}
			else {
				Map();
			}
		}
		else {
			cout << "이동하기를 사용하기까지 " << limit << "일 남았습니다." << endl;
			system("pause");
			system("cls");
		}
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
			else { }
		}
	}
	void ItemUse(int key) {
		cout << "아이템 사용하시겠습니까?" << endl;
		system("pause");
		switch (item[key]->getId()) {
		case 1:
			water += 15;
			if (water >= 100) water = 100;
			break;
		case 2:
			food += 15;
			if (food >= 100) food = 100;
			break;
		}
		delete item[key];
		bagpull[key] = false;
		
		cout << "아이템이 사용되었습니다." << endl;
		system("pause");
	}
	void addMessage() {
		if (water <= 40) {
			m_key = 1;
			message = true;
		}
		else if (food <= 40) {
			m_key = 2;
		}
		else if (energy <= 40) {
			m_key = 3;
		}
	}
	void Message(int num) {
		if (message) {
			cout << messages[num] << endl;
			message = false;
		}
		else {
			cout << "메세지가 존재하지 않습니다." << endl;
		}
		system("pause");
		system("cls");
	}
	void Shop() {
		int k = 0, p = 0; 
		string key[2] = { "  ", "  " };
		key[p] = "◀";
		while (k != 120) {
			cout << "	┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "	┃  다팔아 가판대       ┃" << endl;
			cout << "	┃          특가 세일중 ┃" << endl;
			cout << "	┗━┳┳━━━━━━━━━━━━━━━━┳┳━┛" << endl;
			cout << "	  ┃┃　　 ∧＿∧　　 ┃┃" << endl;
			cout << "	  ┗┛　　 ('ω')　   ┗┛" << endl;
			cout << "	┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "	┃  식량 2개	    " << key[0] << " ┃" << endl;
			cout << "	┃  생수 2개	    " << key[1] << " ┃" << endl;
			cout << "	┃         	       ┃" << endl;
			cout << "	┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "												Enter : 구매" << endl;
			cout << "												↓,↑ : 이동" << endl;
			cout << "												    X : 종료" << endl;

			// 72 Up 80 Down
			do {
				k = toupper(_getch());
			} while (k != 120 && k != 13 && k != 72 && k != 80);
			// 이동 기능 구현 필요
			if (p != 0 && k == 72) {
				key[p] = "  ";
				key[--p] = "◀";
			}
			else if (p != 1 && k == 80) {
				key[p] = "  ";
				key[++p] = "◀";
			}
			// 구매 기능 구현 필요
			system("cls");
		}
		system("cls");
	}
};