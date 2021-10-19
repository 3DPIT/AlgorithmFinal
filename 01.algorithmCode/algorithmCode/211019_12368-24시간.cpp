#include<iostream>
#include<stdio.h>
using namespace std;
int answer;
int A, B;
void init();//초기화 및 초기입력
void clock24();//시계 측정
int main()
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		clock24();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	answer = A = B = 0;
	scanf("%d %d", &A, &B);
}
void clock24() {
	if (A + B >= 24) {
		answer = A + B - 24;
	}
	else answer = A + B;
}