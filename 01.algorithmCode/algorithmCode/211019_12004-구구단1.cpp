#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int A, answer;
int num[82];
void init();//�ʱ�ȭ �� �ʱ� �Է�
void nineNine1();//������1
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
		nineNine1();
		printf("#%d %s\n", test_case, answer==-1?"No":"Yes");
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void init() {
	A = answer = 0;
	memset(num, 0, sizeof(num));
	scanf("%d", &A);
}
void nineNine1() {
	int flag = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j<= 9; j++) {
			num[i*j] = 1;
		}
	}
	if (num[A] == 0)answer = -1;
	else answer = 0;
}
