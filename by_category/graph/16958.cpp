// https://www.acmicpc.net/problem/16958
// 2023-06-15 00:10:15
#include"bits/stdc++.h"
using namespace std;

inline int get_dist(pair<int,int>& a, pair<int,int>& b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,t; scanf("%d%d", &n, &t);
    vector<vector<int> > graph(n+1);
    vector<pair<int,int> > arr(n+1);
    vector<int> special(n+1);
    for(int i=1; i<=n; i++)
    {
        int s,a,b; scanf("%d%d%d", &s, &a, &b);
        arr[i]={a,b};
        special[i]=s;
    }
    
    vector<vector<int> > dist(n+1, vector<int>(n+1, INT32_MAX/2));

    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            dist[i][j]=dist[j][i]=get_dist(arr[i], arr[j]);
            if(special[i] and special[j])
                dist[i][j]=dist[j][i]=min(dist[i][j], t);
        }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }

    int m; scanf("%d", &m);
    while(m--)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
}

/*
    
*/