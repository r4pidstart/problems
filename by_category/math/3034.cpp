// https://www.acmicpc.net/problem/3034
// 
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