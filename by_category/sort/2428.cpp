// https://www.acmicpc.net/problem/2428
// 2023-06-11 02:15:15
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
    sort(arr.begin(), arr.end());
    
    long ans=0;
    for(int i=0; i<n; i++)
    {
        auto it=lower_bound(arr.begin(), arr.end(), arr[i]*0.9);
        ans+=distance(it, arr.begin()+i);
    }
    printf("%ld", ans);
}


