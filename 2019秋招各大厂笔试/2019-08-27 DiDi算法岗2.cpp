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
		if (parent == -1) return 0; // ˵���˵㸸�ڵ��в����ڷ��ϵ�
		num = parent;
	}
	// û���˳���˵�����ҵ��ˣ������ڵ����set
	sum.insert(parent);
	return 0;
}

int dfsChildren(vector<treeNode> tree, int num, int start, int th, set<int> &sum) {
	//int count = 0;

	vector<int> Children = tree[num].childern;
	int size = Children.size();
	// �����ܽ�����˵����ǰ�ڵ㻹û�ﵽ��ѯ��ȣ����亢�ӽڵ����Ѿ�Ϊ0����˿�ֱ���˳�dfs
	if (size == 0) return 0;
	// �鵽th-1ʱ���Ϳɸ��ݺ��ӽڵ��������ˣ�����ʱҲ�漰��ֱ�ӷ�����Ŀ�Ļ���������ӽڵ�����M�еĵ��������ظ������Ŀ��ܡ�
	if (start == th - 1)
	{
		// �����ӽڵ����δ��set�У�ע�⿴set�Ǵ�ֵ���Ǵ�����
		for (int k = 0; k < size; k++) {
			int Cchildren = Children[k];
			sum.insert(Cchildren);
		}
		// �˳���ѯ
		return 0;
	}
	// û�ﵽth-1����������²���
	for (int k = 0; k < size; k++) {
		int Cchildren = Children[k];
		dfsChildren(tree, Cchildren, start + 1, th, sum); // �ں����н�һ������
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

	vector<treeNode> tree(n + 1, rootNode); // �ѳ�ʼ�����нڵ㣬֮��ֻ��ֱ�Ӵ�ֵ�Ϳ�����

											// ������
	for (int j = 1; j < n; j++) {
		// ���ӽڵ�
		int parent;
		cin >> parent;
		tree[j + 1].num = j + 1;
		tree[j + 1].parent = parent;

		// �游�ڵ�
		if (tree[parent].num == -1) {
			// ˵����δ��¼
			tree[parent].num = parent;
			tree[parent].childern.push_back(j + 1);
		}
		else {
			tree[parent].childern.push_back(j + 1);
		}
	}

	set<int> sum; // �������ҵ��ĵ�ı�Ŵ��ȥ������set��Ԫ��Ψһ�ԣ����Ա�֤���ظ����������ֻ��ͳ��set��count���Ϳ�����
				  // ���Ѳ��Ҹ��ڵ�����ĸ���
	for (int l = 0; l < m; l++) {
		// ֻ�ܲ�ѯ�����ü�������ѯ�Ĺ����д�set����
		// ����ĿҪ���ǽ����е�M��Ҳ�������棬���ڴ�ͬʱ��M�����set������������α����洢
		dfsParent(tree, M[l], d, sum);
		dfsChildren(tree, M[l], 0, d, sum);
	}
	cout << sum.size();
	system("pause");
}