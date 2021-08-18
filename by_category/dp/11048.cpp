// https://www.acmicpc.net/problem/11048
// 2021-08-19 01:55:16 124ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m; scanf("%d%d", &n,&m);
	const int move[3][2]={{1,0}, {1,1}, {0,1}};
	vector<vector<int> > field(n,vector<int>(m,0)), dp(n,vector<int>(m,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &field[i][j]);

	dp[0][0]=field[0][0];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			for(int w=0; w<3; w++)
			{
				int nx=i+move[w][0], ny=j+move[w][1];
				if(!(nx<n && ny<m)) continue;
				dp[nx][ny]=max(dp[nx][ny], dp[i][j]+field[nx][ny]);
			}

	printf("%d", dp[n-1][m-1]);
}

/*

*/