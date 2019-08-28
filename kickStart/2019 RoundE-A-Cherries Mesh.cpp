#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

//const int N = 100;
//int A[N+1][N+1]; // 用于记录边
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
		//每次找最小距离进行存储
		int minDist = 2 * Ni + 1;
		int m = -1; // 标记最小
		for (int j = 1; j < Ni + 1; j++) {
			if (S[j] == -1) {
				if (dist[j] < minDist) {
					minDist = dist[j];
					m = j;
				}
			}
		}
		S[m] = 1; // 标记已进去

		//更新距离
		for (int j = 1; j < Ni + 1; j++) {
			if (S[j] == -1) {
				if (dist[j] >= A[Vi][m] + A[m][j]) {
					dist[j] = A[Vi][m] + A[m][j];
					P[j] = m;
				}
			}
		}
		tolen++;
	}// 更新完Vi至图中各点得最短路径

	// 求最短路径长度
	int result = 0;
	for (int j = 1; j < Ni + 1; j++) {
		int pre = P[j];
		if (pre == -1) continue; // 刨除顶点
		if (pre == j) continue; // 刨除自身
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
		// 边初值设为红糖，根据M得情况再设为黑糖
		//memset(A, 2, sizeof(A)/sizeof(int)); 
		vector<vector<int>> A(Ni + 1, vector<int>(Ni + 1, 2));

		for (int i = 0; i < Mi; i++) {
			int Ci, Di;
			scanf_s("%d%d", &Ci, &Di);
			// 以1为起始,为无向图，故两边都要改
			A[Ci][Di] = 1;
			A[Di][Ci] = 1;
		}

		// 遍历，使用dijkstra算法求解以各定点为起始点得最短路径
		int minNum = 2 * Ni + 1;
		for (int j = 1; j <= Ni; j++) {
			int tempNum = shortestRoad(j,Ni,A);
			if (tempNum < minNum)minNum = tempNum;
		}

		printf("Case #%d: %d", iCase, minNum);
		system("pause");
	}
}
