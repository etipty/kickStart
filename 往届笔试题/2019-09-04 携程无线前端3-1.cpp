#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
/**
* @param nums: an array of integers
* @return: an integer
*/
int maxProduct(vector<int>& nums) {
	int dp;
	int len = nums.size();
	if (len == 1)return nums[0];

	int i, maxm, minm;
	int result;

	dp = maxm = minm = nums[0];
	for (i = 1; i<len; i++) {

		if (nums[i] >= 0) {
			maxm = max(maxm*nums[i], nums[i]);
			minm = min(minm*nums[i], nums[i]);
		}
		else {
			int tmp;
			tmp = maxm;
			maxm = max(minm*nums[i], nums[i]);
			minm = min(tmp*nums[i], nums[i]);
		}
		dp = max(maxm, dp);
	}
	return dp;
}

int main() {
	string res;

	string _s1;
	getline(cin, _s1);

	// 读数方式不对，对于2、3位的数获取错误
	vector<int> nums;
	string tempNum = "";
	for (int i = 0; i < _s1.size(); i++) {
		if (_s1[i] == ' ') {
			// 说明当前数已获取完毕，则应进行存储
			int num = atoi(tempNum.c_str());//将字符串转为数字
			nums.push_back(num);
			tempNum = ""; // 将临时存储字符串归空，用于下一次存储
		}
		else {
			tempNum.push_back(_s1[i]); // 一直弄构成完整数字
		}
	}

	// 携程遇到的问题是对于输入数据的读取，无法调试，可以写方法函数，固定输入调试通过，再OJ调试

	/*vector<int> nums;
	int a;
	while (cin >> a) {
		nums.push_back(a);
	}*/

	int result = maxProduct(nums);

	cout << result;

	system("pause");
}