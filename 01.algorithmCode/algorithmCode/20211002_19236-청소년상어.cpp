#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 4
#define FISHES_SIZE 17
struct Data {
	int y, x, dir;
};

Data fishes[FISHES_SIZE];
Data shark;//��� ����

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int board[SIZE][SIZE];//�Է� 
int answer;//�����

void init();//�ʱ�ȭ �� �Է�
bool safeZone(int y, int x);//���� ���� üũ
void moveShark(int y, int x, int sum);//����� ������
void moveFishes();//����� ������
void copyArr(int copyBoard[SIZE][SIZE], int Board[SIZE][SIZE]);
void copyFish(Data copyFishes[FISHES_SIZE], Data fishes[FISHES_SIZE]);
void fishMove(int y, int x);
int eat(int y, int x);
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		moveShark(0, 0, 0);
		printf("%d\n", answer);
	}
	return 0;
}
void copyFish(Data copyFishes[FISHES_SIZE], Data fishes[FISHES_SIZE]) {
	for (int num = 1; num < FISHES_SIZE; num++) {
		copyFishes[num] = fishes[num];
	}
}
bool safeZone(int y, int x) {
	return 0 <= y && y < SIZE && 0 <= x && x < SIZE;
}
void moveFishes() {
	for (int num = 1; num < FISHES_SIZE; num++) {
		if (fishes[num].dir == -1)continue;

		Data c = fishes[num];
		int dir = c.dir;
		while (1) {
			Data n;
			n.y = c.y + dy[dir]; n.x = c.x + dx[dir];
			if (!safeZone(n.y, n.x) || (shark.y == n.y&&shark.x == n.x)) {
				dir = (dir + 1) % 8;
				continue;
			}
			else if (board[n.y][n.x] == -1) {
				int a = board[n.y][n.x];
				board[n.y][n.x] = board[c.y][c.x];
				board[c.y][c.x] = a;
				fishes[num].y = n.y;
				fishes[num].x = n.x;
				fishes[num].dir = dir;
				break;
			}
			else {//����� �ִ� ���
				int a1 = board[n.y][n.x];
				board[n.y][n.x] = board[c.y][c.x];
				board[c.y][c.x] = a1;
				fishes[board[c.y][c.x]].y = c.y;
				fishes[board[c.y][c.x]].x = c.x;
				fishes[num].y = n.y;
				fishes[num].x = n.x;
				fishes[num].dir = dir;
				break;
			}

		}
	}
}
void fishMove(int y, int x) {
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].y == -1)continue;
		//�� �ְų� ����� ���
		Data c = fishes[i];
		Data n; n.dir = c.dir;
		n.y = c.y + dy[c.dir]; n.x = c.x + dx[c.dir];
		while (!safeZone(n.y, n.x) || (y == n.y&&x == n.x)) {
			n.dir++;
			if (n.dir == 8)n.dir = 0;
			n.y = c.y + dy[n.dir]; n.x = c.x + dx[n.dir];
		}
		//�ٸ� ����Ⱑ �ִ� ���
		if (board[n.y][n.x] != -1) {
			int t = board[n.y][n.x];
			fishes[t].y = c.y; fishes[t].x = c.x;
			fishes[i].y = n.y; fishes[i].x = n.x; fishes[i].dir = n.dir;
			board[c.y][c.x] = t;
			board[n.y][n.x] = i;
		}
		//��ĭ�� ���
		else {
			fishes[i].y = n.y; fishes[i].x = n.x; fishes[i].dir = n.dir;
			board[c.y][c.x] = -1;
			board[n.y][n.x] = i;
		}
	}
}
int eat(int y, int x) {
	int a = board[y][x];
	fishes[board[y][x]].dir = -1;
	fishes[board[y][x]].x = -1;
	fishes[board[y][x]].y = -1;
	board[y][x] = -1;
	return a;
}
void moveShark(int y, int x, int sum) {
	int sharkD = fishes[board[y][x]].dir;
	
	sum += eat(y, x);
	answer = max(answer, sum);//�ִ� ����
	//moveFishes();
	fishMove(y, x);

	for (int cnt = 1; cnt < 4; cnt++) {

		Data n;
		n.y = y + dy[sharkD] * cnt;
		n.x = x + dx[sharkD] * cnt;
		if (safeZone(n.y, n.x) && board[n.y][n.x] != -1) {
			int copyBoard[SIZE][SIZE] = { 0, };
			Data copyFishes[FISHES_SIZE] = { 0, };
			copyArr(copyBoard, board);
			copyFish(copyFishes, fishes);
			moveShark(n.y, n.x, sum);
			copyFish(fishes, copyFishes);
			copyArr(board, copyBoard);

		}


	}
}
void copyArr(int copyBoard[SIZE][SIZE], int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			copyBoard[i][j] = board[i][j];
		}
	}
}
void init() {
	answer = 0x80000000;
	//shark = { 0,0,0 };
	memset(fishes, 0, sizeof(fishes));
	memset(board, 0, sizeof(board));
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			int num, dir;
			scanf("%d %d", &num, &dir);
			board[y][x] = num;
			fishes[num].y = y;
			fishes[num].x = x;
			fishes[num].dir = dir - 1;
		}
	}
}