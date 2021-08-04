#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define NS 1001
int N, M;//정점의 개수, 간선의 개수 
int ret;//결과 값
vector<int>G[NS];
void init();
void search();
int main() {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		search();
	//	printf("#%d %d\n", tc, ret);
		printf("%d\n", ret);
	}
	return 0;
}

void init() {
	N = M = ret = 0;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		G[n].clear();
	}
	for (int m = 0; m < M; m++) {//그래프 생성
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);

	}
}
void search() {
	queue<int>q;
	int visit[NS] = { 0, };// 방문 체크
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			ret++;
			visit[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int d = q.front(); q.pop();
				
				for (int n = 0; n < G[d].size(); n++) {
					if (visit[G[d][n]] == 0) {
						visit[G[d][n]] = 1;
						q.push(G[d][n]);
					}
				}
			}
		}
	 }
}