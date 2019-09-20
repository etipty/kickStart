/*
班级中有很多学生，每个学生都有自己爱好，dota、篮球、打豆豆等等，
站在爱好角度观察，假如兴趣相似度越高，友谊小船划得越远，
现在每个英文字符a、b、c、......、z都代表一种兴趣爱好，并且字母顺序就是热爱程度，求爱好的最大相似度(最长公共子串)。
注意看题目左边的输入输出描述！！！
其实就是个暴力双层循环遍历的过程！
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string findLongest(string A, string B) {
	int m = A.size();
	int n = B.size();
	if (m == 0 || n == 0) return "";

	vector<vector<int>> result(m, vector<int>(n, 0));

	int max = 0;
	int maxM = 0;
	int maxN = 0;

	// 遍历完找到最长公共子串的长度和其所在的尾位置
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A.at(i) == B.at(j) || A.at(i) == B.at(j)-32 || A.at(i) == B.at(j) + 32) {
				if (i == 0 || j == 0) {
					result[i][j] = 1;
				}
				else {
					result[i][j] = result[i - 1][j - 1] + 1;
				}

				if (result[i][j] > max) {
					max = result[i][j];
					maxM = i;
					maxN = j;
				}
			}
		}
	}

	int beginM = maxM - max + 1;

	//这里应该控制所有的字符为小写形式，而不是直接取子串
	//string longestString = A.substr(beginM, max);
	string longestString;
	for (int i = beginM; i <= maxM; i++) {
		longestString += tolower(A[i]);
	}

	return longestString;
}

int main() {
	string A, B;
	cin >> A >> B;

	string result = findLongest(A, B);
	if (result.size() == 0) {
		cout << "" << endl;
	}
	else {
		cout << "result=" << result;
	}
	
	system("pause");
}