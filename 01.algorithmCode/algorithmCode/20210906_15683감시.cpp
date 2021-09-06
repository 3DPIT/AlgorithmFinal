#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define NSIZE 8
#define MSIZE 8
//model 
int N, M;
int board[NSIZE][MSIZE];
int cctvDir[] = { 4,2,4,4,1 };
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ret;
struct info {
	int y, x, num;
};
vector<info>CCTV;

//act
void init();
void dfs(int idx, int cnt);
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		dfs(0,0);
		printf("%d", ret);
	}
	return 0;
}
void init() {
	ret = 0x7fffffff;
	memset(board, 0, sizeof(board));
	N=M=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
			if (0 != board[i][j]&&6!=board[i][j]) {
				CCTV.push_back({ i,j,board[i][j] });//CCTV정보저장
			}
		}
	}
}
void copyArr(int cArr[NSIZE][MSIZE], int Arr[NSIZE][MSIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cArr[i][j] = Arr[i][j];
		}
	}
}
bool safe(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
void printArea(info cctv, int dir) {
	dir = dir % 4;
		info c = cctv;
		while (1) {
			info n;
			n.y = c.y + dy[dir]; n.x = c.x + dx[dir];
			if (!safe(n.y, n.x))break;
			if (board[n.y][n.x] != 6) {
				board[n.y][n.x] = 9;
			}
			else break;
			c.y = n.y; c.x = n.x;
		}
}
void dfs(int idx,int cnt) {
	if (cnt == CCTV.size()) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0) count++;
			}
		}
		ret = ret > count ? count : ret;
		return; 
	}
	int copyboard[NSIZE][MSIZE] = { 0, };
	for (int dir = 0; dir < cctvDir[CCTV[idx].num - 1]; dir++) {
		copyArr(copyboard, board);
		if (CCTV[idx].num == 1) {
			printArea(CCTV[idx], dir);
		}
		if (CCTV[idx].num == 2) {
			printArea(CCTV[idx], dir);
			printArea(CCTV[idx], dir+2);
		}
		if (CCTV[idx].num == 3) {
			printArea(CCTV[idx], dir);
			printArea(CCTV[idx], dir+3);
		}
		if (CCTV[idx].num == 4) {
			printArea(CCTV[idx], dir);
			printArea(CCTV[idx], dir+2);
			printArea(CCTV[idx], dir+3);
		}
		if (CCTV[idx].num == 5) {
			printArea(CCTV[idx], dir);
			printArea(CCTV[idx], dir + 1);
			printArea(CCTV[idx], dir + 2);
			printArea(CCTV[idx], dir + 3);
		}
		dfs(idx + 1, cnt + 1);
		copyArr(board, copyboard);
	}

}