// https://www.acmicpc.net/problem/2193
// 2021-08-15 05:56:48 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<vector<long long> > dp(n+1, vector<long long>(2));
	// dp[i][j] = i자리 j로 끝나는 이친수의 갯수
	dp[1][0]=0;
	dp[1][1]=1;

	for(int i=2; i<=n; i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	printf("%lld", dp[n][0]+dp[n][1]);
}

/*
	1000 1010 / 1001
	10000 10100 10010 / 10001 10101
	100000 101000 100100 100010 101010 / 100001 101001 100101
*/