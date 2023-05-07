// https://www.acmicpc.net/problem/16895
// 2023-05-07 16:08:42
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
    
    int ret=0;
    for(int i=0; i<n; i++)
        ret^=arr[i];
    
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<arr[i]; j++)
            if((ret ^ arr[i] ^ j) == 0) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/