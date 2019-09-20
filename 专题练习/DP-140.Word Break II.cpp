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

����˼·������vector�Ŀ������Խ�����ɾ��ӵĴ洢����Ȼ���ӿ����ж����֧��������vector�����䣬�ɶ����п��ܵľ��Ӷ����д洢
ͬʱ����ʹ��map���Ѿ���õĲ��ֵĽ�����б��棬�����´��ٱ�������ʱ����ֱ��ȡ�����ֵ����combine

Runtime: 32 ms, faster than 21.24% of C++ online submissions for Word Break II.
Memory Usage: 14.6 MB, less than 63.64% of C++ online submissions for Word Break II.
�������ٶ��е������迴����⣡����
��Ϊunordered_mapЧ����������
Runtime: 20 ms, faster than 48.61% of C++ online submissions for Word Break II.
Memory Usage: 14.5 MB, less than 63.64% of C++ online submissions for Word Break II.
������ȥ�����࿼�Ǻ���Ż����
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

// �������pre���ܰ����ã�Ҫע�⣡������Ϊpre��̬���˵Ļ���ָ��&����
vector<string> combine(string word, vector<string> pre) {
	//if (pre.size() == 0) {
	//	// ��preΪ��ʱ��˵�����ַָ��������޷������ָ��ַ�����ɾ��ӣ�������ϲ����������Ӧ���ؿ�
	//	return pre;
	//}
	// �����ǿ���Ŀ����Ƕ���ģ�û��Ӱ�죡����
	for (int i = 0; i < pre.size(); i++) {
		// �����п��ܵ�ǰ׺�������б������׺�������
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

	// ��������string�Ƿ�ɽ�һ��ϸ��
	for (int i = 1; i < s.size(); i++) {
		string tempWord = s.substr(i);
		if (wordDict.count(tempWord)) {
			vector<string> pre = combine(tempWord, wordBreakString(s.substr(0, i), wordDict));
			// ��preΪ��ʱ�������ҲΪ�գ���������������ڣ�Ҳδ��¼
			result.insert(result.end(), pre.begin(), pre.end());
		}
	}

	// ��sΪһ������ʱ��result����Ϊ��
	memory[s] = result;
	return result;
}

// ����Ŀ����������֪���������н����Ҫ��vector�н��д洢
vector<string> wordBreak(string s, vector<string>& wordDict) {
	// �Ƚ�wordDictionaryת���������б�����ݽṹ
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