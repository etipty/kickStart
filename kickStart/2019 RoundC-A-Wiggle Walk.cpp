#include<iostream>
#include<stdio.h>
#include<set>
#include<utility>
using namespace std;

//int const N = 5e4 + 5; 
// const的位置与类型声明的位置可以互换无影响，但涉及到指针时，const在*的右侧则是修饰指针，在*的左侧则是修饰指针指向的变量
const int N = 5e4 + 5;
set<pair<int, int>> Segr[N], Segc[N];
char s[N];

// 占据位置，并通过set对Grid进行侵蚀
void remove(int r, int c) {
	{// 先操作行
		// 获取当前位置所到达的set元素的位置
		auto it = Segr[r].lower_bound(make_pair(c + 1, -1));
		if (it != Segr[r].begin())
			it--;
		int lo = it->first;
		int le = it->second;

		Segr[r].erase(it); // 对找到的set进行重构

		if (lo < c) {
			Segr[r].insert(make_pair(lo, c - 1));
		}
		if (le > c) {
			Segr[r].insert(make_pair(c + 1, le));
		}
	}
	{// 再操作列
		auto it = Segc[c].lower_bound(make_pair(r + 1, -1));
		if (it != Segc[c].begin())
			it--;
		int lo = it->first;
		int le = it->second;

		Segc[c].erase(it); // 对找到的set进行重构

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
	s[Ni] = 0; // 设定字符串结尾标志，不然会出错

	// 初始化set集合，注意是从1开始
	for (int i = 1; i <= R; i++) {
		Segr[i].clear();
		Segr[i].insert(make_pair(1, C));
	}
	for (int j = 1; j <= C; j++) {
		Segc[j].clear();
		Segc[j].insert(make_pair(1, R));
	}

	// 占据起始位置
	remove(Sr, Sc);

	// 对Ni个指令进行执行，循环定位与侵蚀
	for (int k = 0; k < Ni; k++) {
		char struc = s[k];

		//if (struc == 'N') {
		//	auto it = Segc[Sc].lower_bound(make_pair(Sr + 1, -1));
		//	if (it != Segc[Sc].begin()) // 注意此处判断一定不能写错，不然会导致死循环，TLE
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

	// 最终的Sr,Sc即为所在的位置
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