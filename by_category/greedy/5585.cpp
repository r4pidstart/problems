// https://www.acmicpc.net/problem/5585
// 2021-09-23 02:49:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,ans=0; scanf("%d", &n);
    n=1000-n;
    while(n>=500) n-=500, ans++;
    while(n>=100) n-=100, ans++;
    while(n>=50) n-=50, ans++;
    while(n>=10) n-=10, ans++;
    while(n>=5) n-=5, ans++;
    while(n>=1) n-=1, ans++;
    printf("%d", ans);
}

/*
    
*/