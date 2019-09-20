#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

/*这种穷举每一轮的办法不对，因为C在那一轮选择拿了球会对其有影响，但状态只记录了前一轮的，后续某一轮会赢球在前序有多种可能的选择，
*而这种写法像是深度优先遍历，每一次并没有把当前状态定下来，递推公式是错的
*/
/* C的状态只有1取红，0不取红*/
// 计算每一轮胜出的概率
void getRate(int i, int preC, int numsH, int nums, vector<vector<double>>& dp) {
	//if(numsH == 0) 
	if (nums <= 0) return;
	if (numsH == 0) return ;

	if (preC == 1) {
		double sh = ((double)(nums - numsH + 2) / (nums + 3))*((double)(nums - numsH + 1) / (nums + 2))*((double)(numsH + 1) / (nums + 1));
		dp[i][1] += ((double)numsH/ nums)* sh;
		if (nums < 3)return;
	}
	else if (preC == 0) {
		double sh = ((double)(nums - numsH + 3) / (nums + 3))*((double)(nums - numsH + 2) / (nums + 2))*((double)(nums - numsH + 1) / (nums + 1));
		dp[i][0] += ((double)numsH / nums)*sh;
		if (nums < 3)return;
	}

	// 本轮C可能取红也可能不取红
	getRate(i + 1, 0, numsH, nums - 3, dp);
	getRate(i + 1, 1, numsH - 1, nums - 3, dp);
}

double solve(int n, int m) {
	int nums = n + m;
	vector<vector<double>> dp(n, vector<double>(2, 0));

	double result = 0;

	dp[0][0] = (double)n / nums;
	// 从1开始真正
	getRate(1, 0, n, nums-3, dp);
	getRate(1, 1, n - 1, nums - 3, dp);

	for (int i = 0; i < n; i++) {
		result = result + dp[i][0] + dp[i][1];
	}

	return result;

}

int main() {
	
	while (1) {
		int n, m;
		cin >> n >> m;

		double result = solve(n, m);

		cout << fixed << setprecision(5) << result << endl;
	}

	system("pause");

}
