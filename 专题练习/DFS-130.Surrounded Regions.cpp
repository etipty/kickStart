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


Runtime: 96 ms, faster than 5.08% of C++ online submissions for Surrounded Regions.
Memory Usage: 100.9 MB, less than 6.25% of C++ online submissions for Surrounded Regions.
*/

#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

// ���ٽ����б������
void dfsRegion(vector<vector<char>>& board, map<pair<int, int>, int>& markedRegion, map<pair<int, int>, int>& toChange, int i, int j, int& flag) {
	int m = board.size();
	int n = board[0].size();

	//if (i<0 || j<0 || i >= m || j >= n) return; // �����������������

	pair<int, int> tempPair = make_pair(i, j);
	// �Ѿ����ҹ���ֱ�ӷ��ز����ٱ���
	if (toChange.count(tempPair)) return;

	// δ���ҹ�
	if (board[i][j] == 'X') return;

	if (board[i][j] == 'O') {
		if (markedRegion.count(tempPair)) {
			// ������ҵ����Ǳ���ǹ���Ԫ�أ���ֱ��Ϊ-1��������
			flag = -1;
			return;
		}

		if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
			// û��ǹ��ȶ�����б��
			markedRegion[tempPair] = 1;
			flag = -1;// ��ǰ�����Ѿ������ϣ���ͬʱ��Ҫ������м�¼���´β鵽����ֱ����ֹ
			return;
		}

		toChange[tempPair] = 1;
		// ��Ȼʹ����DFS��ע�����ڲ��϶���ݹ����DFS������Ͳ���
		// δ����ǹ��ҷ���������ѭ��������
		dfsRegion(board, markedRegion, toChange, i, j - 1, flag);
		dfsRegion(board, markedRegion, toChange, i, j + 1, flag);
		dfsRegion(board, markedRegion, toChange, i - 1, j, flag);
		dfsRegion(board, markedRegion, toChange, i + 1, j, flag);
	}
}

void solve(vector<vector<char>>& board) {
	int m = board.size();
	if (m > 0) {
		int n = board[0].size();

		map<pair<int, int>, int> markedRegion;
		map<pair<int, int>, int> toChange;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {
					pair<int, int> tempPair = make_pair(i, j);
					if (i == 0 || j == 0 || i == m - 1 || j == n - 1 || markedRegion.count(tempPair)) {
						// û��ǹ��ȶ�����б��
						if (!markedRegion.count(tempPair))markedRegion[tempPair] = 1;
						continue; // ��ǰ�����Ѿ������ϣ���ͬʱ��Ҫ������м�¼���´β鵽����ֱ����ֹ
					}
					else {
						// �Ǳ߽�㣬�ɶ�����в���
						if (!toChange.count(tempPair)) {
							toChange[tempPair] = 1;
							int flag = 1;
							// ѭ��������
							dfsRegion(board, markedRegion, toChange, i, j - 1, flag);
							dfsRegion(board, markedRegion, toChange, i, j + 1, flag);
							dfsRegion(board, markedRegion, toChange, i - 1, j, flag);
							dfsRegion(board, markedRegion, toChange, i + 1, j, flag);

							// ��õ����������������Ѳ�����
							if (flag == -1) {
								// �����в����ϵ����򣬶����д��ı�����㱣��ԭ��
								// ���Ըò������Ѿ����ȥ�ĵ���б��
								map<pair<int, int>, int>::iterator it = toChange.begin();

								for (; it != toChange.end(); it++) {
									markedRegion[it->first] = 1;
								}
								toChange.clear();
							}
							else {
								// ˵���ÿ���ϣ�������Ԫ�ؽ��з�ת
								map<pair<int, int>, int>::iterator it = toChange.begin();

								for (; it != toChange.end(); it++) {
									board[it->first.first][it->first.second] = 'X';
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	vector<vector<char>> board = { { '1', '1', '1', '1', '0' },{ '1', '1', '0', '1', '0' },{ '1', '1', '0', '0', '0' },{ '0', '0', '0', '0', '0' } };

	solve(board);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (j == board[0].size()-1) {
				cout << board[i][j] << endl;
			}
			else {
				cout << board[i][j] << ' ';
			}
		}
	}

	system("pause");
}