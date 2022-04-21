// https://www.acmicpc.net/problem/10986
// 2022-04-21 21:41:00 240ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    vector<long long> mod_sum(n+1), mod_cnt(m);
    mod_cnt[0]=1;
    for(int i=1; i<=n; i++)
        mod_sum[i]=(mod_sum[i-1]+arr[i-1])%m, mod_cnt[mod_sum[i]]++;

    long long ans=0;
    for(int i=0; i<m; i++)
        ans+=mod_cnt[i] * (mod_cnt[i]-1) / 2;
    printf("%lld", ans);
}

/*
    
*/