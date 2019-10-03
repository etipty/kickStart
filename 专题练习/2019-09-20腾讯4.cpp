/*
有n个正整数，然后将下述操作进行k次，下述操作包括3步：1.选出n个数中最小的正数x（非0）；2.输出x；3. 将所有>0的数减去x；
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