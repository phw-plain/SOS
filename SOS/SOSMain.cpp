#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <iomanip>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
#include "UserClass.cpp"		// User 클래스 소스 파일
#pragma comment(lib,"winmm.lib")
using namespace std;

bool User::bagpull[12] = { false, false, false, false, false, false, false, false, false, false, false, false };
int Item::cnt = 0;
int Water::cnt = 0;
int Food::cnt = 0;
void Intro();
void Rule();
void GameOver();
int Menu();
int Level();

int main() {
	User test;
	test.play();
	srand((unsigned)time(NULL));
	int num = 0;
	while (num != 3) {
		num = Menu();
		switch (num) {
		case 1: {
			system("cls");
			Intro();
			//int level = Level();
			//User u(level);
			User u;
			if (u.play()) {
				GameOver();
				system("pause");
			}
			else {
				cout << "게임 클리어" << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			system("cls");
			Rule();
			break;
		}
		}
		system("cls");
	}
}

void Intro() {
	const char* story[5];
	story[0] = "20XX년 2월 13일, 핸드폰으로 문자가 왔다.";
	story[1] = "앞으로 당신은 외부와의 연결이 끊긴 지하철에서 생존해야 합니다.";
	story[2] = "배고픔, 수분, 에너지가 일정 범위로 내려가면 당신은 사망합니다.";

	const char* story_y[1];
	story_y[0] = "Y버튼을 누르자 알수없는 빛에 휩싸였다...";

	const char* story_n[3];
	story_n[0] = "N버튼을 누르자 화면이 멈췄다...";
	story_n[1] = "핸드폰이 고장났나?";
	story_n[2] = "이것저것 누르다보니 알수없는 빛이 주위를 에워쌌다..";

	char yn;

	for (int i = 0; i < sizeof(story) / sizeof(char*); i++) {
		
		switch (i) {
		case 0: {
			cout << "\n\n\n\n\n\n\n\n\n\n\n" << "			              ";
			PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			for (int j = 0; j < strlen(story[i]); j++) {
				Sleep(50);
				cout << story[i][j];
			}
			PlaySound(NULL, 0, 0);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "												Enter : 다음 장면으로" << endl;
			cout << "												S : 스킵" << endl;
			do {
				yn = tolower(_getch());
			} while (yn != 13 && yn != 's'); // 13은 Enter 

			break;
		}
		case 1: {
			PlaySound(TEXT("alarm1.wav"), 0, SND_FILENAME | SND_ASYNC);
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
			Sleep(2000);
			system("cls");
			PlaySound(TEXT("alarm1.wav"), 0, SND_FILENAME | SND_ASYNC);
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
			Sleep(2000);
			PlaySound(NULL, 0, 0);
			cout << "\n\n";
			cout << "												Y, N : 다음 장면으로" << endl;
			cout << "												S : 스킵" << endl;
			do {
				yn = tolower(_getch());
			} while (yn != 's' && yn != 'y' && yn != 'n');

			break;
		}
		case 2: {
			PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			if (yn == 'y') {
				cout << "\n\n\n\n\n\n\n\n\n\n\n" << "			              ";
				for (int j = 0; j < strlen(story_y[0]); j++) {
					Sleep(50);
					cout << story_y[0][j];
				}
				PlaySound(NULL, 0, 0);
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << "												Enter : 다음 장면으로" << endl;
				cout << "												S : 스킵" << endl;
				do {
					yn = tolower(_getch());
				} while (yn != 13 && yn != 's');
			}
			else {
				for (int k = 0; k < sizeof(story_n) / sizeof(char*); k++) {
					cout << "\n\n\n\n\n\n\n\n\n\n\n" << "			              ";
					PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
					for (int j = 0; j < strlen(story_n[k]); j++) {
						Sleep(50);
						cout << story_n[k][j];
					}
					if (k < sizeof(story_n) / sizeof(char*)) {
						PlaySound(NULL, 0, 0);
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						cout << "												Enter : 다음 장면으로" << endl;
						cout << "												S : 스킵" << endl;
						do {
							yn = tolower(_getch());
						} while (yn != 13 && yn != 's');

						if (yn == 's') break;
						system("cls");
					}
				}
			}
			break;
		}
		case 3: case 4: {
			cout << "\n\n\n\n\n\n\n\n\n\n\n" << "			  ";
			PlaySound(TEXT("typing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			for (int j = 0; j < strlen(story[i - 2]); j++) {
				Sleep(50);
				cout << story[i - 2][j];
			}
			PlaySound(NULL, 0, 0);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "												Enter : 다음 장면으로" << endl;
			cout << "												S : 스킵" << endl;
			do {
				yn = tolower(_getch());
			} while (yn != 13 && yn != 's');

			break;
		}
		}
		if (yn == 's') break;
		system("cls");
	}
	system("cls");
}
int Menu() {
	char check[3] = { '>', ' ', ' ' };
	int key = 0, k = 0;
	PlaySound(TEXT("main.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (k != 13) { // 72 80
		system("cls");
		textcolor(LIGHTGREEN, BLACK);
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
		textcolor(RED, BLACK);
		cout << endl << endl << "					       survival of subway" << endl << endl << endl;
		textcolor(LIGHTGREEN, BLACK);
		cout << "					        ________________" << endl;
		cout << "					       		" << endl;
		cout << "					         " << check[0] << "  게임 시작	" << endl;
		cout << "					         " << check[1] << "  게임 방법	" << endl;
		cout << "					         " << check[2] << "  게임 종료	" << endl;
		cout << "					        ________________" << endl;
		do {
			k = _getch();
		} while (k != 13 && k != 72 && k != 80);
		if (key != 2 && k == 80) {
			check[key] = ' ';
			check[++key] = '>';
		}
		else if (key != 0 && k == 72) {
			check[key] = ' ';
			check[--key] = '>';
		}
		textcolor(WHITE, BLACK);
	}
	int num;
	for (int i = 0; i < 3; i++) {
		if (check[i] == '>') num = i + 1;
	}
	PlaySound(NULL, 0, 0);
	return num;
}

//int Level() {
//	int level;
//	cout << "\n\n\n\n\n\n\n";
//	cout << "					           난이도 설정 " << endl;
//	cout << "					                   " << endl;
//	cout << "					            1. 쉬움    " << endl;
//	cout << "					            2. 보통    " << endl;
//	cout << "					            3. 어려움  " << endl;
//	cout << "					                   " << endl;
//	cout << "\n\n\n					         ☞  ";
//	cin >> level;
//	system("cls");
//	return level;
//}

void Rule() {
	cout << "		== 게임 플레이 방법 ==" << endl;
	cout << endl;
	cout << "▶ 배고픔과 수분 에너지가 떨어지지 않게 잘 유지해야 합니다." << endl;
	cout << "▶ 위 세가지는 쾌적, 양호, 최악으로 분류됩니다." << endl;
	cout << "▶ 상태가 양호인 경우에는 확률적으로 이동하기 기능을 사용할 수 없습니다." << endl;
	cout << "▶ 상태가 최악인 경우에는 확률적으로 사망하며 게임 오버 됩니다." << endl;
	cout << endl;
	cout << "<이동하기>" << endl;
	cout << "▶ 이동하기를 통해서 다른 역으로 이동할 수 있습니다." << endl;
	cout << "▶ 난이도에 따라서 역을 이동할 수 있는 간격이 정해집니다." << endl;
	cout << "▶ 한 번 방문한 역은 다시 돌아갈 수 없습니다." << endl;
	cout << endl;
	cout << "<조작키>" << endl;
	cout << "Enter, 다음 장면으로 넘어갈 수 있다." << endl;
	cout << "S, 인트로 진행 도중 스킵할 수 있다." << endl;
	cout << "B, 가방 : 아이템을 확인할 수 있다." << endl;
	cout << "M, 지도 : 지하철 노선을 볼 수 있다." << endl;
	_getch();
}

void GameOver() {
	textcolor(LIGHTGREEN, BLACK);
	cout << endl << endl;
	cout << "               ■■■■■■■■          ■■■■■	      ■■    ■■         ■■■■■■■■" << endl;
	cout << "               ■                     ■            ■      ■     ■     ■       ■" << endl;
	cout << "               ■                     ■            ■      ■     ■     ■       ■" << endl;
	cout << "               ■      ■■■■       ■■■■■■■■      ■     ■     ■       ■■■■■■■■" << endl;
	cout << "               ■            ■       ■            ■      ■     ■     ■       ■" << endl;
	cout << "               ■            ■       ■            ■      ■     ■     ■       ■" << endl;
	cout << "               ■■■■■■■■       ■            ■      ■     ■     ■       ■■■■■■■■" << endl;
	cout << endl << endl;
	cout << "               ■■■■■■■■       ■            ■      ■■■■■■■■       ■■■■■■■" << endl;
	cout << "               ■            ■       ■            ■      ■                     ■            ■" << endl;
	cout << "               ■            ■       ■            ■      ■                     ■            ■" << endl;
	cout << "               ■            ■       ■            ■      ■■■■■■■■       ■■■■■■■" << endl;
	cout << "               ■            ■       ■            ■      ■                     ■            ■" << endl;
	cout << "               ■            ■         ■        ■        ■                     ■            ■" << endl;
	cout << "               ■■■■■■■■           ■■■■          ■■■■■■■■       ■            ■" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	textcolor(WHITE, BLACK);
}