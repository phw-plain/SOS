#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <iomanip>
#pragma comment(lib,"winmm.lib")
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
		while(day > 0){
			Phone();
			char check = tolower(_getch());
			system("cls");
			switch(check){
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
	}
	void Phone() {
		cout << "	   << 핸드폰 >>" << endl;
		cout << "_________________________________" << endl;
		cout << "|	   			|" << endl;
		cout << "|-------------------------------|" << endl;
		cout << "|	     2052년  2월 13일	|" << endl;
		cout << "|				|" << endl;
		cout << "|    ________       ________ 	|" << endl;
		cout << "|   |        |     |	    |	|" << endl;
		cout << "|   |  가방  |     |  지도  |	|" << endl;
		cout << "|   |________|     |________|	|" << endl;
		cout << "|				|" << endl;
		cout << "|				|" << endl;
		cout << "|    ________			|" << endl;
		cout << "|   |        |			|" << endl;
		cout << "|   |  상태  |			|" << endl;
		cout << "|   |________|			|" << endl;
		cout << "|				|" << endl;
		cout << "|				|" << endl;
		cout << "|   ________________________/|	|" << endl;
		cout << "|  |			     |	|" << endl;
		cout << "|  | 1일차,                  |	|" << endl;
		cout << "|  | 언제쯤 나갈 수 있을까.. |	|" << endl;
		cout << "|  |_________________________|	|" << endl;
		cout << "|				|" << endl;
		cout << "|				|" << endl;
		cout << "|-------------------------------|" << endl;
		cout << "|	        ○		|" << endl;
		cout << "|_______________________________|" << endl;
		cout << endl << "1. 잠자기" << endl;
		cout << "2. 이동하기" << endl;

	}
};

int User::cnt = 0;

void Intro();
int Menu();
int Level();

int main() {
	int num = 0;
	while(num != 3) {
		num = Menu();
		switch (num){
		case 1: {
			system("cls");
			Intro();
			int level = Level();
			User u(level);
			u.play();
			break;
		}
		case 2: break;
		case 3: break;
		default: cout << "\n						 << 입력 오류 >>\n" << endl;
			cout << "					       처음으로 돌아갑니다.\n" << endl;
			cout << "					      ";
			for (int i = 0; i < 5; i++) {
				Sleep(1000);
				cout << " · ";
			}
			break;
		}
		system("cls");
	}
}

void Intro() {
	const char* story[11];
	story[0] = "2052년 2월 13일, 그날의 퇴근길은 유독 지하철에 사람이 없었던 날이었다.";
	story[1] = "이상함을 느끼는 것도 잠시 ..."; 
	story[2] = "커다란 굉음과 함께 지하철 크게 흔들렸다.";
	story[3] = "얼마가지 않아 주위는 고요해지고 지하철은 더 이상 움직이지 않았다.";
	story[4] = "나는 비상 전화로 무슨 일인지 알아보려 했지만 기관사는 대답하지 않았다.";
	story[5] = "전화를 내려놓고 기관실로 향했다.";
	story[6] = "도착한 곳은 원래는 기관실이 있어야 하는 뻥 트인 공간이었다.";
	story[7] = "외부와는 연락이 되지 않는다.";
	story[8] = "간신히 발견한 ㅁㅁ역은 밖으로 나갈 수 없게 붕괴되어 있었다.";
	story[9] = "외부에서 누군가 발견할 때 까지 이곳에서 버텨야 한다.";
	story[10] = "금방 나갈 수 있겠지...";

	for(int i = 0; i < sizeof(story)/sizeof(char*); i++){
		PlaySound(TEXT("Typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
		cout << "\n\n\n\n\n" << "			  ";
		for (int j = 0; j < strlen(story[i]); j++) {
			Sleep(50);
			cout << story[i][j];
		}
		PlaySound(NULL, 0, 0);
		if (tolower(_getch()) == 's') break;
		system("cls");
	}
	system("cls");
}
int Menu() {
	PlaySound(TEXT("main.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << endl << endl << endl;
	cout << "	■■■■■■■■			■■■■■■■■			■■■■■■■■" << endl;
	cout << "	■■■■■■■■			■■■■■■■■			■■■■■■■■" << endl;
	cout << "	■■					■■	    ■■			■■			" << endl;
	cout << "	■■					■■	    ■■			■■			" << endl;
	cout << "	■■■■■■■■			■■	    ■■			■■■■■■■■" << endl;
	cout << "	■■■■■■■■			■■	    ■■			■■■■■■■■" << endl;
	cout << "		    ■■			■■	    ■■				    ■■" << endl;
	cout << "		    ■■			■■	    ■■				    ■■" << endl;
	cout << "	■■■■■■■■			■■■■■■■■			■■■■■■■■" << endl;
	cout << "	■■■■■■■■			■■■■■■■■			■■■■■■■■" << endl;



	cout << endl << endl << "					       survival of subway" << endl << endl << endl;
	cout << "					       ------------------" << endl;
	cout << "					       |		|" << endl;
	cout << "					       | 1. 게임 시작	|" << endl;
	cout << "					       | 2. 게임 방법	|" << endl;
	cout << "					       | 3. 게임 종료	|" << endl;
	cout << "					       |		|" << endl;
	cout << "					       ------------------" << endl;
	cout << endl << endl << "					       ☞ ";
	int num;
	cin >> num;
	PlaySound(NULL, 0, 0);
	return num;
}

int Level() {
	int level;
	cout << "\n\n\n\n\n";
	cout << "					   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	cout << "					   ▒              ▒" << endl;
	cout << "					   ▒  난이도 설정 ▒" << endl;
	cout << "					   ▒              ▒" << endl;
	cout << "					   ▒   1. 쉬움    ▒" << endl;
	cout << "					   ▒   2. 보통    ▒" << endl;
	cout << "					   ▒   3. 어려움  ▒" << endl;
	cout << "					   ▒              ▒" << endl;
	cout << "					   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl << endl;
	cout << endl << "					       ☞  ";
	cin >> level;
	system("cls");
	return level;
}