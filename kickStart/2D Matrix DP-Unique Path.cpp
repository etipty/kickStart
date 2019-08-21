/*********************************DP*****************************************/
/*Unique Paths*/
/*因为m,n的取值范围是100，所以可能的路径取值范围会有double取值才能包含*/
#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int Row = obstacleGrid.size();
	if (!Row) return 0;
	int Column = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1) return 0;

	vector< vector<double> > dp(Row, vector<double>(Column, 0));

	dp[0][0] = 1;

	for (int j = 1; j<Column; j++) {
		dp[0][j] = obstacleGrid[0][j];
		if (dp[0][j] == 0) dp[0][j] = dp[0][j - 1];
		else dp[0][j] = 0;
	}

	for (int i = 1; i<Row; i++) {
		dp[i][0] = obstacleGrid[i][0];
		if (dp[i][0] == 0) dp[i][0] = dp[i - 1][0];
		else dp[i][0] = 0;
	}

	for (int i = 1; i<Row; i++) {
		for (int j = 1; j<Column; j++) {
			dp[i][j] = obstacleGrid[i][j];
			if (dp[i][j] == 1) dp[i][j] = 0;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[Row - 1][Column - 1];
}

int main() {
	vector<vector<int>> Grid = { { 0, 0, 0 },{ 0, 1, 0 },{ 0, 0, 0 } };
	cout << uniquePathsWithObstacles(Grid) << endl;
	system("pause");
}