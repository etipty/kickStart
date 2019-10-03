/*
作者：vegeken
链接：https://www.nowcoder.com/discuss/271330?type=all&order=time&pos=&page=2
来源：牛客网

题意：有n个人比赛，每个人都有一个权值，现在要将n个人分成两组，两组间的人数差<=1，问怎么分组可以使得两个组的人的权值和的差最小。

个人做法：题目有个很关键的条件就是所有人的权值和<=1e5，所以可以用类似背包的方法做。

第i个人的权值记为a[i]，令dp[i][j][k]表示只考虑前i个人，用j个人是否能将权值凑成k，如果可以则dp[i][j][k]=1,否则为0，那么转移就是如果dp[i-1][j][k]为1，那么dp[i][j+1][k+a[i]]也为1，否则为0，初始条件dp[0][0][0]=1。

考虑到dp数组空间可能会超，可以使用滚动数组节省空间。
*/

#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int X[110];

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(X, 0, sizeof(X));
	}
}