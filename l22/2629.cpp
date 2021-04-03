// https://www.acmicpc.net/problem/2629
// 2021-04-03 23:43:40 0ms
#include<iostream>
using namespace std;

int memo[31][15001]={};
int weigh[31]={};

int abs(int target)
{
    if(target<0)
        return (target*-1);
    else
        return target;
}

int dp(int index, int sum, int marble_q)
{
    if(index>marble_q)
        return 0;
    if(memo[index][sum]==1)
        return 0;
    
    memo[index][sum]=1;

    dp(index+1, sum+weigh[index], marble_q);
    dp(index+1, sum, marble_q);
    dp(index+1, abs(sum-weigh[index]), marble_q);

    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &weigh[i]);
    dp(0,0,n);
    
    int t; scanf("%d", &t);
    int target[t];
    for(int i=0; i<t; i++)
        scanf("%d", &target[i]);
    
    for(int i=0; i<t; i++)
        if(target[i]>15000)
            printf("N ");
        else
            printf("%c ", memo[n][target[i]] ? 'Y':'N');
}