// https://www.acmicpc.net/problem/5557
// 2021-08-22 23:00:24 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> > dp(101,vector<long long>(21, 0));
vector<int> num(101);

int main(void)
{
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i+1]);
    dp[1][num[1]]=1;

    for(int i=2; i<n; i++)
        for(int j=0; j<=20; j++)
        {
            if(j+num[i]<=20) dp[i][j+num[i]]+=dp[i-1][j];
            if(0<=j-num[i]) dp[i][j-num[i]]+=dp[i-1][j];
        }

    printf("%lld", dp[n-1][num[n]]);
}

/*

*/