/*
�����쵼��m��mΪż�������ˣ�ÿ������һ��ͬ���һ��������������ʱ��Ϊ�����˵�ʱ��Ȩֵ֮�ͣ�
���ڸ���n�����ݣ�ÿ������������ֵx��y��������x���˵�ʱ��ȨֵΪy�����������������ʲôʱ�����

������Ϊʲôֻ����10%���о�Ӧ����ϸ�ڴ��������ûŪ�ã�������������յ�����ȫAC��
���ܵĴ���㣺
1.num�ǿ���Ž�ȥ��������Ŀ���ԣ������û������4��һ����VS�������һ�²��ܷ��ִ���
2.��maxʱforѭ���еĴ�������
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> Times;
	while (N--) {
		int num;
		int tempTime;
		cin >> num >> tempTime;
		for (int i = 0; i < num; i++) {
			// ��num������ȫ���Ž�ȥ
			Times.push_back(tempTime);
		}
	}
	//sort(Times, Times+Times.size());
	sort(Times.begin(), Times.end());
	int shortestTime = Times[0] + Times[Times.size() - 1];
	for (int i = 0; i < (Times.size() + 1) / 2; i++) {
		//cout << "��" << i << "��" << Times[i] + Times[Times.size() - 1 - i] << endl;
		shortestTime = max(shortestTime, Times[i] + Times[Times.size() - 1 - i]);
	}
	//cout << shortestTime;
	cout << "���ս����" << shortestTime;
	//system("pause");
}