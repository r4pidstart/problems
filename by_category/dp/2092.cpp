// https://www.acmicpc.net/problem/2092
// 2023-01-05 19:08:46
#include"bits/stdc++.h"
using namespace std;

const int MOD=1'000'000;

int main(void)
{
#ifdef LOCAL
#endif
    int t, a, s, b;
    scanf("%d%d%d%d", &t, &a, &s, &b);
    vector<int> arr(t+1);
    for(int i=0; i<a; i++)
    {
		int a; scanf("%d", &a);
		arr[a]++;
	}    

    vector<vector<int> > dp(t+1, vector<int>(b+1));
	dp[0][0]=1;
	for(int i=1; i<=t; i++)
	{
		for(int j=0; j<=b; j++)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
		for(int j=1; j<=arr[i]; j++)
		{
			for(int k=1; k<=b; k++)
				if(k-j >= 0)
					dp[i][k]=(dp[i][k] + dp[i-1][k-j])%MOD;
		}
	}
	printf("%ld", accumulate(dp[t].begin()+s, dp[t].begin()+b+1, 0L)%MOD);
}

/*
    
*/