// https://www.acmicpc.net/problem/13415
// 2024-05-01 23:30:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    multiset<int> mse(arr.begin()+1, arr.end());

    int k; scanf("%d", &k);
    vector<pair<int, int> > query(k);
    for(int i=0; i<k; i++)
        scanf("%d%d", &query[i].first, &query[i].second);
    
    reverse(query.begin(), query.end());

    int prev_max=0;
    vector<int> used(n+1, 0);
    for(int i=0; i<k; i++)
    {
        auto [a, b]=query[i];
        if(b > prev_max)
            prev_max=b, used[b]=-1;
        
        if(a > prev_max)
            prev_max=a, used[a]=1;
    }

    vector<int> ans(n+1);
    int prev_stat=0;
    for(int i=n; i>0; i--)
    {
        if(used[i])
            prev_stat=used[i];
        
        if(prev_stat==-1)
            used[i]=-1;
        else if(prev_stat==1)
            used[i]=1;

        if(used[i]==-1)
            ans[i]=*mse.begin(), mse.erase(mse.find(ans[i]));
        else if(used[i]==1)
            ans[i]=*prev(mse.end()), mse.erase(mse.find(ans[i]));
        else
            ans[i]=arr[i], mse.erase(mse.find(ans[i]));
    }

    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);
}

/*
    
*/