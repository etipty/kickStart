/*
�������ʵ���ѣ��ؼ������������ж�Ҫ���ã�����Ծͻ���30min��������û������������
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;

	string tempStr = "";
	//string tempStr1 = "";
	int count = 0;
	int flag = -1;
	vector<string> result;
	// ��ȡ��������
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a'&&input[i] <= 'z') || (input[i] >= 'A'&&input[i] <= 'Z')) {
			if (count > 0) {
				// �����������
				if (count == 1) {
					// ���ӷ�
					if (flag == -1) {
						// ˵��ǰһ��Ϊ�Ƿ��ַ���Ӧ����������
						count = 0;
					}
					else {
						if (tempStr.size() > 0) {
							tempStr += "-";
							count = 0;
							flag = -1;
						}
						else {
							flag = -1;
							tempStr += input[i];
							count = 0;
							continue;
						}
						
					}
				}
				else if (count >= 2) {
					// �����
					result.push_back(tempStr);
					tempStr = "";
					count = 0;
				}
			}
			// ���������������ַ�
			tempStr += input[i];
		}
		else if (input[i] == '-') {
			flag = 1;
			count++;
		}
		else {
			// �Ƿ����ţ�ͳһ�����������
			flag = -1; // Ҫ��¼�Ƿ��ַ�
			if (tempStr.size() > 0) {
				result.push_back(tempStr);
				tempStr = "";
			}
			// ���tempStr.size()Ϊ0˵��Ϊ����Ƿ����Ų��ù�
		}
	}

	if (tempStr.size() > 0) {
		result.push_back(tempStr);
	}

	// �����뵹�����
	cout << result[result.size() - 1];
	for (int j = result.size() - 2; j >= 0; j--) {
		cout << " " << result[j];
	}
	system("pause");
}