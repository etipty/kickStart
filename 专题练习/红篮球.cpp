#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

/*�������ÿһ�ֵİ취���ԣ���ΪC����һ��ѡ��������������Ӱ�죬��״ֻ̬��¼��ǰһ�ֵģ�����ĳһ�ֻ�Ӯ����ǰ���ж��ֿ��ܵ�ѡ��
*������д������������ȱ�����ÿһ�β�û�аѵ�ǰ״̬�����������ƹ�ʽ�Ǵ��
*/
/* C��״ֻ̬��1ȡ�죬0��ȡ��*/
// ����ÿһ��ʤ���ĸ���
void getRate(int i, int preC, int numsH, int nums, vector<vector<double>>& dp) {
	//if(numsH == 0) 
	if (nums <= 0) return;
	if (numsH == 0) return ;

	if (preC == 1) {
		double sh = ((double)(nums - numsH + 2) / (nums + 3))*((double)(nums - numsH + 1) / (nums + 2))*((double)(numsH + 1) / (nums + 1));
		dp[i][1] += ((double)numsH/ nums)* sh;
		if (nums < 3)return;
	}
	else if (preC == 0) {
		double sh = ((double)(nums - numsH + 3) / (nums + 3))*((double)(nums - numsH + 2) / (nums + 2))*((double)(nums - numsH + 1) / (nums + 1));
		dp[i][0] += ((double)numsH / nums)*sh;
		if (nums < 3)return;
	}

	// ����C����ȡ��Ҳ���ܲ�ȡ��
	getRate(i + 1, 0, numsH, nums - 3, dp);
	getRate(i + 1, 1, numsH - 1, nums - 3, dp);
}

double solve(int n, int m) {
	int nums = n + m;
	vector<vector<double>> dp(n, vector<double>(2, 0));

	double result = 0;

	dp[0][0] = (double)n / nums;
	// ��1��ʼ����
	getRate(1, 0, n, nums-3, dp);
	getRate(1, 1, n - 1, nums - 3, dp);

	for (int i = 0; i < n; i++) {
		result = result + dp[i][0] + dp[i][1];
	}

	return result;

}

int main() {
	
	while (1) {
		int n, m;
		cin >> n >> m;

		double result = solve(n, m);

		cout << fixed << setprecision(5) << result << endl;
	}

	system("pause");

}
