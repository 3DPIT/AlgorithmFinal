//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//int horseScore[10];
//int D[10];
//int answer;//�����
//int ret;
//int board[33] = {
//	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
//	13,16,19,22,24,28,27,26,25,30,35,40,0
//};
//void init();//�ʱ�ȭ �� �Է�
//void dfs(int idx, int cnt);//4���� ����
//bool move(int num, int idx);//���� �̵�
//struct Data {
//	int idx,flag;
//}horse[5];
//int main(void) {
//	int testCase = 1;
//	for (int tc = 1; tc <= testCase; tc++) {
//		init();
//		dfs(0, 0);
//		printf("%d\n", answer);
//	}
//	return 0;
//}
//void init() {
//	memset(horseScore, 0, sizeof(horseScore));
//	answer = 0x80000000;
//	for(int i=1;i<=4;i++)
//	horse[i].idx = -1;
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &horseScore[i]);
//	}
//}
//bool move(int num,int idx) {
//	for (int i = 0; i < horseScore[idx]; i++) {
//		if (horse[num].flag == -1)continue;
//		else if (horse[num].idx == 4 && horse[num].flag == 1) {
//			horse[num].flag = 0;
//			horse[num].idx = 19;
//		}
//		else if (horse[num].idx == 9 && horse[num].flag == 1) {
//			horse[num].flag = 0;
//			horse[num].idx = 22;
//		}
//		else if (horse[num].idx == 14 && horse[num].flag == 1) {
//			horse[num].flag = 0;
//			horse[num].idx = 24;
//		}
//		else if (horse[num].idx == 18 && horse[num].flag == 1) {
//			horse[num].flag = 0;
//			horse[num].idx = 30;
//		}
//		else if ((horse[num].idx == 21|| horse[num].idx == 23|| horse[num].idx == 26)) {
//			horse[num].flag = 0;
//			horse[num].idx = 27;
//		}
//		else if ((horse[num].idx == 30)) horse[num].flag = -1;
//		else horse[num].idx++;
//	}
//	for (int i = 1; i <= 4; i++) {//Ȯ��
//			if (i!=num&&horse[i].idx!=-1&&horse[num].idx!=-1&& horse[i].flag != -1&& horse[num].flag!=-1 &&
//				horse[i].idx == horse[num].idx)return 0;
//	}
//	if (horse[num].idx == 4 || horse[num].idx == 9 || horse[num].idx == 14 || horse[num].idx == 18
//		||horse[num].idx==21||horse[num].idx==23||horse[num].idx==26) {
//		horse[num].flag = 1;//�̵� üũ
//	}
//	if(horse[num].flag!=-1)
//	ret +=board[horse[num].idx];
//	return 1;
//}
//
//void dfs(int idx, int cnt) {
//	if (cnt == 10) {
//		for (int i = 1; i <= 4; i++) {
//			horse[i].idx = -1;
//			horse[i].flag = 0;
//		}
//		ret = 0;
//		for (int k= 0; k < 10; k++) {
//			if (move(D[k], k) == 0) return;
//		}
//		answer = max(answer, ret);
//		return;
//	}
//	for (int i = 1; i <= 4; i++) {
//		D[idx] = i;//�ְ� 
//		dfs(idx + 1, cnt + 1);
//		D[idx] = 0;//����
//	}
//}
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define S 10
int cube[S];//�ֻ������� �� ���� �迭
int ret;//����� ���庯��
int D[S];//1���� ���� 4���� ���� ����
int B[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-1,
			13,16,19,25,22,24,28,27,26,30,35 };//������ �� ����
struct Data {
	int idx, pidx;//������ �ε��� ���� ������ �ε�����
};
void init_input() {//�ʱ�ȭ �� �ʱ� �Է�
	//�ʱ�ȭ
	ret = 0x80000000;//�ּҰ� ����
	memset(cube, 0, sizeof(cube));
	memset(D, 0, sizeof(D));
	//�ʱ� �Է�
	for (int i = 0; i < 10; i++) {
		scanf("%d", &cube[i]);
	}
}
void dfs(int idx, int cnt) {//1. ���� �� ���� ���� ���ϱ�(o)
	if (cnt == 10) {
		int sum = 0;//�� ����
		Data horse_info[5] = { 0, };
		for (int i = 0; i < 10; i++) {//���� ������� ����
			int num = D[i];//���� ����
			for (int j = 0; j < cube[i]; j++) {//���� �̵�����
				//3. ������ĭ ������ ���̵� ���� ��Ű��
				if (horse_info[num].pidx == -1)continue;
				if (horse_info[num].pidx != 0) {//��ġ �̵� ��Ű�� Ư���� ĭ����
					horse_info[num].idx = horse_info[num].pidx;//��ġ �̵�
					horse_info[num].pidx = 0;
				}
				else if (horse_info[num].pidx != -1) {//+1�� �����Ǵ� ĭ������ �̵�
					horse_info[num].idx++;
				}
				if (horse_info[num].idx == 27)horse_info[num].pidx = 25;//24->25
				else if (horse_info[num].idx == 30)horse_info[num].pidx = 25;//26->25
				else if (horse_info[num].idx == 25)horse_info[num].pidx = 31;//25->30
				else if (horse_info[num].idx == 32) horse_info[num].pidx = 20;//35->40
				else if (horse_info[num].idx == 21)	horse_info[num].pidx = -1;//40->����

			}
			//2. �̵��� �������� ���� �ִ��� Ȯ���ؼ� �� ����� ��ü�� �������� �׸��� ������������
			for (int h = 1; h <= 4; h++) {
				if (h != num && horse_info[num].idx != 0 && horse_info[num].pidx != -1 &&
					horse_info[h].idx == horse_info[num].idx) {
					return;//��ü ���Ͻ�Ű��
				}
			}
			if (horse_info[num].pidx != -1) sum += B[horse_info[num].idx];//���� ����

			//�Ķ� �κп� ���߸� �׹������� �̵� ��Ű�� ���� 
			if (horse_info[num].idx == 5) horse_info[num].pidx = 22;//10->13
			else if (horse_info[num].idx == 10)horse_info[num].pidx = 26;//20->22
			else if (horse_info[num].idx == 15) horse_info[num].pidx = 28;//30->28

		}
		//4. �ù� ����� ������ �ִ밪 ���ؼ� ret �� �����ϱ�
		ret = max(ret, sum);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (D[idx] == 0) {
			D[idx] = i;
			dfs(idx + 1, cnt + 1);
			D[idx] = 0;
		}
	}

}
void play() {
	dfs(0, 0);
}
int main(void) {
	int T = 1;//�׽�Ʈ ���̽� ����
	//scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init_input();//�ʱ�ȭ �� �ʱ� �Է�
		play();//���� ����
		//���
		printf("%d\n", ret); //printf("#%d %d\n", tc, ret);
	}
	return 0;
}
