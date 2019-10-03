/*
从示例看出，两个相连，数小的那个为父节点
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	vector<int> children;
	int parent;
};

// dfs 操作2清空num，即清空父节点和自己
void setParents(vector<Node>& springTree, int num) {
	if (num == -1) return;
	springTree[num].val = 0;
	int parent = springTree[num].parent;
	setParents(springTree, parent);
}

// dfs 操作1填满num，即填满子节点和自身
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
	// 用initial这种标准格式初始化数据，然后从1下标开始，摒弃0,开始时蓄水池水量都为0
	vector<Node> springTree(n+1,initial);
	while (count < n - 1) {
		// 获取n-1个连接关系
		count++;
		int first, second;
		cin >> first >> second;

		int min = first < second ? first : second;
		int max = first > second ? first : second;

		springTree[min].children.push_back(max);
		springTree[max].parent = min;
	}// 树构建完成

	// 获取操作数并执行操作
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