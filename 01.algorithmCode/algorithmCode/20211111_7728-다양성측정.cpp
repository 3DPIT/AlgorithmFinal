#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string num;
int answer;
int visitNumber[10];
void initData();
void checkNum();
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		checkNum();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void initData() {
	answer = 0;
	num.clear();
	memset(visitNumber, 0, sizeof(visitNumber));
	cin >> num;
}
void checkNum() {
	for (int i = 0; i < num.size(); i++) {
		if (visitNumber[num[i] - '0'] == 1)continue;
		visitNumber[num[i]-'0'] = 1;
		answer++;
	}
}