/*
1、 根据给出的字符数组，按照下面样例的要求，构造一颗完全二叉树；

2、 打印构造好的完全二叉树，打印的格式要求见样例；

3、 翻转该树，而后打印翻转后的效果；
*/

#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<deque>
#include<algorithm>
using namespace std;
struct N {
	char c;
	int f, p, l, r, num;
};
int fact(int m, vector<N>&b)
{
	if (m == -1 || b[m].c == ' ')
		return 0;
	return 1 + fact(b[m].l, b);
}
void fact1(vector<N>&b, int h) {
	int t = 0, flag = 1;
	vector<N>d;
	while (t < b.size())
	{
		d.clear();
		while (t<b.size() && b[t].f == flag)
		{
			d.push_back(b[t]);
			if (b[t].num == pow(2, b[t].f - 1) - 1)
			{
				if (b[t].c != ' ') {
					int val = fact(b[t].num, b) - 1;
					int sum = 0, v = pow(2, h - b[t].f - 1);
					for (int i = 0; i < val; ++i)
					{
						sum += v;
						v >>= 1;
					}
					for (int i = 0; i < sum; ++i)
						cout << " ";
					cout << b[t].c;
				}
				else {
					cout << b[t].c;
				}
			}
			else if (b[t].num == b[b[t].p].l) {
				int d = pow(2, h - b[t].f);
				for (int i = 0; i < 2 * d - 1; ++i)
					cout << " ";
				cout << b[t].c;
			}
			else if (b[t].num == b[b[t].p].r) {
				int d = pow(2, h - b[t].f);
				int e = b[b[t].p].l;
				if (b[e].c == ' ' && (b[b[t].p].num == pow(2, b[b[t].p].f - 1) - 1))
				{
					for (int i = 0; i < d - 1; ++i)
						cout << " ";
					cout << b[t].c;
				}
				else {
					for (int i = 0; i < 2 * d - 1; ++i)
						cout << " ";
					cout << b[t].c;
				}
			}
			t++;
		}
		cout << endl;
		cout << endl;
		int index = (flag != h ? pow(2, h - flag - 1) : 0);
		int size = fact(d[0].num, b) - 1;
		int val = 0, v = pow(2, h - d[0].f - 1);
		for (int i = 0; i < size; ++i)
		{
			val += v;
			v >>= 1;
		}
		val -= 1;
		int val1 = 1;
		for (int i = 0; i < index; ++i) {
			for (int j = 0; j < d.size(); ++j)
			{
				string left = " ", right = " ";
				if (d[j].l == -1 || b[d[j].l].c == ' ')
					left = " ";
				else left = "/";
				if (d[j].r == -1 || b[d[j].r].c == ' ')
					right = " ";
				else right = "\\";
				if (d[j].num == (pow(2, d[j].f - 1) - 1))
				{
					for (int i1 = 0; i1 < val; ++i1)
						cout << " ";
					if (d[j].p == -1 || !((b[d[j].p].num == (pow(2, b[d[j].p].f - 1) - 1)) && (left == " ")))
						cout << left;
					for (int j1 = 0; j1 < val1; ++j1)
						cout << " ";
					cout << right;
				}
				else {
					if (d[j].num == b[d[j].p].l)
					{
						int len = 2 * pow(2, h - b[d[j].p].f) - 1 - 2 * pow(2, h - d[j].f);
						for (int i1 = 0; i1 < len - 1 - val1; ++i1)
							cout << " ";
						cout << left;
						for (int j1 = 0; j1 < val1; ++j1)
							cout << " ";
						cout << right;
					}
					else if (d[j].num == b[d[j].p].r) {
						int len = 2 * pow(2, h - d[j].f) - 1;
						for (int i1 = 0; i1 < len - 1 - val1; ++i1)
							cout << " ";
						cout << left;
						for (int j1 = 0; j1 < val1; ++j1)
							cout << " ";
						cout << right;
					}
				}
			}
			val--;
			val1 += 2;
			cout << endl;
			cout << endl;
		}
		flag++;
	}
}
int main() {
	string s = "";
	while (getline(cin, s))
	{
		vector<char>a;
		for (int i = 0; i<s.length(); ++i)
			if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z'))
				a.push_back(s[i]);
		vector<N>b;
		deque<N>c;
		N n;
		n.c = a[0];
		n.f = 1;
		n.num = 0;
		n.p = -1;
		c.push_back(n);
		while (!c.empty()) {
			N n = c.front();
			c.pop_front();
			n.l = 2 * n.num + 1;
			if (n.l<a.size())
			{
				N n1;
				n1.f = n.f + 1;
				n1.p = n.num;
				n1.num = n.l;
				n1.c = a[n.l];
				c.push_back(n1);
			}
			else n.l = -1;
			n.r = 2 * n.num + 2;
			if (n.r<a.size())
			{
				N n2;
				n2.f = n.f + 1;
				n2.p = n.num;
				n2.num = n.r;
				n2.c = a[n.r];
				c.push_back(n2);
			}
			else n.r = -1;
			b.push_back(n);
		}
		int h = b[b.size() - 1].f;
		int len = (int)b.size() - 1;
		for (int j = 0; j <= len; ++j)
		{
			if (b[j].f == h)
				break;
			if (b[j].f != h - 1)
				continue;
			if (b[j].l == -1)
			{
				b[j].l = 2 * b[j].num + 1;
				N n;
				n.p = b[j].num;
				n.num = b[j].l;
				n.f = b[j].f + 1;
				n.c = ' ';
				n.r = -1;
				n.l = -1;
				b.push_back(n);
			}
			if (b[j].r == -1)
			{
				b[j].r = 2 * b[j].num + 2;
				N n;
				n.p = b[j].num;
				n.num = b[j].r;
				n.f = b[j].f + 1;
				n.c = ' ';
				n.r = -1;
				n.l = -1;
				b.push_back(n);
			}
		}
		fact1(b, h);
		int t = 0, flag = 1;
		while (t < b.size()) {
			int first = t, last = t;
			while (last<b.size() && b[last].f == flag)
				last++;
			vector<char>d;
			for (int i = first; i < last; ++i)
			{
				d.push_back(b[i].c);
			}
			int k = 0;
			reverse(d.begin(), d.end());
			for (int j = first; j < last; ++j)
			{
				b[j].c = d[k++];
			}
			flag++;
			t = last;
		}
		fact1(b, h);
	}
}