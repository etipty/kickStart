#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;
	getline(cin, input);

	vector<int> A;
	vector<int> B;

	int R;

	for (int i = 0; i < input.size(); ) {
		// �����ݽ��зֽ�
		if (input[i] == 'A') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					if (tempStr.size() > 0) {
						// ˵�����Ǵ�ļ����
						int tempNum = atoi(tempStr.c_str());
						A.push_back(tempNum);
						tempStr = "";
					}
				}
				else if (input[i] == '}') {
					// ˵��A�Ļ�ȡ������
					int tempNum = atoi(tempStr.c_str());
					A.push_back(tempNum);
					tempStr = "";
					i++;
					break;
				}
			}
		}
		else if (input[i] == 'B') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					if (tempStr.size() > 0) {
						// ˵�����Ǵ�ļ����
						int tempNum = atoi(tempStr.c_str());
						B.push_back(tempNum);
						tempStr = "";
					}
				}
				else if (input[i] == '}') {
					// ˵��A�Ļ�ȡ������
					int tempNum = atoi(tempStr.c_str());
					B.push_back(tempNum);
					tempStr = "";
					i++;
					break;
				}
			}
		}
		else if (input[i] == 'R') {
			i++;
			string tempStr = "";
			for (; i < input.size(); i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					tempStr += input[i];
				}
				else if (input[i] == ',') {
					// ˵��R����ǰ���ȡ��
					int tempNum = atoi(tempStr.c_str());
					R = tempNum;
					tempStr = "";
				}
			}
			// Rȡֵ��������
			if (tempStr.size() > 0) {
				// ˵�����Ǵ�ļ����
				int tempNum = atoi(tempStr.c_str());
				R = tempNum;
				tempStr = "";
			}
		}
		else {
			i++;
		}
	}

	if (A.size() == 0 || B.size() == 0) {
		// ����������
		cout << "";
		return 0;
	}
	// ���������������
	int start = 0; // ������¼B��A��ĳ�ʼλ��
	for (int i = 0; i < A.size(); i++) {
		for (int j = start; j < B.size(); j++) {
			if (A[i] <= B[j]) {
				start = j;
				// �Һ����������Ҫ���
				int count = 0;
				for (int k = B.size() - 1; k >= j; k--) {
					if (B[k] - A[i] <= R) {
						for (int l = j; l <= k; l++) {
							count++;
							// ��������������
							cout << "(" << A[i] << "," << B[l] << ")";
						}
					}
				}
				if (count == 0) {
					// ˵��û�У�����������
					cout << "(" << A[i] << "," << B[j] << ")";
				}

				// �Ѿ��ҵ������������ˣ������ټ���ѭ��
				break;
			}
		}
	}
	system("pause");
}