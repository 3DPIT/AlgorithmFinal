#include<iostream>
#include<vector>
using namespace std;

int N, ret;
void init();
void zero();
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		zero();
		printf("#%d %d\n", test_case, ret);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void zero() {
	vector<int> money;
	for (int n = 0; n < N; n++) {
		int num;
		scanf("%d", &num);
		if (num == 0 && money.size() == 0)continue;
		else if (num == 0) money.pop_back();
		else money.push_back(num);
	}
	for (int idx = 0; idx < money.size(); idx++) {
		ret += money[idx];
	}
}
void init() {
	N = ret = 0;
	scanf("%d", &N);
}