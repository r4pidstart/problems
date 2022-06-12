// https://www.acmicpc.net/problem/1743
// 2022-06-12 15:52:55 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > table(n, vector<int>(m));

    queue<pair<pair<int,int>, int> > q;
    vector<vector<int> > visited(n, vector<int>(m));
    
    int ans=0;  
    const array<pair<int, int>, 4> way4={make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
    for(int i=0; i<k; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        table[a-1][b-1]=1;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j])
                q.push({{i, j}, 1});
            int cnt=0;
            while(q.size())
            {
                auto now=q.front().first; 
                int trash=q.front().second;
                q.pop();
                
                if(visited[now.first][now.second]) continue;
                else visited[now.first][now.second]++, cnt++;


                for(auto it : way4)
                {
                    int nx=now.first+it.first, ny=now.second+it.second;
                    if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny])
                        q.push({{nx,ny}, cnt+1});
                }
            }
            ans=max(ans, cnt);
        }
    printf("%d", ans);
}

/*
    
*/