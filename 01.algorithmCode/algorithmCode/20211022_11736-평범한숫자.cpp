
#include<iostream>
using namespace std;
int N;
int answer;
int arr[21];//���� ����
void init();//�ʱ�ȭ �� �ʱ� �Է�
void normalNumber();//����� ���� Ȯ��
int main(int argc, char** argv)
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		normalNumber();
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void init() {
	N = answer=0;
	scanf("%d", &N);
	for(int n = 0; n < N; n++) {
		scanf("%d",&arr[n]);
	}
}
void normalNumber() {
	for (int i = 1; i < N - 1; i++) {
		int  small = 0,big = 0;
		if (arr[i - 1] < arr[i])small++;
		if (arr[i + 1] < arr[i]) small++;
		if (arr[i - 1] > arr[i])big++;
		if (arr[i + 1] > arr[i]) big++;
		if (small == 1 && big == 1)answer++;
	}
}