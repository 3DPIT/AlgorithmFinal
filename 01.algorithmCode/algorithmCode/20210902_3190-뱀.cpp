#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define SIZE 101 // ������ �ִ� ũ��
int N, K, L;//�Է����� �־����� ����ũ��,����� ����, ���� ���� ��ȯ Ƚ��
int board[SIZE][SIZE];
int dy[] = { 0,1,0,-1 };//����
int dx[] = { 1,0,-1,0 };
void init();
void play();//���� ����
struct info {
	int y, x, size, dir;
}snake;
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		play();
	}
	return 0;
}
void init() {
	memset(board, 0, sizeof(board));
}
bool safeZone(int y, int x) {
	return 1 <= y && y <= N && 1 <= x && x <= N;
}
void play() {
	snake.y = snake.x = snake.size = 1;
	snake.dir = 0;

	scanf("%d", &N);
	scanf("%d", &K);
	for (int k = 0; k < K; k++) {//��� ��ġ
		int y, x;
		scanf("%d %d", &y, &x);
		board[y][x] = -1;
	}
	scanf("%d", &L);
	int time = 0;
	board[1][1] = 1;
	for (int l = 0; l < L; l++) {
		int X; char  C;
		scanf("%d %c", &X, &C);
		while (1) {
			if (time == X) {//���� ��ȭ
				if (C == 'D') {
					snake.dir++;
					if (snake.dir == 4) snake.dir = 0;

				}
				else {
					snake.dir--;
					if (snake.dir == -1) snake.dir = 3;
				}
				if (l != L - 1) {
					break;
				}
			}
			++time;
			snake.y += dy[snake.dir]; snake.x += dx[snake.dir];
			//����� ����
			if (-1==board[snake.y][snake.x]) {

				board[snake.y][snake.x] = 0;
				snake.size++;
			}
			//���� ����
			int tail = time - snake.size ;
			if (!safeZone(snake.y, snake.x) || (board[snake.y][snake.x] != 0 && tail <= board[snake.y][snake.x])){
					while (l != L-1) {//������ �Ҹ�
						l++;
						scanf("%d %c", &X, &C);
					}
				printf("%d\n", time);
				break;
			}
			board[snake.y][snake.x] = time;

		}
	}

}
