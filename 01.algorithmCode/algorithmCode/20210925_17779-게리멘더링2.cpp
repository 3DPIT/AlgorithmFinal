#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define SIZE 21
struct Data {
	int x, y;
};

int A[SIZE][SIZE];// ���ű� �Է� �迭
int B[SIZE][SIZE] = { 0, };
int N;//�迭 ũ��
int answer;//�ּҰ��ǰ��

void init();//�ʱ�ȭ
void elect();//���ű� ����
void oneArea(int X, int Y, int D1, int D2);//�Ϲ� ���ű�
void twoArea(int X, int Y, int D1, int D2);//�̹� ���ű�
void treeArea(int X, int Y, int D1, int D2);//��� ���ű�
void fourArea(int X, int Y, int D1, int D2);//��� ���ű� 
void fiveArea(int X, int Y, int D1, int D2);//���� ���ű�
void five(int X, int Y, int D1, int D2);//���� ���ű�
bool safeZone(int y, int x);// ����üũ
void result();//����� ����

int main(void)
{
	int testCase = 1;
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		elect();
		printf("%d\n", answer);
	}
	return 0;
}
void init() {
	N = 0;
	answer = 0x7fffffff;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}
void elect() {
	for (int d1 = 1; d1 <= N; d1++) {
		for (int d2 = 1; d2 <= N; d2++) {

			for (int x = 1; x <= N; x++) {
				for (int y = 1; y <= N; y++) {
					if (x + d1 + d2 <= N && y - d1 < y&&y + d2 <= N) {

						memset(B, 0, sizeof(B));
						fiveArea(x, y, d1, d2);
						oneArea(x, y, d1, d2);
						twoArea(x, y, d1, d2);
						treeArea(x, y, d1, d2);
						fourArea(x, y, d1, d2);
						result();
					}
				}//for y=1
			}//for x=1

		}//for d2 
	}//for d1 
}
void fiveArea(int X, int Y, int D1, int D2) {
	vector<Data> fiveStart;
	for (int x = X, y = Y; x <X + D1, y > Y - D1; x++, y--) {
		if (safeZone(x, y))
			fiveStart.push_back({ x, y });
	}
	for (int x = X + D1, y = Y - D1; x <= X + D1 + D2, y <= Y - D1 + D2; x++, y++) {
		if (safeZone(x, y))
			fiveStart.push_back({ x, y });
	}
	vector<Data> fiveEnd;
	for (int x = X, y = Y; x < X + D2, y < Y + D2; x++, y++) {
		if (safeZone(x, y))
			fiveEnd.push_back({ x,y });
	}
	for (int x = X + D2, y = Y + D2; x <= X + D2 + D1, y >= Y + D2 - D1; x++, y--) {
		if (safeZone(x, y))
			fiveEnd.push_back({ x,y });
	}
	for (int i = 0; i < fiveStart.size(); i++) {
		int x = fiveStart[i].x;
		for (int y = fiveStart[i].y; y <= fiveEnd[i].y; y++) {
			B[x][y] = 5;
		}
	}
	int a;
}
void oneArea(int X, int Y, int D1, int D2) {
	for (int r = 1; r < X + D1; r++) {
		for (int c = 1; c <= Y; c++) {
			if (B[r][c] == 0)B[r][c] = 1;
		}
	}
}

void twoArea(int X, int Y, int D1, int D2) {
	for (int r = 1; r <= X + D2; r++) {
		for (int c = Y + 1; c <= N; c++) {
			if (B[r][c] == 0)B[r][c] = 2;
		}
	}
}
void treeArea(int X, int Y, int D1, int D2) {
	for (int r = X + D1; r <= N; r++) {
		for (int c = 1; c < Y - D1 + D2; c++) {
			if (B[r][c] == 0)B[r][c] = 3;
		}
	}
}
void fourArea(int X, int Y, int D1, int D2) {
	for (int r = X + D2 + 1; r <= N; r++) {
		for (int c = Y - D1 + D2; c <= N; c++) {
			if (B[r][c] == 0)B[r][c] = 4;
		}
	}
}
bool safeZone(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}
void result() {
	int num[7] = { 0, };//��������
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			num[B[i][j]] += A[i][j];
		}
	}
	int peopleMin = 0x7fffffff;
	int peopleMax = 0x80000000;
	for (int i = 1; i <= 5; i++) {
		peopleMin = min(peopleMin, num[i]);
		peopleMax = max(peopleMax, num[i]);
	}
	answer = min(answer, peopleMax - peopleMin);
}

void five(int X, int Y, int d1, int d2) {

	//(x, y), (x + 1, y - 1), (x + d1, y - d1)
	vector<int>sx;//x���� ����
	vector<int>ex;//x�� ����
	vector<int>sy;//y���� ����
	vector<int>ey;//y�� ����
	for (int x = X, y = Y; x < X + d1, y > Y - d1; x++, y--) {
		B[x][y] = 5;
		sx.push_back(x);
		sy.push_back(y);//
	}
	//(x, y), (x + 1, y + 1),(x + d2, y + d2)
	for (int x = X, y = Y; x < X + d2, y < Y + d2; x++, y++) {
		B[x][y] = 5;
		ex.push_back(x);
		ey.push_back(y);
	}
	//(x + d1, y - d1), (x + d1 + 1, y - d1 + 1),(x + d1 + d2, y - d1 + d2)
	for (int x = X + d1, y = Y - d1; x <= X + d1 + d2, y <= Y - d1 + d2; x++, y++) {
		B[x][y] = 5;
		sx.push_back(x);
		sy.push_back(y);//
	}
	//x + d2, y + d2), (x + d2 + 1, y + d2 - 1),(x + d2 + d1, y + d2 - d1)
	for (int x = X + d2, y = Y + d2; x <= X + d2 + d1, y >= Y + d2 - d1; x++, y--) {
		B[x][y] = 5;
		ex.push_back(x);
		ey.push_back(y);
	}

	for (int i = 0; i < sx.size(); i++) {
		for (int x = sx[i]; x <= ex[i]; x++) {
			for (int y = sy[i]; y <= ey[i]; y++) {
				B[x][y] = 5;

			}
		}
	}


}