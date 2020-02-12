#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define StartPoint Map[1][1]
#define EndPoint Map[8][18]
#define interval 40
#define move(a, b) Map[pos.r + a][pos.c + b]

struct point { int r, c; } record[10 * 20] = { {1,1} };
int goal = 0;

void loadFile(int[][20]);
void dispMap(int[][20]); //콘솔 창에 출력
void Find_dir(int[][20], point[], point, int*);
void gotoxy(short, short); //커서 초기화를 위한 함수

int main() {
	int iter = 0, Map[10][20];
	srand((unsigned)time(NULL));
	loadFile(Map); //파일을 로드
	dispMap(Map); // 로드한 파일을 맵 초기화용으로 배열에 따로 저장
	Find_dir(Map, record, { 1,0 }, &iter);
	loadFile(Map);
	for (int i = 0; i < iter; i++) {
		Map[record[i].r][record[i].c] = 2;
		Map[record[i + 1].r][record[i + 1].c] = 3;
		dispMap(Map);
	}
	printf("Robot moved %d times", iter);
}

void loadFile(int Map[][20]) {
	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "r");
	if (fp != NULL) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				fscanf_s(fp, "%d ", &Map[i][j]);
			}
		}
		fclose(fp);
	}
	StartPoint = 3;
}

void dispMap(int Map[][20]) {
	gotoxy(0, 0); //커서 초기화
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			switch (Map[i][j])
			{
			case 0: //안지나간 길
				printf("□"); break;
			case 1: //막혀있는 벽
				printf("■"); break;
			case 2: // 지나간 길
				printf(" "); break;
			case 3: //현재 위치
				printf("★"); break;
			}
		}
		puts("");
	}
	Sleep(interval);
}

void gotoxy(short r, short c) {
	COORD cur = { r, c };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void Find_dir(int Map[][20], point record[], point m, int* iter) {
	if (goal == 1) return;
	if (record[*iter].r == 8 && record[*iter].c == 18) goal = 1;
	record[*iter + 1] = { record[*iter].r + m.r, record[*iter].c + m.c };
	if (record[*iter].r == 8 && record[*iter].c == 18) goal = 1;
	if (Map[record[*iter + 1].r][record[*iter + 1].c] > 0) return;
	Map[record[*iter].r][record[*iter].c] = 2;
	Map[record[(*iter) + 1].r][record[(*iter) + 1].c] = 3;
	(*iter)++;
	//dispMap(Map);

	Find_dir(Map, record, { 1, 1 }, iter);
	Find_dir(Map, record, { 0, 1 }, iter);
	Find_dir(Map, record, { 1, 0 }, iter);
	Find_dir(Map, record, { -1, 1 }, iter);
	Find_dir(Map, record, { -1, 0 }, iter);
	Find_dir(Map, record, { 1, -1 }, iter);
	Find_dir(Map, record, { 0, -1 }, iter);
	Find_dir(Map, record, { -1, -1 }, iter);
	if (goal == 1) return;
	(*iter)--;
	Map[record[*iter].r][record[*iter].c] = 3;
	Map[record[(*iter) + 1].r][record[(*iter) + 1].c] = 2;
	//dispMap(Map);
}
