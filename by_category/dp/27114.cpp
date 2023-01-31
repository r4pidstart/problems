// https://www.acmicpc.net/problem/27114
// 2023-02-01 03:59:59
#include"bits/stdc++.h"
using namespace std;

int l,r,b, K;
int ans(int k, int now)
{
	static vector<vector<int> > dp(K+1, vector<int>(4, -1));

	if(k<0)
		return INT32_MAX/2;
	else if(k==0 and now==0)
		return 0;
	
	if(dp[k][now] != -1)
		return dp[k][now];
	
	int ret=INT32_MAX/2;
	
	// left
	ret=min(ret, ans(k-l, (now+4-1)%4)+1);
	// right
	ret=min(ret, ans(k-r, (now+1)%4)+1);
	// back
	ret=min(ret, ans(k-b, (now+2)%4)+1);

	return dp[k][now]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	scanf("%d%d%d%d", &l, &r, &b, &K);
	for(int i=10000; i<K; i+=10000) ans(i, 0);
	printf("%d", ans(K, 0) > K ? -1 : ans(K, 0));
}

/*
	
*/