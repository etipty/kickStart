/*
��ʾ��������������������С���Ǹ�Ϊ���ڵ�
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	vector<int> children;
	int parent;
};

// dfs ����2���num������ո��ڵ���Լ�
void setParents(vector<Node>& springTree, int num) {
	if (num == -1) return;
	springTree[num].val = 0;
	int parent = springTree[num].parent;
	setParents(springTree, parent);
}

// dfs ����1����num���������ӽڵ������
void setChildren(vector<Node>& springTree, int num) {
	springTree[num].val = 1;
	vector<int> childs = springTree[num].children;
	if (childs.size() == 0) return;
	for (int i = 0; i < childs.size(); i++) {
		int tempC = childs[i];
		setChildren(springTree, tempC);
	}
}

int main() {
	int n;
	int count = 0;
	cin >> n;

	Node initial;
	initial.val = 0;
	initial.parent = -1;
	// ��initial���ֱ�׼��ʽ��ʼ�����ݣ�Ȼ���1�±꿪ʼ������0,��ʼʱ��ˮ��ˮ����Ϊ0
	vector<Node> springTree(n+1,initial);
	while (count < n - 1) {
		// ��ȡn-1�����ӹ�ϵ
		count++;
		int first, second;
		cin >> first >> second;

		int min = first < second ? first : second;
		int max = first > second ? first : second;

		springTree[min].children.push_back(max);
		springTree[max].parent = min;
	}// ���������

	// ��ȡ��������ִ�в���
	int q;
	cin >> q;
	while (q--) {
		int c, v;
		cin >> c >> v;
		switch (c)
		{
		case 1:
			setChildren(springTree, v);
			break;
		case 2:
			setParents(springTree, v);
			break;
		case 3:
			cout << springTree[v].val << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
}