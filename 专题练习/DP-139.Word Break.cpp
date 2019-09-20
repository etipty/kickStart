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

分析：
各种边界条件考虑：
1.字符串为空，返回true;
2.worDict为空，返回false;
3.前面某个字符串的分割导致后续不能分割，但若跳过此字符串后续均能分割成功，则返回true;(这点未能考虑到)
正常情况下返回true和false的条件
1.必须是按顺序匹配;！！！！理解错误，题目中3是og无法匹配，不是因为顺序的问题！！！！
2.循环匹配能分割，返回true;
3.循环匹配一周仍未能匹配分割，返回false;

Runtime: 8 ms, faster than 76.34% of C++ online submissions for Word Break.
Memory Usage: 10.8 MB, less than 64.15% of C++ online submissions for Word Break.
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

bool IsWordBreak(string s, vector<string>& wordDict, int posS, int posWD, int&count) {
	// 判断当前位置的wordDict是否能分割string
	if (posS >= s.size()) return true;
	if (s.substr(posS, wordDict[posWD].size()) == wordDict[posWD]) {
		count = 0;
		return IsWordBreak(s, wordDict, posS + wordDict[posWD].size(), (posWD + 1)% wordDict.size(), count);
	}
	else {
		if (count >= wordDict.size()) return false; // 循环一圈之后还是未能匹配到则返回false
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
				// 找到上一个匹配的词的末尾位置，然后从此开始截断查找是否有匹配的，若有则对此位置标记为true，若找到首位置仍无法匹配则说明无此截断的单词存在于字典中标记为false
				// 注意这块儿s在去substr时与dp正好错开一位对齐
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
		// 因为对分割匹配顺序无要求，所以可以放入比较容易查找的数据结构中进行处理
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