#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
using namespace std;

class Item {
private:
	int id = 0;
public:
	virtual int getId() {
		return id;
	}
	// 순수 가상 함수 = 이름 출력
	virtual string getName() = 0;
};
class Water : public Item {
private:
	int id = 1;
public:
	int getId() {
		return id;
	}
	string getName() {
		return "생수";
	}
};
class Food : public Item {
private:
	int id = 2;
public:
	int getId() {
		return id;
	}
	string getName() {
		return "식량";
	}
};
class Messages {
private:
	string name;
	string text;
public:
	static int cnt;
	Messages(string name, string text) : name(name), text(text) {
		cnt++;
	}
	string getName() {
		return name;
	}
	string getText() {
		return text;
	}
	~Messages() {

		cnt--;
	}
};
class Quests {
private:
	string name;
	string text;
	string item;
	int reward;
	int num;
public:
	static int cnt;
	Quests(int id, string item) : item(item), num(num) {
		cnt++;
		switch (id) {
			case 1: name = "고영희";
					text = "캣잎을 구해다 주면 좋겠어... 보상은 충분히 하도록 할게";
					num = rand() % 1 + 1;
					reward = 5000 * num;
					break;
		}
	}
	string getName() {
		return name;
	}
	string getText() {
		return text;
	}
	string getItem() {
		return item;
	}
	int getNum() {
		return num;
	}
	~Quests() {
		cnt--;
	}
};

class User {
private:
	bool life;
	int month;		// 월
	int day;		// 일
	int s_day;		// 생존 해야 하는 일자
	int survive;	// 총 생존 날짜
	int water;		// 수분 수치
	int food;		// 배고픔 수치
	int energy;		// 에너지 수치
	int money;		// 보유 돈
	int state;		// 상태 변수
	Quests* quest[8];	// 메세지
	Messages* message[8];	// 메세지
	Item* item[12];			// 아이템

	int position;	// 현재 역 위치
	string map[16] = {
		"국화역", "장미역", "난초역", "동백역", "매화역",
		"모란역", "벚꽃역", "수련역", "안개역", "연꽃역",
		"팬지역", "백합역", "철쭉역", "수국역", "카라역",
		"박하역"
	};

