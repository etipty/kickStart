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

		// 对数组进行dp,0表示不能跳过去，1表示可以跳过去;0表示不用技能，1表示用技能
		vector<vector<int>> dp(n, vector<int>(2, 0));
		// 倒着进行遍历
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