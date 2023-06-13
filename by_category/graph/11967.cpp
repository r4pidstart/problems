// https://www.acmicpc.net/problem/11967
// 2023-06-14 03:53:29
#include"bits/stdc++.h"
using namespace std;

int turn_on_switch(int x, int y, queue<pair<int,int> >& q,
     map<pair<int,int>, vector<pair<int,int> > >& graph, 
     vector<vector<int> >& waiting, vector<vector<int> >& visited, vector<vector<int> >& is_light_on)
{
    for(auto& [a,b] : graph[{x,y}])
        {
            is_light_on[a][b]=1;
            if(waiting[a][b])
            {
                q.push({a, b});
                turn_on_switch(a, b, q, graph, waiting, visited, is_light_on);
            }
        }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    map<pair<int,int>, vector<pair<int,int> > > graph;
    for(int i=0; i<m; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
        graph[{a,b}].push_back({c,d});
    }

    vector<vector<int> > visited(n+1, vector<int>(n+1));
    vector<vector<int> > is_light_on=visited, waiting=visited;
    queue<pair<int,int> > q;

    q.push({1,1});
    visited[1][1]=1;
    turn_on_switch(1, 1, q, graph, waiting, visited, is_light_on);
    is_light_on[1][1]=1;

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x,y]=q.front();
        q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<nx and nx<=n and 0<ny and ny<=n and !visited[nx][ny])
            {
                visited[nx][ny]=1;
                if(is_light_on[nx][ny])
                {
                    q.push({nx, ny});
                    turn_on_switch(nx, ny, q, graph, waiting, visited, is_light_on);
                }
                else
                    waiting[nx][ny]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
        cnt+=accumulate(is_light_on[i].begin(), is_light_on[i].end(), 0);
    printf("%d", cnt);
}

/*
    
*/