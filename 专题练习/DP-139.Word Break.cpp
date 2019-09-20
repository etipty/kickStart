/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

������
���ֱ߽��������ǣ�
1.�ַ���Ϊ�գ�����true;
2.worDictΪ�գ�����false;
3.ǰ��ĳ���ַ����ķָ�º������ָܷ�����������ַ����������ָܷ�ɹ����򷵻�true;(���δ�ܿ��ǵ�)
��������·���true��false������
1.�����ǰ�˳��ƥ��;����������������Ŀ��3��og�޷�ƥ�䣬������Ϊ˳������⣡������
2.ѭ��ƥ���ָܷ����true;
3.ѭ��ƥ��һ����δ��ƥ��ָ����false;

Runtime: 8 ms, faster than 76.34% of C++ online submissions for Word Break.
Memory Usage: 10.8 MB, less than 64.15% of C++ online submissions for Word Break.
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

bool IsWordBreak(string s, vector<string>& wordDict, int posS, int posWD, int&count) {
	// �жϵ�ǰλ�õ�wordDict�Ƿ��ָܷ�string
	if (posS >= s.size()) return true;
	if (s.substr(posS, wordDict[posWD].size()) == wordDict[posWD]) {
		count = 0;
		return IsWordBreak(s, wordDict, posS + wordDict[posWD].size(), (posWD + 1)% wordDict.size(), count);
	}
	else {
		if (count >= wordDict.size()) return false; // ѭ��һȦ֮����δ��ƥ�䵽�򷵻�false
		count++;
		return IsWordBreak(s, wordDict, posS, (posWD + 1) % wordDict.size(), count);
	}
}

bool IsWordBreak2(string s, set<string> & wordDict) {
	if (s.size() == 0) return true;
	if (wordDict.size() == 0) return false;

	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (dp[j]) {
				// �ҵ���һ��ƥ��Ĵʵ�ĩβλ�ã�Ȼ��Ӵ˿�ʼ�ضϲ����Ƿ���ƥ��ģ�������Դ�λ�ñ��Ϊtrue�����ҵ���λ�����޷�ƥ����˵���޴˽ضϵĵ��ʴ������ֵ��б��Ϊfalse
				// ע������s��ȥsubstrʱ��dp���ô�һλ����
				string tempWord = s.substr(j, i - j);
				if (wordDict.find(tempWord) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
	}
	return dp[s.size()];
}

bool wordBreak(string s, vector<string>& wordDict) {
	/*if (s.size() == 0) return true;
	else {
		int count = 0;
		return IsWordBreak(s, wordDict, 0, 0, count);
	}*/
	set<string> wordDictionary;
	for (int i = 0; i < wordDict.size(); i++) {
		// ��Ϊ�Էָ�ƥ��˳����Ҫ�����Կ��Է���Ƚ����ײ��ҵ����ݽṹ�н��д���
		wordDictionary.insert(wordDict[i]);
	}
	return IsWordBreak2(s, wordDictionary);
}

int main() {
	/*string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };*/
	string s = "applepenapple";
	vector<string> wordDict = { "apple","pen" };

	bool result = wordBreak(s, wordDict);
	cout << result << endl;
	system("pause");
}