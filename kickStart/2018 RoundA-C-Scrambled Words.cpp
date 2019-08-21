/*Scrambled Words 看思路之后写出的正确解法*/
//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

int num[26];
unsigned long long SEED = 1331; //这个种子设置选取？
// 构建word的hash Map
unsigned long long getHash(char start, char end, int num[26]) {
	unsigned long long result = (start - 'a')*SEED + (end - 'a');
	for (int i = 0; i < 26; i++) {
		result = result*SEED + num[i];
	}
	return result;
}

//string wordsList[20010]; // 存储字典
char dict[1000010]; // 用以临时存储字典，因为最终要比较的是字典的HashMap,所以可以不用单独数组存储
unsigned long long wordsMap[20010]; // 存储字典对应的Hash串
int length[20010]; // 存储字典中各词对应的长度
int X[1000010]; // 存储用于计算S的X因为是与10^9取余，所以剩余的肯定小于10^9
char S[1000010]; // 用以存储S

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int L;
		scanf_s("%d", &L);
		int tolen = 0;// 用以记录字典中不重复长度的字符串的个数
		int Count = 0;// 用于记录包含的字符个数
		for (int i = 0; i < L; i++) {
			//cin>>wordsList[i];
			//scanf_s("%s", dict);
			cin >> dict;
			//int len = wordsList[i].length();
			int len = strlen(dict);
			// 初始化用于统计字符数的num数组
			memset(num, 0, sizeof(num));
			for (int j = 1; j < len - 1; j++) {
				// 统计单词中间的字母出现次数
				//num[wordsList[i][j] - 'a']++; // 需不需要每次对num初始化？
				num[dict[j] - 'a']++;
			}
			// 构建词典HashMap
			//unsigned long long tempMap = getHash(wordsList[i][0], wordsList[i][len - 1], num);
			unsigned long long tempMap = getHash(dict[0], dict[len - 1], num);
			wordsMap[i] = tempMap;
			length[tolen++] = len;
		}
		sort(length, length + tolen); // 对length进行排序
		tolen = unique(length, length + tolen) - length;

		//char s1, s2;
		int N, A, B, C, D;
		cin >> S[0] >> S[1];
		scanf_s("%d%d%d%d%d", &N, &A, &B, &C, &D);

		// 生成S string的push_back可能慢，进行验证
		//string S = "";
		//S.push_back(s1);
		//S.push_back(s2);
		X[0] = (int)S[0];
		X[1] = (int)S[1];
		for (int i = 2; i < N; i++) {
			X[i] = ((long long)A*X[i - 1] + (long long)B*X[i - 2] + C) % D;
			char tempS = (char)(97 + (X[i] % 26));
			//S.push_back(tempS);
			S[i] = tempS;
		}

		// 构建字典map表
		unordered_map<unsigned long long, int>mp;
		for (int i = 0; i < L; i++) {
			mp[wordsMap[i]]++;
		}
		// 以字典中有的字符串长度为依据对S进行遍历比较
		for (int i = 0; i < tolen; i++) {
			int len = length[i];
			if (len > N) continue; // 如果字典中字符串长度大于S的长度，则不用判断
			// 初始化用于记录字符个数的数组
			memset(num, 0, sizeof(num));
			for (int j = 1; j < len - 1; j++) {
				num[S[j] - 'a']++;
			}
			unsigned long long tempStr = getHash(S[0], S[len - 1], num);
			// 本来map的目的就是快速查找，外层的for循环根本没必要啊！！！！
			if (mp.count(tempStr)) {
				Count += mp[tempStr]; // 以防止字典中本身就有互为scramble的字符串，而这也需要统计在加数上
				mp.erase(tempStr);
			}
			for (int j = len; j < N; j++) {
				num[S[j - 1] - 'a']++;
				num[S[j - len + 1] - 'a']--;
				unsigned long long tempMStr = getHash(S[j - len + 1], S[j], num);
				if (mp.count(tempMStr)) {
					Count += mp[tempMStr];
					mp.erase(tempMStr);
				}
			}

		}
		printf("Case #%d: %d\n", iCase, Count);
		system("pause");
	}
}