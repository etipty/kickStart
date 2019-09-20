/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

	 来源：力扣（LeetCode）
	 链接：https://leetcode-cn.com/problems/burst-balloons
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

执行结果：通过 显示详情
执行用时 :
20 ms, 在所有 C++ 提交中击败了97.82%的用户
内存消耗 :
9.3 MB, 在所有 C++ 提交中击败了48.29%的用户
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxCoins(vector<int>& nums) {

	int N = nums.size();

	// 首尾插入1，使其符合条件
	nums.insert(nums.begin(), 1);
	nums.insert(nums.end(), 1);

	// 定义一个数组，用来记录不同取值边界下，该边界条件内的区间段的最大值
	vector<vector<int>> rangeValues(N+2, vector<int>(N+2, 0));

	for (int len = 1; len <= N; len++) {
		for (int start = 1; start <= N - len + 1; start++) {
			int end = start + len - 1;
			/*int bestcoins = 0;*/

			for (int fina = start; fina <= end; fina++) {

				rangeValues[start][end] = max(rangeValues[start][end], nums[start - 1] * nums[fina] * nums[end + 1] + rangeValues[start][fina - 1] + rangeValues[fina + 1][end]);
				/*int coins = rangeValues[start][fina - 1] + rangeValues[fina + 1][end];
				coins += nums[start - 1] * nums[fina] * nums[end + 1];
				if (coins>bestcoins) bestcoins = coins;*/
			}

			/*rangeValues[start][end] = bestcoins;*/
		}
	}

	return rangeValues[1][N];

}

int main() {
	vector<int>  nums = { 3,1,5,8 };
	int result = maxCoins(nums);
	cout << result<<endl;
	system("pause");
}