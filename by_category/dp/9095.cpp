// https://www.acmicpc.net/problem/9095
// 2021-08-15 20:22:10 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int t; scanf("%d", &t);
	for(int T=0; T<t; T++)
	{
		int n; scanf("%d", &n);
		vector<int> dp(n+1,0);
		// dp[i]: i를 만드는 방법의 수
		dp[0]=1, dp[1]=1, dp[2]=2;
		for(int i=3; i<=n; i++)
			dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
		printf("%d\n", dp[n]);
	}
}

/*

*/