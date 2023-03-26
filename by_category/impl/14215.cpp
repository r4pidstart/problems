// https://www.acmicpc.net/problem/14215
// 2023-03-27 02:55:47
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int arr[3]; scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
    sort(arr, arr+3);
    int ans=0;
    for(int i=1; i<=arr[0]; i++)
        for(int j=i; j<=arr[1]; j++)
            for(int k=j; k<=arr[2]; k++)
                if(i+j > k) ans=max(ans, i+j+k);
    printf("%d", ans);
}

/*
    
*/