#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 21
int N;//�迭�� ũ��, ����� ����
int answer;//�����

int sea[SIZE][SIZE];//�ٴ��� ���� ����
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

struct Data {
	int y, x, size, cnt;
}shark;

void init();//�ʱ�ȭ
void eatingShark();//���� �ùķ��̼� 
bool safeZone(int y, int x);//���� üũ


int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		eatingShark();
		printf("%d\n", answer);
	}
	return 0;
}
bool safeZone(int y, int x) {//���� üũ
	return 0 <= y && y < N && 0 <= x && x < N;
}
void eatingShark() {
	int eat = 0;
	while (1) {
		queue<Data>q;
		q.push(shark);
		int visit[SIZE][SIZE] = { 0, };
		visit[shark.y][shark.x] = 1;
		int minimunNumY = 0x7fffffff; int minimunNumX = 0x7fffffff;//�ּ� y,x
		int minimunCount = 0x7fffffff;
		while (!q.empty()) {
			Data c = q.front(); q.pop();

			if (sea[c.y][c.x] != 0 && sea[c.y][c.x] < shark.size) {//��� ���� �� �ִ� ����� ���� y,x �ּ� ����
				if (minimunCount >= c.cnt) {//�ּ� ����
					minimunCount = c.cnt;
					if ((minimunNumY > c.y) || (minimunNumY == c.y&&minimunNumX > c.x)) {//���� ����Ⱑ ������ x���������� 
						minimunNumY = c.y;
						minimunNumX = c.x;
					}
				}
			}

			for (int dir = 0; dir < 4; dir++) {
				Data n;
				n.y = c.y + dy[dir]; n.x = c.x + dx[dir]; n.cnt = c.cnt;
				if (safeZone(n.y, n.x) && sea[n.y][n.x] <= shark.size && 0 == visit[n.y][n.x]) {
					visit[n.y][n.x] = 1;
					n.cnt++;
					q.push(n);
				}//if safezone ...
			}//for(int dir dir 4 dir++)
		}//while(!.q.empty())
		//cout << minimunNumY << " " << minimunNumX<<" "<< minimunCount << endl;
		if (minimunNumX == 0x7fffffff)break;
		answer += minimunCount;
		eat++;
		if (eat == shark.size) {//����
			shark.size++;
			eat = 0;
		}
		shark.y = minimunNumY;
		shark.x = minimunNumX;
		shark.cnt = 0;
		sea[shark.y][shark.x] = 0;
	}//while(1)
}

void init() {
	N = answer = 0;
	memset(sea, 0, sizeof(sea));
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {//�Է� ����
		for (int j = 0; j < N; j++) {
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9) {
				shark.y = i; shark.x = j; shark.size = 2, shark.cnt = 0;;
				sea[i][j] = 0;
			}
		}
	}

}