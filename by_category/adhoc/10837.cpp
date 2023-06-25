// https://www.acmicpc.net/problem/10837
// 2023-06-25 10:37:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int k,t; scanf("%d%d", &k, &t);
    while(t--)
    {
        int a,b; scanf("%d%d", &a, &b);
        int remain=k-max(a,b);
        if(a>b)
            printf("%d\n", (a-b)-remain<=2);
        else if(a<b)
            printf("%d\n", (b-a)-remain<=1);
        else
            printf("1\n");
    }
}

/*
    
*/