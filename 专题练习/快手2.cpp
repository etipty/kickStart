/*
思路：求出间隔数即可，要用string的find函数
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int k;
	cin >> k;
	string library;
	cin >> library;

	// 暴力也不大
	//int count = 0;
	vector<int> jiangeNum;
	int pre = 0;// 用以记录上一个的位置

	for (int i = 0; i < library.size(); i++) {
		//if (library[i] == 1) {
		//	if (count == 0 && i != 0) {
		//		jiangeNum.push_back(i + 2);
		//	}
		//	count++;
		//	if (count >= k) {
		//		// 要求有k个1
		//		jiangeNum.push_back(i - pre + 1);
		//	}
		//	pre = i;
		//}
		if (library[i] == 1) {
			// 要求有k个1
			jiangeNum.push_back(i - pre + 1);
			pre = i;
		}
	}
	int result = 0;
	for (int i = 1; i < jiangeNum.size(); i++) {
		result += jiangeNum[i] * jiangeNum[i - 1] - jiangeNum[i];
	}
	result = result - jiangeNum[jiangeNum.size() - 1];
	cout << result;
	system("pause");
}