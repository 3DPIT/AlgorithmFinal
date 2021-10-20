#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define SIZE 21
int N;// �ٵ��� ũ��
char board[SIZE][SIZE];
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int answer;
void init();//�ʱ� ȭ�� �� �ʱ� �Է�
bool safeZone(int y, int x);//���� üũ
void playGame();//���� ����
int main()
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		playGame();
		printf("#%d %s\n", test_case, answer == 1 ? "YES" : "NO");
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
bool safeZone(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}
void init() {
	N = answer = 0;
	memset(board, 0, sizeof(board));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s",board[i]);
	}
}void playGame() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'o') {
				for (int dir = 0; dir < 8; dir++) {
					int count = 1;
					int cy = i + dy[dir];
					int cx = j + dx[dir];
					while (safeZone(cy, cx) && board[cy][cx] == 'o'){
						count++;
						cy = cy + dy[dir];
						cx = cx + dx[dir];
					}
					if (count >= 5) {
						answer = 1; return;
					}
				}
			}
		}
	}
}