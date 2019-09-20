#include<iostream>
#include<set>
#include<utility>
#include<string>
#include<vector>
using namespace std;


// ռ��λ�ã���ͨ��set��Grid������ʴ
void remove(int r, int c, vector<set<pair<int, int>>> &Segr, vector<set<pair<int, int>>> &Segc) {
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

int main() {
	int T;
	// int iCase = 0;
	cin >> T;
	while (T--) {
		int M, N;
		cin >> M >> N;
		vector<string> Mstr;
		int i = 0;

		// �����־����ȡ��
		while (i < M) {
			string iM;
			cin >> iM;
			Mstr.push_back(iM);
			i++;
		}

		// ����set����洢�߽�
		vector<set<pair<int, int>>> Segr(M + 1);
		vector<set<pair<int, int>>> Segc(N + 1);

		// ��ʼ��set���ϣ�ע���Ǵ�1��ʼ,��ʼ��set
		for (int i = 1; i <= M; i++) {
			Segr[i].clear();
			Segr[i].insert(make_pair(1, N));
		}
		for (int j = 1; j <= N; j++) {
			Segc[j].clear();
			Segc[j].insert(make_pair(1, M));
		}

		// ����0�ֽ�ɵ�pair���
		for (int i = 0; i < M; i++) {
			int flag = 0; //��Ǹ��е�ĳ��pair�Ƿ��Ѽ�¼���
			int left;
			int right;
			for (int j = 0; j < N; j++) {
				if (Mstr[i][j] == '0') {
					remove(i, j, Segr, Segc);
				}
			}
		}

		// ѭ����⹹�ɵľ������
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