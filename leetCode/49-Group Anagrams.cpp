#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<string> //Ϊ��ʹcout�����string
using namespace std;

const int SEED = 1331;
unsigned long long getHash(const string& str) {
	int num[26];
	memset(num, 0, sizeof(num)); // ע��˴���ʼ��Ҫʹ��sizeof(num)�����С��������ֱ��ʹ��26����Ȼ��������

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
			result[tolen++][0] = strs[i]; // ��ǰ���͵Ļ�û�У���˽��丳ֵΪ��һ��
		}
		else {
			int index = hashMap[tempHash];
			result[index].push_back(strs[i]); // ������ڣ����ҵ�������������������д洢
		}
	}

	// ����Ҫ�Խ�����п��ַ�������
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