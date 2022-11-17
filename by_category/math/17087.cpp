// https://www.acmicpc.net/problem/17087
// 2022-11-06 21:47:00
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,s; scanf("%d%d", &n,&s);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i]-=s;
    }
    int ans=arr[0];
    for(int i=1; i<n; i++)
        ans=gcd(ans, arr[i]);
    printf("%d", ans);
}

/*
    
*/