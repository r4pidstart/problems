// https://www.acmicpc.net/problem/1890
// 2021-08-19 03:06:01 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<vector<long long> > field(n, vector<long long>(n,0)), dp(n, vector<long long>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &field[i][j]);

	dp[0][0]=1;
	const int move[2][2]={{0,1}, {1,0}};
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			for(int w=0; w<2; w++)
			{
				int nx=i+move[w][0]*field[i][j], ny=j+move[w][1]*field[i][j];
				if(!(nx<n && ny<n) || (i==n-1 && j==n-1)) continue;
				dp[nx][ny]+=dp[i][j];
			}
		}
	printf("%lld", dp[n-1][n-1]);
}

/*

*/