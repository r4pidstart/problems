// https://www.acmicpc.net/problem/2010
// 2022-03-22 21:42:19 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int ans=1;
    while(n--)
    {
        int a; scanf("%d", &a);
        ans+=(a-1);
    }
    printf("%d", ans);
}

/*
    
*/