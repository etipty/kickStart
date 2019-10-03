#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main() {
	int T;
	cin >> T;
	int iCase = 0;
	while (T--) {
		iCase++;
		int N, K;
		cin >> N >> K;
		// 存储高度突变的起点和终点及其对应的高程值
		map<pair<int, int>, int> heights;
		int origionalH;
		int originalIndex = 0;
		cin >> origionalH;
		for (int i = 1; i < N; i++) {
			int tempH;
			cin >> tempH;
			if (tempH != origionalH) {
				pair<int, int>  indexBound = make_pair(originalIndex, i-1);
				heights[indexBound] = origionalH;

				// 改变Bound
				origionalH = tempH;
				originalIndex = i;
			}
		}
		pair<int, int>  indexBound = make_pair(originalIndex, N - 1);
		heights[indexBound] = origionalH;

		int nums = heights.size();
		if (nums - 1 <= K) {
			cout << "Case #" << iCase << ": " << 0 << endl;
		}
		else if (nums - 1 <= K - 1) {
			cout << "Case #" << iCase << ": " << 1 << endl;
		}
		else {
			int max = nums - 1 - K;
			// 每次找最优进行踏平

			cout << max;
		}
	}
}