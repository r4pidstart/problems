// https://www.acmicpc.net/problem/1284
// 2022-05-27 02:17:39 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    while(n)
    {
        int ans=1;
        while(n)
        {
            if(n%10 == 0) ans+=5;
            else if(n%10 == 1) ans+=3;
            else ans+=4;
            n/=10;
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
}

/*
    
*/