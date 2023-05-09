// https://www.acmicpc.net/problem/2374
// 2023-05-06 22:37:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans=0;
    int _max=0, _min=INT32_MAX, prev=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        _max=max(a, _max);
        if(i) ans+=max(0, a-prev);
        prev=a;
    }
    printf("%ld", _max-prev + ans);
}

/*
    
*/