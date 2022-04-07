// https://www.acmicpc.net/problem/9325
// 2022-04-08 01:29:22 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int a; scanf("%d", &a);
        int n; scanf("%d", &n);
        while(n--)
        {
            int b,c; scanf("%d%d", &b, &c);
            a+=b*c;
        }
        printf("%d\n", a);
    }
}

/*
    
*/