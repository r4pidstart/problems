// https://www.acmicpc.net/problem/10942
// 2021-04-02 23:04:50 316ms
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int memo[n+1][n+1]={}, arr[n+1]={};
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    for(int i=0; i<=n; i++)
        memo[i][i]=1;

    for(int i=1; i<n; i++)
    {
        if(arr[i]==arr[i+1])
            memo[i][i+1]=1;
    }
    for(int d=2; d<n; d++) // 공차
    {
        for(int i=1; i+d<=n; i++)
        {        
            if(memo[i+1][i+d-1]==1)
                if(arr[i]==arr[i+d])
                    memo[i][i+d]=1;
            // memo[i+1][i+d-1]가 팰린드롬일때 arr[i]==arr[i+d]이면 팰린드롬
        }
    }

    int m; scanf("%d", &m);
    while(m--)
    {
        int s,e;
        scanf("%d%d", &s, &e);
        printf("%d\n", memo[s][e]);
    }
}