// https://www.acmicpc.net/problem/2836
// 2021-08-08 02:47:20 172ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<pair<int,int> > route;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(a>b)
            route.push_back({b,a});
    }

    long long ans=m;
    sort(route.begin(), route.end());

    int tstart=route[0].first, tend=route[0].second;
    for(auto& it : route)
    {
        if(it.first <= tend)
            tend=max(tend, it.second);
        else
            ans+=2*(tend-tstart), tstart=it.first, tend=it.second;
    }
    ans+=2*(tend-tstart);
    printf("%lld", ans);
}

/*

*/