// https://www.acmicpc.net/problem/11727
// 2021-08-15 06:00:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> dp(n+1,0);
	dp[0]=1, dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
	}
	printf("%d", dp[n]);
}

/*

*/