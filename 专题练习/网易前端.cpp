/*
����һ��������x����������N��ʹ��N������λ֮������S[N]>=x����С����N
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