#include<iostream>
#include<string>
using namespace std;

int main() {
	string InputString;
	cin >> InputString;

	string OutputNum = "";
	string OutputString = "";

	int size = InputString.size();

	for (int i = 0; i < size; i++) {
		if (InputString.at(i) >= '0' && InputString.at(i) <= '9') {
			if (OutputNum == "") {
				OutputNum += InputString[i];
			}else if (OutputNum.find(InputString[i]) == string::npos) {
				// ע��string���Ҳ���ʱ�ķ���ֵ����Ϊstring::npos�����ҵ��򷵻ز��ҵ�����λ��
				OutputNum += InputString[i];
			}
		}
		if ((InputString.at(i) >= 'a' && InputString.at(i) <= 'z') || (InputString.at(i) >= 'A' && InputString.at(i) <= 'Z')) {
			OutputString += InputString[i];
		}
	}

	OutputString = OutputNum + OutputString;

	cout << OutputString;

	system("pause");
}