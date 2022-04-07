// https://www.acmicpc.net/problem/15969
// 2022-04-08 01:13:57 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int lo=INT32_MAX, hi=INT32_MIN;
    while(n--)
    {
        int a; scanf("%d", &a);
        lo=min(lo, a), hi=max(hi, a);
    }
    printf("%d", hi-lo);
}

/*
    
*/