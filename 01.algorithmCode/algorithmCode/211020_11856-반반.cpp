#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int alphabet[27];
int answer;//��� �� ����
void init();//�ʱ�ȭ �� �ʱ��Է�

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		printf("#%d %s\n", test_case, answer == 2 ? "Yes" : "No");
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void init() {
	answer = 0;
	memset(alphabet, 0, sizeof(alphabet));
	for (int i = 0; i < 4; i++) {
		char alpha;
		scanf(" %c", &alpha);
		alphabet[alpha - 'A']++;
	}
	//cout << 'Z' - 'A' << endl;
	for (int i = 0; i < 27; i++) {
		if (alphabet[i] == 2) {
			answer++;
		}
	}
}
