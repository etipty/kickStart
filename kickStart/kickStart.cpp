/* KS roundD*/
/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


map<int, pair<int, char>> H; // ��¼Gi����ʼλ�ü�����
map<int, vector<int>> finalState; // ��¼����״̬
map<int, int> gCount;
void init() {
	H.clear();
	finalState.clear();
	gCount.clear();
}

// ��ȡ��ֹ״̬
pair<int, char> getPosADir(int g) {
	if (H.count(g)) {
		return H[g];
	}
}

// �洢��ֹ״̬
void setState(pair<int, char> finalPos, int g) {
	if (!H.count(g)) {
		H[g] = finalPos;
	}
}

// �洢�������¹�״̬
void setNState(int gId) {
	int n = H[gId].first;
	if (!finalState.count(n)) {
		// �����û��ֵ
		vector<int> IDs;
		IDs.push_back(gId);
		finalState[n] = IDs;
	}
	else {
		vector<int> IDs = finalState[n];
		IDs.push_back(gId);
		finalState[n] = IDs;
	}
}

// �Դ�����������
// void changeCount(int N, map<int, vector<int>> finalState, map<int, int> gCount)

// �����¼����
void getCount(int N) {
	for (int i = 1; i <= N; i++) {
		if (finalState.count(i)) {
			vector<int> gIDs;
			gIDs = finalState[i];
			for (int j = 0; j < gIDs.size(); j++) {
				int gId = gIDs[j];
				if (gCount.count(gId)) {
					gCount[gId] += 1;
				}
				else {
					gCount[gId] = 1;
				}
				pair<int, char> endPos = H[gId];
				char dir = endPos.second;
				// ��������¹ݽ��в���
				if (dir == 'C') {
					vector<int> gBIDs;
					int adjacentN = i + 1;
					while (!finalState.count(adjacentN)) {
						if (adjacentN < N)
						{
							adjacentN++;
						}
						else {
							adjacentN++;
							adjacentN = adjacentN % N;
						}
					}

					gBIDs = finalState[adjacentN];
					for (int k = 0; k < gBIDs.size(); j++) {
						int gBId = gBIDs[k];
						if (gCount.count(gBId)) {//�����еĴ�����1
							gCount[gId] -= 1;
						}
						else {
							gCount[gId] = -1;
						}
					}
				}
				else if (dir == 'A') {
					vector<int> gSIDs;
					int adjacentN = i - 1;
					while (!finalState.count(adjacentN)) {
						if (adjacentN > 2)
						{
							adjacentN--;
						}
						else {
							adjacentN--;
							adjacentN = (N + adjacentN) % N;
							adjacentN = adjacentN ? adjacentN : N;
						}
					}

					gSIDs = finalState[adjacentN];
					for (int k = 0; k < gSIDs.size(); j++) {
						int gSId = gSIDs[k];
						if (gCount.count(gSId)) {//�����еĴ�����1
							gCount[gSId] -= 1;
						}
						else {
							gCount[gSId] = -1;
						}
					}
				}
			}
		}
	}
}

int getFinalPos(int start, int N, int M, char dir) {
	int end = M % N;
	if (dir == 'C') {
		end = (start + end) % N;
	}
	else if (dir == 'A') {
		end = (start - end + N) % N;
	}
	return end ? end : N; // λ�ñ�Ǵ�1��ʼ
}



int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int N, G, M;
		int startG = 0;
		char dirG;
		scanf_s("%d%d%d", &N, &G, &M);
		init();
		int gId = 1; // �˿�id��1��ʼ
		while (gId<=G) {
			cin >> startG >> dirG; // ��ȡGi����ʼλ�ü�����
			int endPos = getFinalPos(startG, N, M, dirG);
			pair<int, char> finalPos = make_pair(endPos, dirG); // �洢Gi����ֹλ�ü�����
			setState(finalPos, gId);
			gId++; // ��ȡ��һλ�˿͵���Ϣ
		}

		// ��������״̬��¼����
		for (int i = 1; i<=G; i++) {
			setNState(i);
		}

		// �����¼����
		getCount(N);
		cout << "Case #" << iCase << ":" << ' ';
		for (int i = 1; i <= G; i++) {
			int count = gCount[i];
			cout << count << ' ';
		}
		cout << endl;
		system("pause");
	}
}
*/





/*********************************Sherlock and the Bit Strings*****************************************/
/*
// #include<bits/stdlib.h>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<iostream>
using namespace std;

int num[110]; // �ȹ�С���ݼ�
int strain[110]; // ���Լ�¼��Ǵ�

void set_Num(int P, int tolen, int N) {
	int m_pow = 0; // ���Լ���P�Ĵ���
	int m_mod = 0; // ���Լ�¼P�ȵ�ǰ�������ֵ
	while (P) {
		if (P / 2) {
			P = P / 2;
			int temp_mod = P % 2;
			m_mod += temp_mod*pow(2, m_pow);
			m_pow++;
		}
		else {
			break;
		}
	}
	// int high = 0;
	for (int i = tolen - 1; i >= 0; i--) {
		int tempN = N - strain[i] - (tolen - i - 1);
		if (tempN == m_pow) {
			for (int j = strain[i]; j<N; j++) {
				num[j] = 1;
			}
			return;
		}
		else if (N - strain[i] == m_pow + 1 && m_mod>0) {
			// high=m_pow;
			for (int j = strain[i - 1]; j<strain[i]; j++) {
				num[j] = 1;
			}

			// �Ժ������ʹ�õݹ鸳ֵ
			set_Num(m_mod, tolen, N);
			return;
		}
	}
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int N, K, P;
		scanf_s("%d%d%d", &N, &K, &P);
		memset(num, 0, N); //��ǰN����ȫ��Ϊ0
		memset(strain, 0, K);
		int tolen = 0; // ���Լ�¼ʵ�ʺ�1�ĸ���
		while (K--) {
			int A, B, C;
			scanf_s("%d%d%d", &A, &B, &C);
			num[A - 1] = C; //����Լ����S���и�ֵ
			if (C == 1)strain[tolen++] = A;
		}
		set_Num(P, tolen, N);
		printf("Case #%d: ", iCase);
		for (int i = 0; i<N; i++) {
			cout << num[i];
		}
		cout << endl;
	}
}
*/
