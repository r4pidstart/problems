// https://www.acmicpc.net/problem/22862
// 2023-11-29 19:29:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int lo=0, hi=0, cnt=0, ans=0;
    while(hi < n)
    {
        if(cnt > k)
            cnt-=arr[lo++]&1;
        else
            cnt+=arr[hi++]&1;
        if(cnt <= k) ans=max(ans, hi-lo-cnt);
    }
    printf("%d", ans);
}

/*
    
*/