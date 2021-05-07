
#include<bits/stdc++.h>
using namespace std;

typedef struct _dp
{
    int dist, p1, p2; // 경찰차 이전 위치
}_dp;

int n,w;
_dp ans={INT32_MAX,0,0};
pair<int,int> event[1002];
vector<vector<_dp> > dp(1001, vector<_dp>(1001, {INT32_MAX, 0,0}));
stack<int> route;

int get_dist(int a, int b)
{
    return abs(event[a].first-event[b].first) + abs(event[a].second-event[b].second);
}

void dfs(int one, int two)
{
    int modtwo=two%1001;
    if(one == w || two == w)
    {
        if(ans.dist > dp[one][modtwo].dist)
            ans={dp[one][modtwo].dist, one, modtwo};
        return;
    }
    int next=max(one,modtwo)+1;
    int dist_1=dp[one][modtwo].dist + get_dist(one,next),
        dist_2=dp[one][modtwo].dist + get_dist(two,next);
    if(dist_1 < dp[next][modtwo].dist)
    {
        dp[next][modtwo]={dist_1, one, modtwo};
        dfs(next, two);
    }
    if(dist_2 < dp[one][next].dist)
    {
        dp[one][next]={dist_2, one, modtwo};
        dfs(one, next);
    }
}

void get_route(_dp now)
{
    if(now.p1==0 && now.p2==0)
        return;
    if(now.p1 > dp[now.p1][now.p2].p1)
        route.push(1);
    else
        route.push(2);
    get_route(dp[now.p1][now.p2]);
}

int main(void)
{
    scanf("%d%d", &n, &w);
    event[0]={1,1}, event[1001]={n,n}, dp[0][0].dist=0;
    for(int i=1; i<=w; i++)
        scanf("%d%d", &event[i].first, &event[i].second);
    dfs(0,1001);
    get_route(ans);
    printf("%d\n", ans.dist);
    while(!route.empty())
    {
        printf("%d\n", route.top());
        route.pop();
    }
}