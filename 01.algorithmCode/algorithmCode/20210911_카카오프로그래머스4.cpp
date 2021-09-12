
#include <string>
#include <vector>
#include <iostream>
#include<map>

using namespace std;
int lion[11];
vector<int> retLion;
int ret = 0x80000000;
//		dfs1(0,0, chk, lion,n);
vector<int>D;
int scoreArr[11] = { 10,9,8,7,6,5,4,3,2,1 };
map<int, int> chkdouble;
void dfs1(int idx, int cnt, int chk,int sum, int lion[10],int n, vector<int> info) {
	if (cnt == chk) {
		
		if(sum!=n)return;
		int c = 0;
		int lion1[10] = { 0, };
		for (int i = 0; i < 10; i++) {
			if (lion[i] != 0) {
				lion1[i] = D[c++];
			}
		}
		

		int score_apeach = 0;
		int score_lion = 0;
		for (int i = 0; i < 10; i++) {
			if (info[i] == lion1[i]&&(0!= info[i])) {
				score_apeach += scoreArr[i];
			}
			else if (info[i] < lion1[i]) {
				score_lion += scoreArr[i];
			}
			else if (info[i] > lion1[i]) {
				score_apeach += scoreArr[i];
			}

		}
		if (score_lion - score_apeach > 0) {
			if (ret < score_lion) {
				ret = score_lion;
					retLion.clear();
				for (int i = 0; i < 10; i++) {
					retLion.push_back(lion1[i]);
				}
				retLion.push_back(0);
				for (int i = 0; i < 11; i++) {
					cout << retLion[i] << " ";
				}
				cout << endl;
			}
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (sum > n)return;
		D.push_back(i);
	dfs1(idx+1,cnt+1,chk,sum+i,lion,n,info);
		D.pop_back();

	}
}

void dfs(int idx, int cnt, int ni, vector<int> info,int n) {
	if (idx==11)return;
	else if(cnt==ni){
		int chk = 0;
		for (int i = 0; i < 10; i++) {
			if (ni == 1) {
				if (lion[i] == 1) {
					lion[i] = n;
				}
			}
			else {
				if (lion[i] == 1) chk++;
			}
		}
		if(ni!=1)
		dfs1(0,0, chk,0,lion,n,info);

		return;
	}
	lion[idx] = 1;
	dfs(idx + 1, cnt+1, ni, info,n);
	lion[idx] = 0;
	dfs(idx + 1, cnt, ni, info,n);

}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	for (int ni=1; ni < n; ni++) {
		dfs(0, 0, ni, info,n);
	}
	if (0x80000000 == ret) return { -1 };
	else {
		return retLion;
	}
}
int main() {
	vector<int> answer = solution(10, { 0,0,0,0,0,0,0,0,3,4,3 });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}