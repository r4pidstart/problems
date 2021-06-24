// https://www.acmicpc.net/problem/12014
// 2021-06-24 23:40:16 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    int memo[10000];
    for(int j=1; j<=t; j++)
    {
        int n,k; scanf("%d%d", &n,&k);
        memset(memo,0,sizeof(memo));
        int lis_length=0;
        for(int i=1; i<=n; i++)
        {
            int num; scanf("%d", &num);
            // lis
            auto it=lower_bound(memo, memo+lis_length, num)-memo;
            memo[it]=num;
            if(it==lis_length)
            {
                memo[it]=num;
                lis_length++;
            }
        }
        printf("Case #%d\n", j);
        if(k<=lis_length)
            printf("1\n");
        else
            printf("0\n");
    }
}