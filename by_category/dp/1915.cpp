// https://www.acmicpc.net/problem/1915
// 2021-08-21 21:05:47 88ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m; scanf("%d%d", &n,&m);
	vector<vector<int> > field(n+1, vector<int>(m+1, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%1d", &field[i+1][j+1]);
	
	int ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			if(field[i][j])
				field[i][j]=min({field[i-1][j-1], field[i-1][j], field[i][j-1]})+1;
			ans=max(ans, field[i][j]);
		}

	printf("%d", ans*ans);
}

/*

*/