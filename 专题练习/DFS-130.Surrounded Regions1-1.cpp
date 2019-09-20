/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn��t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
Two cells are connected if they are adjacent cells connected horizontally or vertically.

���Բ��ñ�Ե��ʴ�Ĳ��ԶԲ����������Ľ���DFSѭ��ȫ����ǣ�ʣ��Ĳ���DFSֱ��ȫ���������з�ת���ɣ�ʱ�临�Ӷ�O(n^2)

Runtime: 16 ms, faster than 100.08% of C++ online submissions for Surrounded Regions.
Memory Usage: 14.1 MB, less than 89% of C++ online submissions for Surrounded Regions.
*/

#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

// �Ա�Ե���ǲ���������DFS���ʱ�ǣ���ԭ�����ϲ��������Լ����ڴ濪��
void dfsRegion(vector<vector<char>>& board, int i, int j) {
	int m = board.size();
	int n = board[0].size();
	if (i < 0 || j < 0 || i == m || j == n || board[i][j] == 'X'|| board[i][j] == '1') return;
	board[i][j] = '1';

	// ��Ȼʹ����DFS��ע�����ڲ��϶���ݹ����DFS������Ͳ���
	// δ����ǹ��ҷ���������ѭ��������
	dfsRegion(board, i, j - 1);
	dfsRegion(board, i, j + 1);
	dfsRegion(board, i - 1, j);
	dfsRegion(board, i + 1, j);
}

void solve(vector<vector<char>>& board) {
	int m = board.size();
	if (m > 0) {
		int n = board[0].size();

		// �ȶԱ߽����������ұ��
		for (int i = 0; i < m; i++) {
			if (board[i][0] == 'O') {
				dfsRegion(board, i, 0);
			}
			if (n > 1) {
				dfsRegion(board, i, n-1);
			}
		}

		for (int j = 1; j < n - 1; j++) {
			if (board[0][j] == 'O') {
				dfsRegion(board, 0, j);
			}
			if (m > 1) {
				dfsRegion(board, m - 1, j);
			}
		}

		// ������δ��ǵ�O���з�ת
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}

		// �����Ա�ǵĽ��лָ�
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '1') {
					board[i][j] = 'O';
				}
			}
		}
	}
}

int main() {
	vector<vector<char>> board = { { 'O', 'O'},{ 'O', 'O' } };

	solve(board);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (j == board[0].size() - 1) {
				cout << board[i][j] << endl;
			}
			else {
				cout << board[i][j] << ' ';
			}
		}
	}

	system("pause");
}