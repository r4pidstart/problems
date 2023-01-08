// https://www.acmicpc.net/problem/13974
// 2023-01-08 10:06:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		vector<int> psum(n+1);
		for(int i=1; i<=n; i++)
			psum[i]=psum[i-1]+arr[i-1];
		
		vector<vector<int> > dp(n+2, vector<int>(n+2)), knuth(n+2, vector<int>(n+2));
		for(int i=1; i<=n; i++)
			knuth[i][i]=i;
		
		for(int len=1; len<=n; len++)
			for(int i=1; i<=n-len; i++)
			{
				int j=i+len;
				dp[i][j]=1e9;
				for(int k=knuth[i][j-1]; k<=knuth[i+1][j]; k++)
				{
					if(dp[i][j] > dp[i][k]+dp[k+1][j]+psum[j]-psum[i-1])
					{
						knuth[i][j]=k;
						dp[i][j]=dp[i][k]+dp[k+1][j]+psum[j]-psum[i-1];
					}
				}
			}
		printf("%d\n", dp[1][n]);
	}
}

/*
	
*/