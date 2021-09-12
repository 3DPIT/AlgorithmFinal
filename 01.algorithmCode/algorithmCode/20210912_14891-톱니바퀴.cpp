#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define MAX_Y 5
#define MAX_X 9
int wheel[MAX_Y][MAX_X];// 톱니바퀴 정보 저장 배열
int K;// 회전 횟수
void init();//초기화
int answer;//결과값
void clockRotate(int num);//시계방향 회전
void rClockRotate(int num);//반시계방향 회전
void rotate();//실제 회전을 하는 공간
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		rotate();
		printf("%d\n", answer);
	}
	return 0;
}
void rotate() {
	for (int k = 0; k < K; k++) {
		int num, dir;// 해당 톱니 바퀴 숫자, 방향
		scanf("%d %d", &num, &dir);
		int rotateData[8] = { 0, };
		rotateData[num] = dir;
		for (int i = num; i > 1; i--) {//왼쪽 탐색
			if (wheel[i][7] != wheel[i - 1][3]) {
				rotateData[i - 1] = rotateData[i] * -1;
			}
			else break;
		}
		for (int i = num ; i < 8; i++) {//오른쪽 탐색
			if (wheel[i][3] != wheel[i + 1][7]) {
				rotateData[i + 1] = rotateData[i] * -1;
			}
			else break;
		}
		for (int i = 1; i <= 8; i++) {
			if (rotateData[i] == -1) {
				rClockRotate(i);
			}
			else if (rotateData[i] == 1) {
				clockRotate(i);
			}
		}
	}

	int two = 1;
	for (int y = 1; y <= 4; y++) {
		answer += wheel[y][1] == 1 ? two : 0;
		two *= 2;
	}
}
void init() {
	memset(wheel, 0, sizeof(wheel));
	K = answer = 0;
	for (int y = 1; y <= MAX_Y - 1; y++) { //톱니바퀴 정보 저장
		for (int x = 1; x <= MAX_X - 1; x++) {
			scanf("%1d", &wheel[y][x]);
		}
	}
	scanf("%d", &K);
}
void clockRotate(int num) {
	int temp = wheel[num][8];
	for (int i = 8; i >= 2; i--) {
		wheel[num][i] = wheel[num][i - 1];
	}
	wheel[num][1] = temp;
}
void rClockRotate(int num) {
	int temp = wheel[num][1];
	for (int i = 1; i <= 7; i++) {
		wheel[num][i] = wheel[num][i + 1];
	}
	wheel[num][8] = temp;
}