#include<iostream>
#include<stdio.h>
using namespace std;
int N;
void initData();//초기화
int main(int argc, char** argv)
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		printf("#%d ", test_case);
		for (int i = 0; i < N; i++) {
			printf("1/%d ", N);
		}
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void initData() {
	N = 0;
	scanf("%d", &N);
}