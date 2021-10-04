#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
#define SIZE 201
int N, K, A[SIZE];
int answer;
void init();
void moveRobot();
int main(void) {
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		moveRobot();
		printf("%d\n", answer);
	}
}
void moveRobot() {
	//queue<int>robot;
	int robot[200 * 1000];
	int front = 0, back = 0;
	int zeroCnt = 0;
	while(zeroCnt<K){//	�������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�.�׷��� �ʴٸ� 1������ ���ư���.

		answer++;
		//��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
		int temp = A[(2 * N)-1];
		for (int i = (2 * N) - 1; i >= 1; i--) {
			A[i] = A[i - 1];
		}
		A[0] = temp;
		for (int i = front; i < back; i++) {
			robot[i]++;
			if (robot[i] == N - 1) {
				front++;
			}
		}
		//	���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�.���� �̵��� �� ���ٸ� ������ �ִ´�.
		for (int i = front; i < back; ++i) {
			int next = robot[i] + 1;
			if (A[next] == 0 || (i != front && robot[i - 1] == next)) {
				continue;
			}
			robot[i] = next;
			if (robot[i] == N - 1) {
				++front;
			}
			A[next]--;
			if (A[next] == 0) {
				zeroCnt++;
			}
		}
		
		//	�κ��� �̵��ϱ� ���ؼ��� �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־�� �Ѵ�.
		//	�ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
		if (A[0] > 0 && (back == 0 || robot[back - 1] != 0)) {
			robot[back++] = 0;
			A[0]--;
			if (A[0] == 0) {
				zeroCnt++;
			}
		}
	}
}
void init() {
	N = K = answer = 0;
	memset(A, 0, sizeof(A));
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N*2; i++) {
		scanf("%d", &A[i]);
	}
}