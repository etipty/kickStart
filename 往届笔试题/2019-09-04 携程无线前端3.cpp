#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

int main() {
	int a;
	int result = 1;
	vector<int> results;
	map<int,int> jiangePos;
	vector<int> zeroPos;
	int count = 0;

	while (scanf_s("%d", &a) != EOF)
	{
		if (a == 0) {
			zeroPos.push_back(count);
			results.push_back(result);
			result = 1; //�Ӵ˴���Ҫ���˻��Ͽ�
		}
		if (a < 0) {
			jiangePos[count] = a;
			results.push_back(result);
			result = 1; //�Ӵ˴���Ҫ���˻��Ͽ�
		}
		if (a > 0) result *= a;
		count++;// ��¼�������ĸ���
	}

	int resultM = 1;

	if (zeroPos.size() == 0) {
		for (int i = 0; i < results.size(); i++) {
			resultM *= results[i];
		}

		if (jiangePos.size() % 2 == 0) {
			if (jiangePos.size() > 0) {
				map<int, int>::iterator it = jiangePos.begin();
				for (; it != jiangePos.end(); it++) {
					resultM *= it->second;
				}
			}
		}
		else {//�������ȥ��ͷ
			map<int, int>::iterator it1 = jiangePos.begin();
			map<int, int>::iterator it2 = jiangePos.end();

			resultM = resultM / results[0] * ((--it2)->second) > resultM / results[results.size() - 1] * ((it1)->second);
		}
	}
	else {
		// �������Ϊ0��������

	}

	cout << resultM;

	system("pause");
}