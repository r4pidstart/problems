// https://www.acmicpc.net/problem/1311
// 2021-05-27 03:29:29 76ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > cost;
vector<int> dp;

int main(void)
{
    int n; scanf("%d", &n);

    cost.assign(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &cost[i][j]);
    dp.assign(1<<n, INT32_MAX);
    dp[0]=0;

    for(int i=0, l=pow(2,n); i<l; i++)
    {
        bitset<20> binary=i;
        int next_work=binary.count();

        for(int p=0; p<n; p++)
        {
            if(binary[p] == 0) // 해당 사람이 가진 일이 없으면
                dp[i|(1<<p)]=min(dp[i|(1<<p)], dp[i]+cost[p][next_work]);
        }
    }

    printf("%d", dp[(1<<n)-1]);
}