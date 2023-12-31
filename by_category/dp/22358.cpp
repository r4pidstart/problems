// https://www.acmicpc.net/problem/22358   
// 2023-12-29 01:02:26  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k,s,t; scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<vector<long> > dp(graph.size(), vector<long>(k+1, -1));
    dp[s][0]=0;
    for(int j=0; j<=k; j++) // k
        for(int i=1; i<=n; i++) // now
        {
            int now=i, cnt=j;
            if(dp[now][cnt] != -1)
            {
                for(auto [next, cost] : graph[now])
                {
                    if(now > next)
                    {
                        if(cnt < k) dp[next][cnt+1]=max(dp[next][cnt+1], dp[now][cnt]);
                    }
                    else
                        dp[next][cnt]=max(dp[next][cnt], dp[now][cnt]+cost);
                }
            }
        }
    long res=*max_element(dp[t].begin(), dp[t].end());
    printf("%ld", res);
}

/*
    
*/