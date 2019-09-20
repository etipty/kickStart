#include<iostream>
#include<map>
using namespace std;


int main() {
	int N, K;
	cin >> N >> K;
	map<int, int> fruits;

	int result = 0;
	// 记录所有的果汁类型
	int i = 0;
	while (i<N) {
		int fruit;
		cin >> fruit;
		if (!fruits.count(fruit)) {
			fruits[fruit] = 1;
		}
		else {
			fruits[fruit] += 1;
		}
		i++;
	}

	map<int, int>::iterator it = fruits.begin();
	for (; it != fruits.end(); it++) {
		result += it->second / 2 + it->second % 2;
	}

	cout << result;

	system("pause");
}