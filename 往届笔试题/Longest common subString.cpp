/*
�༶���кܶ�ѧ����ÿ��ѧ�������Լ����ã�dota�����򡢴򶹶��ȵȣ�
վ�ڰ��ýǶȹ۲죬������Ȥ���ƶ�Խ�ߣ�����С������ԽԶ��
����ÿ��Ӣ���ַ�a��b��c��......��z������һ����Ȥ���ã�������ĸ˳������Ȱ��̶ȣ��󰮺õ�������ƶ�(������Ӵ�)��
ע�⿴��Ŀ��ߵ������������������
��ʵ���Ǹ�����˫��ѭ�������Ĺ��̣�
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string findLongest(string A, string B) {
	int m = A.size();
	int n = B.size();
	if (m == 0 || n == 0) return "";

	vector<vector<int>> result(m, vector<int>(n, 0));

	int max = 0;
	int maxM = 0;
	int maxN = 0;

	// �������ҵ�������Ӵ��ĳ��Ⱥ������ڵ�βλ��
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A.at(i) == B.at(j) || A.at(i) == B.at(j)-32 || A.at(i) == B.at(j) + 32) {
				if (i == 0 || j == 0) {
					result[i][j] = 1;
				}
				else {
					result[i][j] = result[i - 1][j - 1] + 1;
				}

				if (result[i][j] > max) {
					max = result[i][j];
					maxM = i;
					maxN = j;
				}
			}
		}
	}

	int beginM = maxM - max + 1;

	//����Ӧ�ÿ������е��ַ�ΪСд��ʽ��������ֱ��ȡ�Ӵ�
	//string longestString = A.substr(beginM, max);
	string longestString;
	for (int i = beginM; i <= maxM; i++) {
		longestString += tolower(A[i]);
	}

	return longestString;
}

int main() {
	string A, B;
	cin >> A >> B;

	string result = findLongest(A, B);
	if (result.size() == 0) {
		cout << "" << endl;
	}
	else {
		cout << "result=" << result;
	}
	
	system("pause");
}