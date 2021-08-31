#include<stdio.h>
#include<map>
#include<string>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
struct Data {
	long long int number;
	int cnt;
};

int A, B, ret;//A: 시작, B: 만들어야하는 숫자, ret: 결과값
void init() {
	A = B = 0; ret = 0x7fffffff;
	scanf("%d %d", &A, &B);
}

void AtoB() {
	map<long long int , int>visit;// 방문 체크 맵
	queue<Data>q;
	q.push({ A,1 });
	visit[A] = 1;
	while (!q.empty()) {
		Data current = q.front(); q.pop();
		if (current.number > B || current.number > 1000000000) continue;

		if (current.number == B) {
			ret = min(ret, current.cnt);
		}
		//*2
		Data next = current;
		next.number = current.number * 2;

		if (visit[next.number] == 0) {
			visit[next.number] = 1;
			q.push({ next.number,next.cnt + 1 });
		}
		//add 1

		next.number = (current.number * 10) + 1;
		if (visit[next.number] == 0) {
			visit[next.number] = 1;
			q.push({ next.number,next.cnt + 1 });
		}
	}
}

int main() {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		AtoB();
		if (ret == 0x7fffffff) {
			ret = -1;
		}
		//printf("#%d %d\n", tc, ret);
		cout << ret << endl;
	}

}