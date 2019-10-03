/*
��n����������Ȼ��������������k�Σ�������������3����1.ѡ��n��������С������x����0����2.���x��3. ������>0������ȥx��
*/

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int nums[100010];
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	int count = 0;
//	while (count<n) {
//		cin >> nums[count++];
//	}
//
//	sort(nums, nums + n);
//
//	int wholeDown = 0;
//	for (int i = 0; i<k; i++) {
//		int j;
//		for (j = 0; j<n; j++) {
//			while (nums[j] - wholeDown <= 0)j++;
//			if (j == n) break;
//			cout << nums[j] - wholeDown << endl;
//			wholeDown = nums[j];
//			break;
//		}
//		if (j == n) break;
//	}
//	system("pause");
//}

#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	set<int> nums;
	int count = 0;
	while (count<n) {
		int tempNum;
		cin >> tempNum;
		nums.insert(tempNum);
		count++;
	}

	int wholeDown = 0;
	set<int>::iterator it = nums.begin();
	int i = 0;
	for (; i<k && it != nums.end(); i++) {
		cout << *it - wholeDown << endl;
		wholeDown = *it;
		it++;
	}
	for (; i<k; i++) {
		cout << 0 << endl;
	}
	system("pause");
}