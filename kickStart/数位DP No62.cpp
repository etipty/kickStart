/*********************************��λDP��ϰ*****************************************/
/*No 62*/
#include<stdio.h>
#include<iostream>

int a[18]; // �����洢ÿһλ��
int dp[18][2]; // �����洢״̬

// ��λDPʵ������һ��ÿλ������ȥֵ������ȱ���ȡֵ�Ľ��
int dfs(int pos, int pre, int status, bool limit) {
	if (pos == -1) return 1;
	if (!limit && dp[pos][status] != -1) return dp[pos][status]; // ��Ϊû�����Ƶ������״̬���������޹أ���ͳ�ƴ���һ��
	int up = limit ? a[pos] : 9;
	int tmp = 0;
	for (int i = 0; i <= up; i++) {
		if (i == 4) continue;
		if (pre == 6 && i == 2) continue;
		tmp += dfs(pos - 1, i, i == 6, limit && i == a[pos]);
	}
	if (!limit)dp[pos][status] = tmp; // ��Ϊû�����Ƶ������״̬���������޹أ���ͳ�ƴ���һ�£�������Ҫ��¼״̬
	return tmp; // ����û�д洢״ֵ̬�������ͳ�ƴ�����Ϊ��������
}

int solve(int x) {
	int pos = 0;
	while (x) {
		a[pos++] = x % 10; // �ӵ�λ��ʼ�洢
		x = x / 10; // �˾䲻����������ᵼ����ѭ����
	}
	return dfs(pos - 1, -1, 0, true); // ��Ϊ���ֵ�ǰλ�����ڣ���0�ǿ��ܻ���ڵ�Ӱ��ֵ������Ӧ�ò��ڷ�Χ�ڵ�ֵ����ǰλ��ֵ
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

