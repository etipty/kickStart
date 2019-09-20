#include <iostream>
#include <vector>
#include<string>
#include <numeric>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
string sortVersion(string s1, string s2) {
	if (s1.size() == 0) return s2;
	else if (s2.size() == 0) return s1;

	string result = "";
	vector<int> version1;
	vector<int> version2;

	string tempNum = "";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') {
			tempNum += s1[i];
		}
		else if (s1[i] == '.') {
			int tempInt = atoi(tempNum.c_str());
			version1.push_back(tempInt);
			tempNum = "";
		}
	}

	int tempInt = atoi(tempNum.c_str());
	version1.push_back(tempInt);
	tempNum = "";

	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= '0' && s2[i] <= '9') {
			tempNum += s2[i];
		}
		else if (s2[i] == '.') {
			int tempInt = atoi(tempNum.c_str());
			version2.push_back(tempInt);
			tempNum = "";
		}
	}

	tempInt = atoi(tempNum.c_str());
	version2.push_back(tempInt);

	// �Ƚ������汾�Ŵ�С�������رȽ�֮��Ľ��
	int numSize = version1.size() > version2.size() ? version2.size() : version1.size();
	for (int i = 0; i < numSize; i++) {
		if (version1[i] < version2[i]) {
			// һ��������С�ȽϽ��֮���Ӧ�����������ٽ��к����Ƚ��ˣ���Ȼ�����Ĵ�����ı��������´��󰡣�����
			result = s1 + ',' + s2;
			break;
		}
		else if (version1[i] > version2[i]) {
			result = s2 + ',' + s1;
			break;
		}
	}
	// ˵������Сλ���Ƚ�ʱ��ͬ������һ�����λ����Ӧ�������
	if (result == "") {
		result = version1.size() < version2.size() ? s1 + ',' + s2 : s2 + ',' + s1;
	}

	return result;
}
/******************************����д����******************************/


int main() {
	string res;

	while (1) {
		string _s1;
		getline(cin, _s1);
		string _s2;
		getline(cin, _s2);

		res = sortVersion(_s1, _s2);
		cout << res << endl;
	}

	system("pause");

	return 0;

}
