#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
int N;//���� �Է�
vector<char>password;
void initData();// �ʱ�ȭ �� �ʱ� �Է�
void openPassword();//�н����� Ǯ��
int main(int argc, char** argv)
{
	int test_case;
	int T;


	for (test_case = 1; test_case<=10; ++test_case)
	{
		initData();
		openPassword();
		printf("#%d ", test_case);
		for (int i = 0; i < password.size(); i++ ) {
			printf("%c", password[i]);
		}
		printf("\n");
	}
	return 0;
}
void initData() {
	N = 0;
	password.clear();
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char num;
		scanf(" %1c", &num);
		password.push_back(num);
	}
}
void openPassword() {
	while (1) {
		int flag = 0;
		for (int i = 0; i < password.size() - 1; i++) {
			if (password.size() == 0) break;
			if (password[i] == password[i + 1]) {
				password.erase(password.begin() + i, password.begin() + i + 2);
				i -= 2;
				flag = 1;
			}
		}
		if (flag == 0)break;
	}
}