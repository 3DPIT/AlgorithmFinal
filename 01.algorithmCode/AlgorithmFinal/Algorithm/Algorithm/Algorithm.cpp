// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int logTypeCheck(string logs)
{
	int team_name_small = logs.find("team_name");
	int team_name_big = logs.find("TEAM_NAME");
	if (team_name_small == -1 && team_name_big == -1) return 1;
	int application_name_small = logs.find("application_name");
	int application_name_big = logs.find("APPLICATION_NAME");
	if (application_name_small == -1 && application_name_big == -1) return 1;
	int error_level_small = logs.find("error_level");
	int error_level_big = logs.find("ERROR_LEVEL");
	if (application_name_small == -1 && application_name_big == -1) return 1;
	int message_small = logs.find("message");
	int message_big = logs.find("MESSAGE");
	if (message_small == -1 && message_big == -1) return 1;

	return 0;
}
int specialCheck(string logs) {
	
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i]=='!'||logs[i]=='~'||logs[i]=='@'|| logs[i]=='#'|| logs[i]=='$'
			|| logs[i]=='%'|| logs[i]=='^' || logs[i]=='&'  || logs[i]=='*' 
			|| logs[i]=='+' || logs[i]=='/' || logs[i]=='?' )
			return 1;
	}
	return 0;
}
int numberCheck(string logs){
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i] == '1' || logs[i] == '2' || logs[i] == '3' || logs[i] == '4' || logs[i] == '5'
			|| logs[i] == '6' || logs[i] == '7' || logs[i] == '8' || logs[i] == '9'
			|| logs[i] == '0')
			return 1;
	}
	return 0;
}
int sizeCheck(string logs)
{
	if (logs.size() > 100) return 1;
	return 0;
}
int spaceCheck(string logs)
{
	int spaceCount = 0;
	for (int i = 0; i < logs.size(); i++)
	{
		if (logs[i] == ' ')spaceCount++;
	}
	if (spaceCount != 11) return 1;
	return 0;
}
int solution(vector<string> logs) {
	int answer = 0;
	for (int i = 0; i < logs.size(); i++)
	{
		//1 team_name 
		//application_name 
		//error_level 
		//message 

			if (logTypeCheck(logs[i]) == 1) {//로그 타입이 있는지 체크
				answer++;
				continue;
			}
			if (specialCheck(logs[i])==1)//특수문자 체크
			{
				answer++;
				continue;
			}
			if (sizeCheck(logs[i]) == 1)//로그 길이 체크
			{
				answer++;
				continue;
			}
			if (spaceCheck(logs[i]) == 1)//로그 공백 체크
			{
				answer++;
				continue;
			}
			if (numberCheck(logs[i]) == 1)//숫자 체크
			{
				answer++;
				continue;
			}
	}
	return answer;
}
int main()
{
	//cout << solution({"team_name : db application_name : dbtest error_level : info message : test", "team_name : test application_name : I DONT CARE error_level : error message : x", "team_name : ThisIsJustForTest application_name : TestAndTestAndTestAndTest error_level : test message : IAlwaysTestingAndIWillTestForever", "team_name : oberervability application_name : LogViewer error_level : error" });
	cout << solution({ "team_name : MyTeam application_name : YourApp error_level : info messag : IndexOutOfRange", "no such file or directory", "team_name : recommend application_name : recommend error_level : info message : RecommendSucces11", "team_name : recommend application_name : recommend error_level : info message : Success!", "   team_name : db application_name : dbtest error_level : info message : test", "team_name     : db application_name : dbtest error_level : info message : test", "team_name : TeamTest application_name : TestApplication error_level : info message : ThereIsNoError" });

}
