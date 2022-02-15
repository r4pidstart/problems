// https://www.acmicpc.net/problem/16234
// 2022-02-15 23:52:14 1220ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,l,r; scanf("%d%d%d", &n, &l, &r);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    int ans=0;
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    while(true)
    {
        int flag=0;
        vector<vector<int> > visited(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                int sum=0;
                queue<pair<int,int> > change;
                queue<pair<int,int> > q;
                q.push({i,j});
                while(!q.empty())
                {
                    pair<int,int> now=q.front(); q.pop();
                    if(visited[now.first][now.second]) continue;
                    change.push({now.first, now.second});
                    visited[now.first][now.second]=1;
                    sum+=table[now.first][now.second];

                    for(int k=0; k<4; k++)
                    {
                        int nextx=now.first+mov[k][0], nexty=now.second+mov[k][1];
                        if(0<=nextx and nextx<n and 0<=nexty and nexty<n)
                        {
                            int dif=abs(table[now.first][now.second] - table[nextx][nexty]);
                            if(l<=dif and dif<=r)
                                q.push({nextx, nexty});
                        }
                    }
                }
                if(change.size() > 1)
                {
                    flag++;
                    int res=sum/change.size();
                    while(!change.empty())
                    {
                        pair<int,int> now=change.front(); change.pop();
                        table[now.first][now.second]=res;
                    }
                }
            }
        if(flag) ans++;
        else break;
    }
    printf("%d", ans);
}

/*
    
*/