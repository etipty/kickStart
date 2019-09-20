#include<iostream>
#include<set>
#include<utility>
#include<string>
#include<vector>
using namespace std;


// 占据位置，并通过set对Grid进行侵蚀
void remove(int r, int c, vector<set<pair<int, int>>> &Segr, vector<set<pair<int, int>>> &Segc) {
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

int main() {
	int T;
	// int iCase = 0;
	cin >> T;
	while (T--) {
		int M, N;
		cin >> M >> N;
		vector<string> Mstr;
		int i = 0;

		// 将数字矩阵获取到
		while (i < M) {
			string iM;
			cin >> iM;
			Mstr.push_back(iM);
			i++;
		}

		// 两个set数组存储边界
		vector<set<pair<int, int>>> Segr(M + 1);
		vector<set<pair<int, int>>> Segc(N + 1);

		// 初始化set集合，注意是从1开始,初始化set
		for (int i = 1; i <= M; i++) {
			Segr[i].clear();
			Segr[i].insert(make_pair(1, N));
		}
		for (int j = 1; j <= N; j++) {
			Segc[j].clear();
			Segc[j].insert(make_pair(1, M));
		}

		// 构造0分界成的pair组合
		for (int i = 0; i < M; i++) {
			int flag = 0; //标记该行的某个pair是否已记录左界
			int left;
			int right;
			for (int j = 0; j < N; j++) {
				if (Mstr[i][j] == '0') {
					remove(i, j, Segr, Segc);
				}
			}
		}

		// 循环求解构成的矩形面积
		int result = 0;

		for (int i = 1; i <= M; i++) {
			set<pair<int, int>> tempSegr = Segr[i];
			set<pair<int, int>>::iterator it1 = tempSegr.begin();
			/*set<pair<int, int>>::iterator it2 = tempSegr.end();
			it2--;
			for (; it1 != tempSegr.end(); it1++) {
				for (; it2 != it1; it2++) {

				}
			}*/

			for (; it1 != tempSegr.end(); it1++) {
				int left = it1->first;
				int right = it1->second;

				for (int k = left; k != right; k++) {

					set<pair<int, int>> tempSegc1 = Segc[k];
					if (tempSegc1.begin()->first != i) continue;

					for (int l = right; l != k; l--) {
						set<pair<int, int>> tempSegc2 = Segc[l];
						if (tempSegc2.begin()->first != i) continue;

						int tempDown = tempSegc1.begin()->second < tempSegc2.begin()->second ? tempSegc1.begin()->second : tempSegc2.begin()->second;
						
						set<pair<int, int>> tempSegr2 = Segr[tempDown];
						set<pair<int, int>>::iterator it2 = tempSegr2.begin();
						for (; it2 != tempSegr2.end(); it2++) {
							int tempResult = (it2->second - it2->first + 1)*tempDown;
							if (result == 0) {
								result = tempResult;
							}
							else if (tempResult > result) {
								result = tempResult;
							}
						}
					}
				}
			}
		}
		cout << result << endl;
	}
}