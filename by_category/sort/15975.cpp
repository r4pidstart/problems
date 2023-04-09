// https://www.acmicpc.net/problem/15975
// 2023-04-09 09:37:09
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > arr(n+1);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[b].push_back(a);
    }

    for(int i=0; i<=n; i++)
        sort(arr[i].begin(), arr[i].end());

    long ans=0;
    for(auto it : arr)
    {
        if(it.size()<2) continue;
        for(int i=0; i<it.size(); i++)
        {
            int tmp=INT32_MAX;
            if(i!=0) tmp=min(tmp, it[i]-it[i-1]);
            if(i!=it.size()-1) tmp=min(tmp, it[i+1]-it[i]);
            ans+=tmp;
        }
    }
    printf("%ld\n", ans);
}

/*
    
*/