// https://www.acmicpc.net/problem/25418
// 2024-02-18 03:53:30
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,k; scanf("%d%d", &a, &k);
    int cnt=0;
    while(k!=a)
    {
        if(k&1 or k/2<a) k--;
        else k/=2;
        cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/