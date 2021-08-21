﻿#define _CRT_SECURE_NO_WARNINGS
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
			::system("cls");
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
		cout << "|	     20XX년  2월 13일	|" << endl;
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
	const char* story[5];
	story[0] = "20XX년 2월 13일, 핸드폰으로 문자가 왔다.";
	story[1] = "앞으로 당신은 외부와의 연결이 끊긴 지하철에서 생존해야 합니다."; 
	story[2] = "배고픔, 수분, 에너지가 일정 범위로 내려가면 당신은 사망합니다.";

	char yn;

	for(int i = 0; i < sizeof(story)/sizeof(char*); i++){
		switch (i) {
			case 0: {
				cout << "\n\n\n\n\n" << "			  ";
				PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				for (int j = 0; j < strlen(story[i]); j++) {
					Sleep(50);
					cout << story[i][j];
				}
				break;
			}
			case 1: {
				PlaySound(TEXT("alarm1"), 0, SND_FILENAME | SND_ASYNC);
				cout << "_________________________________" << endl;
				cout << "| SOS   			|" << endl;
				cout << "|-------------------------------|" << endl;
				cout << "|  |＼_______________________	|" << endl;
				cout << "|  | 심심한 당신을 위해	     |	|" << endl;
				cout << "|  | 준비한 이색 체험!!	     |	|" << endl;
				cout << "|  |_________________________|	|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|-------------------------------|" << endl;
				cout << "|	        ○		|" << endl;
				cout << "|_______________________________|" << endl;
				Sleep(3000);
				::system("cls");
				PlaySound(TEXT("alarm1"), 0, SND_FILENAME | SND_ASYNC);
				cout << "_________________________________" << endl;
				cout << "| SOS   			|" << endl;
				cout << "|-------------------------------|" << endl;
				cout << "|  |＼_______________________	|" << endl;
				cout << "|  | 심심한 당신을 위해	     |	|" << endl;
				cout << "|  | 준비한 이색 체험!!	     |	|" << endl;
				cout << "|  |_________________________|	|" << endl;
				cout << "|				|" << endl;
				cout << "|  |＼_______________________	|" << endl;
				cout << "|  | 지금 바로 참가	     |	|" << endl;
				cout << "|  | 하시겠습니까?(Y/N)      |	|" << endl;
				cout << "|  |_________________________|	|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|				|" << endl;
				cout << "|-------------------------------|" << endl;
				cout << "|	        ○		|" << endl;
				cout << "|_______________________________|" << endl;
				yn = tolower(_getch());
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				for (int j = 0; j < strlen(story[i]); j++) {
					Sleep(25);
					cout << story[i][j];
				}
				break;
			}
		}
		PlaySound(NULL, 0, 0);
		if (tolower(_getch()) == 's') break;
		::system("cls");
	}
	::system("cls");
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
	::system("cls");
	return level;
}