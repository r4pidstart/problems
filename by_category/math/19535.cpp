// https://www.acmicpc.net/problem/
// 2024-02-01 02:59:07
#include"bits/stdc++.h"
using namespace std;

int get_parent(int now, int prev, const vector<vector<int> >& graph, vector<int>& parent)
{
    for(int next : graph[now])
        if(next != prev)
            parent[next]=now, get_parent(next, now, graph, parent);
    return 0;
}

long ncr(int n, int r)
{
    static vector<vector<long> > memo(300001, vector<long>(4, -1));

    if(n<r) return 0;
    else if(r==0) return 1;
    else if(n==0) return 1;
    if(memo[n][r] != -1) return memo[n][r];

    return memo[n][r]=ncr(n-1, r)+ncr(n-1, r-1);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> parent(n+1);
    get_parent(1, -1, graph, parent);
    long d_cnt=0, g_cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(graph[i].size()>1 and graph[parent[i]].size()>1)
            d_cnt+=(graph[i].size()-1)*(graph[parent[i]].size()-1);
        g_cnt+=ncr(graph[i].size(), 3);       
    }
    #ifdef LOCAL
        printf("%ld %ld\n", d_cnt, g_cnt);
    #endif
    if(d_cnt==g_cnt*3) printf("DUDUDUNGA");
    else if(d_cnt>g_cnt*3) printf("D");
    else printf("G");
}

/*
    
*/