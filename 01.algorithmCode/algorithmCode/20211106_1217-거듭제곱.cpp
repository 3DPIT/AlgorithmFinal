#include<iostream>
using namespace std;
int N, M;
long long answer = 0;
void initData();
int power(int num, int idx);
int main()
{
	int test_case;
	int T;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		initData();
		answer=power(N, 0);
		printf("#%d %d\n", test_case, answer);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void initData() {
	scanf("%d %d", &N, &M);
}
int power(int num, int idx) {
	if (idx == M-1) {
		return num;
	}
	return power(num*N, idx + 1);
}