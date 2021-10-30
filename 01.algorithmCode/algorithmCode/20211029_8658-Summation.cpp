#include<iostream>
#include<string>
#include<vector>
using namespace std;
int maxNum, minNum;
void initData();
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		printf("#%d %d %d\n", test_case, maxNum, minNum);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void initData() {
	maxNum = 0x80000000;
	minNum = 0x7fffffff;
	string firstNumber;
	for (int i = 0; i < 10; i++) {
		cin >> firstNumber;
		int sumNumber = 0;
		for (int i = 0; i < firstNumber.size(); i++) {
			sumNumber += firstNumber[i] - '0';
		}
		if (sumNumber > maxNum)maxNum = sumNumber;
		if (sumNumber < minNum)minNum = sumNumber;
	}
}