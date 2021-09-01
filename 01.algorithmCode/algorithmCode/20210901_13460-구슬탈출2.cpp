#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#define NMSIZE 11
using namespace std;
char board[NMSIZE][NMSIZE];// ������ ���� �ʱ׷����� ��
int chk[NMSIZE][NMSIZE][NMSIZE][NMSIZE];// ���� ��ġ üũ�ϴ� �迭
int N, M;//���� ���� ũ���Է� ����
int ret;//����� ����
int dy[] = { 0,1,0,-1 };// �����¿� �̵� ���� �迭
int dx[] = { 1,0,-1,0 };
void init();//�ʱ�ȭ
void play();//�ùķ��̼� ����

struct ballXY {
	int ry, rx;//������ y,x
	int by, bx;//�Ķ��� y,x
	int cnt;
};

int main(void) {
	int testcase = 1;
	for (int tc = 1; tc <= testcase; tc++) {
		init();
		play();
		//printf("#%d %d\n", tc, ret);
		printf("%d\n", ret);
	}
	return 0;
}
ballXY D;
void init() {
	N = M = 0;
	ret = 0x7fffffff;// �ּ��� ����� ����
	memset(board, 0, sizeof(board));
	memset(chk, 0, sizeof(chk));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'R') {
				board[i][j] = '.';
				D.ry = i;
				D.rx = j;
			}
			else if (board[i][j] == 'B') {
				board[i][j] = '.';
				D.by = i;
				D.bx = j;
			}
		}
	}
	D.cnt = 0;
}
void play() {
	queue<ballXY>q;
	q.push(D);// �� ���� ��ġ ����
	chk[D.ry][D.rx][D.by][D.bx] = 1;
	while (!q.empty()) {
		D = q.front(); q.pop();

		if (D.cnt == 11) {
			break;
		}
		if (board[D.ry][D.rx] == 'O') {
			ret = D.cnt;// �����
			break;
		}
		for (int dir = 0; dir < 4; dir++) {
			ballXY N = D;
			int rcnt = 0;//��� �̵��ߴ��� Ȯ��
			while (1) {//������ �̵�
				rcnt++;
				N.ry = N.ry + dy[dir];
				N.rx = N.rx + dx[dir];
				if (board[N.ry][N.rx] == '#') {//���� ���
					N.ry = N.ry - dy[dir];
					N.rx = N.rx - dx[dir];
					break;
				}
				if (board[N.ry][N.rx] == 'O') {//Ȧ�� �����

					break;
				}
			}
			int bcnt = 0;//����̵��ߴ��� Ȯ��
			while (1) {
				bcnt++;
				N.by = N.by + dy[dir];
				N.bx = N.bx + dx[dir];
				if (board[N.by][N.bx] == '#')//���ΰ��
				{
					N.by = N.by - dy[dir];
					N.bx = N.bx - dx[dir];
					break;
				}
				if (board[N.by][N.bx] == 'O') {//Ȧ�� �� ���
					break;
				}
			}
			if (board[N.ry][N.rx] == 'O' && board[N.by][N.bx] == 'O' || board[N.ry][N.rx] == '.' && board[N.by][N.bx] == 'O') {// ������ �Ǹ� �ȵǴ� ���
				continue;
			}
			if (N.ry == N.by&&N.rx == N.bx) {//���� ������ ���
				if (rcnt < bcnt) {//�Ķ����� ���߿� �°��
					N.by = N.by - dy[dir]; N.bx = N.bx - dx[dir];
				}
				if (rcnt > bcnt) {//�������� ���߿� �°��
					N.ry = N.ry - dy[dir]; N.rx = N.rx - dx[dir];
				}
			}
			if (chk[N.ry][N.rx][N.by][N.bx] == 0) {//�湮 üũ
				chk[N.ry][N.rx][N.by][N.bx] = 1;
				N.cnt++;
				q.push(N);
			}
		}
	}
		if (0x7fffffff == ret) {
			ret = -1;
		}
	
}