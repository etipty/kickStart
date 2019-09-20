#include<iostream>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

void getSign(set<pair<int, int>> &money, int &result, int M) {
	if ((money.end()->first)*(money.end()->second) < M) return;
	set<pair<int, int>>::iterator it1 = money.end();
	set<pair<int, int>>::iterator it2 = money.begin();
	for (; it1 != money.begin(); it1--) {
		for (; it2 != it1; it2++) {
			if (it2->first + it1->first >= M) {
				result += it2->second < it1->second ? it2->second : it1->second;

				pair<int, int> temp1 = make_pair(it1->first, (it1->second - it2->second < it1->second ? it2->second : it1->second));
				pair<int, int> temp2 = make_pair(it2->first, (it2->second - it2->second < it1->second ? it2->second : it1->second));
				money.erase(*it1);
				money.erase(*it2);

				if (temp1.second > 0) {
					money.insert(temp1);
					it1 = money.find(temp1);

				}

				if (temp2.second > 0) {
					money.insert(temp2);
				}

			}
		}
	}
	getSign(money, result, M);
}
int main() {
	int N, M;
	cin >> N >> M;

	int result = 0;

	set<pair<int, int>> money;
	int sign = 0;
	while (sign < N) {
		int tempSign;
		int tempNum;
		cin >> tempSign >> tempNum;
		money.insert(make_pair(tempSign, tempNum));
		sign++;
	}

	// 进行组合
	set<pair<int, int>>::iterator it;
	it = lower_bound(money.begin(),money.end(), make_pair(M, 0));
	for (; it != money.end(); it--) {
		result += it->second;
		money.erase(*it);
	}
	getSign(money, result, M);

	cout << result;
}