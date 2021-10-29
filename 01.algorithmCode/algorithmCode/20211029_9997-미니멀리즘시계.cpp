
#include<iostream>
#include<stdio.h>

using namespace std;
int num;
void initData();//초기화 및 초기입력
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();

		printf("#%d %d %d\n", test_case, (num * 2) / 60, (num * 2) % 60);
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void initData() {
	num = 0;
	scanf("%d", &num);
}