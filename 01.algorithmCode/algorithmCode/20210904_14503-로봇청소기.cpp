#include<stdio.h>
#include<vector>
#include<string.h>
#define N_MAX_SIZE 51
#define M_MAX_SIZE 51
int N, M;
int board[N_MAX_SIZE][M_MAX_SIZE];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
struct posData {
	int y, x, dir;
}robot;
void init();
void init_test();
void cleanRoom();
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		cleanRoom();
	}
	return 0;
}
void init() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot.y, &robot.x, &robot.dir);
	for (int i = 0; i < N; i++) {
		for (int j =0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	//init_test();
}

void init_test() {
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		printf("%d", board[i][j]);
	}
	printf("\n");
}
printf("%d %d %d %d %d\n", N, M, robot.y, robot.x, robot.dir);
}

void cleanRoom() {
	int time = 1;
	while (1) {
		if (0 == board[robot.y][robot.x]) { //1
			board[robot.y][robot.x] = ++time;
		}
		int i = 0;
		int copydir = robot.dir;
		for (; i < 4; i++) {
			copydir--;
			if (copydir == -1)copydir = 3;
			int ny = robot.y + dy[copydir]; int nx = robot.x + dx[copydir];
			if (board[ny][nx] == 0) {//왼쪽에 청소할 공간
				robot.y = ny; robot.x = nx;
				robot.dir = copydir;
				break;
			}
		}
		if (i == 4) {//4방향 모두 청소할 곳 없는경우
			int rny = robot.y - dy[robot.dir]; int rnx = robot.x - dx[robot.dir];
			if (board[rny][rnx] != 1) {//벽이 아닌경우
				robot.y = rny; 
				robot.x = rnx;
			}
			else {
				break;
			}
		}
	}
	printf("%d\n", time - 1);
}