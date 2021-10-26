#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define SIZE 101
int N, minNum, maxNum;
int block[SIZE];
void initData();// �ʱ�ȭ �� �ʱ� �Է�
void upDownTest();//�ö󰡱�, ��������
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		upDownTest();
		printf("#%d %d %d\n", test_case, minNum*-1, maxNum);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void initData() {
	N = 0;
	minNum = 0;
	maxNum = 0;
	memset(block, 0, sizeof(block));
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &block[n]);
	}
}
void upDownTest(){
	for (int i = 0; i < N-1; i++) {
		int num = block[i] - block[i + 1];
		if(num<=0)minNum = minNum > num ? num : minNum;
		else if(num>=0) maxNum = maxNum < num ? num : maxNum;
	}
}