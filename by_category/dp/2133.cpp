// https://www.acmicpc.net/problem/2133
// 2021-08-19 01:34:30 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> dp(31,0);
	dp[0]=1, dp[2]=3;
	for(int i=4; i<=n; i++)
	{
		dp[i]=dp[i-2]*3;
		for(int j=4; j<=i; j++)
			if(!(j%2))
				dp[i]+=(dp[i-j]*2);
	}
	printf("%d", dp[n]);
}

/*

*/