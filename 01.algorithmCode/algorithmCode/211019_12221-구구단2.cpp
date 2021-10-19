#include<iostream>
#include<stdio.h>
using namespace std;
int A, B, answer;
void init();//초기화 및 초기 입력
void nineNine2();//구구단2
int main(int argc, char** argv)
{
	int test_case;
	int T;

	scanf("%d", &T);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		nineNine2();
		printf("#%d %d\n", &test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	A = B = answer = 0;
	scanf("%d %d", &A, &B);
}
void nineNine2() {
	if (A >= 10 || B >= 10) {
		answer = -1;
	}
	else {
		answer = A * B;
	}
}
