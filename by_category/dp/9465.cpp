// https://www.acmicpc.net/problem/9465
// 2021-08-16 23:02:19 236ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		vector<vector<int> > arr(n+1, vector<int>(2));
		for(int i=0; i<2; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &arr[j][i]);

		vector<vector<int> > dp(n+1, vector<int>(2,0));
		// dp[i][j]: i,j 스티커를 뜯었을 때 최대 점수

		dp[1][0]=arr[1][0], dp[1][1]=arr[1][1];
		for(int i=2; i<=n; i++)
		{
			dp[i][0]=max(dp[i-1][1], dp[i-2][1])+arr[i][0];
			dp[i][1]=max(dp[i-1][0], dp[i-2][0])+arr[i][1];
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
}

/*

*/