/*
给出两个长度为n的数组a和b，然后求其所有可能组成的数对的和的异或，即所有可能的（a[i]+b[j]）的异或
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int b[maxn];

int n;

int main()
{
	cin >> n;
	for (int i = 0; i<n; ++i) cin >> a[i];
	for (int i = 0; i<n; ++i) cin >> b[i];
	int ans = 0;
	for (int v = (1 << 28); v; v >>= 1) {
		int tp = 0;
		for (int i = 0; i<n; ++i) {
			a[i] &= ((v << 1) - 1);
			b[i] &= ((v << 1) - 1);
		}
		sort(a, a + n);
		sort(b, b + n);
		for (int i = n - 1; i >= 0; --i) {//枚举a
			int v1 = lower_bound(b, b + n, v - a[i]) - b;
			int v2 = lower_bound(b, b + n, 2 * v - a[i]) - b;
			int v3 = lower_bound(b, b + n, 3 * v - a[i]) - b;
			tp += v2 - v1 + n - v3;
			tp &= 1;
		}
		if (tp) ans |= v;
	}
	cout << ans << endl;
	return 0;
}