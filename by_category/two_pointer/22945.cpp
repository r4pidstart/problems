// https://www.acmicpc.net/problem/22945
// 2023-04-25 13:17:03
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int lo=0, hi=n-1;
    long ans=0;
    while(lo<=hi)
    {
        ans=max(ans, 1L*min(arr[lo], arr[hi])*max(0, hi-lo-1));
        if(arr[lo] < arr[hi]) lo++;
        else hi--;
    }
    printf("%ld", ans);
}

/*
    
*/