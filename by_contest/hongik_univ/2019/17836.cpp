// https://www.acmicpc.net/problem/17836
// 2021-11-10 02:17:50 B
#include<bits/stdc++.h>
using namespace std;

const int way[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct node
{
	int dist, gram, x, y;
};

int main(void)
{
	int n,m,t; scanf("%d%d%d", &n,&m,&t);
	vector<vector<int> > table(n, vector<int>(m));
	vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(2,0)));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &table[i][j]);
	
	queue<node> q;
	q.push({0,0,0,0});
	int ans=-1;
	while(!q.empty())
	{
		auto now=q.front(); q.pop();
		if(visited[now.x][now.y][now.gram]) continue;
		visited[now.x][now.y][now.gram]++;
		if(now.x==n-1 and now.y==m-1)
		{
			ans=now.dist;
			break;
		}
		for(int i=0; i<4; i++)
		{
			int nx=now.x+way[i][0], ny=now.y+way[i][1];
			if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny][now.gram])
			{
				if(table[nx][ny]==1)
				{
					if(now.gram) q.push({now.dist+1, now.gram, nx, ny});
				}
				else if(table[nx][ny]==2)
					q.push({now.dist+1, 1, nx, ny});
				else
					q.push({now.dist+1, now.gram, nx, ny});
			}
		}
	}

	if(ans!=-1 and ans<=t) printf("%d", ans);
	else printf("Fail");
}

/*
	
*/