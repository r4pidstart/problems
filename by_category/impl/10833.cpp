// https://www.acmicpc.net/problem/10833
// 2022-03-23 23:25:38 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int cnt=0;
    while(n--)
    {
        int a,b; scanf("%d%d", &a, &b);
        cnt+=b%a;
    }
    printf("%d", cnt);
}

/*
    
*/