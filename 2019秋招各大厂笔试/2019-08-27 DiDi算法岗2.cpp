#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct treeNode {
	int num;
	int parent;
	vector<int> childern;
};

int dfsParent(vector<treeNode> tree, int num, int th, set<int> &sum) {
	int parent;
	for (int i = 0; i < th; i++) {
		parent = tree[num].parent;
		if (parent == -1) return 0; // 说明此点父节点中不存在符合的
		num = parent;
	}
	// 没有退出，说明查找到了，将父节点存入set
	sum.insert(parent);
	return 0;
}

int dfsChildren(vector<treeNode> tree, int num, int start, int th, set<int> &sum) {
	//int count = 0;

	vector<int> Children = tree[num].childern;
	int size = Children.size();
	// 当还能进来，说明当前节点还没达到查询深度，而其孩子节点数已经为0，因此可直接退出dfs
	if (size == 0) return 0;
	// 查到th-1时，就可根据孩子节点数返回了，但此时也涉及到直接返回数目的话，如果孩子节点中有M中的点则会存在重复计数的可能。
	if (start == th - 1)
	{
		// 将孩子节点依次存进set中，注意看set是传值还是传引用
		for (int k = 0; k < size; k++) {
			int Cchildren = Children[k];
			sum.insert(Cchildren);
		}
		// 退出查询
		return 0;
	}
	// 没达到th-1还需继续往下查找
	for (int k = 0; k < size; k++) {
		int Cchildren = Children[k];
		dfsChildren(tree, Cchildren, start + 1, th, sum); // 在孩子中进一步查找
	}
}

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> M;
	for (int i = 0; i < m; i++) {
		int tempM;
		cin >> tempM;
		M.push_back(tempM);
	}

	treeNode rootNode;
	rootNode.num = -1;
	rootNode.parent = -1;

	vector<treeNode> tree(n + 1, rootNode); // 已初始化所有节点，之后只用直接存值就可以了

											// 构建树
	for (int j = 1; j < n; j++) {
		// 存子节点
		int parent;
		cin >> parent;
		tree[j + 1].num = j + 1;
		tree[j + 1].parent = parent;

		// 存父节点
		if (tree[parent].num == -1) {
			// 说明还未记录
			tree[parent].num = parent;
			tree[parent].childern.push_back(j + 1);
		}
		else {
			tree[parent].childern.push_back(j + 1);
		}
	}

	set<int> sum; // 用来将找到的点的编号存进去，由于set的元素唯一性，可以保证不重复计数，最后只用统计set的count数就可以了
				  // 深搜查找父节点满足的个数
	for (int l = 0; l < m; l++) {
		// 只管查询，不用计数，查询的过程中存set即可
		// 若题目要求是将所有的M点也记在里面，则在此同时将M点存入set，避免后续二次遍历存储
		dfsParent(tree, M[l], d, sum);
		dfsChildren(tree, M[l], 0, d, sum);
	}
	cout << sum.size();
	system("pause");
}