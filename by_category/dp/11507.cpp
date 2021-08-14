// https://www.acmicpc.net/problem/11057
// 2021-08-15 06:12:14 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d",&n);
	vector<vector<int> > dp(n+1, vector<int>(10, 0));
	// dp[i][j]=i자리 오르막 수 중 j로 끝나는 수

	for(int i=0; i<10; i++)
		dp[1][i]=1;

	for(int i=1; i<n; i++)
		for(int j=0; j<10; j++)
			for(int k=j; k<10; k++)
				dp[i+1][k]=(dp[i+1][k]+dp[i][j])%10007;
	
	int ans=0;
	for(int i=0; i<10; i++)
		ans=(ans+dp[n][i])%10007;
	printf("%d", ans);
}

/*

*/