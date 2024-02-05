// https://www.acmicpc.net/problem/9764
// 2024-02-06 01:49:20
#include"bits/stdc++.h"
using namespace std;

int dp(int now, int used)
{
    static vector<vector<int> > memo(2001, vector<int>(2001, -1));
    if(now==0)
        return 1;
    if(memo[now][used] != -1)
        return memo[now][used];
    
    int ret=0;
    for(int i=used+1; i<=now; i++)
        ret=(ret+dp(now-i, i))%100999;

    return memo[now][used]=ret;
}

int main(void)
{
    int t; scanf("%d", &t);

    while(t--)
    {
        int a; scanf("%d", &a);
        printf("%d\n", dp(a, 0));
    }
}

/*
    
*/