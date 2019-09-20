/*
验证正确通过的程序
此题关键点在于：
1.对于所有的数只要是其左右两边的符号是相同的，那么这个数就可以与其他数交换；
2.对于右边符号是同级或比自己低一级的则该数可以纳入前面的数一起进行排序
3.对于'*'和'+'，其可以从第一个数一起纳入排序；对于'-'和'/'其必须从第二个数开始纳入排序

其实对于本题关键在于分析，可以不必实现排序算法，直接用sort即可
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Partition(vector<int>& nums, int left, int right) {
	int pivot = nums[left], l = left + 1, r = right;
	while (l <= r) {
		if (nums[l] > pivot && nums[r] < pivot)
			swap(nums[l], nums[r]);
		if (nums[l] <= pivot) l++;
		if (nums[r] >= pivot) r--;
	}
	swap(nums[left], nums[r]);
	return r;
}

// 快速排序，是冒泡排序的改进，每次仅归位一个元素，将一个序列不断划分为左右两段递归排序下去，最坏时间复杂度O(n^2)，最好时间复杂度O(logn)，空间复杂度O(logn)
void QuickSort(vector<int> &nums, int lo, int hi) {
	if (hi <= lo) return;
	int seg = Partition(nums, lo, hi);
	QuickSort(nums, lo, seg - 1);
	QuickSort(nums, seg + 1, hi);
}

int main() {
	int n; cin >> n;
	vector<int> nums(n, 0);
	vector<char> ops(n, '+');
	for (int i = 0; i<n - 1; ++i) {
		cin >> nums[i];
		cin >> ops[i + 1];
	}
	cin >> nums[n - 1];

	int l = 0, r = 0;
	while (r<n) {
		while (r<n && ops[r] == ops[l]) ++r;
		--r;
		if (ops[l] == '+' || ops[l] == '-') {
			if (r<n - 1 && (ops[r + 1] == '*' || ops[r + 1] == '/'))
				QuickSort(nums, l, r - 1);
			else
				QuickSort(nums, l, r);

		}
		else if (ops[l] == '*') {
			if (l>0 && (ops[l - 1] == '+' || ops[l - 1] == '-'))
				QuickSort(nums, l - 1, r);
			else
				QuickSort(nums, l, r);
		}
		else if (ops[l] == '/') {
			QuickSort(nums, l, r);
		}
		++r; l = r;
	}

	string ans = to_string(nums[0]);
	for (int i = 1; i<n; ++i) {
		ans.push_back(' ');
		ans.push_back(ops[i]);
		ans.push_back(' ');
		ans += to_string(nums[i]);
	}
	cout << ans << endl;

	system("pause");
	return 0;
}