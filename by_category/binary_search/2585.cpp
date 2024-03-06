// https://www.acmicpc.net/problem/2585
// 2024-03-03 21:54:54
#include"bits/stdc++.h"
using namespace std;

inline int required_fuel(const pair<int,int>& a, const pair<int,int>& b)
{
    return ceil(sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))/10);
}

int decision(const vector<pair<int, int> >& arr, int mid, int k)
{
    // bfs
    queue<pair<int, int> > q;
    vector<int> visited(arr.size());
    
    q.push({0, -1});
    visited[0]=1;

    while(q.size())
    {
        auto [now, cnt]=q.front();
        q.pop();

        if(cnt > k)
            return 0;
        if(now==arr.size()-1)
            return 1;

        for(int i=0; i<arr.size(); i++)
        {
#ifdef LOCAL
            if(mid==(1e9)/2)
                printf("- %d->%d %d\n", now, i, required_fuel(arr[now], arr[i]));
#endif  
            if(!visited[i] and required_fuel(arr[now], arr[i])<=mid)
                q.push({i, cnt+1}), visited[i]=1;
        }
    }
    return 0;
}

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<pair<int,int> > arr(n+2);
    arr[0]={0, 0};
    for(int i=1; i<=n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    arr[n+1]={10000, 10000};

    int lo=0, hi=1e9, ans=hi;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(arr, mid, k))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/