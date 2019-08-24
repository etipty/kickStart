#include<stdio.h>

int E[110];
int L[110];

void sort_maopao(int E[], int L[], int size) {
	for (int i = 0; i<size; i++) {
		for (int j = i + 1; j<size; j++) {
			if (L[i]>L[j]) {
				// 将损失最大的冒至最后
				int tmpL = L[j];
				L[j] = L[i];
				L[i] = tmpL;

				int tmp = E[j];
				E[j] = E[i];
				E[i] = tmp;
			}
			else if (L[i] == L[j]) {
				if (E[i]<E[j]) {
					// 将能量最小的冒至最后
					int tmp = E[j];
					E[j] = E[i];
					E[i] = tmp;

					int tmpL = L[j];
					L[j] = L[i];
					L[i] = tmpL;
				}
			}
		}

	}
}

int main() {
	int T;
	scanf_s("%d", &T);
	int iCase = 0;
	while (T--) {
		iCase++;
		int N, S;
		scanf_s("%d", &N);
		int i = 0;
		while (N--) {
			scanf_s("%d%d%d", &S, &E[i], &L[i]);
			i++;
		}
		sort_maopao(E, L, i);

		int totEnergy = 0;
		for (int j = 0; j<i; j++) {
			if (E[j] == 0) {
				printf("Case #%d: %d\n", iCase, totEnergy);
				break;
			}
			totEnergy += E[j];

			for (int k = 0; k<i; k++) {
				if (E[k] >= L[k] * S)
				{
					E[k] -= L[k] * S;
				}
				else {
					E[k] = 0;
				}
			}
		}

	}
}