#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

//const int N = 100;
//int A[N+1][N+1]; // ���ڼ�¼��
//int dist[N+1];
//int S[N+1];
//int P[N+1];

int shortestRoad(int Vi,int Ni,vector<vector<int>> A) {
	//memset(S, -1, sizeof(S));
	vector<int> S(Ni+1, -1);
	S[Vi] = 1;
	//memset(P, Vi, sizeof(P));
	vector<int> P(Ni + 1, Vi);
	//memset(dist, 2*Ni+1, sizeof(dist));
	vector<int> dist(Ni + 1,  2 * Ni + 1);
	for (int i = 1; i < Ni + 1; i++) {
		dist[i] = A[Vi][i];
	}
	
	int tolen = 0;
	while (tolen < Ni - 1) {
		//ÿ������С������д洢
		int minDist = 2 * Ni + 1;
		int m = -1; // �����С
		for (int j = 1; j < Ni + 1; j++) {
			if (S[j] == -1) {
				if (dist[j] < minDist) {
					minDist = dist[j];
					m = j;
				}
			}
		}
		S[m] = 1; // ����ѽ�ȥ

		//���¾���
		for (int j = 1; j < Ni + 1; j++) {
			if (S[j] == -1) {
				if (dist[j] >= A[Vi][m] + A[m][j]) {
					dist[j] = A[Vi][m] + A[m][j];
					P[j] = m;
				}
			}
		}
		tolen++;
	}// ������Vi��ͼ�и�������·��

	// �����·������
	int result = 0;
	for (int j = 1; j < Ni + 1; j++) {
		int pre = P[j];
		if (pre == -1) continue; // �ٳ�����
		if (pre == j) continue; // �ٳ�����
		result += A[pre][j];
	}
	return result;
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int Ni, Mi;
		scanf_s("%d%d", &Ni, &Mi);
		// �߳�ֵ��Ϊ���ǣ�����M���������Ϊ����
		//memset(A, 2, sizeof(A)/sizeof(int)); 
		vector<vector<int>> A(Ni + 1, vector<int>(Ni + 1, 2));

		for (int i = 0; i < Mi; i++) {
			int Ci, Di;
			scanf_s("%d%d", &Ci, &Di);
			// ��1Ϊ��ʼ,Ϊ����ͼ�������߶�Ҫ��
			A[Ci][Di] = 1;
			A[Di][Ci] = 1;
		}

		// ������ʹ��dijkstra�㷨����Ը�����Ϊ��ʼ������·��
		int minNum = 2 * Ni + 1;
		for (int j = 1; j <= Ni; j++) {
			int tempNum = shortestRoad(j,Ni,A);
			if (tempNum < minNum)minNum = tempNum;
		}

		printf("Case #%d: %d", iCase, minNum);
		system("pause");
	}
}
