#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void initData();//�ʱ�ȭ
int K;
int answer;
vector<int>num;
void codingTest();//�ڵ� �׽�Ʈ ���
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		codingTest();
		printf("#%d %d\n", test_case, answer);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void codingTest() {
	while (1) {
		if (num.size() == 1)break;
		for (int i = 0; i < num.size() - 1; i++) {
			answer += abs(num[i] - num[i + 1]);
			if (num[i] < num[i + 1]) {
				num.erase(num.begin() + i);
			}
			else {
				num.erase(num.begin() + i + 1);
			}
		}
	}
}
void initData() {
	K = answer = 0;
	num.clear();
	scanf("%d", &K);
	int kMax = 1 << K;

	for (int i = 0; i < kMax; i++) {
		int number = 0;
		scanf("%d", &number);
		num.push_back(number);
	}
}