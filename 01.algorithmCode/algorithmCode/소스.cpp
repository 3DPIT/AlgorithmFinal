#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(void) {
	int N;
	int K;
	scanf("%d %d", &N, &K);
	vector<int>v;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		v.push_back(i + 1);
	}
	for (int k = 0; k < K; k++) {
		int A, B;
		scanf("%d %d",&A, &B);
		if (A == 1) {
			auto idx = find(v.begin(), v.end(), B);
			v.erase(v.begin() + (idx - v.begin()));
			ret += B;
		}
		else {
			v.push_back(B);
		}
	}
	printf("%d\n", ret);
}





