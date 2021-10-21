#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define SIZE 100001
int answer;//����� ����
int people[SIZE];
int N;
map<int, int>peopleMap;
void init();//�ʱ�ȭ �� �ʱ� �Է�
void money();//�� ���
int main()
{
	int test_case;
	int T;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		money();
		printf("#%d %d\n", test_case, answer);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void init() {
	N = answer = 0;
	peopleMap.clear();
	memset(people, 0, sizeof(people));
	scanf("%d", &N);

}
void money() {
	int sum = 0;
	for (int n = 0; n < N; n++) {
		int num;
		scanf("%d", &num);
		sum += num;
		peopleMap[num]++;
	}
	double sumResult = (double)(sum / N);
	for (auto iter: peopleMap) {
		if (iter.first <= sumResult) {
			answer += iter.second;
		}
	}
}