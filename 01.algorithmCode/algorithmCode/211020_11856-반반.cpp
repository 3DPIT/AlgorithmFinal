#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int alphabet[27];
int answer;//결과 값 저장
void init();//초기화 및 초기입력

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		printf("#%d %s\n", test_case, answer == 2 ? "Yes" : "No");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void init() {
	answer = 0;
	memset(alphabet, 0, sizeof(alphabet));
	for (int i = 0; i < 4; i++) {
		char alpha;
		scanf(" %c", &alpha);
		alphabet[alpha - 'A']++;
	}
	//cout << 'Z' - 'A' << endl;
	for (int i = 0; i < 27; i++) {
		if (alphabet[i] == 2) {
			answer++;
		}
	}
}
