#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;

const int N = 1e2 + 5;
const int M = 1e2 + 5;
//set<int> dp[N+1][M];
int dp[N + 1][N + 1][2];// 多一维区分是不是当前
int startPos[N + 1];
char dir[N+1];

void nStatu(int min, int Gi, int Ni) {
	int currentPos;
	// 
	for (int i = 1; i < Gi; i++) {
		dp[currentPos][i][0] = dp[currentPos][i][1];
	}
	for (int i = 1; i < Gi; i++) {
		if (dir[i] == 'C') {
			currentPos = (startPos[i] + min) % Ni ? (startPos[i] + min) % Ni : Ni;
		}
		else {
			currentPos = (startPos[i] - min) % Ni + Ni ? (startPos[i] - min) % Ni + Ni : Ni;
		}
		// 需要在记录第min时对第min-1得数据初始化
		dp[currentPos][i][1] = 1; // 标记记录了
	}

}

int main() {
	int T;
	int iCase = 0;
	scanf("%d", &T);
	while (T--) {
		iCase++;
		int Ni, Gi, Mi;
		scanf("%d%d%d", &Ni, &Gi, &Mi);
		int tolG = 1;
		memset(dp, 0, sizeof(dp));
		while (tolG < Gi) {
			cin >> startPos[tolG];
			cin >> dir[tolG++];
		}
		nStatu(0,Gi,Ni);
	}
}
