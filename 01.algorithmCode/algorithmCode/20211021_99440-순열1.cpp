
#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
//map<int, int>chk;
int chk[100001];
int answer;
int N;
void init();//초기화 및 초기입력
void checkNumRow();//수열 확인
int main()
{
	int test_case;
	int T;

	scanf("%d",&T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		checkNumRow();
		printf("#%d %s\n", test_case, answer==1?"No":"Yes");

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void init() {
	answer = 0;
	memset(chk, 0, sizeof(chk));
	scanf("%d", &N);
}
void checkNumRow() {
	for (int n = 0; n < N; n++) {
		int num;
		scanf("%d", &num);
		if (chk[num] == 1) {
			answer = 1;
			continue;
		}
		else {
			chk[num] = 1;
		}
	}
}