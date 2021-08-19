// https://www.acmicpc.net/problem/1309
// 2021-08-19 21:35:31 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<vector<int> > dp(n+1, vector<int>(3,0));
	dp[1][0]=1, dp[1][1]=1, dp[1][2]=1;

	for(int i=2; i<=n; i++)
		for(int j=0; j<3; j++)
		{
			dp[i][j]=(dp[i-1][(j+1)%3]+dp[i-1][(j+2)%3])%9901;
			if(j==2) dp[i][j]=(dp[i][j]+dp[i-1][j])%9901;
		}

	printf("%d", (dp[n][0]+dp[n][1]+dp[n][2])%9901);
}

/*

*/