#include<iostream>
#include<stdio.h>
#include<set>
#include<utility>
using namespace std;

//int const N = 5e4 + 5; 
// const��λ��������������λ�ÿ��Ի�����Ӱ�죬���漰��ָ��ʱ��const��*���Ҳ���������ָ�룬��*�������������ָ��ָ��ı���
const int N = 5e4 + 5;
set<pair<int, int>> Segr[N], Segc[N];
char s[N];

// ռ��λ�ã���ͨ��set��Grid������ʴ
void remove(int r, int c) {
	{// �Ȳ�����
		// ��ȡ��ǰλ���������setԪ�ص�λ��
		auto it = Segr[r].lower_bound(make_pair(c + 1, -1));
		if (it != Segr[r].begin())
			it--;
		int lo = it->first;
		int le = it->second;

		Segr[r].erase(it); // ���ҵ���set�����ع�

		if (lo < c) {
			Segr[r].insert(make_pair(lo, c - 1));
		}
		if (le > c) {
			Segr[r].insert(make_pair(c + 1, le));
		}
	}
	{// �ٲ�����
		auto it = Segc[c].lower_bound(make_pair(r + 1, -1));
		if (it != Segc[c].begin())
			it--;
		int lo = it->first;
		int le = it->second;

		Segc[c].erase(it); // ���ҵ���set�����ع�

		if (lo < r) {
			Segc[c].insert(make_pair(lo, r - 1));
		}
		if (le > r) {
			Segc[c].insert(make_pair(r + 1, le));
		}
	}
}

void solve(int iCase) {
	int Ni, R, C, Sr, Sc;
	scanf_s("%d%d%d%d%d", &Ni, &R, &C, &Sr, &Sc);
	cin >> s;
	s[Ni] = 0; // �趨�ַ�����β��־����Ȼ�����

	// ��ʼ��set���ϣ�ע���Ǵ�1��ʼ
	for (int i = 1; i <= R; i++) {
		Segr[i].clear();
		Segr[i].insert(make_pair(1, C));
	}
	for (int j = 1; j <= C; j++) {
		Segc[j].clear();
		Segc[j].insert(make_pair(1, R));
	}

	// ռ����ʼλ��
	remove(Sr, Sc);

	// ��Ni��ָ�����ִ�У�ѭ����λ����ʴ
	for (int k = 0; k < Ni; k++) {
		char struc = s[k];

		//if (struc == 'N') {
		//	auto it = Segc[Sc].lower_bound(make_pair(Sr + 1, -1));
		//	if (it != Segc[Sc].begin()) // ע��˴��ж�һ������д����Ȼ�ᵼ����ѭ����TLE
		//		it--;
		//	Sr = it->second;
		//}
		//else if (struc == 'S') {
		//	auto it = Segc[Sc].lower_bound(make_pair(Sr + 1, -1));
		//	Sr = it->first;
		//}
		//else if (struc == 'W') {
		//	auto it = Segr[Sr].lower_bound(make_pair(Sc + 1, -1));
		//	if (it != Segr[Sr].begin())
		//		it--;
		//	Sc = it->second;
		//}
		//else {
		//	auto it = Segr[Sr].lower_bound(make_pair(Sc + 1, -1));
		//	Sc = it->first;
		//}

		switch (struc) {
		case 'N':
		{
			auto it = Segc[Sc].lower_bound(make_pair(Sr + 1, -1));
			if (it != Segc[Sc].begin())
				it--;
			Sr = it->second;
			break;
		}
		case 'S':
		{
			auto it = Segc[Sc].lower_bound(make_pair(Sr + 1, -1));
			Sr = it->first;
			break;
		}
		case 'W':
		{
			auto it = Segr[Sr].lower_bound(make_pair(Sc + 1, -1));
			if (it != Segr[Sr].begin())
				it--;
			Sc = it->second;
			break;
		}
		case 'E':
		{
			auto it = Segr[Sr].lower_bound(make_pair(Sc + 1, -1));
			Sc = it->first;
			break;
		}
		}

		remove(Sr, Sc);
	}

	// ���յ�Sr,Sc��Ϊ���ڵ�λ��
	printf("Case #%d: %d %d\n", iCase, Sr, Sc);
}

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		solve(iCase);
	}
}