	// 고영희 대화 내용
	string talk1[7] = {									
		"어 왔어?... 안그래도 언제 오려나 생각하고 있었어								"
		, "넌 누구야??													"
		, "나는 고영희라고 해, 너를 부른 이유는 부탁할게 있어서야								"
		, "혹시 캣닢이라는 거에 대해 알고있니?										"
		, "내가 가장 좋아하는건데 이곳에서는 구하기가 쉽지 않아...								"
		, "혹시 캣닢을 본다면 소소한 보상을 해줄테니 나에게 꼭 가져다줬으면해!!						"
		, "그래 알겠어													"
	};
public:
	static bool bagpull[12];
	static bool m_pull[8];
	static bool q_pull[8];
	//User(int level) {
	User() {
		MessageAdd("SOS 운영자", "SOS 게임에 오신 것을 환영합니다.\n기본적으로 지급되는 생수와 식량 외에 더 많은 것을 얻고 싶다면 다른 곳으로 움직여야 할 것 입니다.\n그럼 행운을 빕니다.\n\n※ 한번 본 메세지는 더 이상 확인할 수 없습니다.");
		MessageAdd("고영희	", "안녕? 혹시 시간이 된다면 동백역으로 와줘 너에게도 도움이 될 거야");
		ItemAdd(1);
		ItemAdd(1);
		ItemAdd(2);
		life = true;						// 생존여부
		food = 100;
		water = 100;
		energy = 100;
		s_day = 30;							// 생존해야 하는 날짜
		survive = 1;						// 생존한 날짜
		month = 2;							// 월
		day = 13;							// 일
		money = 100000;						// 보유 돈
		//quest = false;
		position = 0;
		state = 1;
	}
	bool play() {
		while (s_day > 0) {
			PlaySound(TEXT("playbgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			char check = Phone();
			system("cls");
			PlaySound(NULL, 0, 0);
			switch (check) {
				case 'e': Bag(); break;
				case 'q': Quest(); break;
				case 'w': Map(); break;
				case '1': NextDay(); break;
				case '2': Message(); break;
				case '3': Shop(); break;
				case '9': 
					Talk("아...안녕??						", "햄스타");
					for(int i=0; i<7; i++)
						if (i == 1 || i == 6) 
							Talk(talk1[i], "  나  ");
						else 
							Talk(talk1[i], "고영희");
					break;
			}
			if (!life) {
				break;
			}
		}
		if (survive == day) return false;
		else return true;
	}
	void Bag() {
		string check[12] = { "--", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };
		int key = 0, k = 0;
		while (k != 88) {
			cout << "\n\n\n";
			cout << "						      ____" << endl;
			cout << "						     / /＼＼" << endl;
			cout << "					____________/_/___＼＼___________" << endl;
			cout << "					|				|" << endl;
			// 아이템 이름 출력
			cout << "					|";
			for (int i = 0; i < 3; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			// 아이템 선택 창
			cout << "					|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[0] << "       " << check[1] << "       " << check[2];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "					|_______________________________|" << endl;
			cout << "					|				|" << endl;
			cout << "					|";
			for (int i = 3; i < 6; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[3] << "       " << check[4] << "       " << check[5];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "					|_______________________________|" << endl;
			cout << "					|				|" << endl;
			cout << "					|";
			for (int i = 6; i < 9; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[6] << "       " << check[7] << "       " << check[8];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "					|_______________________________|" << endl;
			cout << "					|				|" << endl;
			cout << "					|";
			for (int i = 9; i < 12; i++) {
				if (bagpull[i])
					cout << "     " << item[i]->getName();
				else
					cout << "        ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTBLUE, BLACK);
			cout << check[9] << "       " << check[10] << "       " << check[11];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "					|_______________________________|" << endl;
			cout << "\n\n\n\n";
			cout << "												Enter : 선택" << endl;
			cout << "												←,→ : 이동" << endl;
			cout << "												    X : 종료" << endl;
			do {
				k = toupper(_getch());
			} while (k != 13 && k != 75 && k != 77 && k != 88);
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
			cout << "		   ------";
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
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			if (key[15]) textcolor(MAGENTA, BLACK);
			cout << "		" <<  map[15] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[6]) textcolor(MAGENTA, BLACK);
			cout << map[6] << "" << endl;
			textcolor(WHITE, BLACK);
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			if (key[14]) textcolor(MAGENTA, BLACK);
			cout << "		" << map[14] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[7]) textcolor(MAGENTA, BLACK);
			cout << map[7] << endl;
			textcolor(WHITE, BLACK);
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			cout << "		   ------";
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
			cout << "\n\n		   현재 역 : " << map[position] << endl;
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
		cout << "	_________________________________	_________________________________		_________________" << endl;
		cout << "	|	   			|	|				|		||　|∧,,∧	|" << endl;
		cout << "	|-------------------------------|	|				|		||＿|*－ω-)	|" << endl;
		cout << "	|";
		switch (state) {
		case 1: textcolor(LIGHTGREEN, BLACK);
			break;
		case 2: textcolor(YELLOW, BLACK);
			break;
		case 3: textcolor(LIGHTRED, BLACK);
			break;
		}
		cout << "   ■";
		textcolor(WHITE, BLACK);
		cout << "	     20XX년  " << month << "월 " << day << "일	|	| ";
		if(Quests::cnt != 0) cout << "현재 진행중인 퀘스트 " << Quests::cnt << "개";
		else cout << "퀘스트가 없습니다.	";
		cout<< "	|		||  |ｏ";
		textcolor(LIGHTRED, BLACK);
		cout << "♥";
		textcolor(WHITE, BLACK);
		cout << "ｏ	|" << endl;
		cout << "	|				|	|				|		||￣|━ J	|" << endl;
		cout << "	|    ________       ________ 	|	|_____________________________  |		|_______________|" << endl;
		cout << "	|   |        |     |	    |	|				      ＼|"<< endl;
		cout << "	|   |  가방  |     |  지도  |	|				    Quest		보유 돈 : " << money << endl;
		cout << "	|   |________|     |________|	|" << endl;
		cout << "	|				|" << endl;
		cout << "	|				|" << endl;
		cout << "	|   ---------  상태  ---------	|";
		if (Messages::cnt != 0)cout << "\t\t         ∧＿∧";
		cout << "				  ┏━━━━━━━━━━━┓" << endl << "	|      수분	       " << water << "	|";
		if (Messages::cnt != 0)cout << "\t\t         ('ω')";
		cout << "				  ┃  S H O P♣┃" << endl << "	|      배고픔          " << food << "	|";
		if (Messages::cnt != 0)cout << "\t\t   ┏━━━━ ∪━ ∪━━━━┓";
		cout << "			  ┗━┳┳━━━━━┳┳━┛" << endl << "	|      에너지          " << energy << "	|";
		if (Messages::cnt != 0)cout << "\t\t   ┃ ＼　　　　 ／ ┃";
		cout << "			   ┏┗┛━━━━━┗┛┓" << endl << "	|   ________________________	|";
		if (Messages::cnt != 0) {
			cout << "\t\t   ┃　 ＼　";
			textcolor(LIGHTRED, BLACK);
			cout << "♡";
			textcolor(WHITE, BLACK);
			cout << " ／   ┃";
		}
		cout << "			   ┃  ┏━┓━┓  ┃" << endl << "	|				|";
		if (Messages::cnt != 0)cout << "\t\t   ┃　／ ＼＿／ ＼ ┃";
		cout << "			   ┃  ┃ ┃ ┃  ┃" << endl << "	|				|";
		if (Messages::cnt != 0)cout << "\t\t   ┗━━━━━━━━━━━━━━━┛";
		cout << "			   ┗━━┗━┛━┛━━┛" << endl << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|";
		if (Messages::cnt != 0)cout << "\t\t      메세지 도착!!";
		if (survive < 10) cout << endl << "	|  | " << survive << "일차,                  |	|" << endl;
		else if (survive < 100) cout << endl << "	|  | " << survive << "일차,                 |	|" << endl;
		cout << "	|  | 언제쯤 나갈 수 있을까.. |	|" << endl;
		cout << "	|  |_________________________|	|							    [1] 취침 하기" << endl;
		cout << "	|				|							    [2] 문자 읽기" << endl;
		cout << "	|				|							    [3] 상점 가기" << endl;
		cout << "	|-------------------------------|							    [Q] 퀘스트보기" << endl;
		cout << "	|	        ○		|							    [W] 지도 열기" << endl;
		cout << "	|_______________________________|							    [E] 가방 열기" << endl;
		char check;
		do {
			check = tolower(_getch());
		} while (check != '1' && check != '2' && check != '3' && check != 'q' && check != 'w' && check != 'e' && check != '9'); // test용 9는 나중에 지워야 함
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
		// 생존 여부
		life = DieCheck();
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
			Sleep(300);
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
		int cnt1 = 0, cnt2 = 0;
		for (int i = position; i != k; i++) {
			if (i == 15) i = -1;
			cnt1++;
		}
		for (int i = position; i != k; i--) {
			if (i == 0) i = 16;
			cnt2++;
		}
		if ((cnt1 <= 5 || cnt2 <= 5) && state != 3 && k != position) {
			int yn; system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
			cout << map << " 으로 이동하시겠습니까?" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "												Y : 시작" << endl;
			cout << "												N : 취소" << endl;
			// 이동 yn 구현 필요 
			do {
				yn = tolower(_getch());
			} while (yn != 121 && yn != 110);
			system("cls");
			if (yn == 121) {
				position = k;
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
				// 생존 여부
				life = DieCheck();
				// 화면에 보여지는 그림
				cout << "\n\n\n\n\n\n";
				PlaySound(TEXT("subway.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cout << "\t\t\t\t\t\t         Ｏ" << endl;
				cout << "\t\t\t\t\t\t       ｏ" << endl;
				cout << "\t\t\t\t\t\t      °" << endl;
				cout << "\t\t\t\t\t\t     ┳┳ ∧∧" << endl;
				cout << "\t\t\t\t\t\t     ┃┃(-∀-)" << endl;
				cout << "\t\t\t\t\t\t    ┏┻┻┷━ Ｏ┏━┷┓┏━┷┓" << endl;
				cout << "\t\t\t\t\t\t    ┃ 　　 ┠┨  ┠┨  ┃" << endl;
				cout << "\t\t\t\t\t\t    ┃ 　　 ┠┨  ┠┨  ┃" << endl;
				cout << "\t\t\t\t\t\t    ┗◎━━◎┛┗◎┛┗◎┛" << endl;
				cout << "\n\n\t\t\t\t\t\t     ";
				const char* a = "이 동 중 . . .";
				textcolor(LIGHTMAGENTA, BLACK);
				for (int j = 0; j < strlen(a); j++) {
					Sleep(300);
					cout << a[j];
				}
				textcolor(WHITE, BLACK);
				Sleep(1000);
				PlaySound(NULL, 0, 0);
				cout << "\n\n\n\n\n\n\n\n\n\n\n";
				cout << "													이동 완료!!" << endl;
				Sleep(1000);
				system("cls");
				// 특정 역 이동시 퀘스트 생성
				if (position == 3) {
					QuestAdd(1, "캣잎");
				}
			}
			else {
				Map();
			}
		}
		else if (k == position) {
			cout << "현재 " << map << "에 있으므로 이동할 수 없습니다." << endl;
			system("pause");
			system("cls");
		}
		else if (state == 3) {
			cout << "현재 이동하기를 사용할 수 있는 상태가 아닙니다." << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "한 번에 이동할 수 있는 역의 범위를 넘어갔습니다. [이동 불가]" << endl;
			system("pause");
			system("cls");
		}
		
	}
	bool DieCheck() {
		bool answer = true;
		if (water <= 10 || food <= 10 || energy <= 10) {		// 90% 확률로 사망
			if ((rand() % 99 + 1) <= 90) answer = false;
		}
		else if (water <= 20 || food <= 20 || energy <= 20) {	// 50% 확률로 사망
			if ((rand() % 99 + 1) <= 50) answer = false;
		}
		else if (water <= 30 || food <= 30 || energy <= 30) {	// 20% 확률로 사망
			if ((rand() % 99 + 1) <= 20) answer = false;
			state = 3;
		} else if (water <= 50 || food <= 50 || energy <= 50) {
			state = 2;
		} else {
			state = 1;
		}
		return answer;
	}
	bool ItemAdd(int id) {
		// 아이템을 생성해주는 메소드
		int i;
		for (i = 0; i < 12; i++) {
			if (!bagpull[i]) {
				switch (id) {
				case 1: item[i] = new Water();
					break;
				case 2: item[i] = new Food();
					break;
				}
				bagpull[i] = true;
				break;
			}
		}
		if (i == 12) return false;
		return true;
	}
	void ItemUse(int key) {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cout << item[key]->getName() << "아이템 사용하시겠습니까?" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "												Y : 시작" << endl;
		cout << "												N : 취소" << endl;
		int k;
		do {
			k = toupper(_getch());
		} while (k != 89 && k != 78);
		if (k == 89) {
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   ";
			switch (item[key]->getId()) {
			case 1:
				cout << "수분 25 상승" << endl;
				water += 25;
				if (water >= 100) water = 100;
				break;
			case 2:
				cout << "배고픔 30 상승" << endl;
				food += 30;
				if (food >= 100) food = 100;
				break;
			}
			delete item[key];
			bagpull[key] = false;
			Sleep(1000);
		}
	}
	void MessageAdd(string name, string text) {
		int i;
		for (i = 0; i < 8; i++) {
			if (!m_pull[i]) {
				message[i] = new Messages(name, text);
				m_pull[i] = true;
				break;
			}
		}
		// 메시지 함이 꽉 찼다는 경고 문구를 출력하는 부분 만들기
	}
	void MessageUse(int idx) {
		cout << message[idx]->getText() << endl;
		_getch();
		m_pull[idx] = false;
		delete message[idx];
	}
	void Message() {
		if (Messages::cnt != 0) {
			string check[8] = { "■", "□", "□", "□", "□", "□", "□", "□" };
			int key = 0, k = 0;
			while (Messages::cnt != 0 && k != 88) {
				system("cls");
				int p = -1;
				int ps[8];
				cout << "				_________________________________________________________" << endl;
				cout << "				|		  					|" << endl;
				cout << "				|-------------------------------------------------------|" << endl;
				cout << "				|				 20XX년  " << month << "월 " << day << "일	| " << endl;
				cout << "				|							|" << endl;
				for (int i = 0; i < 8; i++) {
					if (m_pull[i]) {
						p++;
						if (i != 7) {
							if (p != 0)
								cout << "				|	__________________________________________	|" << endl;
							cout << "				|							|" << endl;
							cout << "				|	" << message[i]->getName() << " 				" << check[p] << "	|" << endl;
						}
						else {
							cout << "				|	__________________________________________	|		Enter : 선택" << endl;
							cout << "				|							|		↑,↓ : 이동" << endl;
							cout << "				|	" << message[i]->getName() << " 				" << check[p] << "	|			X : 종료" << endl;
						}
						ps[p] = i;
					}
				}
				for (int i = p+1; i < 8; i++) {
					if (i != 7) {
						cout << "				|							|" << endl;
						cout << "				|							|" << endl;
						cout << "				|							|" << endl;
					}
					else {
						cout << "				|							|		Enter : 선택" << endl;
						cout << "				|							|		↑,↓ : 이동" << endl;
						cout << "				|							|		    X : 종료" << endl;
					}
				}
				do {
					k = toupper(_getch());
				} while (k != 13 && k != 72 && k != 80 && k != 88);
				if (key != (Messages::cnt - 1) && k == 80) {
					check[key] = "□";
					check[++key] = "■";
				}
				else if (key != 0 && k == 72) {
					check[key] = "□";
					check[--key] = "■";
				}
				else if (k == 13) {
					system("cls");
					MessageUse(ps[key]);
					check[key] = "□";
					check[0] = "■";
				}
			}
		}
		if(Messages::cnt == 0) {
			int k = 0;
			cout << "				_________________________________________________________" << endl;
			cout << "				|    							|" << endl;
			cout << "				|-------------------------------------------------------|" << endl;
			cout << "				|				 20XX년  " << month << "월 " << day << "일	| " << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|		메세지가 존재하지 않습니다.		|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|		    X : 종료" << endl;
			do {
				k = toupper(_getch());
			} while (k != 88);
		}
		system("cls");
	}
	void Shop() {
		int k = 0, p = 0; 
		string key[2] = { "  ", "  " };
		key[p] = "◀";
		while (k != 120) {
			cout << "							┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "							┃					보유돈 " << "50000원" << "	  ┃" << endl;
			cout << "							┃	   ____ 					  ┃" << endl;
			cout << "							┃	  |____|					  ┃" << endl;
			cout << "							┃	 /     ＼					  ┃" << endl;
			cout << "							┃	|   水   |		      ._, , .,, _	  ┃" << endl;
			cout << "							┃	|________|		      ( : (　   ..)	  ┃" << endl;
			cout << "		┏━━━━━━━━━━━━━━━━━━━━━━┓		┃	[        ]		      | : |  -ω- |	  ┃" << endl;
			cout << "		┃  S H O P♣           ┃		┃	[        ]		      | : |　　　 |	  ┃" << endl;
			cout << "		┃        다 팔아요~!   ┃		┃	[________]		       `' '------´	  ┃" << endl;
			cout << "		┗━┳┳━━━━━━━━━━━━━━━━┳┳━┛		┃							  ┃" << endl;
			cout << "		  ┃┃　　 ∧＿∧　　 ┃┃			┃	[  생수  ]			[  식량  ]	  ┃" << endl;
			cout << "		  ┗┛　　 ('ω')　   ┗┛			┃							  ┃" << endl;
			cout << "		┏━━━━━━━━━━━━━━━━━━━━━━┓		┃    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━	  ┃" << endl;
			cout << "		┃     식량 5,000원     ┃		┃							  ┃" << endl;
			cout << "		┃     생수 4,500원     ┃		┃     ";
			textcolor(CYAN, BLACK);
			cout << "┏━━━━━━━━━━┓		      ┏━━━━━━━━━━┓	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "		┃     히든 3,000원     ┃		┃     ";
			textcolor(CYAN, BLACK);
			cout << "┃  ┏━━━━┓  ┃		      ┃  ┏━━━━┓  ┃	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "		┃         	       ┃		┃     ";
			textcolor(CYAN, BLACK);
			cout << "┗━━┛    ┃　┃		      ┗━━┛    ┃　┃	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "		┗━━━━━━━━━━━━━━━━━━━━━━┛		┃         ";
			textcolor(CYAN, BLACK);
			cout << "┏━━━┛　┃		          ┏━━━┛　┃	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "							┃         ";
			textcolor(CYAN, BLACK);
			cout << "┃　┏━━━┛		          ┃　┏━━━┛	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "							┃         ";
			textcolor(CYAN, BLACK);
			cout << "┗━━┛			          ┗━━┛		  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "							┃         ";
			textcolor(CYAN, BLACK);
			cout << "┏━━┓			          ┏━━┓		  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "							┃         ";
			textcolor(CYAN, BLACK);
			cout << "┗━━┛			          ┗━━┛		  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "							┃	[  히든  ]			[  히든  ]	  ┃" << endl;
			cout << "							┃							  ┃" << endl;
			cout << "							┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
			cout << "													Enter : 구매" << endl;
			cout << "													↓,↑ : 이동" << endl;
			cout << "													    X : 종료" << endl;
			// 72 Up 80 Down
			do {
				k = toupper(_getch());
			} while (k != 88 && k != 13 && k != 72 && k != 80);
			// 이동 기능 구현 필요
			if (p != 0 && k == 72) {
				key[p] = "  ";
				key[--p] = "◀";
			}
			else if (p != 1 && k == 80) {
				key[p] = "  ";
				key[++p] = "◀";
			}
			else if (k == 13) {
				system("cls");
				switch (p) {
				case 0:
					cout << "식량의 가격은 5,000원 입니다. 구매하시겠습니까?" << endl;
					system("pause");
					if (ItemAdd(2) /*&& money >= 5000*/)
						money -= 3000;
					else if (money < 5000) {
						cout << "보유 금액이 부족합니다." << endl;
						system("pause");
					}
					else {
						cout << "가방 공간이 가득찼습니다. 더 이상 구매할 수 없습니다." << endl;
						system("pause");
					}
					break;
				case 1:
					cout << "생수의 가격은 4,500원 입니다. 구매하시겠습니까?" << endl;
					system("pause");
					if (ItemAdd(1) /*&& money >= 4500*/)
						money -= 1700;
					else if (money < 4500) {
						cout << "보유 금액이 부족합니다." << endl;
						system("pause");
					}
					else {
						cout << "가방 공간이 가득찼습니다. 더 이상 구매할 수 없습니다." << endl;
						system("pause");
					}
					break;
				}
			}
			else { // X를 누른 경우
				break;
			}
			// 구매 기능 구현 필요
			system("cls");
		}
		system("cls");
	}
	void QuestRead(int idx) {
		cout << quest[idx]->getName() << endl;
		cout << quest[idx]->getText() << endl;
		// 퀘스트에 필요한 아이템 보유 현황 출력 구현
		cout << quest[idx]->getItem() << " : 0/" << quest[idx]->getNum() << endl;
		_getch();
	}
	void QuestAdd(int id, string item) {
		quest[0] = new Quests(id, item);
		q_pull[0] = true;
	}
	void Quest() {
		if (Quests::cnt != 0) {
			string check[8] = { "■", "□", "□", "□", "□", "□", "□", "□" };
			int key = 0, k = 0;
			while (Quests::cnt != 0 && k != 88) {
				system("cls");
				int p = -1;
				int ps[8];
				cout << "				_________________________________________________________" << endl;
				cout << "				|		  					|" << endl;
				cout << "				|-------------------------------------------------------|" << endl;
				cout << "				|				 20XX년  " << month << "월 " << day << "일	| " << endl;
				cout << "				|							|" << endl;
				for (int i = 0; i < 8; i++) {
					if (q_pull[i]) {
						p++;
						if (i != 7) {
							if (p != 0)
								cout << "				|	__________________________________________	|" << endl;
							cout << "				|							|" << endl;
							cout << "				|	" << quest[i]->getName() << " 				" << check[p] << "	|" << endl;
						}
						else {
							cout << "				|	__________________________________________	|		Enter : 선택" << endl;
							cout << "				|							|		↑,↓ : 이동" << endl;
							cout << "				|	" << quest[i]->getName() << " 				" << check[p] << "	|			X : 종료" << endl;
						}
						ps[p] = i;
					}
				}
				for (int i = p + 1; i < 8; i++) {
					if (i != 7) {
						cout << "				|							|" << endl;
						cout << "				|							|" << endl;
						cout << "				|							|" << endl;
					}
					else {
						cout << "				|							|		Enter : 선택" << endl;
						cout << "				|							|		↑,↓ : 이동" << endl;
						cout << "				|							|		    X : 종료" << endl;
					}
				}
				do {
					k = toupper(_getch());
				} while (k != 13 && k != 72 && k != 80 && k != 88);
				if (key != (Messages::cnt - 1) && k == 80) {
					check[key] = "□";
					check[++key] = "■";
				}
				else if (key != 0 && k == 72) {
					check[key] = "□";
					check[--key] = "■";
				}
				else if (k == 13) {
					system("cls");
					QuestRead(ps[key]);
					check[key] = "□";
					check[0] = "■";
				}
			}
		}
		if (Quests::cnt == 0) {
			int k = 0;
			cout << "				_________________________________________________________" << endl;
			cout << "				|    							|" << endl;
			cout << "				|-------------------------------------------------------|" << endl;
			cout << "				|				 20XX년  " << month << "월 " << day << "일	| " << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|		퀘스트가 존재하지 않습니다.		|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|" << endl;
			cout << "				|							|		    X : 종료" << endl;
			do {
				k = toupper(_getch());
			} while (k != 88);
		}
		system("cls");
	}
	void Talk(string str, string name) {
		cout << endl << endl << endl << endl << endl << endl << endl;
		if(name == "고영희"){
			cout << "						　　　　　　　　　　　  　;' ':;,,　　　　       ,;'':;," << endl;
			cout << "						　　　　　　　　　　　   ;'　　 ':;,.,.,.,.,.,,,;'　　';," << endl;
			cout << "						      　　　　　　　　 ,:'　　　　　　　　 　   ::::::::" << endl;
			cout << "						         　　　　　　,:' ／ 　 　　　　＼ 　　   ::::::::'," << endl;
			cout << "						　             　　 :'　 ●　　　　　 ●　 　　    ::::::::" << endl;
			cout << "						　　  　　　　　　　i　 '''　(__人__)　　'''' 　　  :::::::::" << endl;
			cout << "						　　　　  　　　　　 :　 　　　　　　　　　 　     ::::::::" << endl;
			cout << "						　　　　　　　　　　　`:,  　　　　　 　 　     ::::::::::" << endl;
			cout << "						　　　　  　　　　　　 ,:'　　　　　　　    : :::::::::::::" << endl;
			cout << "						　　　　　　　 　　 ,:'　　　　　　　　        : : ::::::::::" << endl;
		}
		else if (name == "햄스타") {
			cout << endl << endl << endl;
			cout << "						　　　　　　　　　　　  　 　 　|``--,...　　　　　``　＊ |" << endl;
			cout << "						　　　　　　　　　　　  　　  　i  ＼　　　　　　　　　 ／:;" << endl;
			cout << "						　　　　　　　　　　　  　　    ミ　　　　 　　　　　　    ミ" << endl;
			cout << "						　　　　　　　　　　　  　　   〉 　　　　●　　.　　●　　　ミ" << endl;
			cout << "						　　　　　　　　　　　  　　   ミ　 　 ``　　　人　　　　　 ミ" << endl;
			cout << "						　　　　　　　　　　　  　  　ミ :　　　　　 　　　　 　　　  ミ" << endl;
			cout << "						　　　　　　　　　　　  　  ,I:　　　　　　　つ♣⌒　　        :I," << endl;
		}
		else if (name == "  나  ") {
			cout << "	　  　,;'':;, 　　　　       ,;'':;," << endl;
			cout << "	　　 ;'　　 ':;,.,.,.,.,.,,,;'　　 ';," << endl;
			cout << "	　 ,:'　　　　　　　　 　            ':," << endl;
			cout << "	  ,:'                   　　           ':," << endl;
			cout << "	 :'　         __           __           ':" << endl;
			cout << "	 i　                    　　             i" << endl;
			cout << "	  :　 　*　 　　　　ㅅ  　       *      :" << endl;
			cout << "	   `:,  　　　　　 　 　             ,:`" << endl;
			cout << "	   ,:'　　　　　　　                ':," << endl;
			cout << "	,:'　　　　　　　　                    ':," << endl;
		}
		if (name == "  나  ") {
			cout << " __________" << endl;
			cout << "|  " << name << "  |" << endl;
			cout << "|__________|____________________________________________________________________________________________________________" << endl;

		}
		else {
			cout << "													     __________" << endl;
			cout << "													    |  " << name << "  |" << endl;
			cout << "____________________________________________________________________________________________________________|__________|" << endl;
		}
		cout << "|															|" << endl;
		cout << "|	" << str << "|" << endl;
		cout << "|															|" << endl;
		cout << "|															|" << endl;
		cout << "|															|" << endl;
		cout << "|															|" << endl;
		cout << "|															|" << endl;
		cout << "|															|" << endl;
		cout << "|______________________________________________________________________________________________________________________|" << endl;
		char yn;
		do {
			yn = tolower(_getch());
		} while (yn != 13); // 13은 Enter 
		system("cls");
	}
};