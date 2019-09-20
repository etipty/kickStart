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

	// ������ʽ���ԣ�����2��3λ������ȡ����
	vector<int> nums;
	string tempNum = "";
	for (int i = 0; i < _s1.size(); i++) {
		if (_s1[i] == ' ') {
			// ˵����ǰ���ѻ�ȡ��ϣ���Ӧ���д洢
			int num = atoi(tempNum.c_str());//���ַ���תΪ����
			nums.push_back(num);
			tempNum = ""; // ����ʱ�洢�ַ�����գ�������һ�δ洢
		}
		else {
			tempNum.push_back(_s1[i]); // һֱŪ������������
		}
	}

	// Я�������������Ƕ����������ݵĶ�ȡ���޷����ԣ�����д�����������̶��������ͨ������OJ����

	/*vector<int> nums;
	int a;
	while (cin >> a) {
		nums.push_back(a);
	}*/

	int result = maxProduct(nums);

	cout << result;

	system("pause");
}