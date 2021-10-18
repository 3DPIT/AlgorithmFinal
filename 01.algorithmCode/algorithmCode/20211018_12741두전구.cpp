#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int chk[101];
int A, B, C, D;
int answer;//결과값
void init();//초기화
void lightChk();//불켜기
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		lightChk();
		printf("#%d %d\n", test_case, answer==0?0:answer-1);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void lightChk() {
	for (int i = A; i <= B; i++) {
		chk[i]++;
	}
	for (int i = C; i <= D; i++) {
		chk[i]++;
		if (chk[i] == 2)answer++;
	}
}
void init() {
	memset(chk, 0, sizeof(chk));
	A = B = C = D = answer=0;
	scanf("%d %d %d %d", &A, &B, &C, &D);
}