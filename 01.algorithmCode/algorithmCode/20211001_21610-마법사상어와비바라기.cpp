#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define SIZE 51
struct Data {
	int y, x;
};
int N, M;
int A[SIZE][SIZE];
int answer;
int dy[] = {0,0,-1,-1,-1,0,1,1,1 };
int dx[] = {0, -1,-1,0,1,1,1,0,-1 };
void init();//초기화 및 입력
void magic();//마법의 시작
bool safeZone(int y, int x);//
int moveCloud();//구름 이동
int makeCloud();//구름 생성
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		magic();
		printf("%d\n", answer);
	}

	return 0;
}

void init() {
	N = M = answer = 0;
	memset(A, 0, sizeof(A));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}
bool safeZone(int y, int x) {
	return 1 <= y && y <= N && 1 <= x && x <= N;
}
void magic() {
	vector<Data>cloud;
	cloud.push_back({ N,1 });
	cloud.push_back({ N,2 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 1,2 });
	for (int m = 0; m < M; m++) {
		int cloudA[SIZE][SIZE] = { 0, };
		int dir, cnt;
		scanf("%d %d", &dir, &cnt);
		for (int c = 0; c < cnt; c++) {
			for (int i = 0; i < cloud.size(); i++) {//이동
				cloud[i].y += dy[dir];
				cloud[i].x += dx[dir];
				if (cloud[i].y == 0)cloud[i].y = N;
				if (cloud[i].y == N + 1)cloud[i].y = 1;
				if (cloud[i].x == 0)cloud[i].x = N;
				if (cloud[i].x == N + 1)cloud[i].x = 1;
			}// for int i 
		}// for int c
		for (int i = 0; i < cloud.size(); i++) {//비내림
			A[cloud[i].y][cloud[i].x]++;
			cloudA[cloud[i].y][cloud[i].x] = 1;//이전 구름 체크
		}
		for (int i = 0; i < cloud.size(); i++) {//주변 대각선 체크
			for (int dir = 2; dir <= 8; dir += 2) {
				int ny = cloud[i].y + dy[dir];
				int nx = cloud[i].x + dx[dir];
				if (safeZone(ny, nx)&&A[ny][nx]!=0) {
					cloudA[cloud[i].y][cloud[i].x]++;
				}
			}
		}
		for (int i = 0; i < cloud.size(); i++) {
			A[cloud[i].y][cloud[i].x] += cloudA[cloud[i].y][cloud[i].x] - 1;
		}
		// 구름 생성
		cloud.clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (cloudA[i][j] == 0&&A[i][j]>=2) {
					A[i][j] -= 2;
					cloud.push_back({ i,j });
				}
			}
		}

	}//for int m
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += A[i][j];
		}
	}
}