// https://www.acmicpc.net/problem/17944
// 2021-10-30 23:30:56 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,t; scanf("%d%d", &n,&t);
    int remain=t;
    while(remain >= (4*n-2)) remain-=(4*n-2);

    if(remain <= 2*n)
        printf("%d", remain);
    else 
        printf("%d", 4*n-remain);
}

/*
    
*/