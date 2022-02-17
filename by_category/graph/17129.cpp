// https://www.acmicpc.net/problem/17129
// 2022-02-17 16:17:16 616ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL)->sync_with_stdio(false);
	int n,m; cin >> n >> m;
	vector<vector<int> > table(n, vector<int>(m));
	pair<int, int> start;
	for(int i=0; i<n; i++)
	{
		string s; cin >> s;
		for(int j=0; j<m; j++)
		{
			table[i][j]=s[j] - '0';
			if(table[i][j] == 2)
				start={i, j};
		}
	}
	queue<pair<pair<int,int>, int> > q;
	const int mov[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
	vector<vector<int> > visited(n, vector<int>(m,0));
	q.push({start, 0});
	while(!q.empty())
	{
		pair<int,int> now=q.front().first; int dist=q.front().second; q.pop();
		if(visited[now.first][now.second]) continue;
		visited[now.first][now.second] = 1;

		if(table[now.first][now.second] > 2)
		{
			cout << "TAK\n" << dist;
			return 0;
		}

		for(int mv=0; mv<4; mv++)
		{
				int nx=now.first+mov[mv][0], ny=now.second+mov[mv][1];
				if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and table[nx][ny] != 1)
					q.push({{nx, ny}, dist+1});
		}
	}
	cout << "NIE";
}
