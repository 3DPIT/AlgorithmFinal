#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define SIZE 100001
int answer;//결과값 저장
int people[SIZE];
int N;
map<int, int>peopleMap;
void init();//초기화 및 초기 입력
void money();//돈 계산
int main()
{
	int test_case;
	int T;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		money();
		printf("#%d %d\n", test_case, answer);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	N = answer = 0;
	peopleMap.clear();
	memset(people, 0, sizeof(people));
	scanf("%d", &N);

}
void money() {
	int sum = 0;
	for (int n = 0; n < N; n++) {
		int num;
		scanf("%d", &num);
		sum += num;
		peopleMap[num]++;
	}
	double sumResult = (double)(sum / N);
	for (auto iter: peopleMap) {
		if (iter.first <= sumResult) {
			answer += iter.second;
		}
	}
}