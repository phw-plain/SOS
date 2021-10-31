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
	// 파일 입출력
	//FILE* pFile = fopen("Jumsu.txt", "r");
	// 파일이 존재하지 않는 경우


	//char str[50];
	//fgets(str, 50, pFile);
	//fclose(pFile);
	//cout << str << endl;
	

	//ifstream write("Jumsu.txt");
	//ofstream read("Jumsu.txt");

	//// 파일이 없는 경우 새로 파일 생성
	//if (write.fail()) {
	//	ofstream WriteFile("Jumsu.txt");
	//}
	//ofstream WriteFile("Jumsu.txt"); // 파일 생성
	//WriteFile << "test	300" << endl;
	//WriteFile.close();
	//string Jumsu; // 파일 내용
	//ifstream ReadFile("Jumsu.txt");
	//cout << "현재 점수 : ";
	//while (getline(ReadFile, Jumsu)) {
	//	cout << Jumsu << endl; // 파일 라인 단위로 출력

	//}
	/*system("pause");
	system("cls");*/

	/*User test;
	if (test.play()) {
		GameOver(test);
	}
	else {
		GameClear(test);
	}*/
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
	cout << "▶ 위 세가지는 쾌적(초록), 양호(노랑), 최악(빨강)으로 분류됩니다." << endl;
	cout << "▶ 상태가 최악인 경우에는 이동하기 기능을 사용할 수 없습니다." << endl;
	cout << "▶ 또한 확률적으로 사망하며 게임 오버 됩니다." << endl;
	cout << endl;
	cout << "<이동하기>" << endl;
	cout << "▶ 이동하기를 통해서 다른 역으로 이동할 수 있습니다." << endl;
	cout << "▶ 난이도에 따라서 역을 이동할 수 있는 간격이 정해집니다." << endl;
	cout << "▶ 한 번 방문한 역은 다시 돌아갈 수 없습니다." << endl;
	cout << endl;
	cout << "<조작키>" << endl;
	cout << "Enter, 다음 장면으로 넘어갈 수 있다." << endl;
	cout << "S, 인트로 진행 도중 스킵할 수 있다." << endl;
	cout << "1, 취침하기 : 다음날로 넘어갈 수 있다." << endl;
	cout << "2, 문자보기 : 도착한 메세지를 확인할 수 있다." << endl;
	cout << "Q, 가방 : 아이템을 확인할 수 있다." << endl;
	cout << "W, 지도 : 지하철 노선을 볼 수 있다." << endl;
	_getch();
}

void Rank() {
	textcolor(LIGHTGREEN, BLACK);
	cout << endl << endl << endl;
	cout << "		   ■■■■■■          ■■■■■        ■■        ■      ■          ■" << endl;
	cout << "		   ■          ■      ■          ■      ■  ■      ■      ■          ■" << endl;
	cout << "		   ■          ■      ■          ■      ■   ■     ■      ■        ■" << endl;
	cout << "		   ■■■■■■        ■■■■■■■      ■    ■    ■      ■■■■■" << endl;
	cout << "		   ■          ■      ■          ■      ■     ■   ■      ■        ■" << endl;
	cout << "		   ■          ■      ■          ■      ■      ■  ■      ■          ■" << endl;
	cout << "		   ■          ■      ■          ■      ■        ■■      ■          ■" << endl;
	cout << endl << endl << endl;
	cout << "					     ________________________" << endl;
	cout << "					       		" << endl;
	// 랭킹 계산
	FILE* pFile = fopen("Jumsu.txt", "r");
	int cnt = -1;
	int rank[10][2];
	char* name[10];
	char arr[10][100];
	int i = 0;
	while (true)
	{
		char* pStr = fgets(arr[i++], 100, pFile);
		cnt++;
		if (pStr == NULL) {
			break;
		}
		strcpy(arr[i], pStr);
	}
	for (i = 0; i < cnt; i++) {
		char* temp = strtok(arr[i], " ");
		name[i] = temp;
		temp = strtok(NULL, " ");
		rank[i][0] = i+1;
		rank[i][1] = atoi(temp);
	}
	for (i = 0; i < cnt - 1; i++) {
		for (int j = 0; j < cnt; j++) {
			if (rank[i][1] > rank[j][1]) {
				int temp = rank[i][0];
				rank[i][0] = rank[j][0];
				rank[j][0] = temp;
			}
		}
	}
	for (i = cnt-1; i >= 0; i--) {
		cout << cnt - i << ".   " << name[i] << "\t" << rank[rank[i][0]-1][1] << endl;
	}
	cout << "\n					     ________________________" << endl;
	textcolor(WHITE, BLACK);
	system("pause");
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
	cout << "               플레이 타임 : " << a.getPlaytime() << "초" << endl << endl;
	cout << endl << endl << endl << endl << endl;
	system("pause");
	system("cls");
}
void GameClear (User a) {
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
	cout << "               플레이 타임 : " << a.getPlaytime() << "초" << endl << endl;
	cout << "               이름 입력   : ";
	char username[10];
	cin >> username;
	cout << endl << endl << endl << endl << endl;
	// 게임 기록 저장
	char buf[256];
	sprintf_s(buf, "%d", a.getPlaytime());
	strcat(username, "\t");
	strcat(username, buf);
	char result[100];
	strcpy(result, "\n");
	strcat(result, username);
	FILE* pFile = fopen("Jumsu.txt", "a");
	fputs(result, pFile);
	fclose(pFile);
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