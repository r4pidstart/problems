// https://www.acmicpc.net/problem/
// 2022-10-26 01:08:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,o,f, sx,sy, ex,ey;
        scanf("%d%d%d%d%d%d%d%d", &n, &m, &o, &f, &sx, &sy, &ex, &ey);
        vector<vector<int> > obstacles(n+1, vector<int>(m+1));
        for(int i=0; i<o; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            obstacles[a][b]=c;
        }

        queue<pair<int, pair<int,int> > > q;
        vector<vector<vector<int> > > visited(n+1, vector<vector<int> >(m+1, vector<int>(f+1)));
        q.push({f, {sx, sy}});
        visited[sx][sy][f]=1;

        int flag=0;
        const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(q.size())
        {
            int nx=q.front().second.first, ny=q.front().second.second, remain_pow=q.front().first;
            q.pop();
            
            if(nx==ex and ny==ey)
            {
                flag=1;
                break;
            }

            for(int w=0; w<4; w++)
            {
                int nextx=nx+way[w][0], nexty=ny+way[w][1];
                if(0<nextx and nextx<=n and 0<nexty and nexty<=m and remain_pow \
                    and obstacles[nextx][nexty]-obstacles[nx][ny] <= remain_pow and !visited[nextx][nexty][remain_pow-1])
                    q.push({remain_pow-1, {nextx, nexty}}), visited[nextx][nexty][remain_pow-1]=1;
            }
        }
        printf("%s\n", flag ? "잘했어!!":"인성 문제있어??");
    }
}

/*
    
*/