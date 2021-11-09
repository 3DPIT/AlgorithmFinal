#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
bool cmp(string a, string b) {
	if (a.size() == b.size())return a < b;
	return a.size() < b.size();
}
vector<string> name;
void initData() {
	scanf("%d", &N);
	name.clear();
	for (int n = 0; n < N; n++) {
		string lifeName;
		cin >> lifeName;
		name.push_back(lifeName);
	}
	sort(name.begin(), name.end(), cmp);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();

		printf("#%d\n", test_case);
		for (int n = 0; n < N; n++) {
			if (name[n] == name[n + 1]) {
				continue;
			}
			cout << name[n] << '\n';
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}