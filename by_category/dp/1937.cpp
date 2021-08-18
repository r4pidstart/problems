// https://www.acmicpc.net/problem/1937
// 2021-08-19 03:51:14 56ms
#include<bits/stdc++.h>
using namespace std;

const int way[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
vector<vector<int> > field, dp;
int n;

int dfs(int i, int j)
{
	if(dp[i][j]) return dp[i][j];

	int ret=0;

	for(int w=0; w<4; w++)
	{
		int nx=i+way[w][0], ny=j+way[w][1];
		if(!(nx<n && ny<n && 0<=nx && 0<=ny)) continue;

		if(field[i][j] < field[nx][ny])
			ret=max(ret, dfs(nx,ny));
	}

	return dp[i][j]=ret+1;
}

int main(void)
{
	scanf("%d", &n);
	field.assign(n, vector<int>(n,0));
	dp.assign(n, vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &field[i][j]);

	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			ans=max(ans, dfs(i,j));

	printf("%d", ans);
}

/*

*/