/* Even digits ����˼·д����ȷ�ⷨ*/
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

// ��ȡ��������Сbeautiful integer
long long getNextInt(long long N) {
	int num[20]; //������Ϊ16�Σ��ʲ��ᳬ��16λ
	int ctn = 0; // ��¼���ݵ�λ��

	// ���ν����������
	do {
		num[ctn++] = N % 10;
		N = N / 10;
	} while (N);

	num[ctn++] = 0; // ��ֹΪ9ʱ��λ��һ���
	// �Ӹ�λ��ʼ�ж���ż��
	for (int i = ctn - 1; i >= 0; i--) {
		if (num[i] & 1) {
			// 9����
			if (num[i] == 9) {
				int j = i + 1;
				while (num[j] == 8)j++; // �ҵ���Ϊ8��ż�����ܼӣ�����ȫΪ0
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

// ��ȡ����С�����beautiful integer
long long getPreInt(long long N) {
	int num[20]; //������Ϊ16�Σ��ʲ��ᳬ��16λ
	int ctn = 0; // ��¼���ݵ�λ��

	// ���ν����������
	do {
		num[ctn++] = N % 10;
		N = N / 10;
	} while (N);

	// �Ӹ�λ��ʼ�ж���ż��
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