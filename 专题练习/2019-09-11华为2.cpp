/*
这个题其实不难，关键是条件各处判断要调好，光调试就花了30min，第三题没看到。。。。
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;

	string tempStr = "";
	//string tempStr1 = "";
	int count = 0;
	int flag = -1;
	vector<string> result;
	// 获取整个输入
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a'&&input[i] <= 'z') || (input[i] >= 'A'&&input[i] <= 'Z')) {
			if (count > 0) {
				// 遇到特殊符号
				if (count == 1) {
					// 连接符
					if (flag == -1) {
						// 说明前一个为非法字符，应继续往后走
						count = 0;
					}
					else {
						if (tempStr.size() > 0) {
							tempStr += "-";
							count = 0;
							flag = -1;
						}
						else {
							flag = -1;
							tempStr += input[i];
							count = 0;
							continue;
						}
						
					}
				}
				else if (count >= 2) {
					// 间隔符
					result.push_back(tempStr);
					tempStr = "";
					count = 0;
				}
			}
			// 符合条件的输入字符
			tempStr += input[i];
		}
		else if (input[i] == '-') {
			flag = 1;
			count++;
		}
		else {
			// 非法符号，统一当间隔符处理
			flag = -1; // 要记录非法字符
			if (tempStr.size() > 0) {
				result.push_back(tempStr);
				tempStr = "";
			}
			// 如果tempStr.size()为0说明为多个非法符号不用管
		}
	}

	if (tempStr.size() > 0) {
		result.push_back(tempStr);
	}

	// 对输入倒序输出
	cout << result[result.size() - 1];
	for (int j = result.size() - 2; j >= 0; j--) {
		cout << " " << result[j];
	}
	system("pause");
}