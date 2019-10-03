/*
给定一个输入数x，让求整数N，使得N的所有位之和满足S[N]>=x的最小整数N
*/

#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int inputX;
		cin >> inputX;
		int count = inputX / 9;
		int pre = inputX % 9;
		int outPut = pre;
		for (int i = 0; i<count; i++) {
			outPut = outPut * 10 + 9;
		}
		cout << outPut << endl;
	}
	system("pause");
}