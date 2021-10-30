#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define SIZE 100
struct Data {
	int y, x;
};
int answer;
int board[SIZE][SIZE];
vector<Data>magnetic;
void initData();//초기화 및 초기 입력
void moveMagnetic();//마그네틱 이동
int main()
{
	int test_case;
	int T;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		scanf("%d", &T);
		initData();
		moveMagnetic();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
void initData() {
	answer = 0;
	memset(board, 0, sizeof(board));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}
void moveMagnetic() {
	int flag = 1;
	while (1) {
		if (flag == 0)break;
		flag = 0;
		for (int j = 0; j < SIZE; j++) {
			for (int i = 0; i < SIZE; i++) {
				if (board[i][j] == 1) {
					if (i + 1 >=SIZE) {
						board[i][j] = 0;
						continue;
					}
					if (board[i+1][j] == 0) {
						board[i][j] = 0;
						board[i+1][j] = 1;
						i++;
						flag = 1;
					}
				}
				else if(board[i][j] == 2) {
					if (i - 1 < 0) {
						board[i][j] = 0;
						continue;
					}
					if (board[i - 1][j] == 0) {
						board[i][j] = 0;
						board[i - 1][j] = 2;
						flag = 1;
					}
				}
			}
		}
	}
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (board[y][x] == 1) {
				while (1) {
					y++;
					if (y >= SIZE)break;
					if (board[y][x] == 2) {
						answer++;
						y--;
						break;
					}
				}
			}
		}
	}
}