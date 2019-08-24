#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<string> //为了使cout能输出string
using namespace std;

const int SEED = 1331;
unsigned long long getHash(const string& str) {
	int num[26];
	memset(num, 0, sizeof(num)); // 注意此处初始化要使用sizeof(num)计算大小，而不是直接使用26，不然会计算错误

	for (int i = 0; i<str.size(); i++) {
		num[str[i] - 'a']++;
	}

	unsigned long long sum = 0;
	for (int j = 0; j<26; j++) {
		sum = sum*SEED + num[j];
	}

	return sum;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int N = strs.size();
	map<unsigned long long, int> hashMap;
	vector<vector<string>> result(N + 1, vector<string>(1, ""));
	int tolen = 0;
	for (int i = 0; i<strs.size(); i++) {
		unsigned long long tempHash = getHash(strs[i]);
		if (!hashMap.count(tempHash))
		{
			hashMap[tempHash] = tolen;
			result[tolen++][0] = strs[i]; // 当前类型的还没有，因此将其赋值为第一个
		}
		else {
			int index = hashMap[tempHash];
			result[index].push_back(strs[i]); // 如果存在，则找到其所在类的索引，进行存储
		}
	}

	// 还需要对结果进行空字符串处理
	for (int k = N; k >= tolen; k--) result.pop_back();
	return result;
}

int main() {
	//vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
	//vector<string> strs = { "h","h","h"};
	vector<string> strs = { "tea", "and", "ace", "ad", "eat", "dans" };
	vector<vector<string>> result = groupAnagrams(strs);
	cout << "[";
	for (int i = 0; i < result.size(); i++) {
		cout << "[";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ",";
		}
		cout << "]" << ",";
	}
	cout << "]";
	system("pause");
}