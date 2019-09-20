/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

����Ҳ����BFS�⣬DFSתBFSֻ�����϶��м��ɣ�C++�Դ�queue��Ҳ����vector���й���ά������
Runtime: 12 ms
Memory Usage: 10.5 MB
*/

#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;

void searchAdjacent(vector<vector<char>>& grid, int i, int j) {
	int m = grid.size();
	int n = grid[0].size();

	if (i<0 || j<0 || i >= m || j >= n) return;

	// ����Ѿ�Ϊ2˵���Ѿ����ҹ���߽粻���ٲ��ң����Ϊ0˵��Ϊ�߽�
	if (grid[i][j] == '2' || grid[i][j] == '0') return;

	if (grid[i][j] == '1') {
		grid[i][j] = '2';
		searchAdjacent(grid, i, j + 1);
		searchAdjacent(grid, i, j - 1);
		searchAdjacent(grid, i + 1, j);
		searchAdjacent(grid, i - 1, j);
	}
}

int numIslands(vector<vector<char>>& grid) {
	int m = grid.size();
	if (m == 0) return 0; // Ҫ����[]���ֱ߽����
	int n = grid[0].size();

	set<pair<int, int>> Islands;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (grid[i][j] == '1') {
				Islands.insert(make_pair(i, j));
				grid[i][j] = '2'; // ���Ϊ�Ѳ��ҹ�
				searchAdjacent(grid, i, j + 1);
				searchAdjacent(grid, i, j - 1);
				searchAdjacent(grid, i + 1, j);
				searchAdjacent(grid, i - 1, j);
			}
		}
	}

	int result = Islands.size();
	return result;
}

int main() {

	vector<vector<char>> input = { { '1', '1', '1', '1', '0' },{ '1', '1', '0', '1', '0' },{ '1', '1', '0', '0', '0' },{ '0', '0', '0', '0', '0' } };

	int count = numIslands(input);

	cout << count << endl;

	system("pause");
}