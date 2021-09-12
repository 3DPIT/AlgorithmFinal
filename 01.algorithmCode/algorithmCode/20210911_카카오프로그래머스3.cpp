#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
struct Data {
	string time;
	string stauts;
};
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map< string, int >carMap;
	vector<Data> carTimeAndInOut[1001];
	vector<string> allCarInfo;
	for (int i = 0; i < records.size(); i++) {//주차장 기록 
		istringstream ss(records[i]);
		string stringBuffer;
		vector<string> carInfo;// 분리된 데이터 저장
		while (getline(ss, stringBuffer, ' ')) {
			carInfo.push_back(stringBuffer);
			allCarInfo.push_back(stringBuffer);
		}
		carMap[carInfo[1]] = 1;
	}
	map<string, int >::iterator iter;// 분류
	int num = 0;
	for (iter = carMap.begin(); iter != carMap.end(); iter++) {
		iter->second = 0;
		iter->second = num++;
	}// map 재설정
	for (int i = 0; i < allCarInfo.size(); i += 3) {
		carTimeAndInOut[carMap[allCarInfo[i + 1]]].push_back({ allCarInfo[i],allCarInfo[i + 2] });
	}
	for (int i = 0; i < carMap.size(); i++) {
		int time = 0;
		for (int j = 0; j < carTimeAndInOut[i].size(); j+=2) {// 계산 시작
		//누적 시간 계산
			int clock1, minuth1, clock2, minuth2;
			if (j + 1 == carTimeAndInOut[i].size()) {//out를 안한 상태
				clock1 = 1439;
				clock2 = ((carTimeAndInOut[i][j].time[0] - '0') * 10 + (carTimeAndInOut[i][j].time[1] - '0'))*60;
				minuth2 = (carTimeAndInOut[i][j].time[3] - '0') * 10 + (carTimeAndInOut[i][j].time[4] - '0');
				clock2 += minuth2;
			}
			else {
				clock1 = ((carTimeAndInOut[i][j + 1].time[0] - '0') * 10 + (carTimeAndInOut[i][j + 1].time[1] - '0'))*60;
				minuth1 = (carTimeAndInOut[i][j + 1].time[3] - '0') * 10 + (carTimeAndInOut[i][j + 1].time[4] - '0');
				clock2 = ((carTimeAndInOut[i][j].time[0] - '0') * 10 + (carTimeAndInOut[i][j].time[1] - '0'))*60;
				minuth2 = (carTimeAndInOut[i][j].time[3] - '0') * 10 + (carTimeAndInOut[i][j].time[4] - '0');
				clock1 += minuth1;
				clock2 += minuth2;
			}
				clock1 -= clock2;		
				time += clock1;
		}
		//계산해서 저장
		if (time < fees[0]) {//기본료 경우
			answer.push_back(fees[1]);
		}
		else {
			int timeFee = 0;
			if (0 != ((time - fees[0]) % fees[2])) {
				timeFee = ((time - fees[0]) / fees[2]);
					timeFee += 1;
			}
			else {
				timeFee= ((time - fees[0]) / fees[2]);
			}

			int fee = fees[1] +(timeFee)*fees[3];
			answer.push_back(fee);
		}
	}
	return answer;
}
int main(void) {
	vector<int> answer = solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	answer = solution({ 120, 0, 60, 591 }, { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN" });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	answer = solution({ 1, 461, 1, 10 }, { "00:00 1234 IN" });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}