#include <iostream>
#include <vector>
#include<string>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int longestSubStrLength(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	if (m == 0 || n == 0) return 0;

	vector<vector<int>> result(m, vector<int>(n, 0));

	int max = 0;

	// 遍历完找到最长公共子串的长度和其所在的尾位置
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s1.at(i) == s2.at(j) || s1.at(i) == s2.at(j) - 32 || s1.at(i) == s2.at(j) + 32) {
				if (i == 0 || j == 0) {
					result[i][j] = 1;
				}
				else {
					result[i][j] = result[i - 1][j - 1] + 1;
				}

				if (result[i][j] > max) {
					max = result[i][j];
				}
			}
		}
	}

	return max;

}
/******************************结束写代码******************************/


int main() {
	int res;

	string _s1;
	getline(cin, _s1);
	string _s2;
	getline(cin, _s2);

	res = longestSubStrLength(_s1, _s2);
	cout << res << endl;

	system("pause");

	return 0;
}
