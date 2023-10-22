// https://www.acmicpc.net/problem/24499
// 2023-10-22 11:18:26
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
    
    arr.insert(arr.end(), arr.begin(), arr.end());

    int tmp=0, ans=0;
    for(int i=0; i<k; i++)
        tmp+=arr[i];
    ans=tmp;
    for(int i=k; i<2*n; i++)
    {
        tmp-=arr[i-k], tmp+=arr[i];
        ans=max(ans, tmp);
    }
    printf("%d", ans);
}

/*
    
*/