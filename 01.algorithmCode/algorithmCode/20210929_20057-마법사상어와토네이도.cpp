#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>]
using namespace std;
#define SIZE 1000
int N;
int answer;//��� ��
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };
int dustY[4][9] = {
{ 0,-1,1,-2,2,-1,1,-1,1},
{2,1,1,0,0,0,0,-1,-1},
{0,-1,1,-2,2,-1,1,-1,1},
{-2,-1,-1,0,0,0,0,1,1}
};
int dustX[4][9] = {
{ -2,-1,-1,0,0,0,0,1,1 },
{0,-1,1,-2,2,-1,1,-1,1},
{2,1,1,0,0,0,0,-1,-1},
{0,1,-1,2,-2,-1,1,-1,1}
};
double percent[] = {0.05,0.10,0.10,0.02,0.02,0.07,0.07,0.01,0.01 };
int board[SIZE][SIZE];// �𷡸��������
int safeBoard[SIZE][SIZE];//���߿� ��� ���ϴ� �κ� üũ
void init();//�ʱ�ȭ
void wind();//��ǳ ����
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		wind();
		printf("%d\n", answer);
	}
	return 0;

}
void init() {
	N = answer = 0;
	memset(board, 0, sizeof(board));
	memset(safeBoard, 0, sizeof(safeBoard));
	scanf("%d", &N);
	int sum = 0;
	for (int i = 2; i <= N + 1; i++) {
		for (int j = 2; j <= N + 1; j++) {
			scanf("%d", &board[i][j]);
			safeBoard[i][j] = 1;
			//sum += board[i][j];
		}
	}
}
void wind() {
	int y; int x;
		y = N - ((N / 2) - 1);
		x = N - ((N / 2) - 1);

	
	int num = 1;
	int cnt = 2;//������ �ι� �̵�
	int dir = 0;
	while (1) {
		if (y == 2 && x == 2)break;
		if (N -1 == num) {
			cnt = 3;//�������� ���� �̵�
		}
		for (int c = 0; c < cnt; c++) {
			for (int n = 0; n < num; n++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				int sum = 0;
				for (int d = 0; d < 9; d++) {
					int num1 = (int)(board[ny][nx] * percent[d]);
					sum += num1;
					board[ny + dustY[dir][d]][nx + dustX[dir][d]] += num1;
				}
				board[ny][nx] -= sum;
				board[ny + dy[dir]][nx + dx[dir]] += board[ny][nx];
				board[ny][nx] = 0;
				y = ny;
				x = nx;
			}
			dir++;
			if (dir == 4)dir = 0;
		}
		num++;

	}
	int sum = 0;
	for (int i = 0; i <= N+3; i++) {
		for (int j = 0; j <= N+3; j++) {
			if (1 != safeBoard[i][j]) {
				answer += board[i][j];
				//printf("%2d ", board[i][j]);
			}
			//sum += board[i][j];
			//else printf("%2d",0);
		}
		//printf("\n");
	}
}