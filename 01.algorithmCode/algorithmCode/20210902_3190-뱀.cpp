#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define SIZE 101 // 보드의 최대 크기
int N, K, L;//입력으로 주어지는 보드크기,사과의 개수, 뱀의 방향 변환 횟수
int board[SIZE][SIZE];
int dy[] = { 0,1,0,-1 };//방향
int dx[] = { 1,0,-1,0 };
void init();
void play();//게임 시작
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
	for (int k = 0; k < K; k++) {//사과 위치
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
			if (time == X) {//방향 변화
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
			//사과인 조건
			if (-1==board[snake.y][snake.x]) {

				board[snake.y][snake.x] = 0;
				snake.size++;
			}
			//종료 조건
			int tail = time - snake.size ;
			if (!safeZone(snake.y, snake.x) || (board[snake.y][snake.x] != 0 && tail <= board[snake.y][snake.x])){
					while (l != L-1) {//남은것 소모
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
