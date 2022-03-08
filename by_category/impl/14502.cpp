// https://www.acmicpc.net/problem/14502
// 2022-03-08 20:23:32 396ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    queue<pair<int,int> > q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);

    int ans=0;
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};

    for(int a=0; a<n; a++)
        for(int b=0; b<m; b++)
            for(int c=0; c<n; c++)
                for(int d=0; d<m; d++)
                    for(int e=0; e<n; e++)
                        for(int f=0; f<m; f++)
                        {
                            if(table[a][b] or table[c][d] or table[e][f] or make_pair(a,b)==make_pair(c,d) or make_pair(a,b)==make_pair(e,f) or make_pair(c,d)==make_pair(e,f)) continue;
                            table[a][b]=table[c][d]=table[e][f]=1;
                            
                            queue<pair<int,int> > q;
                            for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                                    if(table[i][j]==2)
                                        q.push({i,j});
                            vector<vector<int> > tmptable(table);
                            vector<vector<int> > visited(n, vector<int>(m, 0));
                            while(!q.empty())
                            {
                                auto [x,y]=q.front(); q.pop();
                                if(visited[x][y]) continue;
                                visited[x][y]=1;

                                for(int i=0; i<4; i++)
                                {
                                    int nx=x+mov[i][0], ny=y+mov[i][1];
                                    if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and !tmptable[nx][ny])
                                    {
                                        tmptable[nx][ny]=2;
                                        q.push({nx,ny});
                                    }
                                }
                            }

                            int tmp=0;
                            for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                                    if(tmptable[i][j]==0)
                                        tmp++;
                            
                            ans=max(tmp, ans);
                        
                            table[a][b]=table[c][d]=table[e][f]=0;
                        }
    printf("%d", ans);
}

/*
    
*/