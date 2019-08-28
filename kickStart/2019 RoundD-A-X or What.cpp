#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int A[N];
int Count[N];

bool isXorEven(int *Astart, int *Aend) {
	int sum = 0;
	for (int *i = Astart; i <= Aend; i++) {
		sum ^= *i;
	}
	int count = 0;
	while (sum) {
		int mod = sum % 2;
		if(mod == 1)count++;
		sum = sum / 2;
	}

	if (count % 2 == 0)return true;
	else return false;
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int Ni, Q;
		scanf_s("%d%d", &Ni, &Q);
		// 初始化数组
		memset(A, 0, sizeof(A));
		memset(Count, 0, sizeof(Count));

		int index = 0;
		while (index < Ni)scanf_s("%d", &A[index++]);
		int qi = 0;
		while (qi<Q) {
			int P, V;
			scanf_s("%d%d", &P, &V);
			A[P] = V;

			// 计算异或和
			int maxCount = 0;
			for (int i = 0; i < Ni; i++) {
				//int iSum = 0;
				//iSum ^= A[i];
				// 需要考虑可能只有一个得情况
				bool isEven = isXorEven(A + i, A + i);
				if (isEven) {
					if (maxCount<1) maxCount = 1;
				}
				for (int j = i + 1; j < Ni; j++) {
					//iSum ^= A[j];
					bool isEven = isXorEven(A + i, A + j); // 中断位置出错，也可能当前不是偶但与之后的结合就成偶了
					// 先不跳出，试下
					if (isEven) {
						int tempCount = j - i + 1;
						if (tempCount > maxCount)maxCount = tempCount;
					}
				}
				if (maxCount >= Ni - i) break;
			}

			Count[qi++] = maxCount;
		}

		printf("Case #%d:", iCase);
		for (int j = 0; j < Q; j++) {
			printf(" %d", Count[j]);
		}
		printf("\n");
	}
	system("pause");
}