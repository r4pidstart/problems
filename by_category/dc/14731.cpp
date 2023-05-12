// https://www.acmicpc.net/problem/14731
// 2023-05-13 00:16:40
#include"bits/stdc++.h"
using namespace std;

const int mod=(int)1e9+7;

long mypow(long a)
{
	static map<long, long> dp;
	if(dp.find(a) != dp.end()) return dp[a];

	if(a==0) return dp[a]=1;
	else if(a&1) return dp[a]=mypow(a-1)*2%mod;
	long tmp=mypow(a/2);
	return dp[a]=tmp*tmp%mod;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	long ans=0;
	for(int i=0; i<n; i++)
	{
		long a,b; scanf("%ld%ld", &a, &b);
		if(b)
			ans=(ans+(a*b%mod)*mypow(b-1)%mod)%mod;
	}
	printf("%ld", ans);

}

/*
	
*/