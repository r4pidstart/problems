// https://www.acmicpc.net/problem/15487
// 2024-02-17 05:40:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    // from first
    vector<int> dpf(n+1);
    {
        dpf[0]=INT32_MIN/2;
        int mn=INT32_MAX/2;
        for(int i=1; i<=n; i++)
        {
            dpf[i]=max(dpf[i-1], arr[i-1]-mn);
            mn=min(mn, arr[i-1]);
        }
    }

    // from last
    vector<int> dpl(n+1);
    {
        dpl[n]=INT32_MIN/2;
        int mx=INT32_MIN/2;
        for(int i=n-1; i>=0; i--)
        {
            dpl[i]=max(dpl[i+1], mx-arr[i]);
            mx=max(mx, arr[i]);
        }
    }

    #ifdef LOCAL
        for(int i=0; i<=n; i++)
            printf("%d ", dpf[i]);
        printf("\n");
        for(int i=0; i<=n; i++)
            printf("%d ", dpl[i]);
        printf("\n");
    #endif

    int ans=INT32_MIN/2;
    for(int i=0; i<n; i++)
        ans=max(ans, dpf[i]+dpl[i]);
    printf("%d", ans);
}

/*
    
*/