#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 101
struct Data {
	int number;
	int count;
};

int time;
int r, c, k;//Ȯ���ؾ��ϴ� A[r][c]==k ��
int y, x;
int answer;//�����
int A[SIZE][SIZE];//����迭 
void init();//�ʱ�ȭ
void R();//R����
void C();//C����
bool cmp(Data a, Data b);//�������� ����
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		while (time <= 101) {
			if (A[r][c] == k)break;
			if (y >= x) R();
			else if (y < x)C();
			time++;
		}
		if (time != 102)answer = time;
		printf("%d\n", answer);
	}
	return 0;
}

void init() {
	r = c = k = time = 0;
	y = x = 3;
	answer = -1;
	memset(A, 0, sizeof(A));
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}
void R() {
	//����ü �迭�� ����, ���� ����
	// ����
	// �ִ� c�� ���� ����
	int maxC = 0x80000000;
	for (int i = 1; i <= y; i++) {
		Data num[101] = { 0, };
		for (int j = 1; j <= x; j++) {
			num[A[i][j]].number = A[i][j];
			num[A[i][j]].count++;
			A[i][j] = 0;
		}
		vector<Data>sortNumber;
		for (int n = 1; n <= 100; n++) {
			if (num[n].number != 0) {
				sortNumber.push_back({ n,num[n].count });
			}
		}
		sort(sortNumber.begin(), sortNumber.end(), cmp);
		int size = sortNumber.size() * 2;
		if (maxC < size) maxC = size;// �ִ� �� ��
		int idx = 1;
		for (int s = 0; s < sortNumber.size(); s++) {//�迭 ������ ����
			A[i][idx++] = sortNumber[s].number;
			A[i][idx++] = sortNumber[s].count;
		}
	}
	x = maxC;
}
void C() {
	//����ü �迭�� ����, ���� ����
	// ����
	// �ִ� c�� ���� ����
	int maxR = 0x80000000;
	for (int j = 1; j <= x; j++) {
		Data num[101] = { 0, };
		for (int i = 1; i <= y; i++) {
			num[A[i][j]].number = A[i][j];
			num[A[i][j]].count++;
			A[i][j] = 0;
		}
		vector<Data>sortNumber;
		for (int n = 1; n <= 100; n++) {
			if (num[n].number != 0) {
				sortNumber.push_back({ n,num[n].count });
			}
		}
		sort(sortNumber.begin(), sortNumber.end(), cmp);
		int size = sortNumber.size() * 2;
		if (maxR < size) maxR = size;// �ִ� �� ��
		int idx = 1;
		for (int s = 0; s < sortNumber.size(); s++) {//�迭 ������ ����
			A[idx++][j] = sortNumber[s].number;
			A[idx++][j] = sortNumber[s].count;
		}
	}
	y = maxR;
}
bool cmp(Data a, Data b) {
	if (a.count == b.count)return a.number < b.number;
	return a.count < b.count;
}