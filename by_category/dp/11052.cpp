// https://www.acmicpc.net/problem/11052
// 2021-08-15 06:06:01 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d",&n);
	vector<int> price(n+1, 0);
	for(int i=1; i<=n; i++)
		scanf("%d",&price[i]);
	
	vector<int> dp(n+1, 0);
	// dp[i]=i개의 카드를 사는데 필요한 최대금액
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			dp[i]=max(dp[i], dp[i-j]+price[j]);

	printf("%d", dp[n]);
}

/*

*/