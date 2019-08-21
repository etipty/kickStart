/*********************************数位DP练习*****************************************/
/*No 62*/
#include<stdio.h>
#include<iostream>

int a[18]; // 用来存储每一位数
int dp[18][2]; // 用来存储状态

// 数位DP实际上是一个每位按可能去值进行深度遍历取值的结果
int dfs(int pos, int pre, int status, bool limit) {
	if (pos == -1) return 1;
	if (!limit && dp[pos][status] != -1) return dp[pos][status]; // 因为没有限制的情况下状态与输入数无关，其统计次数一致
	int up = limit ? a[pos] : 9;
	int tmp = 0;
	for (int i = 0; i <= up; i++) {
		if (i == 4) continue;
		if (pre == 6 && i == 2) continue;
		tmp += dfs(pos - 1, i, i == 6, limit && i == a[pos]);
	}
	if (!limit)dp[pos][status] = tmp; // 因为没有限制的情况下状态与输入数无关，其统计次数一致，所以需要记录状态
	return tmp; // 对于没有存储状态值的情况下统计次数即为计算所得
}

int solve(int x) {
	int pos = 0;
	while (x) {
		a[pos++] = x % 10; // 从低位开始存储
		x = x / 10; // 此句不能忘，否则会导致死循环！
	}
	return dfs(pos - 1, -1, 0, true); // 因为首字的前位不存在，而0是可能会存在的影响值，所以应用不在范围内的值进行前位赋值
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--) {
		iCase++;
		int L, R;
		scanf_s("%d%d", &L, &R);
		printf("Case #%d: %d", iCase, solve(R) - solve(L) + 1);
	}
}

