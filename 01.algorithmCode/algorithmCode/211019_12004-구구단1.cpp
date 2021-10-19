#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int A, answer;
int num[82];
void init();//초기화 및 초기 입력
void nineNine1();//구구단1
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
		nineNine1();
		printf("#%d %s\n", test_case, answer==-1?"No":"Yes");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	A = answer = 0;
	memset(num, 0, sizeof(num));
	scanf("%d", &A);
}
void nineNine1() {
	int flag = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j<= 9; j++) {
			num[i*j] = 1;
		}
	}
	if (num[A] == 0)answer = -1;
	else answer = 0;
}
