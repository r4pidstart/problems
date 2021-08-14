// https://www.acmicpc.net/problem/11726
// 2021-08-15 05:48:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> dp(n+1);
	dp[0]=0, dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		dp[i]=(dp[i-2] + dp[i-1])%10007;
		// i-2개에서 가로로 두개 + i-1개에서 세로로 한개
	}
	printf("%d", dp[n]);
}

/*
	
*/