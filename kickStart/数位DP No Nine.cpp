/*No Nine*/
#include<stdio.h>
#include<cstring>


long long dp[19][9]; //维护状态
int a[19]; // 存储数位

// 深度优先遍历各位可能的取值中符合条件的数的个数
long long dfs(int pos, int mod, bool limit) {
	if (pos == -1) {
		if (mod > 0) return 1; // 如果取完所有之后余数大于0，则符合条件
		else return 0;
	}
	if (!limit && dp[pos][mod] != -1) return dp[pos][mod];

	int up = limit ? a[pos] : 8; // 因为不能取9，所以直接上限设8
	long long tmp = 0;
	for (int i = 0; i <= up; i++) {
		tmp += dfs(pos - 1, (mod * 10 + i) % 9, limit && i == a[pos]);
	}
	if (!limit) dp[pos][mod] = tmp;
	return tmp;
}

long long solve(long long x) {
	int pos = 0;
	while (x) {
		a[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos - 1, 0, true);
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	// 状态与输入无关，因此在外部进行初始化
	memset(dp, -1, sizeof(dp));
	while (T--) {
		iCase++;
		long long F, L;
		scanf_s("%lld%lld", &F, &L);
		printf("Case #%d: %lld\n", iCase, solve(L) - solve(F) + 1);
	}
}