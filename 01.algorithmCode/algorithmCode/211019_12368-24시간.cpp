#include<iostream>
#include<stdio.h>
using namespace std;
int answer;
int A, B;
void init();//�ʱ�ȭ �� �ʱ��Է�
void clock24();//�ð� ����
int main()
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		clock24();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void init() {
	answer = A = B = 0;
	scanf("%d %d", &A, &B);
}
void clock24() {
	if (A + B >= 24) {
		answer = A + B - 24;
	}
	else answer = A + B;
}