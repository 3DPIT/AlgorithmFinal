#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
int password[8];
int startIdx, endIdx;
void init();
void searchPassword();
int main(int argc, char** argv)
{
	int test_case;
	int T;
;

	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= 8; ++test_case)
	{
		cin >> T;
		init();
		searchPassword();
		printf("#%d ", test_case);
		int idx = startIdx;
		while(1){
			printf("%d ", password[idx++]);
			idx = idx % 8;
			if (idx == endIdx) {
				printf("%d\n", password[idx]);
				break;
			}
		}

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void searchPassword() {
	int idx = 0;
	int num = 1;
	while (1) {
		if (password[idx] - num <= 0) {
			password[idx] = 0;
			startIdx = idx+1; 
			endIdx = idx ;
			if (startIdx == 8) startIdx = 0;
			break;
		}
		password[idx] -= num;
		num++;
		idx++;
		if (num == 6)num = 1;
		if (idx == 8)idx = 0;
	}
}
void init() {
	startIdx = endIdx = 0;
	memset(password, 0, sizeof(password));
	for (int i = 0; i < 8; i++) {
		scanf("%d", &password[i]);
	}
}