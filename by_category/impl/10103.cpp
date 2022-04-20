// https://www.acmicpc.net/problem/10103
// 2022-04-20 22:18:52
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int a=100, b=100;
    while(n--)
    {
        int c,d; scanf("%d%d", &c, &d);
        if(c>d)
            b-=c;
        else if(c<d)
            a-=d;
    }
    printf("%d %d", a, b);
}

/*
    
*/