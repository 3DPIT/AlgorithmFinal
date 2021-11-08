#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int N, answer;
int chk[300];
string friends;
void initData();
void chkFriends();
int main(int argc, char** argv)
{
	int test_case;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		initData();
		chkFriends();
		printf("#%d %d\n", test_case, answer);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void chkFriends() {
	int cnt = 0;
	for (int i = 0; i < friends.size()-1; i++) {
		if (chk[i] == 1)continue;
		chk[i] = 1;
		cnt++;
		int flag = 0;
		for (int j = i + 1; j < friends.size(); j++) {
			if (friends[i] == 40) {
				if (chk[j] == 0 && friends[i] == friends[j] - 1) {
					cnt++;
					chk[j] = 1;
					flag = 1;
					break;
				}
			}
			else {
				if (chk[j] == 0 && friends[i] == friends[j] - 2) {
					cnt++;
					chk[j] = 1;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			answer = 0;
			break;
		}
		if (cnt == N)break;
	}
}
void initData() {
	N = 0; answer = 1;
	memset(chk, 0, sizeof(chk));
	scanf("%d", &N);
	cin >> friends;
}