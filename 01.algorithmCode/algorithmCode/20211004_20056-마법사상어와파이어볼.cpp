#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 51
struct Data {
	int y, x, m, d, s;
};
vector<Data>fireBall;
int N, M, K, answer;
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
void init();//초기화 및 초기입력
void moveFireBall();//파이어볼 이동
void solve();//결과값 산출
bool cmp(Data a, Data b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		moveFireBall();
		printf("%d\n", answer);
	}
	return 0;
}

void init() {
	N = M = K = answer = 0;
	fireBall.clear();
	scanf("%d %d %d", &N, &M, &K);
	for (int m = 0; m < M; m++) {
		Data c;
		scanf("%d %d %d %d %d", &c.y, &c.x, &c.m, &c.s, &c.d);
		c.y--;
		c.x--;
		fireBall.push_back(c);
	}
}

void solve() {
	for (int i = 0; i < fireBall.size(); i++) {
		answer += fireBall[i].m;
	}
}
void moveFireBall() {
	while (K--) {
		for (int i = 0; i < fireBall.size(); i++) {//파이어볼 이동
			Data c = fireBall[i];
			Data n = c;
			n.y = (c.y + (dy[c.d] * c.s%N) + N) % N;
			n.x = (c.x + (dx[c.d] * c.s%N) + N) % N;
			fireBall[i] = n;
		}
		int flag = 0;
		sort(fireBall.begin(), fireBall.end(), cmp);//정렬
		vector<Data>copyfire;

		int size = fireBall.size();
		for (int i = 0; i < fireBall.size() - 1; i++) {
			flag = 0;
			if (fireBall.size() == 0)break;
			for (int j = i + 1; j < fireBall.size(); j++) {
				if (fireBall.size() == 0)break;
				int cnt = 1;
				int odd = 0, even = 0;//홀 짝
				if (fireBall[i].d % 2 == 0)even++;
				else odd++;
				Data saveData = fireBall[i];
				while (j != fireBall.size() && fireBall[i].y == fireBall[j].y&&fireBall[i].x == fireBall[j].x) {
					if (fireBall.size() == 0)break;
					flag = 1;
					saveData.m += fireBall[j].m;
					saveData.s += fireBall[j].s;
					if (fireBall[j].d % 2 == 0)even++;//짝 , 홀 검증
					else odd++;

					cnt++;
					fireBall.erase(fireBall.begin() + j);
				}
				if (cnt != 1) {
					fireBall.erase(fireBall.begin() + i);
					i--;
					Data c = saveData;
					int sM = c.m / 5;
					int sS = c.s / cnt;
					if (sM != 0) {
						Data n;
						if (odd == cnt || even == cnt) {//방향 0,2,4,6
							for (int dir = 0; dir <= 6; dir += 2) {
								copyfire.push_back({ c.y,c.x,sM,dir,sS });
							}
						}
						else {//방향 1,3,5,7
							for (int dir = 1; dir <= 7; dir += 2) {
								copyfire.push_back({ c.y,c.x,sM,dir,sS });
							}
						}
					}
					break;
				}
				if (flag == 0)break;
			}
		}//2개이상 걸러주기
		while (!copyfire.empty()) {// 다시 저장
			fireBall.push_back({ copyfire.front() }); copyfire.erase(copyfire.begin());
		}

	}
	solve();
}