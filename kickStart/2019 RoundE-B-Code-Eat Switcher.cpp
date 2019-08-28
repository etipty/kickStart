#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	int iCase = 0;
	scanf_s("%d", &T);
	while (T--) {
		iCase++;
		int Days, Slots;
		scanf_s("%d%d", &Days, &Slots);
		vector< vector<int> > S(Slots + 1, vector<int>(2, 0));
		vector< vector<int> > D(Days + 1, vector<int>(2, 0));
		int SD[2] = { 0,0 };
		for (int i = 1; i <= Slots; i++) {
			scanf_s("%d%d", &S[i][0], &S[i][1]);
			SD[0] += S[i][0];
			SD[1] += S[i][1];
		}
		for (int j = 1; j <= Days; j++) {
			scanf_s("%d%d", &D[j][0], &D[j][1]);
		}

		printf("Case #%d: ", iCase);
		for (int k = 1; k <= Days; k++) {
			double tempc = (double)D[k][0] / SD[0];
			double tempe = (double)D[k][1] / SD[1];
			if (tempc + tempe <= 1)printf("Y");
			else printf("N");
		}
		////double tolc = 0;
		//double tole = 0;
		//for (int k = 1; k <= Days; k++) {
		//	for (int l = 1; l <= Slots; l++) {
		//		double tempc = (double)S[l][0]/ SD[0];
		//		tole += (1 - tempc)*S[l][1];
		//		//double tempe = (double)S[l][1] / D[k][1];
		//	}
		//	if (tole >= D[k][1])printf("Y");
		//	else printf("N");
		//}
		printf("\n");
		system("pause");
	}
}