// https://www.acmicpc.net/problem/14881
// 2023-08-03 00:42:19
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        if(a<c and b<c) printf("NO\n");
        else printf(c%gcd(a,b) ? "NO\n":"YES\n");
    }
}

/*
    
*/