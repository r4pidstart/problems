// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> dp(n+1);
	dp[0]=, dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		dp[i]=(dp[i-2] + dp[i-1])%10007;
		// i-2개에서 가로로 두개 + i-1개에서 세로로 한개
	}
	printf("%d", dp[n]);
}

/*
	
*/