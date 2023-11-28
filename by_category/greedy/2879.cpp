// https://www.acmicpc.net/problem/2879
// 2023-11-28 01:37:32
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
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[i]=a-arr[i];
    }

    int ans=0, tmp=0;
    for(int i=0; i<n; i++)
    {
        if(tmp*arr[i] <= 0)
        {
            ans+=abs(tmp);
            tmp=0;
        }
        if(arr[i] < 0)
        {
            if(arr[i] > tmp) ans+=abs(tmp-arr[i]);
        }
        else
        {
            if(arr[i] < tmp) ans+=abs(tmp-arr[i]);
        } 
        tmp=arr[i];
    }
    printf("%d", ans+abs(tmp));
}

/*

*/