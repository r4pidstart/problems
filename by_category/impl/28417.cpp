// https://www.acmicpc.net/problem/28417
// 2023-08-04 04:02:39
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int ans=0;
    while(n--)
    {
        int a,b; scanf("%d%d", &a, &b);
        vector<int> arr(5);
        for(int i=0; i<5; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end(), greater<>());
        ans=max(ans, max(a,b)+arr[0]+arr[1]);
    }
    printf("%d", ans);
}

/*
    
*/