// https://www.acmicpc.net/problem/17240
// 2024-01-13 04:23:27
#include"bits/stdc++.h"
using namespace std;

int ans(int now, int mask, const vector<vector<int> >& arr)
{
    static vector<vector<int> > dp(arr.size()+1, vector<int>(1<<5, -1));
    if(mask==(1<<5)-1 or now==arr.size()) return 0;
    if(dp[now][mask] != -1) return dp[now][mask];
    
    int ret=0;
    for(int i=0; i<5; i++) // select this
        if(!(mask&(1<<i)))
            ret=max(ret, ans(now+1, mask|(1<<i), arr)+arr[now][i]);

    // or skip
    ret=max(ret, ans(now+1, mask, arr));
    return dp[now][mask]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > arr(n, vector<int>(5));
    for(int i=0; i<n; i++)
        for(int j=0; j<5; j++)
            scanf("%d", &arr[i][j]);
    
    printf("%d", ans(0, 0, arr));
}

/*
    
*/