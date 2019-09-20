#include<iostream>
#include<string>
using namespace std;

int main() {
	string InputString;
	cin >> InputString;

	string OutputNum = "";
	string OutputString = "";

	int size = InputString.size();

	for (int i = 0; i < size; i++) {
		if (InputString.at(i) >= '0' && InputString.at(i) <= '9') {
			if (OutputNum == "") {
				OutputNum += InputString[i];
			}else if (OutputNum.find(InputString[i]) == string::npos) {
				// 注意string查找不到时的返回值类型为string::npos，查找到则返回查找到的首位置
				OutputNum += InputString[i];
			}
		}
		if ((InputString.at(i) >= 'a' && InputString.at(i) <= 'z') || (InputString.at(i) >= 'A' && InputString.at(i) <= 'Z')) {
			OutputString += InputString[i];
		}
	}

	OutputString = OutputNum + OutputString;

	cout << OutputString;

	system("pause");
}