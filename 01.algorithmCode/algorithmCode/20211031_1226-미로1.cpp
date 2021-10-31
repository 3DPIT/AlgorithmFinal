#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define SIZE 16
char board[SIZE][SIZE];
int visit[SIZE][SIZE];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int answer;
void initData();//�ʱ�ȭ �� �ʱ��Է�
void miroSearch();//�̷� Ž��
struct Data {
	int y, x;
}s,e;
int main()
{
	int test_case;
	int T;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		initData();
		miroSearch();
		printf("#%d %d\n",test_case, answer);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void miroSearch() {
	queue<Data>q;
	q.push({ s.y,s.x });
	visit[s.y][s.x] = 1;

	while (!q.empty()) {
		Data c = q.front(); q.pop();
		if (c.y == e.y&&c.x == e.x) {
			answer = 1;
			break;
		}
		for (int dir = 0; dir < 4; dir++) {
			Data n;
			n.y = c.y + dy[dir];
			n.x = c.x + dx[dir];
			if (visit[n.y][n.x] == 0 && board[n.y][n.x] != '1') {
				visit[n.y][n.x] = 1;
				q.push(n);
			}
		}
	}
}
void initData() {
	answer = 0;
	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			scanf(" %1c", &board[y][x]);
			if (board[y][x] == '2') {//��� ��ġ
				s.y = y;
				s.x = x;
			}
			else if (board[y][x] == '3') {//������ ��ġ
				e.y = y;
				e.x = x;
			}
		}
	}
}