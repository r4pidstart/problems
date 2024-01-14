// https://www.acmicpc.net/problem/31235
// 2024-01-14 21:30:15
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
    
    int ans=1, tmp=1, prev=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] < prev) tmp++;
        else prev=arr[i], tmp=1;
        ans=max(ans, tmp);
    }
    printf("%d", ans);    
}

/*
    
*/