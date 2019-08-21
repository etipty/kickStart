#include<stdio.h>
#include<algorithm>
using namespace std;

int a[100010];
int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int N, P;
		scanf_s("%d%d", &N, &P);
		int to = 0;
		while (to<N) {
			scanf_s("%d", &a[to++]);
		}

		// ʹ��ʱ����̣�����ӽ������
		// ��Ҫ�������У�������reverse
		sort(a, a + N);
		reverse(a, a + N);

		// ������ʼ״̬��Ȼ����һ���������ڽ����ƶ����ң�
		// ά��һ��״̬sum��ʹ�ÿռ临�ӶȽ���
		int cur_skill = 0;
		int cur_sum = a[0] * P;
		for (int i = 0; i<P; i++) {
			cur_sum -= a[i];
			cur_skill += a[i];
		}

		// �ƶ����ڱ�������С
		for (int i = P; i<N; i++) {
			cur_skill += a[i] - a[i - P];
			cur_sum = min(cur_sum, a[i - P + 1] * P - cur_skill);
		}

		printf("Case #%d: %d\n", iCase, cur_sum);
	}
}