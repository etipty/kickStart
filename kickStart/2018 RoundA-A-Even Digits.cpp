/* Even digits 根据思路写的正确解法*/
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

// 获取比其大的最小beautiful integer
long long getNextInt(long long N) {
	int num[20]; //大数级为16次，故不会超过16位
	int ctn = 0; // 记录数据的位数

	// 依次将数存进数组
	do {
		num[ctn++] = N % 10;
		N = N / 10;
	} while (N);

	num[ctn++] = 0; // 防止为9时高位进一溢出
	// 从高位开始判断奇偶性
	for (int i = ctn - 1; i >= 0; i--) {
		if (num[i] & 1) {
			// 9特殊
			if (num[i] == 9) {
				int j = i + 1;
				while (num[j] == 8)j++; // 找到不为8的偶数才能加，其余全为0
				num[j] += 2;
				while (j)num[--j] = 0;
			}
			else {
				num[i] += 1;
				int j = i;
				while (j)num[--j] = 0;
			}
			break;
		}
	}

	long long ans = 0;
	for (int i = ctn - 1; i >= 0; i--) {
		ans = ans * 10 + num[i];
	}
	return ans;
}

// 获取比其小的最大beautiful integer
long long getPreInt(long long N) {
	int num[20]; //大数级为16次，故不会超过16位
	int ctn = 0; // 记录数据的位数

	// 依次将数存进数组
	do {
		num[ctn++] = N % 10;
		N = N / 10;
	} while (N);

	// 从高位开始判断奇偶性
	for (int i = ctn - 1; i >= 0; i--) {
		if (num[i] & 1) {
			num[i]--;
			int j = i;
			while (j)num[--j] = 8;
			break;
		}
	}

	long long ans = 0;
	for (int i = ctn - 1; i >= 0; i--) {
		ans = ans * 10 + num[i];
	}
	return ans;
}

int main() {
	int T;
	scanf_s("%d", &T);
	int iCase = 0;
	while (T--) {
		iCase++;
		long long N;
		scanf_s("%lld", &N);
		long long nextInt = getNextInt(N);
		long long preInt = getPreInt(N);
		printf("Case #%d: %lld\n", iCase, min((nextInt - N), (N - preInt)));
	}
	return 0;
}