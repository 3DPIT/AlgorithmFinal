
#include<iostream>
#include<stdio.h>
using namespace std;
int L, U, X;//� ���
int answer;
void init();//�ʱ�ȭ �� �ʱ��Է�
void checkHealth();//� üũ
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		checkHealth();
		printf("#%d %d\n", test_case, answer);
	
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void init() {
	L = U = X = 0;
	scanf("%d %d %d", &L, &U, &X);
}
void checkHealth() {
	if (L <= X && X <= U)answer = 0;
	else if (U < X)answer = -1;
	else answer = L - X;
}