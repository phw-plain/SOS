#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h> 
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
	virtual ~Item(){}
};
class Water : public Item {
private:
	int id = 1;
public:
	static int cnt;
	Water() {
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "생수";
	}
	~Water() {
		cnt--;
	}
};
class Food : public Item {
private:
	int id = 2;
public:
	static int cnt;
	Food(){
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "식량";
	}
	~Food() {
		cnt--;
	}
};
class Leaf : public Item {
private:
	int id = 3;
public:
	static int cnt;
	Leaf() {
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "캣잎";
	}
	~Leaf() {
		cnt--;
	}
};
class Ribbon : public Item {
private:
	int id = 4;
public:
	static int cnt;
	Ribbon() {
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "리본";
	}
	~Ribbon() {
		cnt--;
	}
};
class Cheese : public Item {
private:
	int id = 5;
public:
	static int cnt;
	Cheese() {
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "치즈";
	}
	~Cheese() {
		cnt--;
	}
};
class Book : public Item {
private:
	int id = 6;
public:
	static int cnt;
	Book() {
		cnt++;
	}
	int getId() {
		return id;
	}
	string getName() {
		return "도서";
	}
	~Book() {
		cnt--;
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
	Quests(int id, string item, string name) : item(item), num(num), name(name) {
		cnt++;
		num = rand() % 2 + 1;
		reward = 5000 * num;
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
	int state;		// 상태
	int s_cnt;		// 상점 이용 제한
	int story;		// 스토리 확인 갯수
	int playtime;	// 플레이 타임
	Quests* quest[8];	// 메세지
	Messages* message[8];	// 메세지
	Item* item[12];			// 아이템

	int position;	// 현재 역 위치
	string map[16] = {
		"국화역", "장미역", "난초역", "동백역", "매화역",
		"모란역", "별꽃역", "수련역", "안개역", "연꽃역",
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
	// 나  비 대화 내용
	string talk2[7] = {
		"...(엄청난 고민이 있어보인다.)											"
		, "혹시 무슨일 있어??												"
		, "그게... 내가 항상 하고다니던 리본이 보이지가 않아...								"
		, "어디에서 잃어버렸는지 기억하고 있어?										"
		, "아니.. 모르겠어..												"
		, "혹시 꼭 그 리본이 아니어도 괜찮으니까 혹시 나에게 어울릴만한 리본이 있다면 가져다주지 않을래?			"
		, "그래 알겠어, 찾게 되면 연락할게!										"
	};
	// 햄스타 대화 내용
	string talk3[8] = {
		"한참 걸릴줄 알았는데 빨리 왔군											"
		, "내 이름은 햄스타 Mr.Ham이라고 부르도록 해									"
		, "어쩌다 보니 알게됬는데 너 요즘 고양이들 사이에서 유명하던데?							"
		, "뭐가?														"
		, "말 만하면 필요한걸 가져다 주는 녀석이 있다고									"
		, "그래서 말인데 요즘 치즈를 못먹은지 너무 오래됬어								"
		, "치즈를 얻게 된다면 꼭 나에게 가져오도록 해 그에 대한 대가는 충분히 치를테니 말이야				"
		, "그래 알겠어													"
	};

public:
	static bool bagpull[12];
	static bool m_pull[8];
	static bool q_pull[8];
	User() {
		MessageAdd("SOS 운영자", "SOS 게임에 오신 것을 환영합니다.\n기본적으로 지급되는 생수와 식량 외에 더 많은 것을 얻고 싶다면 다른 곳으로 움직여야 할 것 입니다.\n그럼 행운을 빕니다.\n\n※ 한번 본 메세지는 더 이상 확인할 수 없습니다.");
		MessageAdd("고영희	", "안녕? 혹시 시간이 된다면 동백역으로 와줘 너에게도 도움이 될 거야");
		ItemAdd(1);
		ItemAdd(1);
		ItemAdd(2);
		ItemAdd(3);
		ItemAdd(3);
		life = true;						// 생존여부
		food = 100;
		water = 100;
		energy = 100;
		s_day = 30;							// 생존해야 하는 날짜
		survive = 1;						// 생존한 날짜
		month = 5;							// 월
		day = 25;							// 일
		money = 30000;						// 보유 돈
		position = 0;
		state = 1;
		s_cnt = 0;
		story = 0;
		playtime = time(NULL);
	}
	bool play() {
		while (s_day > 0) {
			PlaySound(TEXT("playbgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			if (survive == 10) MessageAdd("긴급 상황 문자", "현재 지하철역이 대대적으로 붕괴되어 구조에 많은 시간이 소요되고 있습니다.\n현 정부는 현재 대비하지 못한 시민 여러분들의 최선을 다해 빠르게 구조를 마칠 계획입니다.\n");
			if (survive == 20) MessageAdd("긴급 상황 문자", "열흘 뒤 11호선의 구조를 시작할 계획입니다.\n해당 역에 계신 분들은 국화역으로 모여주시기 바랍니다.\n");
			char check = Phone();
			system("cls");
			PlaySound(NULL, 0, 0);
			switch (check) {
				case 'e': Bag(); break;
				case 'q': Quest(); break;
				case 'w': Map(); break;
				case '1': NextDay(); break;
				case '2': Message(); break;
				case '3': if (s_cnt == 0) Shop();
						else ClossShop();
						break;
			}
			if (!life) {
				break;
			}
		}
		playtime = (double)(time(NULL) - playtime);
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
					cout << "         ";
			}
			cout << "\t|" << endl;
			// 아이템 선택 창
			cout << "					|      ";
			textcolor(LIGHTGREEN, BLACK);
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
					cout << "         ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTGREEN, BLACK);
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
					cout << "         ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTGREEN, BLACK);
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
					cout << "         ";
			}
			cout << "\t|" << endl;
			cout << "					|      ";
			textcolor(LIGHTGREEN, BLACK);
			cout << check[9] << "       " << check[10] << "       " << check[11];
			textcolor(WHITE, BLACK);
			cout << "	|" << endl;
			cout << "					|_______________________________|" << endl;
			cout << "\n\n\n\n";
			cout << "													Enter : 선택" << endl;
			cout << "													←,→ : 이동" << endl;
			cout << "													    X : 종료" << endl;
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
			if (key[0]) textcolor(LIGHTGREEN, BLACK);
			cout << map[0];
			textcolor(WHITE, BLACK);
			for (int i = 1; i < 6; i++) {
				cout << "-------";
				if (key[i]) textcolor(LIGHTGREEN, BLACK);
				cout << map[i];
				textcolor(WHITE, BLACK);
			}
			cout << "-----" << endl;
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			if (key[15]) textcolor(LIGHTGREEN, BLACK);
			cout << "		" <<  map[15] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[6]) textcolor(LIGHTGREEN, BLACK);
			cout << map[6] << "" << endl;
			textcolor(WHITE, BLACK);
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			if (key[14]) textcolor(LIGHTGREEN, BLACK);
			cout << "		" << map[14] << "										  ";
			textcolor(WHITE, BLACK);
			if (key[7]) textcolor(LIGHTGREEN, BLACK);
			cout << map[7] << endl;
			textcolor(WHITE, BLACK);
			cout << "		   |										    |" << endl;
			cout << "		   |										    |" << endl;
			cout << "		   ------";
			if (key[13]) textcolor(LIGHTGREEN, BLACK);
			cout << map[13];
			textcolor(WHITE, BLACK);
			for (int i = 12; i > 7; i--) {
				cout << "-------";
				if (key[i]) textcolor(LIGHTGREEN, BLACK);
				cout << map[i];
				textcolor(WHITE, BLACK);
			}
			cout << "-----" << endl;
			cout << "\n\n		   현재 역 : " << map[position] << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n";
			cout << "													Enter : 선택" << endl;
			cout << "													←,→ : 이동" << endl;
			cout << "													    X : 종료" << endl;
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
		if (survive < 10)
			textcolor(LIGHTRED, BLACK);
		else if (month == 6 && day == 14)
			textcolor(LIGHTMAGENTA, BLACK);
		else if (survive < 20)
			textcolor(BROWN, BLACK);
		else
			textcolor(LIGHTGREEN, BLACK);
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
		else cout << "\t\t\t";
		cout << "				  ┏━━━━━━━━━━━┓" << endl << "	|      수분	       " << water << "	|";
		if (Messages::cnt != 0)cout << "\t\t         ('ω')";
		else cout << "\t\t\t";
		cout << "				  ┃  S H O P";
		textcolor(GREEN, BLACK);
		cout << "♣";
		textcolor(WHITE, BLACK);
		cout << "┃" << endl << "	|      배고픔          " << food << "	|";
		if (Messages::cnt != 0)cout << "\t\t   ┏━━━━ ∪━ ∪━━━━┓";
		else cout << "\t\t\t\t";
		cout << "			  ┗━┳┳━━━━━┳┳━┛" << endl << "	|      에너지          " << energy << "	|";
		if (Messages::cnt != 0)cout << "\t\t   ┃ ＼　　　　 ／ ┃";
		else cout << "\t\t\t\t";
		cout << "			   ┏┗┛━━━━━┗┛┓" << endl << "	|   ________________________	|";
		if (Messages::cnt != 0) {
			cout << "\t\t   ┃　 ＼　";
			textcolor(LIGHTRED, BLACK);
			cout << "♡";
			textcolor(WHITE, BLACK);
			cout << " ／   ┃";
		}
		else cout << "\t\t\t\t";
		cout << "			   ┃  ┏━┓━┓  ┃" << endl << "	|				|";
		if (Messages::cnt != 0)cout << "\t\t   ┃　／ ＼＿／ ＼ ┃";
		else cout << "\t\t\t\t";
		cout << "			   ┃  ┃ ┃ ┃  ┃" << endl << "	|				|";
		if (Messages::cnt != 0)cout << "\t\t   ┗━━━━━━━━━━━━━━━┛";
		else cout << "\t\t\t\t";
		cout << "			   ┗━━┗━┛━┛━━┛" << endl << "	|   ________________________/|	|" << endl;
		cout << "	|  |			     |	|";
		if (Messages::cnt != 0)cout << "\t\t      메세지 도착!!";
		else cout << "\t\t\t\t";
		if (survive < 10) cout << endl << "	|  | " << survive << "일차,                  |	|" << endl;
		else if (survive < 100) cout << endl << "	|  | " << survive << "일차,                 |	|" << endl;
		cout << "	|  | 현재역은 ";
		textcolor(LIGHTGREEN, BLACK);
		cout << map[position];
		textcolor(WHITE, BLACK);
		cout << "입니다.  |	|" << endl;
		cout << "	|  |_________________________|	|							    [1] 취침 하기" << endl;
		cout << "	|				|							    [2] 문자 읽기" << endl;
		cout << "	|				|							    [3] 상점 가기" << endl;
		cout << "	|-------------------------------|							    [Q] 퀘스트보기" << endl;
		cout << "	|	        ○		|							    [W] 지도 열기" << endl;
		cout << "	|_______________________________|							    [E] 가방 열기" << endl;
		char check;
		do {
			check = tolower(_getch());
		} while (check != '1' && check != '2' && check != '3' && check != 'q' && check != 'w' && check != 'e');
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
		energy += 30;
		// 에너지 증가
		if (energy > 100) energy = 100;
		// 상점 초기화
		s_cnt = 0;
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
		textcolor(LIGHTGREEN, BLACK);
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
		if ((cnt1 <= 5 || cnt2 <= 5) && state != 2 && k != position) {
			int yn; system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
			cout << map << " 으로 이동하시겠습니까?" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "													Y : 시작" << endl;
			cout << "													N : 취소" << endl;
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
				// 상점 초기화
				s_cnt = 0;
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
				textcolor(LIGHTGREEN, BLACK);
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
				if (life) {
					if (position == 3) {
						if (story == 0) {
							for (int i = 0; i < 7; i++)
								if (i == 1 || i == 6)
									Talk(talk1[i], "  나  ");
								else
									Talk(talk1[i], "고영희");
							story++;
						}
						QuestAdd(1, "캣잎");
					}
					if (position == 2) {
						if (story == 1) {
							for (int i = 0; i < 7; i++)
								if (i == 1 || i == 3 || i == 6)
									Talk(talk2[i], "  나  ");
								else
									Talk(talk2[i], "나  비");
							story++;
						}
						QuestAdd(2, "리본");
					}
					if (position == 10) {
						if (story == 2) {
							for (int i = 0; i < 8; i++)
								if (i == 3 || i == 7)
									Talk(talk3[i], "  나  ");
								else
									Talk(talk3[i], "Mr.Ham");
							story++;
						}
						QuestAdd(3, "치즈");
					}
					if (position == 13) {
						if (story == 3) {
							for (int i = 0; i < 8; i++)
								if (i == 3 || i == 7)
									Talk(talk2[i], "  나  ");
								else
									Talk(talk2[i], "김덕구");
							story++;
						}
						QuestAdd(4, "도서");
					}
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
			Map();
		}
		else if (state == 2) {
			cout << "현재 이동하기를 사용할 수 있는 상태가 아닙니다." << endl;
			system("pause");
			system("cls");
			Map();
		}
		else {
			cout << "한 번에 이동할 수 있는 역의 범위를 넘어갔습니다. [이동 불가]" << endl;
			system("pause");
			system("cls");
			Map();
		}
	}
	bool DieCheck() {
		bool answer = true;
		if (water <= 10 || food <= 10 || energy <= 10) {		// 90% 확률로 사망
			if ((rand() % 99 + 1) <= 90) answer = false;
			state = 3;
		}
		else if (water <= 20 || food <= 20 || energy <= 20) {	// 50% 확률로 사망
			if ((rand() % 99 + 1) <= 50) answer = false;
			state = 3;
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
				case 3: item[i] = new Leaf();
					break;
				case 4: item[i] = new Ribbon();
					break;
				case 5: item[i] = new Cheese();
					break;
				case 6: item[i] = new Book();
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
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
		cout << item[key]->getName() << "아이템 사용하시겠습니까?" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "													Y : 사용" << endl;
		cout << "													N : 취소" << endl;
		int k;
		do {
			k = toupper(_getch());
		} while (k != 89 && k != 78);
		if (k == 89) {
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
			switch (item[key]->getId()) {
			case 1:
				cout << "\t              수분 25 상승" << endl;
				water += 25;
				if (water >= 100) water = 100;
				break;
			case 2:
				cout << "\t              배고픔 30 상승" << endl;
				food += 30;
				if (food >= 100) food = 100;
				break;
			case 3:
				cout << "\t왠지 모르게 기분이 좋아진다.\n\n";
				Sleep(1000);
				cout << "\t\t\t\t\t              상태 변화 없음";
				break;
			case 4:
				cout << "\t아까보다는 조금 멋있어진 것 같다.\n\n";
				Sleep(1000);
				cout << "\t\t\t\t\t              상태 변화 없음";
				break;
			case 5:
				cout << "\t상성이 맞지않는 음식 섭취, 배고픔 -10";
				food -= 10;
				break;
			case 6:
				cout << "\t평소에 하지 않은 행동, 에너지 -10";
				energy -= 10;
				break;
			}
			delete item[key];
			bagpull[key] = false;
			DieCheck();
			Sleep(2000);
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
					key = 0;
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
	void ClossShop() {
		cout << "\n\n\n\n\n\n";
		cout << "						┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout << "						┃  S H O P";
		textcolor(GREEN, BLACK);
		cout << "♣";
		textcolor(WHITE, BLACK);
		cout << "	       ┃" << endl;
		cout << "						┃         C L O S E    ┃" << endl;
		cout << "						┗━┳┳━━━━━━━━━━━━━━━━┳┳━┛" << endl;
		cout << "						  ┃┃　　 ∧＿∧　Z　┃┃" << endl;
		cout << "						  ┗┛　　 (-ω-) z　 ┗┛" << endl;
		cout << "						┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout << "						┃         	       ┃" << endl;
		cout << "						┃         	       ┃" << endl;
		cout << "						┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		cout << "\n					오늘은 더 이상 상점을 이용하실 수 없습니다." << endl;
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "													X : 돌아가기" << endl;
		int k;
		do {
			k = toupper(_getch());
		} while (k != 88);
		system("cls");
	}
	void Shop() {
		s_cnt++;
		int k = 0, key = 0; 
		bool check[4] = { true, false, false, false };
		while (k != 88) {
			cout << "							┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "							┃					보유 돈 " << money << "원	  ┃" << endl;
			cout << "							┃	   ____ 					  ┃" << endl;
			cout << "							┃	  |____|					  ┃" << endl;
			cout << "							┃	 /     ＼					  ┃" << endl;
			cout << "							┃	|   水   |		      ._, , .,, _	  ┃" << endl;
			cout << "							┃	|________|		      ( : (　   ..)	  ┃" << endl;
			cout << "		┏━━━━━━━━━━━━━━━━━━━━━━┓		┃	[        ]		      | : |  -ω- |	  ┃" << endl;
			cout << "		┃  S H O P";
			textcolor(GREEN, BLACK);
			cout << "♣";
			textcolor(WHITE, BLACK);
			cout << "           ┃		┃	[        ]		      | : |　　　 |	  ┃" << endl;
			cout << "		┃        다 팔아요~!   ┃		┃	[________]		       `' '------´	  ┃" << endl;
			cout << "		┗━┳┳━━━━━━━━━━━━━━━━┳┳━┛		┃							  ┃" << endl;
			cout << "		  ┃┃　　 ∧＿∧　　 ┃┃			┃	 [ ";
			if (check[0]) textcolor(LIGHTGREEN, BLACK);
			cout << "생수";
			textcolor(WHITE, BLACK);
			cout << " ]			 [ ";
			if (check[1]) textcolor(LIGHTGREEN, BLACK);
			cout << "식량";
			textcolor(WHITE, BLACK);
			cout << " ]	  ┃" << endl;
			cout << "		  ┗┛　　 ('ω')　   ┗┛			┃							  ┃" << endl;
			cout << "		┏━━━━━━━━━━━━━━━━━━━━━━┓		┃    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━	  ┃" << endl;
			cout << "		┃     식량 5,000원     ┃		┃							  ┃" << endl;
			cout << "		┃     생수 4,500원     ┃		┃     ";
			textcolor(CYAN, BLACK);
			cout << "┏━━━━━━━━━━┓		      ┏━━━━━━━━━━┓	  ";
			textcolor(WHITE, BLACK);
			cout << "┃" << endl;
			cout << "		┃     히든 2,500원     ┃		┃     ";
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
			cout << "							┃	 [ ";
			if (check[2]) textcolor(LIGHTGREEN, BLACK);
			cout << "히든";
			textcolor(WHITE, BLACK);
			cout << " ]			 [ ";
			if (check[3]) textcolor(LIGHTGREEN, BLACK);
			cout << "히든";
			textcolor(WHITE, BLACK); 
			cout << " ]	  ┃" << endl;
			cout << "							┃							  ┃" << endl;
			cout << "							┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
			cout << "													Enter : 구매" << endl;
			cout << "													←,→ : 이동" << endl;
			cout << "													    X : 종료" << endl;
			// 72 Up 80 Down
			do {
				k = toupper(_getch());
			} while (k != 13 && k != 75 && k != 77 && k != 88);
			if (key != 3 && k == 77) {
				check[key] = false;
				check[++key] = true;
			}
			else if (key != 0 && k == 75) {
				check[key] = false;
				check[--key] = true;
			}
			else if (k == 13) {
				system("cls");
				int k2;
				switch (key) {
				case 0:
					cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
					cout << "생수를 구매하시겠습니까?" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "													Y : 구매" << endl;
					cout << "													N : 취소" << endl;
					do {
						k2 = toupper(_getch());
					} while (k2 != 89 && k2 != 78);
					if (k2 == 89) {
						if (ItemAdd(1) && money >= 4500) {
							money -= 4500;
							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
							cout << "생수를 구매하시겠습니까?" << endl;
							cout << "\t\t\t\t\t\t현재 보유량 : " << Water::cnt << endl;
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
							cout << "													Y : 구매" << endl;
							cout << "													N : 취소" << endl;
							Sleep(1500);
						}
						else if (money < 4500) {
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
						}
						else {
							cout << "가방 공간이 가득찼습니다. 더 이상 구매할 수 없습니다." << endl;
							system("pause");
						}
					}
					break;
				case 1:
					cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
					cout << "식량를 구매하시겠습니까?" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "													Y : 구매" << endl;
					cout << "													N : 취소" << endl;
					do {
						k2 = toupper(_getch());
					} while (k2 != 89 && k2 != 78);
					if (k2 == 89) {
						if (ItemAdd(2) && money >= 5000) {
							money -= 5000;
							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
							cout << "식량를 구매하시겠습니까?" << endl;
							cout << "\t\t\t\t\t\t현재 보유량 : " << Food::cnt << endl;
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
							cout << "													Y : 구매" << endl;
							cout << "													N : 취소" << endl;
							Sleep(1500);
						}
						else if (money < 5000) {
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
						}
						else {
							cout << "가방 공간이 가득찼습니다. 더 이상 구매할 수 없습니다." << endl;
							system("pause");
						}
					}
					break;
				case 2:
				case 3:
					cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
					cout << "랜덤을 구매하시겠습니까?" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "													Y : 구매" << endl;
					cout << "													N : 취소" << endl;
					do {
						k2 = toupper(_getch());
					} while (k2 != 89 && k2 != 78);
					if (k2 == 89) {
						if (ItemAdd(2) && money >= 2500) {
							money -= 2500;
							system("cls");
							// 랜덤 모션 구현
							Sleep(1500);
						}
						else if (money < 2500) {
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
						}
						else {
							cout << "가방 공간이 가득찼습니다. 더 이상 구매할 수 없습니다." << endl;
							system("pause");
						}
					}
					break;
				}
			}
			system("cls");
		}
		system("cls");
	}
	void QuestUse(int idx) {
		int check = 0;
		for (int i = 0; i < 12; i++) {
			if(bagpull[i])
				if (quest[idx]->getItem() == item[i]->getName())
					check++;
		}
		if (quest[idx]->getNum() <= check) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    ";
			cout << "Quest Cleear!!" << endl;
			cout << "\n\t\t\t\t\t\t    보상 : " << 5000 * quest[idx]->getNum() << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			int cnt = quest[idx]->getNum();
			for (int j = 0; j < 12; j++) {
				if (bagpull[j]) {
					if (cnt != 0 && quest[idx]->getItem() == item[j]->getName()) {
						cnt--;
						delete item[j];
						bagpull[j] = false;
					}
				}
			}
			if (story != 2 && quest[idx]->getName() == "고영희") MessageAdd("나  비	", "시간 있으면 난초역으로 와줘...");
			else if (story != 3 && quest[idx]->getName() == "나  비") MessageAdd("Mr.Ham	", "너라면 내 부탁도 들어줄 수 있겠군.\n팬지역에서 기다리고 있겠다.");
			else if (story != 4 && quest[idx]->getName() == "Mr.Ham") MessageAdd("김덕구	", "혹시 이 것 너한테도 있을까?\n나는 카라역에 있어!");
			money += 5000 * quest[idx]->getNum();
			delete quest[idx];
			q_pull[idx] = false;
			Sleep(2000);
		} else {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
			cout << "퀘스트 완료에 필요한 아이템이 부족합니다." << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			Sleep(2000);
		}
	}
	void QuestAdd(int id, string item) {
		string name;
		switch (id) {
		case 1: name = "고영희";
			break;
		case 2:  name = "나  비";
			break;
		case 3:  name = "Mr.Ham";
			break;
		case 4:  name = "김덕구";
			break;
		}
		int check = 0;
		for (int i = 0; i < Quests::cnt; i++) {
			if (q_pull[i]) {
				if (quest[i]->getName() == name)
					check++;
			}
		}
		if (check == 0) {
			for (int i = 0; i < 8; i++) {
				if (!q_pull[i]) {
					if (story >= id)
						quest[i] = new Quests(id, item, name);
					q_pull[i] = true;
					break;
				}
			}
		}
	}
	void Quest() {
		if (Quests::cnt != 0) {
			bool check[8] = { true, false, false, false, false, false, false, false };
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
							cout << "				|	" << quest[i]->getName() << " 						|" << endl;
							cout << "				|	" << quest[i]->getItem() << " : ";
							int cnt = 0;
							for (int j = 0; j < 12; j++) {
								if (bagpull[j])
									if (quest[i]->getItem() == item[j]->getName())
										cnt++;
							}
							cout << cnt << "/" << quest[i]->getNum() << "			";
							if (check[p]) textcolor(LIGHTGREEN, BLACK);
							cout << "     완료";
							textcolor(WHITE, BLACK); 
							cout << "	|" << endl;
						}
						else {
							cout << "				|	__________________________________________	|" << endl;
							cout << "				|							|		Enter : 선택" << endl;
							cout << "				|	" << quest[i]->getName() << " 				" << check[p] << "	|		↑,↓ : 이동" << endl;
							cout << "				|	" << quest[i]->getItem() << " : ";
							int cnt = 0;
							for (int j = 0; j < 12; j++) {
								if(bagpull[j])
									if (quest[i]->getItem() == item[j]->getName())
										cnt++;
							}	
							cout << cnt << "/" << quest[i]->getNum() << "			";
							if (check[p]) textcolor(LIGHTGREEN, BLACK);
							cout << "     완료";
							textcolor(WHITE, BLACK);
							cout << "	|			X : 종료" << endl;
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
				if (key != (Quests::cnt - 1) && k == 80) {
					check[key] = false;
					check[++key] = true;
				}
				else if (key != 0 && k == 72) {
					check[key] = false;
					check[--key] = true;
				}
				else if (k == 13) {
					system("cls");
					QuestUse(ps[key]);
					check[key] = false;
					key = 0;
					check[0] = true;
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
		else if (name == "나  비") {
			cout << endl;
			cout << "									　　　　  　　　　　　     .／＞　　フ" << endl;
			cout << "									　　　　  　　　　　　     |   _　 _ l" << endl;
			cout << "									　　　　  　　　　　　    ／` ミ＿Yノ" << endl;
			cout << "									　　　　  　　　　　　   /　　　  　 |" << endl;
			cout << "									　　　　  　　　　　　  /　 ＼ 　　 /" << endl;
			cout << "									　　　　  　　　　　　 │　    |　|　|" << endl;
			cout << "									　　　　  　　　　　　 ／￣|　|　|　|" << endl;
			cout << "									　　　　  　　　　　　 | (￣＼＿＼_)__)" << endl;
			cout << "									　　　　  　　　　　　 ＼二つ" << endl;
		}
		else if (name == "Mr.Ham") {
			cout << endl << endl << endl;
			cout << "						　　　　　　　　　　　  　 　 　|``--,...　　　　　``　＊ |" << endl;
			cout << "						　　　　　　　　　　　  　　  　i  ＼　　　　　　　　　 ／:;" << endl;
			cout << "						　　　　　　　　　　　  　　    ミ　　　　 　　　　　　    ミ" << endl;
			cout << "						　　　　　　　　　　　  　　   〉 　　　　●　　 　　●　　　ミ" << endl;
			cout << "						　　　　　　　　　　　  　　   ミ　 　 ``　　　人　　　　　 ミ" << endl;
			cout << "						　　　　　　　　　　　  　  　ミ :　　　　　 　　　　 　　　  ミ" << endl;
			cout << "						　　　　　　　　　　　  　  ,I:　　　　　　 つ";
			textcolor(RED, BLACK);
			cout << "▶◀";
			textcolor(WHITE, BLACK);
			cout << "⌒　　        :I," << endl;
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
		cout << "|													Enter >>	|" << endl;
		cout << "|______________________________________________________________________________________________________________________|" << endl;
		char yn;
		do {
			yn = tolower(_getch());
		} while (yn != 13); // 13은 Enter 
		system("cls");
	}
	int getSurvive() {
		return survive;
	}
	int getPlaytime() {
		return playtime;
	}
};