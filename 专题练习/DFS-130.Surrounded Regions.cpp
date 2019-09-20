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

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
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

// 对临界点进行遍历标记
void dfsRegion(vector<vector<char>>& board, map<pair<int, int>, int>& markedRegion, map<pair<int, int>, int>& toChange, int i, int j, int& flag) {
	int m = board.size();
	int n = board[0].size();

	//if (i<0 || j<0 || i >= m || j >= n) return; // 这个条件根本进不来

	pair<int, int> tempPair = make_pair(i, j);
	// 已经查找过则直接返回不用再遍历
	if (toChange.count(tempPair)) return;

	// 未查找过
	if (board[i][j] == 'X') return;

	if (board[i][j] == 'O') {
		if (markedRegion.count(tempPair)) {
			// 如果查找到的是被标记过的元素，则直接为-1，并返回
			flag = -1;
			return;
		}

		if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
			// 没标记过先对其进行标记
			markedRegion[tempPair] = 1;
			flag = -1;// 当前区域已经不符合，但同时需要对其进行记录，下次查到可以直接终止
			return;
		}

		toChange[tempPair] = 1;
		// 既然使用了DFS则注意其内部肯定会递归调用DFS，否则就不对
		// 未被标记过且符合条件则循环其邻域
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
						// 没标记过先对其进行标记
						if (!markedRegion.count(tempPair))markedRegion[tempPair] = 1;
						continue; // 当前区域已经不符合，但同时需要对其进行记录，下次查到可以直接终止
					}
					else {
						// 非边界点，可对其进行查找
						if (!toChange.count(tempPair)) {
							toChange[tempPair] = 1;
							int flag = 1;
							// 循环其邻域
							dfsRegion(board, markedRegion, toChange, i, j - 1, flag);
							dfsRegion(board, markedRegion, toChange, i, j + 1, flag);
							dfsRegion(board, markedRegion, toChange, i - 1, j, flag);
							dfsRegion(board, markedRegion, toChange, i + 1, j, flag);

							// 与该点相连的所有邻域已查找完
							if (flag == -1) {
								// 其中有不符合的邻域，对所有待改变点清零保持原样
								// 并对该查找中已经存进去的点进行标记
								map<pair<int, int>, int>::iterator it = toChange.begin();

								for (; it != toChange.end(); it++) {
									markedRegion[it->first] = 1;
								}
								toChange.clear();
							}
							else {
								// 说明该块符合，对所有元素进行反转
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