/*
˼·�������������ɣ�Ҫ��string��find����
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

	// ����Ҳ����
	//int count = 0;
	vector<int> jiangeNum;
	int pre = 0;// ���Լ�¼��һ����λ��

	for (int i = 0; i < library.size(); i++) {
		//if (library[i] == 1) {
		//	if (count == 0 && i != 0) {
		//		jiangeNum.push_back(i + 2);
		//	}
		//	count++;
		//	if (count >= k) {
		//		// Ҫ����k��1
		//		jiangeNum.push_back(i - pre + 1);
		//	}
		//	pre = i;
		//}
		if (library[i] == 1) {
			// Ҫ����k��1
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