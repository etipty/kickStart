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

		// 使得时间最短，即最接近的组合
		// 需要降序排列，可以用reverse
		sort(a, a + N);
		reverse(a, a + N);

		// 构建初始状态，然后用一个滑动窗口进行移动查找，
		// 维护一个状态sum，使得空间复杂度降低
		int cur_skill = 0;
		int cur_sum = a[0] * P;
		for (int i = 0; i<P; i++) {
			cur_sum -= a[i];
			cur_skill += a[i];
		}

		// 移动窗口遍历求最小
		for (int i = P; i<N; i++) {
			cur_skill += a[i] - a[i - P];
			cur_sum = min(cur_sum, a[i - P + 1] * P - cur_skill);
		}

		printf("Case #%d: %d\n", iCase, cur_sum);
	}
}