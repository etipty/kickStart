/*
ȥ�Ķ�ר���ٰ�ĳ���ÿ�����������˾�������ö������롣
��Ϊ˾���ڶ࣬������ΪҲ���ܿأ������Ҫ��ֹĳЩ˾���������ס�
���ǰ����׹�����Ϊ��ÿ������������ȵ�����������˾������������ӻ�Ҫ�࣬��ô���˾������˾����
��ô�������ˣ���ô����򵥣�ʱ�临�Ӷ�O(n)���ռ临�Ӷȣ���͵İ취�ҵ�����˾����
!!!!��ĿҪ�󣬲��������-1������
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