#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;
	getline(cin, input);

	vector<int> A;
	vector<int> B;

	int R;

	for (int i = 0; i < input.size(); ) {
		// 对数据进行分解
		if (input[i] == 'A') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					if (tempStr.size() > 0) {
						// 说明不是大的间隔符
						int tempNum = atoi(tempStr.c_str());
						A.push_back(tempNum);
						tempStr = "";
					}
				}
				else if (input[i] == '}') {
					// 说明A的获取结束了
					int tempNum = atoi(tempStr.c_str());
					A.push_back(tempNum);
					tempStr = "";
					i++;
					break;
				}
			}
		}
		else if (input[i] == 'B') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					if (tempStr.size() > 0) {
						// 说明不是大的间隔符
						int tempNum = atoi(tempStr.c_str());
						B.push_back(tempNum);
						tempStr = "";
					}
				}
				else if (input[i] == '}') {
					// 说明A的获取结束了
					int tempNum = atoi(tempStr.c_str());
					B.push_back(tempNum);
					tempStr = "";
					i++;
					break;
				}
			}
		}
		else if (input[i] == 'R') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					// 说明R是在前面获取的
					int tempNum = atoi(tempStr.c_str());
					R = tempNum;
					tempStr = "";
				}
			}
			// R取值遍历完了
			if (tempStr.size() > 0) {
				// 说明不是大的间隔符
				int tempNum = atoi(tempStr.c_str());
				R = tempNum;
				tempStr = "";
			}
		}
		else {
			i++;
		}
	}

	if (A.size() == 0 || B.size() == 0) {
		// 不符合条件
		cout << "";
		return 0;
	}
	// 获得满足条件的数
	int start = 0; // 用来记录B比A大的初始位置
	for (int i = 0; i < A.size(); i++) {
		for (int j = start; j < B.size(); j++) {
			if (A[i] <= B[j]) {
				start = j;
				// 找后续满足距离要求的
				int count = 0;
				for (int k = B.size() - 1; k >= j; k--) {
					if (B[k] - A[i] <= R) {
						for (int l = j; l <= k; l++) {
							count++;
							// 满足条件的序列
							cout << "(" << A[i] << "," << B[l] << ")";
						}
					}
				}
				if (count == 0) {
					// 说明没有，则输出最近的
					cout << "(" << A[i] << "," << B[j] << ")";
				}

				// 已经找到，可以跳出了，不必再继续循环
				break;
			}
		}
	}
	system("pause");
}