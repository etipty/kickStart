#include<iostream>
using namespace std;

/**
* Definition for a binary tree node.
*/
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
	TreeNode(TreeNode* origin) {
		val = origin->val;
		left = new TreeNode(origin->left);
		right = new TreeNode(origin->right);
	}
};

 // 涉及到拷贝构造的问题
 void dfsFlatten(TreeNode* temp, TreeNode* tempResult) {
	 if (temp->left != NULL) {
		 TreeNode* tempLeft = temp->left;
		 tempResult->right = tempLeft;
		 dfsFlatten(temp->left, tempResult->right);
	 }
	 if (temp->right != NULL) {
		 TreeNode* tempLeft = temp->right;
		 tempResult->right = tempLeft;
		 dfsFlatten(temp->left, tempResult->right);
	 }
	 return;
 }

 void flatten(TreeNode* root) {
	 TreeNode* tempResult = root;
	 dfsFlatten(root, tempResult);
 }