// https://www.acmicpc.net/problem/1102
// 2021-07-17 00:49:04 40ms
#include<bits/stdc++.h>
using namespace std;

int n,p;
vector<vector<int> > cost;
vector<int> dp;
int ans=INT32_MAX;

int main(void)
{
    scanf("%d", &n);
    cost.assign(n, vector<int>(n, INT32_MAX/2));
    dp.assign((1<<n)+1, INT32_MAX/2);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &cost[i][j]);
    
    int init_mask=0;
    for(int i=0; i<n; i++)
    {
        char c; scanf(" \n%c", &c);
        if(c=='Y')
            init_mask=init_mask|(1<<i);
    }

    dp[init_mask]=0;
    scanf("%d", &p);
    bitset<16> i_b=init_mask;
    if(i_b.count() >= p) // 이미 켜져있으면
    {
        printf("0");
        return 0;
    }
    if(i_b.count() == 0) // 켤 수 없으면
    {
        printf("-1");
        return 0;
    }

    for(int mask=init_mask; mask<(1<<n); mask++)
    {
        bitset<16> b=mask;
        if(b.count() >= p)
        {
            ans=min(ans, dp[mask]);
            continue;
        }
        vector<int> cand(n, INT32_MAX);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(b[i])
                    cand[j]=min(cand[j], cost[i][j]);
        
        for(int i=0; i<n; i++)
        {
            if(b[i]) continue;
            dp[mask|(1<<i)]=min(dp[mask|(1<<i)], dp[mask]+cand[i]);
        }
    }
    printf("%d", ans);
}

/*

*/
