
#include<iostream>
#include<stdio.h>

using namespace std;
int num;
void initData();//�ʱ�ȭ �� �ʱ��Է�
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();

		printf("#%d %d %d\n", test_case, (num * 2) / 60, (num * 2) % 60);
		

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void initData() {
	num = 0;
	scanf("%d", &num);
}