// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int dfs(int x, int y, vector<vector<int> >& table, vector<vector<int> >& visited)
{
	const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

	visited[x][y]=1;
	for(int w=0; w<4; w++)
	{
		int nx=(x+way[w][0]+table.size())%table.size();
		int ny=(y+way[w][1]+table[0].size())%table[0].size();

		if(!visited[nx][ny] and table[nx][ny]==0)
			dfs(nx, ny, table, visited);
	}
	return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<vector<int> > table(n, vector<int>(m));
	vector<vector<int> > visited(n, vector<int>(m));

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &table[i][j]);
	
	int cnt=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(!visited[i][j] and table[i][j]==0)
			{
				dfs(i, j, table, visited);
				cnt++;
			}
	printf("%d", cnt);
}

/*
	
*/