#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// 记录m个题，每个答案对应的频数
	vector<vector<int>> answerNum(m, vector<int>(5, 0)); 
	vector<int> credits;

	int count = 0;
	while (count<n) {
		string answers;
		cin >> answers;

		// 对m题各答案进行计数
		for (int i = 0; i < m; i++) {
			switch (answers[i]) {
			case 'A':
				answerNum[i][0]++;
				break;
			case 'B':
				answerNum[i][1]++;
				break;
			case 'C':
				answerNum[i][2]++;
				break;
			case 'D':
				answerNum[i][3]++;
				break;
			case 'E':
				answerNum[i][4]++;
				break;
			}
		}
		count++;
	}// 循环完毕，答案读取完毕

	// 读取各题对应的分数
	for (int i = 0; i < m; i++) {
		int tempC;
		cin >> tempC;
		credits.push_back(tempC);
	}

	int result = 0;
	// 计算分数
	for (int i = 0; i < m; i++) {
		int tempS = 0;
		for (int j = 0; j < 5; j++) {
			if (answerNum[i][j] > tempS)tempS = answerNum[i][j];
		}
		result += credits[i] * tempS;
	}

	cout << result;
}