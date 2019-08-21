/*No Nine*/
#include<stdio.h>
#include<cstring>


long long dp[19][9]; //ά��״̬
int a[19]; // �洢��λ

// ������ȱ�����λ���ܵ�ȡֵ�з������������ĸ���
long long dfs(int pos, int mod, bool limit) {
	if (pos == -1) {
		if (mod > 0) return 1; // ���ȡ������֮����������0�����������
		else return 0;
	}
	if (!limit && dp[pos][mod] != -1) return dp[pos][mod];

	int up = limit ? a[pos] : 8; // ��Ϊ����ȡ9������ֱ��������8
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
	// ״̬�������޹أ�������ⲿ���г�ʼ��
	memset(dp, -1, sizeof(dp));
	while (T--) {
		iCase++;
		long long F, L;
		scanf_s("%lld%lld", &F, &L);
		printf("Case #%d: %lld\n", iCase, solve(L) - solve(F) + 1);
	}
}