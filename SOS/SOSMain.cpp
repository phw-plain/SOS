#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <iomanip>
#include <fstream>
#include <string>
#include "TextColor.h"		// 텍스트 컬러 소스 파일
#include "UserClass.cpp"		// User 클래스 소스 파일
#pragma comment(lib,"winmm.lib")
using namespace std;

#define MAX_DIGITS 10
bool User::bagpull[12] = { false, false, false, false, false, false, false, false, false, false, false, false };
bool User::m_pull[8] = { false, false, false, false, false, false, false, false };
bool User::q_pull[8] = { false, false, false, false };
int Water::cnt = 0;
int Food::cnt = 0;
int Leaf::cnt = 0;
int Ribbon::cnt = 0;
int Cheese::cnt = 0;
int Book::cnt = 0;
int Messages::cnt = 0;
int Quests::cnt = 0;
void Intro();
void Rule();
void Rank();
void GameOver(User a);
void GameSad(User a);
void GameClear(User a);
int Menu();

int main() {
	// system("mode con:cols=150 lines=40");
	system("mode con:cols=120 lines=30");
	system("title Survival Of Subway");
	srand((unsigned)time(NULL));
	int num = 0;
	PlaySound(TEXT("main.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (num != 4) {
		num = Menu();
		switch (num) {
		case 1: {
			PlaySound(NULL, 0, 0);
			system("cls");
			Intro();
			User *u = new User();
			if (u->play()) {
				GameOver(*u);
			}
			else {
				GameClear(*u);
			}
			delete u;
			break;
			PlaySound(TEXT("main.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		case 2: {
			system("cls");
			Rule();
			break;
		}
		case 3: {
			system("cls");
			Rank();
			break;
		}
		}
		system("cls");
	}
}

void Intro() {
	const char* story[5];
	story[0] = "20XX년 5월 25일, 핸드폰으로 문자가 왔다.";
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
	char check[4] = { '>', ' ', ' ', ' ' };
	int key = 0, k = 0;
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
		cout << "					         " << check[2] << "  게임 랭킹	" << endl;
		cout << "					         " << check[3] << "  게임 종료	" << endl;
		cout << "					        ________________" << endl;
		do {
			k = _getch();
		} while (k != 13 && k != 72 && k != 80);
		if (key != 3 && k == 80) {
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
	for (int i = 0; i < 4; i++) {
		if (check[i] == '>') num = i + 1;
	}
	return num;
}

void Rule() {
	cout << "		== 게임 플레이 방법 ==" << endl;
	cout << endl;
	cout << "▶ 배고픔과 수분 에너지가 떨어지지 않게 잘 유지해야 합니다." << endl;
	cout << "▶ 위 세가지는 쾌적(초록), 위험(노랑), 최악(빨강)으로 분류됩니다." << endl;
	cout << "▶ 상태가 쾌적이 아닌 경우에는 이동하기 기능을 사용할 수 없습니다." << endl;
	cout << "▶ 상태가 위험, 최악인 경우 확률적으로 사망하며 게임 오버 됩니다." << endl;
	cout << endl;
	cout << "<이동하기>" << endl;
	cout << "▶ 이동하기를 통해서 다른 역으로 이동할 수 있습니다." << endl;
	cout << "▶ 한번에 5개의 역을 이동할 수 있습니다." << endl;
	cout << "▶ 특정 역에 도착할 경우 퀘스트를 받을 수 있습니다." << endl;
	cout << endl;
	cout << "<SHOP>" << endl;
	cout << "▶ 생존하기와 퀘스트에 필요한 물품을 구매할 수 있습니다." << endl;
	cout << endl;
	cout << "<조작키>" << endl;
	cout << "Enter, 다음 장면으로 넘어갈 수 있다." << endl;
	cout << "S, 인트로 진행 도중 스킵할 수 있다." << endl;
	cout << "1, 취침 하기" << endl;
	cout << "2, 문자 읽기" << endl;
	cout << "3, 상점 가기" << endl;
	cout << "Q, 퀘스트 보기" << endl;
	cout << "W, 지도 열기"  << endl;
	cout << "E, 가방 열기" << endl;
	_getch();
}
void Rank() {
	textcolor(LIGHTGREEN, BLACK);
	cout << endl << endl << endl;
	cout << "			■■■■■■          ■■■■■        ■■        ■      ■          ■" << endl;
	cout << "			■          ■      ■          ■      ■  ■      ■      ■          ■" << endl;
	cout << "			■          ■      ■          ■      ■   ■     ■      ■        ■" << endl;
	cout << "			■■■■■■        ■■■■■■■      ■    ■    ■      ■■■■■" << endl;
	cout << "			■          ■      ■          ■      ■     ■   ■      ■        ■" << endl;
	cout << "			■          ■      ■          ■      ■      ■  ■      ■          ■" << endl;
	cout << "			■          ■      ■          ■      ■        ■■      ■          ■" << endl;
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t     __________________________________\n\n";
	// 랭킹 계산
	ifstream fin("Jumsu.txt");
	if (!fin) {
		cout << "파일 오픈 실패" << endl;
		exit(1);
	}
	string name[11];
	int score[11];
	int rank[11];
	score[0] = 0;
	for (int i = 0; !fin.eof(); i++) {
		fin >> name[i] >> score[i];
	}
	for (int i = 0; i < 11; i++) {
		rank[i] = 0;
		if (score[i] < 0) {
			rank[i] = -1;
			continue;
		}
		for (int j = 0; j < 11; j++) {
			if (score[j] < 0) continue;
			if (score[i] > score[j]) {
				rank[i]++;
			}
		}
	}
	int cnt = 1, m, s;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (score[i] < 0) continue;
			if (rank[j] == i) {
				switch (cnt){
				case 1:	textcolor(LIGHTBLUE, BLACK); break;
				case 2:	textcolor(CYAN, BLACK); break;
				case 3:	textcolor(LIGHTCYAN, BLACK); break;
				default:textcolor(DARKGRAY, BLACK); break;
				}
				cout << "\t\t\t\t\t\t" << cnt++ << ".\t" << name[j];
				if (name[j].length() <= 6) cout << "\t";
				cout << "\t";
				s = score[j] % 60;
				m = score[j] / 60;
				if (m > 10) cout << m << "분 ";
				else if(m != 0) cout << " " << m << "분 ";
				if (s != 0) cout << s;
				else  cout << "00";
				cout << "초" << endl;
			}
		}
	}
	textcolor(LIGHTGREEN, BLACK);
	cout << "\n\t\t\t\t\t     __________________________________\n\n";
	textcolor(WHITE, BLACK);
	fin.close();
	// 게임 기록 저장
	ofstream fout("Jumsu.txt");
	if (!fout) {
		cout << "파일 오픈 실패" << endl;
		exit(1);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			if (score[i] < 0) continue;
			if (rank[j] == i) {
				fout << name[j] << " " << score[j] << endl;
			}
		}
	}
	fout.close();
	_getch();
	system("cls");
}
void GameOver(User a) {
	textcolor(RED, BLACK);
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
	textcolor(WHITE, BLACK);
	cout << endl << endl;
	cout << "               생존        : " << a.getSurvive() << "일" << endl << endl;
	cout << "               플레이 타임 : ";
	int m, s;
	s = a.getPlaytime() % 60;
	m = a.getPlaytime() / 60;
	if (m > 10) cout << m << "분 ";
	else if (m != 0) cout << " " << m << "분 ";
	if (s != 0) cout << s;
	else  cout << "00";
	cout << "초" << endl << endl;
	cout << endl << endl << endl << endl << endl;
	system("pause");
	system("cls");
}
void GameClear(User a) {
	textcolor(LIGHTGREEN, BLACK);
	cout << endl << endl;
	cout << "               ■■■■■■■■         ■■■■■           ■■    ■■         ■■■■■■■" << endl;
	cout << "               ■                     ■          ■       ■     ■     ■       ■" << endl;
	cout << "               ■                     ■          ■       ■     ■     ■       ■" << endl;
	cout << "               ■      ■■■■       ■■■■■■■       ■     ■     ■       ■■■■■■■" << endl;
	cout << "               ■            ■       ■          ■       ■     ■     ■       ■" << endl;
	cout << "               ■            ■       ■          ■       ■     ■     ■       ■" << endl;
	cout << "               ■■■■■■■■       ■          ■       ■     ■     ■       ■■■■■■■" << endl;
	cout << endl << endl;
	cout << "               ■■■■■■■   ■               ■■■■■■■     ■■■■■     ■■■■■■" << endl;
	cout << "               ■               ■               ■               ■          ■   ■          ■" << endl;
	cout << "               ■               ■               ■               ■          ■   ■          ■" << endl;
	cout << "               ■               ■               ■■■■■■■   ■■■■■■■   ■■■■■■" << endl;
	cout << "               ■               ■               ■               ■          ■   ■          ■" << endl;
	cout << "               ■               ■               ■               ■          ■   ■          ■" << endl;
	cout << "               ■■■■■■■   ■■■■■■■   ■■■■■■■   ■          ■   ■          ■" << endl;
	textcolor(WHITE, BLACK);
	cout << endl << endl;
	cout << "               생존        : " << a.getSurvive() << "일" << endl << endl;
	cout << "               플레이 타임 : ";
	int m, s;
	s = a.getPlaytime() % 60;
	m = a.getPlaytime() / 60;
	if (m > 10) cout << m << "분 ";
	else if (m != 0) cout << " " << m << "분 ";
	if (s != 0) cout << s;
	else  cout << "00";
	cout << "초" << endl << endl;
	cout << "               이름 입력   : ";
	char username[10];
	cin >> username;
	cout << endl << endl << endl << endl << endl;
	// 게임 기록 저장
	ofstream fout("Jumsu.txt", ios::app);
	if (!fout) {
		cout << "파일 오픈 실패" << endl;
		exit(1);
	}
	char name[20];
	int score;
	cin >> name;
	score = a.getPlaytime();
	fout << name << " " << score << endl;
	fout.close();
	system("pause");
	system("cls");
}
void GameSad (User a) {
	textcolor(CYAN, BLACK);
	cout << endl << endl; 
	cout << "               ■■■■■■■      ■■■■■■■      ■■■■■■" << endl;
	cout << "               ■                  ■          ■      ■          ■" << endl;
	cout << "               ■                  ■          ■      ■          ■" << endl;
	cout << "               ■■■■■■■      ■■■■■■■      ■          ■" << endl;
	cout << "                           ■      ■          ■      ■          ■" << endl;
	cout << "                           ■      ■          ■      ■          ■" << endl;
	cout << "               ■■■■■■■      ■          ■      ■■■■■■" << endl;
	cout << endl << endl;
	cout << "               ■■■■■■■    ■        ■■    ■■■■■■     ■■■■■■    ■       ■■    ■■■■■■■" << endl;
	cout << "               ■                ■       ■ ■    ■          ■       ■■        ■      ■ ■    ■" << endl;
	cout << "               ■                ■     ■   ■    ■          ■       ■■        ■     ■  ■    ■" << endl;
	cout << "               ■■■■■■■    ■    ■    ■    ■          ■       ■■        ■    ■   ■    ■    ■■■■" << endl;
	cout << "               ■                ■   ■     ■    ■          ■       ■■        ■   ■    ■    ■          ■" << endl;
	cout << "               ■                ■  ■      ■    ■          ■       ■■        ■  ■     ■    ■          ■" << endl;
	cout << "               ■■■■■■■    ■■        ■    ■■■■■■     ■■■■■■    ■■       ■    ■■■■■■■" << endl;
	textcolor(WHITE, BLACK);
	cout << endl << endl;
	cout << "               생존 : " << a.getSurvive() << "일" << endl << endl;
	cout << "               플레이 타임 : " << a.getPlaytime() << "초" << endl << endl;
	cout << "               => 클리어 조건을 만족하지 못하였습니다.";
	cout << endl << endl << endl << endl;
	system("pause");
	system("cls");
}