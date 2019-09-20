/*
��֤��ȷͨ���ĳ���
����ؼ������ڣ�
1.�������е���ֻҪ�����������ߵķ�������ͬ�ģ���ô������Ϳ�����������������
2.�����ұ߷�����ͬ������Լ���һ�����������������ǰ�����һ���������
3.����'*'��'+'������Դӵ�һ����һ���������򣻶���'-'��'/'�����ӵڶ�������ʼ��������

��ʵ���ڱ���ؼ����ڷ��������Բ���ʵ�������㷨��ֱ����sort����
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

// ����������ð������ĸĽ���ÿ�ν���λһ��Ԫ�أ���һ�����в��ϻ���Ϊ�������εݹ�������ȥ���ʱ�临�Ӷ�O(n^2)�����ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(logn)
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