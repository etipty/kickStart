#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int count = 0;
		vector<int> height;
		while (count < n) {
			int tempH;
			cin >> tempH;
			height.push_back(tempH);
			count++;
		}

		// ���������dp,0��ʾ��������ȥ��1��ʾ��������ȥ;0��ʾ���ü��ܣ�1��ʾ�ü���
		vector<vector<int>> dp(n, vector<int>(2, 0));
		// ���Ž��б���
		for (int j = 1; j < n; j++) {
			for (int i = 1; i <= k && i <= (n-j) ; i++) {
				if (height[n - j - i] >= height[n-j]) {
					dp[n - j - i][0] = 1;
					dp[n - j - i][1] = 1;
				}
				else {
					dp[n - j - i][0] = 0;
					dp[n - j - i][1] = 1;
				}
			}
		}
		if (dp[0][0] || dp[0][1]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	system("pause");
}