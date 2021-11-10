#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
int answer;
int N;
void initData();
void password();
vector<int>num;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		password();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void initData() {
	num.clear();
	answer = 0;
	N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n = 0;
		scanf("%d",&n);
		num.push_back(n);
	}
	sort(num.begin(), num.end());
}
void password() {
	if (N == 1) {
		answer = num[0] * num[0];
		return;
	}
	if (N % 2 == 0) {
		int mid = N / 2;
		answer = num[mid] * num[mid - 1];
		return;
	}
	else {
		int mid = N / 2;
		answer = num[mid] * num[mid];
	}
}