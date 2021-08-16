// https://www.acmicpc.net/problem/14501
// 2021-08-16 21:53:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<pair<int,int> > schedule(n+1, pair<int,int>({}));
	for(int i=1; i<=n; i++)
		scanf("%d%d", &schedule[i].first, &schedule[i].second);
	vector<int> dp(n+2, 0);
	for(int i=1; i<=n+1; i++)
	{
		dp[i]=max(dp[i], dp[i-1]);
		if(i+schedule[i].first <= n+1)
			dp[i+schedule[i].first]=max(dp[i+schedule[i].first], dp[i]+schedule[i].second);
	}
	printf("%d", dp[n+1]);
}

/*

*/