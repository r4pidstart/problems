// https://www.acmicpc.net/problem/5063
// 2022-03-25 00:03:32 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        if(a > b-c) printf("do not advertise\n");
        else if(a == b-c) printf("does not matter\n");
        else printf("advertise\n");
    }
}

/*
    
*/