/*
作者：埃德蒙爱足球
链接：https ://www.nowcoder.com/discuss/235938
来源：牛客网
*/

//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

char fuhao[100];
int num[100];
int N;
int find(int begin, int leng, char flg)
{
	while (begin<leng && fuhao[begin] == flg)
	{
		++begin;
	}
	return begin;
}

int main()
{
	int temp = 0;
	cin >> N;
	fuhao[0] = '+';
	for (int i = 0; i<N * 2 - 1; ++i)
	{
		if (i % 2 == 0)
		{
			cin >> num[i / 2];
		}
		else {
			cin >> fuhao[(i + 1) / 2]; // 符号的下标是从1开始
		}
	}

	//  除
	for (int i = 0; i<N;)
	{
		temp = find(i, N, '/');
		if (temp - i >= 1)
		{
			sort(num + i, num + temp);
			i = temp;
		}
		else {
			++i;
		}
	}

	// 乘
	for (int i = 0; i<N;)
	{
		temp = find(i, N, '*');
		if (temp - i >= 1)
		{
			if (fuhao[i - 1] == '/')
				sort(num + i - 1, num + temp - 1);
			else
				sort(num + i, num + temp);
			i = temp;
		}
		else {
			++i;
		}
	}

	// +
	for (int i = 0; i<N;)
	{
		temp = find(i, N, '+');
		if (temp - i >= 1)
		{
			if (temp<N && fuhao[temp] != '-')
			{
				sort(num + i, num + temp - 1);
			}
			else {
				sort(num + i, num + temp);
			}
			i = temp;
		}
		else {
			++i;
		}

	}

	// -
	for (int i = 0; i<N;)
	{
		temp = find(i, N, '-');
		if (temp - i >= 1)
		{
			if (temp<N && fuhao[temp] != '+')
			{
				sort(num + i, num + temp - 1);
			}
			else {
				sort(num + i, num + temp);
			}
			i = temp;
		}
		else
		{
			++i;
		}

	}

	for (int i = 0; i<N * 2 - 1; ++i)
	{
		if (i % 2 == 0)
		{
			cout << num[i / 2];
		}
		else {
			cout << " " << fuhao[(i + 1) / 2] << " ";
		}
	}
	return 0;
}