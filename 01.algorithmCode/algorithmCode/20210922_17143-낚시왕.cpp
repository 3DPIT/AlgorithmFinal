#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 101

struct Data {
	int y, x, speed, dir, size;
};

int R, C, M;//가로 세로 상어 수
int answer;//결과값

vector<Data>sea;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,1,-1 };

void init();//초기화
bool safeZone(int y, int x);// 범위 체크
void fishing();//낚시 시작
bool cmp(Data a, Data b) {//오름 차순 정렬
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		fishing();
		printf("%d\n", answer);
	}
	return 0;
}
void init() {
	R = C = M = answer = 0;
	sea.clear();
	scanf("%d %d %d", &R, &C, &M);

	Data current;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &current.y, &current.x, &current.speed, &current.dir, &current.size);
		if (current.dir == 1 || current.dir == 2) {
			current.speed = current.speed % ((R * 2) - 2);
		}
		else current.speed = current.speed % ((C * 2) - 2);
		sea.push_back({ current.y,current.x,current.speed,current.dir,current.size });
	}
}
bool safeZone(int y, int x) {
	return 1 <= y && y <= R && 1 <= x && x <= C;
}
void fishing() {
	for (int i = 1; i <= C; i++) {//낚시 가능 횟수
		if (sea.size() == 0)break;
		sort(sea.begin(), sea.end(), cmp);
		for (int j = 0; j < sea.size(); j++) {//낚시 부분
			if (sea.size() == 0)break;
			if (sea[j].x == i) {//바늘에 걸린 녀석
				answer += sea[j].size;
				sea.erase(sea.begin() + j);
				break;
			}
		}
		for (int j = 0; j < sea.size(); j++) {//상어 이동
			for (int s = 0; s < sea[j].speed; s++) {

				Data n;
				n.y = sea[j].y + dy[sea[j].dir]; n.x = sea[j].x + dx[sea[j].dir];
				if (safeZone(n.y, n.x)) {
					sea[j].y = n.y;
					sea[j].x = n.x;
				}
				else {
					if (sea[j].dir == 1)sea[j].dir = 2;
					else if (sea[j].dir == 2)sea[j].dir = 1;
					else if (sea[j].dir == 3)sea[j].dir = 4;
					else if (sea[j].dir == 4)sea[j].dir = 3;
					s--;
				}
			}
		}
		if (sea.size() == 0)break;
		sort(sea.begin(), sea.end(), cmp);
		for (int j = 0; j < sea.size() - 1; j++) {
			for (int k = j + 1; k < sea.size(); k++) {
				if (k < sea.size())break;
				int maxSize = sea[j].size;
				int maxIndex = -1;
				while (sea[j].y == sea[k].y&&sea[j].x == sea[k].x) {//같은 것 있다면
					if (maxSize < sea[k].size) {
						maxSize = sea[k].size;
						maxIndex = k;
					}
					else {
						maxIndex = j;
					}
					k++;
				}
				if (maxIndex != -1) {//중복된것이 있는경우
					sea[j].size = sea[maxIndex].size;
					sea[j].speed = sea[maxIndex].speed;
					sea[j].dir = sea[maxIndex].dir;
					sea.erase(sea.begin() + j + 1, sea.begin() + k);
					k--;
					k = j;
				}
			}
		}

	}
}