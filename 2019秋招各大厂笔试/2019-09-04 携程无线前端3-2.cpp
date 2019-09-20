// DP解法，因为最终只需查找出最大值即可，因此不必开一个数组，可以用两个变量进行动态更新维护

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
	int r = nums[0];

	int imax = nums[0];
	int imin = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < 0) swap(imax, imin);

		// 动态存储至当前元素时，连续序列积的最大、最小值
		imax = max(nums[i], nums[i] * imax);
		imin = min(nums[i], nums[i] * imin);

		// 每遍历一个元素后都要对值进行更新，但其实还是未考虑0，可以通过判断负数的个数进行去头或去尾选择
		// 因是动态更新的每个位置的状态，所以隐式考虑了0，去头去尾才无法考虑中间0状态
		r = max(r, imax); 
	}

	return r;
}

int main() {
	vector<int> nums = { 2, 3, -2, 4 };
	int max = maxProduct(nums);
	cout << max << endl;

	system("pause");
}