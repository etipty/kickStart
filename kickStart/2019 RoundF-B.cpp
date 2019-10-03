#include<iostream>
#include<set>
#include<vector>
using namespace std;

// 返回包含数
int getPairN(set<int> first, set<int> second) {
	set<int>::iterator it = second.begin();
	bool flag = false;
	for (; it != second.end(); it++) {
		int tempS = *it;
		if (!first.count(tempS)) {
			// 如果存在不包含的数，则置flag为true
			flag = true;
		}
	}
	if (flag) {
		// 存在不包含的数
		return 2;
	}
	else {
		if (first.size() == second.size()) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

int main() {
	int T;
	cin >> T;
	int iCase = 0;
	while (T--) {
		iCase++;
		int N, S;
		cin >> N >> S;
		int count = 0;
		vector<set<int>> skills;
		while (count < N) {
			int C;
			cin >> C;
			set<int> tempN;
			for (int i = 0; i < C; i++) {
				int tempSkill;
				cin >> tempSkill;
				tempN.insert(tempSkill);
			}
			skills.push_back(tempN);
			count++;
		}

		int result = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (skills[i].size() < skills[j].size()) {
					result += getPairN(skills[j], skills[i]);
				}
				else {
					result += getPairN(skills[i], skills[j]);
				}
			}
		}

		cout << "Case #" << iCase << ": " << result << endl;
	}
}