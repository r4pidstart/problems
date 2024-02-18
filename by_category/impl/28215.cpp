// https://www.acmicpc.net/problem/28215
// 2024-02-18 11:59:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    vector<int> combi(n, 1);
    fill(combi.begin(), combi.begin()+(n-k), 0);
    
    int ans=INT32_MAX;
    do
    {
        int mx=0;
        for(int i=0; i<n; i++)
            if(!combi[i])
            {
                int mi=INT32_MAX;
                for(int j=0; j<n; j++)
                    if(combi[j])
                        mi=min(mi, abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second));
                mx=max(mi, mx);
            }
        ans=min(ans, mx);
    } while (next_permutation(combi.begin(), combi.end()));
    printf("%d", ans);
}

/*
    
*/