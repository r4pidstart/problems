// https://www.acmicpc.net/problem/2878
// 2023-10-26 04:22:02
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int m,n; scanf("%d%d", &m, &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    unsigned long ans=0;
    long remain=reduce(arr.begin(), arr.end(), 0UL)-m;
    for(int i=0; i<n; i++)
    {
        long tmp=min(arr[i]*1L, remain/(n-i));
        ans+=tmp*tmp;
        remain-=tmp;
    }

    printf("%lu", ans);
}

/*
    
*/