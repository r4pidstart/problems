// https://www.acmicpc.net/problem/9781
// 2023-02-02 13:20:04
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<vector<char> > table(n, vector<char>(m)), visited(n, vector<char>(m));
	queue<tuple<int, int, int> > q;
	int ex, ey;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			scanf(" %c", &table[i][j]);
			if(table[i][j] == 'K') q.push({0, i, j});
			if(table[i][j] == 'X') ex=i, ey=j;
		}
	
	const int way[8][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
	while(q.size())
	{
		auto [cnt, x, y]=q.front();
		q.pop();

		if(x==ex and y==ey)
			return !printf("%d", cnt);

		for(int i=0; i<8; i++)
		{
			int nx=x+way[i][0], ny=y+way[i][1];
			if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and table[nx][ny] != '#')
				q.push({cnt+1, nx, ny}), visited[nx][ny]=1;
		}
	}
	printf("-1");

}

/*
	
*/