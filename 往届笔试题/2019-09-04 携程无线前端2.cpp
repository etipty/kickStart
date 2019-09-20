#include <iostream>
#include <vector>
#include<string>
#include <numeric>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
string sortVersion(string s1, string s2) {
	if (s1.size() == 0) return s2;
	else if (s2.size() == 0) return s1;

	string result = "";
	vector<int> version1;
	vector<int> version2;

	string tempNum = "";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') {
			tempNum += s1[i];
		}
		else if (s1[i] == '.') {
			int tempInt = atoi(tempNum.c_str());
			version1.push_back(tempInt);
			tempNum = "";
		}
	}

	int tempInt = atoi(tempNum.c_str());
	version1.push_back(tempInt);
	tempNum = "";

	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= '0' && s2[i] <= '9') {
			tempNum += s2[i];
		}
		else if (s2[i] == '.') {
			int tempInt = atoi(tempNum.c_str());
			version2.push_back(tempInt);
			tempNum = "";
		}
	}

	tempInt = atoi(tempNum.c_str());
	version2.push_back(tempInt);

	// 比较两个版本号大小，并返回比较之后的结果
	int numSize = version1.size() > version2.size() ? version2.size() : version1.size();
	for (int i = 0; i < numSize; i++) {
		if (version1[i] < version2[i]) {
			// 一旦遇到大小比较结果之后就应该跳出，不再进行后续比较了，不然后续的大数会改变结果，导致错误啊！！！
			result = s1 + ',' + s2;
			break;
		}
		else if (version1[i] > version2[i]) {
			result = s2 + ',' + s1;
			break;
		}
	}
	// 说明按最小位数比较时相同，则另一个多出位数的应该排最后
	if (result == "") {
		result = version1.size() < version2.size() ? s1 + ',' + s2 : s2 + ',' + s1;
	}

	return result;
}
/******************************结束写代码******************************/


int main() {
	string res;

	while (1) {
		string _s1;
		getline(cin, _s1);
		string _s2;
		getline(cin, _s2);

		res = sortVersion(_s1, _s2);
		cout << res << endl;
	}

	system("pause");

	return 0;

}
