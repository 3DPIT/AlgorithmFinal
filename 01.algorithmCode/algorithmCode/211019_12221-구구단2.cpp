#include<iostream>
#include<stdio.h>
using namespace std;
int A, B, answer;
void init();//�ʱ�ȭ �� �ʱ� �Է�
void nineNine2();//������2
int main(int argc, char** argv)
{
	int test_case;
	int T;

	scanf("%d", &T);
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		nineNine2();
		printf("#%d %d\n", &test_case, answer);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void init() {
	A = B = answer = 0;
	scanf("%d %d", &A, &B);
}
void nineNine2() {
	if (A >= 10 || B >= 10) {
		answer = -1;
	}
	else {
		answer = A * B;
	}
}
