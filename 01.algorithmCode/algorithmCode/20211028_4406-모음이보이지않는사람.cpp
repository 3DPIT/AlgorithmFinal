#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string word;
void initData();
void removeWord();
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		initData();
		removeWord();
		cout << "#" << test_case << " " << word << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void initData() {
	word.clear();
	cin >> word;
}
void removeWord() {
	for (int idx = 0; idx < word.size(); idx++) {
		if (word[idx] == 'a' || word[idx] == 'e' || word[idx] == 'i' || word[idx] == 'o' || word[idx] == 'u') {
			word.erase(word.begin() + idx);
			idx--;
		}
	}
}