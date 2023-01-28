// https://www.acmicpc.net/problem/27280
// 2023-01-29 03:55:40
#include"bits/stdc++.h"
using namespace std;

// long solution(int m, int n, vector<vector<pair<int, long> > >& dp_range)
// {
// 	static vector<vector<long> > memo(m+1, vector<long>(n+1, -1));

// 	if(m==0) return 0;
// 	if(n<0) return LLONG_MIN/4;

// 	if(memo[m][n] != -1)
// 		return memo[m][n];
	
// 	long ret=LLONG_MIN/4;
// 	for(int i=0; i<=n; i++)
// 		ret=max(ret, solution(m-1, i-1, dp_range)+dp_range[i][n].second);

// 	return memo[m][n]=ret;
// }

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<pair<int, long> > arr(n); // heigth, weight
	for(int i=0; i<n; i++)
		scanf("%d%ld", &arr[i].first, &arr[i].second);
		
	vector<vector<pair<int, long> > > dp_range(n, vector<pair<int, long> >(n));

	for(int i=0; i<n; i++)
		dp_range[i][i]=arr[i];

	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			if(dp_range[i][j-1].first > arr[j].first)
				dp_range[i][j]=dp_range[i][j-1];
			else if(dp_range[i][j-1].first == arr[j].first)
				dp_range[i][j]=dp_range[i][j-1], dp_range[i][j].second+=arr[j].second;
			else
				dp_range[i][j]=arr[j];
		}
		
	// printf("%ld", solution(m, n-1, dp_range));

	vector<vector<long> > dp(n+1, vector<long>(m+1));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			if(j==1) dp[i][j]=dp_range[0][i-1].second;
			else
			{
				for(int k=1; k<=i; k++)
					dp[i][j]=max(dp[i][j], dp[k-1][j-1]+dp_range[k-1][i-1].second);
			}
		}
	printf("%ld", dp[n][m]);
}

/*
		
*/