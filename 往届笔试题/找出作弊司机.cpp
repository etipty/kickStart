/*
去哪儿专车举办某活动，每天积极抢单的司机将会获得额外收入。
因为司机众多，抢单行为也不受控，因此需要防止某些司机刻意作弊。
我们把作弊规则定义为：每天的抢单次数比当天其他所有司机抢单次数相加还要多，那么这个司机作弊司机。
那么问题来了，怎么用最简单（时间复杂度O(n)、空间复杂度）最低的办法找到作弊司机。
!!!!题目要求，不存在输出-1！！！
*/

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	char begin;
	int id;
	int wholeCount = 0;
	int resultId = 0;

	map<int, int> numId;

	cin >> begin;
	while (cin >> id) {
		if (numId.count(id)) {
			numId[id]++;
		}
		else {
			numId[id] = 1;
		}
		wholeCount++;
		char jiange;
		cin >> jiange;
		if (jiange == '}') break;
	}

	map<int, int>::iterator it = numId.begin();
	for (; it != numId.end(); it++) {
		if (it->second > (wholeCount - it->second)) {
			resultId = it->first;
		}
	}

	if (resultId == 0) cout << -1;
	else {
		cout << resultId;
	}
	
	system("pause");
}