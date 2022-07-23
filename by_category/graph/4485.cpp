// https://www.acmicpc.net/problem/4485
// 2022-07-24 00:44:37 8ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, T=0; scanf("%d", &n);
    while(n)
    {
        vector<vector<int> > table(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &table[i][j]);
        
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<> > pq;
        vector<vector<int> > dist(n, vector<int>(n, INT32_MAX/2));
        pq.push({table[0][0], {0, 0}});
        dist[0][0]=table[0][0]; 
        
        const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(pq.size())
        {
            int cnt=pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
            pq.pop();

            if(dist[x][y] < cnt) continue;
            
            for(int w=0; w<4; w++)
            {
                int nx=x+way[w][0], ny=y+way[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<n)
                {
                    int next_dist=cnt+table[nx][ny];
                    if(dist[nx][ny] > next_dist)
                        pq.push({next_dist, {nx, ny}}), dist[nx][ny]=next_dist;
                }
            }
        }
        printf("Problem %d: %d\n", ++T, dist[n-1][n-1]);
        scanf("%d", &n);
    }
}

/*
    
*/