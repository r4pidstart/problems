// https://www.acmicpc.net/problem/9659
// 2022-09-28 01:57:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long n; scanf("%ld", &n);
    // vector<int> dp(10000);
    // dp[1]=1;
    // printf("1");
    // for(int i=2; i<=n; i++)
    // {
    //     int flag=0;
    //     for(int j=1; i-j>=0; j*=4)
    //     {
    //         if(!dp[i-j]) flag++;
    //     }
    //     if(flag) dp[i]=1;
    //     else dp[i]=0;
    //     printf("%d", dp[i]);
    // }
    n--;
    vector<int> pat{1,0,1,1,0};
    printf("%s", pat[n%5] ? "SK":"CY");
}

/*
    
*/