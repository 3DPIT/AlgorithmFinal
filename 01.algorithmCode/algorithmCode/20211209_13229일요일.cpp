#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> week;
string s;
void saveWeek() {
	week["SAT"] = 1;
	week["FRI"] = 2;
	week["THU"] = 3;
	week["WED"] = 4;
	week["TUE"] = 5;
	week["MON"] = 6;
	week["SUN"] = 7;
}
void init() {
	s.clear();
	cin >> s;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	saveWeek();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		printf("#%d %d\n", test_case, week[s]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}