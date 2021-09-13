#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
#define NSIZE 8
#define MSIZE 8
int wall[NSIZE][MSIZE];//벽, 공백, 바이러스 저장되는 배열
int answer;//최대 결과갑 저장
int N, M;
struct Data {
	int y, x;
};
vector<Data>virus;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
void init();
void dfs(int i, int j, int cnt);
bool safe(int y, int x);//범위 체크
//검증코드
void checkWall(int a[NSIZE][MSIZE]); //제대로 벽세워지는지
void checkVirus(vector<Data>v);//제대로 바이러스 뽑는지
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		dfs(0, 0, 0);//벽세우고 계산하기
		//printf("#%d %d\n", tc, answer);
		printf("%d\n", answer);
	}
	return 0;
}

void dfs(int i, int j, int cnt) {
	if (cnt == 3) {
		//checkWall(wall);
		//바이러스 검사후 안전영역 확인
		queue<Data>q;
		int visit[NSIZE][MSIZE] = { 0, };//방문체크
		for (int i = 0; i < virus.size(); i++) {
			q.push({ virus[i].y,virus[i].x });
			visit[virus[i].y][virus[i].x] = 1;
		}
		while (!q.empty()) {
			Data  c = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				Data n;
				n.y = c.y + dy[dir];
				n.x = c.x + dx[dir];
				if (safe(n.y, n.x) && wall[n.y][n.x] == 0 && visit[n.y][n.x] == 0) {
					visit[n.y][n.x] = 1;
					q.push(n);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (wall[i][j] == 0 && visit[i][j] == 0) {
					cnt++;
				}
			}
		}
		answer = answer < cnt ? cnt : answer;
		return;
	}
	for (int y = i; y < N; y++) {
		for (int x = j; x < M; x++) {
			if (wall[y][x] == 0) {
				wall[y][x] = -1;
				dfs(y, x + 1, cnt + 1);
				wall[y][x] = 0;
			}
		}
		j = 0;
	}
}
void init() {
	answer = 0x80000000;
	N = M = 0;
	memset(wall, 0, sizeof(wall));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &wall[i][j]);
			if (2 == wall[i][j]) {
				virus.push_back({ i, j });//바이러스 저장
			}
		}
	}
	//checkVirus(virus);
}

bool safe(int y, int x) {//범위 체크
	return 0 <= y && y < N && 0 <= x && x < M;
}

//검증코드
void checkVirus(vector<Data>v) {
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].y, v[i].x);
	}
}
void checkWall(int a[NSIZE][MSIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}