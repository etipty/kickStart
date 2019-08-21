/*Scrambled Words ��˼·֮��д������ȷ�ⷨ*/
//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

int num[26];
unsigned long long SEED = 1331; //�����������ѡȡ��
// ����word��hash Map
unsigned long long getHash(char start, char end, int num[26]) {
	unsigned long long result = (start - 'a')*SEED + (end - 'a');
	for (int i = 0; i < 26; i++) {
		result = result*SEED + num[i];
	}
	return result;
}

//string wordsList[20010]; // �洢�ֵ�
char dict[1000010]; // ������ʱ�洢�ֵ䣬��Ϊ����Ҫ�Ƚϵ����ֵ��HashMap,���Կ��Բ��õ�������洢
unsigned long long wordsMap[20010]; // �洢�ֵ��Ӧ��Hash��
int length[20010]; // �洢�ֵ��и��ʶ�Ӧ�ĳ���
int X[1000010]; // �洢���ڼ���S��X��Ϊ����10^9ȡ�࣬����ʣ��Ŀ϶�С��10^9
char S[1000010]; // ���Դ洢S

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int L;
		scanf_s("%d", &L);
		int tolen = 0;// ���Լ�¼�ֵ��в��ظ����ȵ��ַ����ĸ���
		int Count = 0;// ���ڼ�¼�������ַ�����
		for (int i = 0; i < L; i++) {
			//cin>>wordsList[i];
			//scanf_s("%s", dict);
			cin >> dict;
			//int len = wordsList[i].length();
			int len = strlen(dict);
			// ��ʼ������ͳ���ַ�����num����
			memset(num, 0, sizeof(num));
			for (int j = 1; j < len - 1; j++) {
				// ͳ�Ƶ����м����ĸ���ִ���
				//num[wordsList[i][j] - 'a']++; // �費��Ҫÿ�ζ�num��ʼ����
				num[dict[j] - 'a']++;
			}
			// �����ʵ�HashMap
			//unsigned long long tempMap = getHash(wordsList[i][0], wordsList[i][len - 1], num);
			unsigned long long tempMap = getHash(dict[0], dict[len - 1], num);
			wordsMap[i] = tempMap;
			length[tolen++] = len;
		}
		sort(length, length + tolen); // ��length��������
		tolen = unique(length, length + tolen) - length;

		//char s1, s2;
		int N, A, B, C, D;
		cin >> S[0] >> S[1];
		scanf_s("%d%d%d%d%d", &N, &A, &B, &C, &D);

		// ����S string��push_back��������������֤
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

		// �����ֵ�map��
		unordered_map<unsigned long long, int>mp;
		for (int i = 0; i < L; i++) {
			mp[wordsMap[i]]++;
		}
		// ���ֵ����е��ַ�������Ϊ���ݶ�S���б����Ƚ�
		for (int i = 0; i < tolen; i++) {
			int len = length[i];
			if (len > N) continue; // ����ֵ����ַ������ȴ���S�ĳ��ȣ������ж�
			// ��ʼ�����ڼ�¼�ַ�����������
			memset(num, 0, sizeof(num));
			for (int j = 1; j < len - 1; j++) {
				num[S[j] - 'a']++;
			}
			unsigned long long tempStr = getHash(S[0], S[len - 1], num);
			// ����map��Ŀ�ľ��ǿ��ٲ��ң�����forѭ������û��Ҫ����������
			if (mp.count(tempStr)) {
				Count += mp[tempStr]; // �Է�ֹ�ֵ��б�����л�Ϊscramble���ַ���������Ҳ��Ҫͳ���ڼ�����
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