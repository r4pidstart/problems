// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,int> > arr;
vector<pair<long long, vector<int> > > dp;
pair<long long, vector<int> > solution(int now, int lim)
{
    if(now==0) return {0, vector<int>()};
    if(dp[now].first != -1) return dp[now];

    int accumulated_dist=0;
    pair<long long, vector<int> > ret={LLONG_MAX/2, vector<int>()};
    for(int i=now; i>0; i--)
    {
        accumulated_dist+=arr[i].first;
        if(accumulated_dist > lim) break;
        if(ret.first > solution(i-1, lim).first + arr[now].second)
        {
            ret=solution(i-1, lim);
            ret.first+=arr[now].second;
        }
    }
    ret.second.push_back(now);
    return dp[now]=ret;
}

int main(void)
{
    int max_dist,n; scanf("%d%d", &max_dist, &n);
    // 이전 정비소까지의 거리, 정비시간
    arr.assign(n+2, {});
    dp.assign(n+2, {-1, vector<int>()});
    for(int i=1; i<=n+1; i++)
        scanf("%d", &arr[i].first);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i].second);

    pair<long long, vector<int> > ans=solution(n+1, max_dist);
    printf("%lld\n%d\n", ans.first, ans.second.size()-1);
    for(int i=0; i<ans.second.size()-1; i++)
        printf("%d ", ans.second[i]);
}

/*
    
*/