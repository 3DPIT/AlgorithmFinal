#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 51
int world[SIZE][SIZE];//�α������ �迭
int visit[SIZE][SIZE] = { 0, };//�湮 üũ

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int answer;//����
int N, L, R;//�迭ũ��, �ּ�, �ִ� ��

struct Data {
	int sum, cout;
};

void init();//�ʱ�ȭ
void moveHuman();//�α��̵�
void dfs(int y, int x, int flag);// �α� ����
bool safeZone(int y, int x);//��������
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		moveHuman();
		printf("%d\n", answer);
	}
	return 0;
}
void init() {
	
	N = L = R = answer = 0;
	memset(world, 0, sizeof(world));
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &world[i][j]);
		}
	}
}
void moveHuman() {
	while (1) {
		memset(visit, 0, sizeof(visit));
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (0 == visit[i][j]) {
					flag++;
					visit[i][j] =flag;
					dfs(i, j,flag);
				}//0 == visit[][]
			}//for j
		}//for i
		if (flag == N * N)break;
		Data answerData[SIZE*SIZE] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				answerData[visit[i][j] - 1].sum += world[i][j];
				answerData[visit[i][j] - 1].cout++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				world[i][j] = answerData[visit[i][j] - 1].sum / answerData[visit[i][j] - 1].cout;
			}
		}
		answer++;
	}//while(1)
}
void  dfs(int y, int x,int flag) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safeZone(ny, nx) && visit[ny][nx] == 0 && L <= abs(world[y][x] - world[ny][nx]) && abs(world[y][x] - world[ny][nx]) <= R) {
			visit[ny][nx] = flag;
			dfs(ny, nx, flag);
		}
	}
}
bool safeZone(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}