// https://www.acmicpc.net/problem/3034
// 2022-05-17 03:53:05 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,w,h; scanf("%d%d%d", &n, &w, &h);
    while(n--)
    {
        int a; scanf("%d", &a);
        if(a*a <= w*w + h*h) printf("DA\n");
        else printf("NE\n");
    }
}

/*
    
*/