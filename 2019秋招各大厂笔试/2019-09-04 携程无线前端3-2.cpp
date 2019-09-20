// DP�ⷨ����Ϊ����ֻ����ҳ����ֵ���ɣ���˲��ؿ�һ�����飬�����������������ж�̬����ά��

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

		// ��̬�洢����ǰԪ��ʱ���������л��������Сֵ
		imax = max(nums[i], nums[i] * imax);
		imin = min(nums[i], nums[i] * imin);

		// ÿ����һ��Ԫ�غ�Ҫ��ֵ���и��£�����ʵ����δ����0������ͨ���жϸ����ĸ�������ȥͷ��ȥβѡ��
		// ���Ƕ�̬���µ�ÿ��λ�õ�״̬��������ʽ������0��ȥͷȥβ���޷������м�0״̬
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