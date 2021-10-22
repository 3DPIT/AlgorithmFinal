
#include<iostream>
#include<stdio.h>
using namespace std;
int L, U, X;//운동 기록
int answer;
void init();//초기화 및 초기입력
void checkHealth();//운동 체크
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		checkHealth();
		printf("#%d %d\n", test_case, answer);
	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	L = U = X = 0;
	scanf("%d %d %d", &L, &U, &X);
}
void checkHealth() {
	if (L <= X && X <= U)answer = 0;
	else if (U < X)answer = -1;
	else answer = L - X;
}