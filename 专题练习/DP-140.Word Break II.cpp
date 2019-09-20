/*
140. Word Break II
Hard

1169

271

Favorite

Share
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
"cats and dog",
"cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
"pine apple pen apple",
"pineapple pen apple",
"pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

此题思路是利用vector的可扩充性进行组成句子的存储，虽然句子可能有多个分支，但由于vector可扩充，可对所有可能的句子都进行存储
同时，可使用map对已经求得的部分的结果进行保存，这样下次再遍历到此时可以直接取出结果值进行combine

Runtime: 32 ms, faster than 21.24% of C++ online submissions for Word Break II.
Memory Usage: 14.6 MB, less than 63.64% of C++ online submissions for Word Break II.
！！！速度有点慢，需看下题解！！！
改为unordered_map效率有所提升
Runtime: 20 ms, faster than 48.61% of C++ online submissions for Word Break II.
Memory Usage: 14.5 MB, less than 63.64% of C++ online submissions for Word Break II.
！！！去除多余考虑后的优化结果
Runtime: 16 ms, faster than 68.12% of C++ online submissions for Word Break II.
Memory Usage: 15 MB, less than 60.61% of C++ online submissions for Word Break II.
*/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;


unordered_map<string, vector<string>> memory;

// 这里参数pre不能绑定引用，要注意！！！因为pre动态改了的话其指向&不定
vector<string> combine(string word, vector<string> pre) {
	//if (pre.size() == 0) {
	//	// 当pre为空时，说明此种分割条件下无法连续分割字符串组成句子，该种组合不成立，因此应返回空
	//	return pre;
	//}
	// 上面那块儿的考虑是多余的，没有影响！！！
	for (int i = 0; i < pre.size(); i++) {
		// 对所有可能的前缀，都进行遍历与后缀进行组合
		pre[i] += " " + word;
	}
	return pre;
}

vector<string> wordBreakString(string s, set<string> & wordDict) {
	if (memory.count(s)) return memory[s];

	vector<string> result;
	if (wordDict.count(s)) {
		result.push_back(s);
	}

	// 继续看该string是否可进一步细分
	for (int i = 1; i < s.size(); i++) {
		string tempWord = s.substr(i);
		if (wordDict.count(tempWord)) {
			vector<string> pre = combine(tempWord, wordBreakString(s.substr(0, i), wordDict));
			// 当pre为空时，插入的也为空，即此种情况不存在，也未记录
			result.insert(result.end(), pre.begin(), pre.end());
		}
	}

	// 当s为一个单词时，result可能为空
	memory[s] = result;
	return result;
}

// 从题目所给函数可知，最终所有结果是要在vector中进行存储
vector<string> wordBreak(string s, vector<string>& wordDict) {
	// 先将wordDictionary转换成易于判别的数据结构
	set<string> wordDictionary;
	for (int i = 0; i < wordDict.size(); i++) {
		wordDictionary.insert(wordDict[i]);
	}

	return wordBreakString(s, wordDictionary);
}

int main() {
	string s = "catsanddog";
	vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
	vector<string> result = wordBreak(s, wordDict);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("pause");
}