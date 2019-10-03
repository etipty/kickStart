/*
现在领导有m（m为偶数）个人，每两个人一起共同完成一个任务，完成任务的时间为两个人的时间权值之和，
现在给出n行数据，每行数据有两个值x和y，代表有x个人的时间权值为y，求所有任务最快在什么时候都完成

不明白为什么只过了10%，感觉应该是细节处理的问题没弄好，第四题就是最终调好了全AC了
可能的错误点：
1.num那块儿放进去的数据数目不对，这个最好还是像第4题一样在VS里面调试一下才能发现错误；
2.求max时for循环中的次数不对
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> Times;
	while (N--) {
		int num;
		int tempTime;
		cin >> num >> tempTime;
		for (int i = 0; i < num; i++) {
			// 把num个数据全部放进去
			Times.push_back(tempTime);
		}
	}
	//sort(Times, Times+Times.size());
	sort(Times.begin(), Times.end());
	int shortestTime = Times[0] + Times[Times.size() - 1];
	for (int i = 0; i < (Times.size() + 1) / 2; i++) {
		//cout << "第" << i << "次" << Times[i] + Times[Times.size() - 1 - i] << endl;
		shortestTime = max(shortestTime, Times[i] + Times[Times.size() - 1 - i]);
	}
	//cout << shortestTime;
	cout << "最终结果：" << shortestTime;
	//system("pause");
}