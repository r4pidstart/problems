// https://www.acmicpc.net/problem/1484
// 2022-09-13 03:58:56 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    int prev=1, cnt=0;
    for(int i=1; i<50002; i++)
    {
        while(i*i - prev*prev > n) prev++;
        if(i*i - prev*prev == n) cnt++, printf("%d\n", i);
    }
    if(!cnt) printf("-1")
}

/*
    
*/