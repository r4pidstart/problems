// https://www.acmicpc.net/problem/5375
// 2021-09-03 01:58:38 40ms
#include<bits/stdc++.h>
using namespace std;

struct Store
{
    int quant, cost, ship;
    bool operator<(Store& a)
    { return cost<a.cost; }
};

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n,&m);
        vector<Store> store(m);
        vector<int> dp(n+1, INT32_MAX/2);
        dp[0]=0;
        for(int i=0; i<m; i++)
            scanf("%d%d%d", &store[i].quant, &store[i].cost, &store[i].ship);
        
        sort(store.begin(), store.end());

        for(int i=0; i<m; i++)
            for(int j=n-1; j>=0; j--)
            {
                int t=min(n, j+store[i].quant); // 최대 n개까지 구매 가능
                dp[t]=min(dp[t], dp[j]+store[i].ship+store[i].cost*(t-j));
            }
        printf("%d\n", dp[n]);
    }
}

/*

*/