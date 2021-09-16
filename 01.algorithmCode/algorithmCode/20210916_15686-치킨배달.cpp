#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define NS 51
struct Data {
	int y, x;
};

vector<Data>chicken;
vector<Data>home;

int N, M;//�迭 ���μ���ũ��, �̾ƾ��� ġŲ��
int answer;
int board[NS][NS];//�Է� �迭
int D[15];//ġŲ ����

void init();//�ʱ�ȭ
void chickenChoose();//ġŲ����
void dfs(int idx, int cnt);
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc<=testCase; tc++) {
		init();
		chickenChoose();
		printf("%d\n", answer);
	}
}
void init() {
	N = M = 0;
	answer = 0x7fffffff;
	memset(board, 0, sizeof(board));
	home.clear(); chicken.clear();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
			if (1 == board[i][j]) {//�� ����
				home.push_back({ i,j });
			}
			else if (2 == board[i][j]) {//ġŲ ����
				chicken.push_back({ i,j });
			}
		}
	}
}
void chickenChoose() {
	dfs(0, 0);
}
void dfs(int idx, int cnt) {
	if (idx > chicken.size())return;
	if (cnt==M) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int homeMin = 0x7fffffff;
			for (int j = 0; j < chicken.size(); j++) {
				if (D[j] == 1) {
					int absNum = abs(home[i].y - chicken[j].y) + abs(home[i].x - chicken[j].x);
					homeMin = homeMin > absNum ? absNum : homeMin;
				}
			}
			sum += homeMin;
		}
		answer = answer > sum ? sum : answer;
		return;
	}
	D[idx] = 1;
	dfs(idx + 1, cnt + 1);
	D[idx] = 0;
	dfs(idx + 1, cnt);
}

