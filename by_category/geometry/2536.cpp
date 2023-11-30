// https://www.acmicpc.net/problem/2536
// 2023-11-29 03:33:18
#include"bits/stdc++.h"
using namespace std;

struct intersect
{
    static inline double ccw(pair<long,long> a, pair<long,long> b, pair<long,long> c)
    {
        return (a.first*b.second)+(b.first*c.second)+(c.first*a.second)-(b.first*a.second)-(c.first*b.second)-(a.first*c.second);
    }

    static int check(pair<long,long> a, pair<long,long> b, pair<long,long> c, pair<long,long> d)
    {
        double one=ccw(a,b,c)*ccw(a,b,d), two=ccw(c,d,a)*ccw(c,d,b);
        if(one <= 0 && two <= 0)
        {
            if(one==0 && two==0) // 일직선인경우
            {
                if(a > b) swap(a,b);
                if(c > d) swap(c,d);
                if(c<=b && a<=d) return 1;
            }
            else return 1;
        }
        return 0;
    }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int k; scanf("%d", &k);

    vector<tuple<int,int,int,int> > edge(k+2);
    for(int i=0; i<k; i++)
    {
        int a,b,c,d,e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        edge[a]={b,c,d,e};
    }
    // edge[0] -> start, edge[k+1] -> end
    int sx, sy, ex, ey; scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    edge[0]={sx, sy, sx, sy}, edge[k+1]={ex, ey, ex, ey};
    
    vector<vector<int> > graph(k+2);
    for(int i=0; i<k+2; i++)
        for(int j=0; j<i; j++)
        {
            auto [ax, ay, bx, by]=edge[i];
            auto [cx, cy, dx, dy]=edge[j];

            if(intersect::check({ax, ay}, {bx, by}, {cx, cy}, {dx, dy}))
                graph[i].push_back(j), graph[j].push_back(i);
        }
    
    queue<int> q;
    vector<int> dist(k+2, -1);
    q.push(0);
    while(q.size())
    {
        int now=q.front();
        q.pop();

        for(int next : graph[now])
            if(dist[next] == -1)
                dist[next]=dist[now]+1, q.push(next);
    }
    printf("%d\n", dist[k+1]);
}

/*
    
*/