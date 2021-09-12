#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;
#define MAXNUM 1001
int chkReport[MAXNUM][MAXNUM] = { 0, };
struct Data {// 경찰과 도둑, 신고한사람과 신고당한 사람
	vector<string> police;
	map<string, int>theif;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	vector<Data>init_info;
	map<string, int>init_id_list;
	for (int i = 0; i < id_list.size(); i++) {
		init_id_list[id_list[i]] = i;
	}
	//각 아이디별 숫자로 변경진행
	vector<string> x;// 분리된 데이터 저장 /x는 제거 목록
	for (int i = 0; i < report.size(); i++) {//신고기록 검색
		istringstream ss(report[i]);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}
	}
	for (int i = 0; i < x.size(); i += 2) {
		chkReport[init_id_list[x[i]]][init_id_list[x[i + 1]]] = 1;
	}
	map<int, int>  chkStop;//정지인원 체크
	for (int x = 0; x < id_list.size(); x++) {
		int reportSum = 0;
		for (int y = 0; y < id_list.size(); y++) {
			if (chkReport[y][x] == 1) {
				reportSum++;
			}
		}
		if (reportSum >= k) {
			chkStop[x] = 1;
		}
		else chkStop[x] = 0;
	}
	for (int y = 0; y < id_list.size(); y++) {
		int cnt = 0;
		for (int x = 0; x < id_list.size(); x++) {
			if (chkReport[y][x] == 1 && chkStop[x] == 1)cnt++;
		}
		answer.push_back(cnt);
	}
		return answer;
}

int main(void) {
	vector<int> answer = solution(
		{ "muzi", "frodo", "apeach", "neo" },
		{ "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" },
		2);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	answer = solution(
		{ "con", "ryan" },
		{ "ryan con", "ryan con", "ryan con", "ryan con" },
		3);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}