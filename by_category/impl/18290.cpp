// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int dfs(int x, int y, int k, vector<vector<int> >& table, vector<vector<int> >& used)
{
	if(k==0)
		return 0;
	if (y==table[0].size())
		return INT32_MIN/2;
	if(x==table.size())
		return dfs(0, y+1, k, table, used);
	
	int ret=dfs(x+1, y, k, table, used);

	if(!used[x][y])
	{
		const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
		for(int i=0; i<4; i++)
			if(0<=x+way[i][0] and x+way[i][0]<table.size() and 0<=y+way[i][1] and y+way[i][1]<table[0].size())
				used[x+way[i][0]][y+way[i][1]]++;
		
		ret=max(ret, dfs(x+1, y, k-1, table, used)+table[x][y]);

		for(int i=0; i<4; i++)
			if(0<=x+way[i][0] and x+way[i][0]<table.size() and 0<=y+way[i][1] and y+way[i][1]<table[0].size())
				used[x+way[i][0]][y+way[i][1]]--;
	}
	
	return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m,k; scanf("%d%d%d", &n, &m, &k);
	vector<vector<int> > table(n, vector<int>(m)), used(n, vector<int>(m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &table[i][j]);

	printf("%d", dfs(0, 0, k, table, used));
}

/*
	
*/